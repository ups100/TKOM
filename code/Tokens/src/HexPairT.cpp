/**
 * @file HexPairT.cpp
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

#include "HexPairT.h"

namespace TKOM_project {
namespace Tokens {

HexPairT::HexPairT()
        : m_incorrect(false)
{
    m_types<<HEXPAIR_T<<STRING_T;
}

HexPairT::~HexPairT()
{

}

bool HexPairT::checkNextChar(char character)
{
    if (m_incorrect)
        return false;

    if ((isdigit(character) || (character >= 'a' && character <= 'f'))
            && m_currentPattern.size() < 2) {
        m_currentPattern[m_currentPattern.size()] = character;
        if(m_currentPattern.size() == 2) {
            if(m_currentPattern[0].isDigit() && m_currentPattern[1].isDigit()) {
                m_types<<DIGIT2_T;
            }
        }
        return true;
    } else {
        m_currentPattern.clear();
        m_incorrect = true;
        return false;
    }
}

bool HexPairT::isValidNow()
{
    return m_currentPattern.size() == 2;
}

} //namespace Tokens
} //namespace TKOM_project
