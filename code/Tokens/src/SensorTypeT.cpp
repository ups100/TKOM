/**
 * @file SensorTypeT.cpp
 *
 * @date 21-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::SensorTypeT
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "SensorTypeT.h"

namespace TKOM_project {
namespace Tokens {

SensorTypeT::SensorTypeT()
{
    m_types<<SENSORTYPE_T<<STRING_T;
    this->m_possiblePatterns<<"Compact sensor"<<"Full sensor";
}

SensorTypeT::~SensorTypeT()
{

}

} //namespace Tokens
} //namespace TKOM_project
