///////////////////////////////////////////////////////////
//  StringT.cpp
//  Implementation of the Class StringT
//  Created on:      19-maj-2013 18:12:32
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "StringT.h"

namespace TKOM_project {
namespace Tokens {

StringT::StringT()
{

}

StringT::~StringT()
{

}

/**
 * true jak pasuje do 1 chociaz
 */
bool StringT::checkNextChar(char character)
{

    return false;
}

QList<TokenTypes> StringT::getTokenTypes()
{

    return QList<TokenTypes>();
}

} //namespace Tokens
} //namespace TKOM_project
