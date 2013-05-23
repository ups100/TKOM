/**
 * @file Token.cpp
 *
 * @date 19-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::CommandDispatcher
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

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
/*bool Token::checkNextChar(char character)
{

    return false;
}*/

const QString& Token::getCurrentPattern()
{

    return m_currentPattern;
}

int Token::getTokenLength()
{
    return this->m_currentPattern.length();
}

const QList<TokenTypes>& Token::getTokenTypes()
{
    return m_types;
}

} //namespace Tokens
} //namespace TKOM_project
