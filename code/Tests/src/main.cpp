#include "Lexer.h"
#include "FileReader.h"
#include "Token.h"
#include "Parser.h"
#include "DataBaseConnection.h"

#include <QList>
#include <QDebug>
#include <iostream>
#include <QtSql/QtSql>
using namespace TKOM_project::Analyser;
using namespace TKOM_project::Tokens;

int main(int argc, char **argv)
{QSqlDatabase m_db;
    if(argc < 3) return -1;
    Lexer *lex = new Lexer(new FileReader(argv[1]));
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
    try {
    Parser parser(lex, new DataBaseConnection(argv[2]));
    parser.parse();
    } catch (QString &s) {
        qDebug()<<s;
    }
    return 0;
}
