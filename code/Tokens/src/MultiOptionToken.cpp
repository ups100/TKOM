/**
 * @file MultiOptionToken.cpp
 *
 * @date 21-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::MultiOptionToken
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "MultiOptionToken.h"

namespace TKOM_project {
namespace Tokens {

MultiOptionToken::MultiOptionToken()
        : m_incorrect(false)
{

}

MultiOptionToken::~MultiOptionToken()
{

}

bool MultiOptionToken::checkNextChar(char character)
{
    if (m_incorrect)
        return false;
    QList<QString> rm;
    foreach(QString pattern, this->m_possiblePatterns) {
        if (pattern[m_currentPattern.size()] != character) {
            rm.append(pattern);
        }
    }

    foreach(QString pattern, rm) {
        m_possiblePatterns.removeOne(pattern);
    }

    if (m_possiblePatterns.size() > 0) {
        m_currentPattern.append(character);
        return true;
    } else {
        m_currentPattern.clear();
        m_incorrect = true;
        return false;
    }
}

bool MultiOptionToken::isValidNow()
{
    return m_possiblePatterns.size() == 1
            && m_currentPattern == m_possiblePatterns.front();
}

} //namespace Tokens
} //namespace TKOM_project
