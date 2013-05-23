/**
 * @file TypeSignT.h
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

#if !defined(EA_8B83C433_88C1_4608_A01C_11B3E9C93BB9__INCLUDED_)
#define EA_8B83C433_88C1_4608_A01C_11B3E9C93BB9__INCLUDED_

#include "Token.h"
#include "MultiOptionToken.h"

namespace TKOM_project {
namespace Tokens {

class TypeSignT : public MultiOptionToken
{

public:

    /**
     * @brief Constructor
     */
    TypeSignT();

    /**
     * @brief Destructor
     */
    virtual ~TypeSignT();

};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_8B83C433_88C1_4608_A01C_11B3E9C93BB9__INCLUDED_)
