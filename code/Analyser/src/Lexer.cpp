/**
 * @file Lexer.cpp
 *
 * @date 19-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Lexer
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "Lexer.h"
#include "Token.h"
#include "FileReader.h"
#include "StringT.h"
#include "SingleOptionToken.h"
#include "HexPairT.h"
#include "HexSignT.h"
#include "SensorTypeT.h"
#include "StatusT.h"
#include "Type2T.h"
#include "TypeSignT.h"
#include "TypeT.h"
#include "UnitT.h"

#include <QList>
#include <QDebug>

namespace TKOM_project {
using namespace Tokens;

namespace Analyser {

Lexer::Lexer(FileReader *source)
        : m_source(source)
{

}

Lexer::~Lexer()
{
    delete m_source;
}

boost::shared_ptr<Tokens::Token> Lexer::getNextToken()
{

    QList<Token*> tokens;

    Token* suitable = 0L;
    Token* stringT = new StringT();

    tokens.append(SingleOptionToken::getAllSigleOptionTokens());
    tokens.append(new HexPairT());
    tokens.append(new HexSignT());
    tokens.append(new SensorTypeT());
    tokens.append(new StatusT());
    tokens.append(new Type2T());
    tokens.append(new TypeSignT());
    tokens.append(new TypeT());
    tokens.append(new UnitT());

    int offset = -1;
    char next;
    do {
        next = m_source->getNextChar();
        ++offset;
    } while (isspace(next) && next != '\n');

    bool wasSpace = false;
    while (tokens.size() > 0) {
        wasSpace = isspace(next) ? true : false;

        stringT->checkNextChar(next);

        for (QList<Token*>::iterator it = tokens.begin(); it != tokens.end();) {
            if (!((*it)->checkNextChar(next))) {
                delete (*it);
                it = tokens.erase(it);
            } else {
                if ((*it)->isValidNow()) {
                    delete suitable;
                    suitable = (*it);

                    it = tokens.erase(it);
                } else {
                    ++it;
                }
            }
        }

        next = m_source->getNextChar();
        if (next == '\0') {
            foreach(Token *t, tokens) {
                delete t;
            }
            tokens.clear();
            return boost::shared_ptr<Tokens::Token>(
                    new SingleOptionToken(QList<TokenTypes>() << EOF_T,
                            QString("\0")));
        }
    }

    Token *toReturn = (suitable != 0L) ? suitable : stringT;
    if (toReturn != stringT) {
        delete stringT;
    } else if (!wasSpace) {
        while ((!isspace(next)) && next != '.' && next != ',') {
            stringT->checkNextChar(next);
            next = m_source->getNextChar();
        }
    }

    m_source->adjustPosition(toReturn->getTokenLength() + offset);

    return boost::shared_ptr<Tokens::Token>(toReturn);
}

} //namespace Analyser
} //namespace TKOM_project
