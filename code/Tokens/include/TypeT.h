/**
 * @file TypeT.h
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

#if !defined(EA_9C4B560F_4082_44c3_AB2A_B07229807675__INCLUDED_)
#define EA_9C4B560F_4082_44c3_AB2A_B07229807675__INCLUDED_

#include "Token.h"
#include "MultiOptionToken.h"

namespace TKOM_project {
namespace Tokens {

class TypeT : public MultiOptionToken
{

public:
    /**
     * @brief Constructor
     */
    TypeT();

    /**
     * @brief Destructor
     */
    virtual ~TypeT();
};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_9C4B560F_4082_44c3_AB2A_B07229807675__INCLUDED_)
