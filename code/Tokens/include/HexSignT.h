/**
 * @file HexSignT.h
 *
 * @date 21-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::HexPairT
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_0C9B86F5_4FD7_464e_B452_94ED16A169C7__INCLUDED_)
#define EA_0C9B86F5_4FD7_464e_B452_94ED16A169C7__INCLUDED_

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

/**
 * @brief Represents single hex sign
 */
class HexSignT : public Token
{

public:
    /**
     * @brief Constructor
     */
    HexSignT();

    /**
     * @brief Destructor
     */
    virtual ~HexSignT();

    virtual bool checkNextChar(char character);
    virtual bool isValidNow();

private:
    /**
     * @brief Informs if token is correct
     */
    bool m_incorrect;
};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_0C9B86F5_4FD7_464e_B452_94ED16A169C7__INCLUDED_)
