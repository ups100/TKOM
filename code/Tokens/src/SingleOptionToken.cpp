///////////////////////////////////////////////////////////
//  SingleOptionToken.cpp
//  Implementation of the Class SingleOptionToken
//  Created on:      19-maj-2013 18:12:32
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "SingleOptionToken.h"

namespace TKOM_project {
namespace Tokens {

SingleOptionToken::SingleOptionToken()
{

}

SingleOptionToken::~SingleOptionToken()
{

}

/**
 * true jak pasuje do 1 chociaz
 */
bool SingleOptionToken::checkNextChar(char character)
{

    return false;
}

QList<TokenTypes> SingleOptionToken::getTokenTypes()
{

    return QList<TokenTypes>();
}

} //namespace Tokens
} //namespace TKOM_project
