/**
 * @file HexPairT.h
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

#if !defined(EA_BF514AA3_8E7A_4657_9D84_3FB72FFC2EFE__INCLUDED_)
#define EA_BF514AA3_8E7A_4657_9D84_3FB72FFC2EFE__INCLUDED_

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

/**
 * @brief Represents two positional hex number.
 */
class HexPairT : public Token
{

public:
    /**
     * @brief Constructor
     */
    HexPairT();

    /**
     * @brief Destructor
     */
    virtual ~HexPairT();

    virtual bool isValidNow();
    virtual bool checkNextChar(char character);

private:
    /**
     * @brief Informs if token is correct
     */
    bool m_incorrect;
};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_BF514AA3_8E7A_4657_9D84_3FB72FFC2EFE__INCLUDED_)
