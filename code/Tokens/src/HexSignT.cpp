/**
 * @file HexSignT.cpp
 *
 * @date 21-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::HexPairT
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "HexSignT.h"

namespace TKOM_project {
namespace Tokens {

HexSignT::HexSignT()
        : m_incorrect(false)
{
    this->m_types<<HEXSIGN_T<<STRING_T;
}

HexSignT::~HexSignT()
{

}

bool HexSignT::checkNextChar(char character)
{
    if (m_incorrect)
        return false;

    if ((isdigit(character) || (character >= 'a' && character <= 'f'))
            && m_currentPattern.size() < 1) {
        m_currentPattern[m_currentPattern.size()] = character;
        if(isdigit(character)) {
            m_types<<DIGIT_T;
        }
        return true;
    } else {
        m_currentPattern.clear();
        m_incorrect = true;
        return false;
    }
}

bool HexSignT::isValidNow()
{
    return m_currentPattern.size() == 1;
}

} //namespace Tokens
} //namespace TKOM_project
