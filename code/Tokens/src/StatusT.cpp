/**
 * @file StatusT.cpp
 *
 * @date 21-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::StatusT
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "StatusT.h"

namespace TKOM_project {
namespace Tokens {

StatusT::StatusT()
{
    m_types << STATUS_T << STRING_T;
    m_possiblePatterns << "OK" << "Present" << "Asserted" << "PS_Failed"
            << "Working" << "Init" << "Policy" << "ProcPresent"
            << "Faulty Faulty" << "Enabled";

}

StatusT::~StatusT()
{

}
} //namespace Tokens
} //namespace TKOM_project
