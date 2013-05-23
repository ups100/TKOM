/**
 * @file TypeT.cpp
 *
 * @date 21-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::TypeT
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */
#include "TypeT.h"

namespace TKOM_project {
namespace Tokens {

TypeT::TypeT()
{
    m_types<<TYPE_T<<STRING_T;
    m_possiblePatterns<<"FRU"<<"IPMB"<<"DLoc";
}

TypeT::~TypeT()
{

}

} //namespace Tokens
} //namespace TKOM_project
