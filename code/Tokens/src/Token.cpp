///////////////////////////////////////////////////////////
//  Token.cpp
//  Implementation of the Class Token
//  Created on:      19-maj-2013 18:12:33
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

Token::Token()
{

}

Token::~Token()
{

}

/**
 * true jak pasuje do 1 chociaz
 */
bool Token::checkNextChar(char character)
{

    return false;
}

const QString& Token::getCurrentPattern()
{

    return QString();
}

} //namespace Tokens
} //namespace TKOM_project
