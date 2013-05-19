///////////////////////////////////////////////////////////
//  nlT.cpp
//  Implementation of the Class nlT
//  Created on:      19-maj-2013 18:12:32
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "nlT.h"

namespace TKOM_project {
namespace Tokens {

nlT::nlT()
{

}

nlT::~nlT()
{

}

/**
 * true jak pasuje do 1 chociaz
 */
bool nlT::checkNextChar(char character)
{

    return false;
}

QList<TokenTypes> nlT::getTokenTypes()
{

    return QList<TokenTypes>();
}

} //namespace Tokens
} //namespace TKOM_project
