/**
 * @file SensorTypeT.h
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

#if !defined(EA_F7E8C339_CFA4_49f2_B4A0_D96307CB66D8__INCLUDED_)
#define EA_F7E8C339_CFA4_49f2_B4A0_D96307CB66D8__INCLUDED_

#include "MultiOptionToken.h"

namespace TKOM_project {
namespace Tokens {

class SensorTypeT : public MultiOptionToken
{

public:
    /**
     * @brief Constructor
     */
    SensorTypeT();

    /**
     * @brief Destructor
     */
    virtual ~SensorTypeT();
};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_F7E8C339_CFA4_49f2_B4A0_D96307CB66D8__INCLUDED_)
