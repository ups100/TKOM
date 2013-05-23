/**
 * @file UnitT.h
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

#if !defined(EA_B639AD35_D778_4528_A704_65665F46A4D9__INCLUDED_)
#define EA_B639AD35_D778_4528_A704_65665F46A4D9__INCLUDED_

#include "Token.h"
#include "MultiOptionToken.h"

namespace TKOM_project {
namespace Tokens {

class UnitT : public MultiOptionToken
{

public:

    /**
     * @brief Constructor
     */
    UnitT();

    /**
     * @brief Destructor
     */
    virtual ~UnitT();

};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_B639AD35_D778_4528_A704_65665F46A4D9__INCLUDED_)
