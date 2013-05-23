/**
 * @file UnitT.cpp
 *
 * @date 21-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::UnitT
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */
#include "UnitT.h"

namespace TKOM_project {
namespace Tokens {

UnitT::UnitT()
{
    m_types << UNIT_T << STRING_T;
    m_possiblePatterns << "precent" << "Volts" << "RPM" << "degrees C" << "CFM";
}

UnitT::~UnitT()
{

}

} //namespace Tokens
} //namespace TKOM_project
