/**
 * @file StringT.cpp
 *
 * @date 19-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::StringT
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "StringT.h"
#include <cctype>

namespace TKOM_project {
namespace Tokens {

StringT::StringT()
        : m_wasWhite(false)
{
    m_types<<STRING_T;
}

StringT::~StringT()
{

}

bool StringT::isValidNow()
{
    return (m_currentPattern.length() != 0);
}

bool StringT::checkNextChar(char character)
{
    if (!m_wasWhite) {
        if (isspace(character)) {
            m_wasWhite = true;
        } else {
            this->m_currentPattern.append(character);
        }
    }

    return true;
}

} //namespace Tokens
} //namespace TKOM_project
