/**
 * @file TypeSignT.cpp
 *
 * @date 21-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::TypeSignT
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "TypeSignT.h"

namespace TKOM_project {
namespace Tokens {

TypeSignT::TypeSignT()
{
    m_types<<TYPESIGN_T<<STRING_T;
    m_possiblePatterns<<"a"<<"m";
}

TypeSignT::~TypeSignT()
{

}

} //namespace Tokens
} //namespace TKOM_project
