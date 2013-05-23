/**
 * @file StatusT.h
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

#if !defined(EA_5B500C13_3A96_42a9_852C_3A75EFFF646E__INCLUDED_)
#define EA_5B500C13_3A96_42a9_852C_3A75EFFF646E__INCLUDED_

#include "Token.h"
#include "MultiOptionToken.h"

namespace TKOM_project {
namespace Tokens {

class StatusT : public MultiOptionToken
{

public:
    /**
     * @brief Constructor
     */
    StatusT();
    /**
     * @brief Destructor
     */
    virtual ~StatusT();

};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_5B500C13_3A96_42a9_852C_3A75EFFF646E__INCLUDED_)
