#include "Lexer.h"
#include "FileReader.h"
#include "Token.h"
#include "Parser.h"
#include "DataBaseConnection.h"

#include <QList>
#include <QDebug>
#include <iostream>

using namespace TKOM_project::Analyser;
using namespace TKOM_project::Tokens;

int main(int argc, char **argv)
{
    //if(argc < 2) return -1;
    Lexer *lex = new Lexer(new FileReader(QString("test")));
    qDebug()<<"jest obiekt";

    /*for(Token *t = lex.getNextToken(); t != 0L; t = lex.getNextToken())
    {
        foreach(TokenTypes tok, t->getTokenTypes() )
        {
            qDebug()<<tok;
        }
        qDebug()<<t->getCurrentPattern();
        char ch;
        std::cin>>ch;
    }*/

    Parser parser(lex, new DataBaseConnection());
    parser.parse();
    return 0;
}
