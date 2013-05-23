/**
 * @file MultiOptionToken.h
 *
 * @date 21-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::MultiOptionToken
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#ifndef __MULTI_OPTION_TOKEN_H__
#define __MULTI_OPTION_TOKEN_H__

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

class MultiOptionToken : public Token
{
public:

    /**
     * @brief Destructor
     */
    ~MultiOptionToken();

    virtual bool isValidNow();
    virtual bool checkNextChar(char character);

protected:
    /**
     * @brief Constructor
     */
    MultiOptionToken();

    /**
     * @brief All possible patterns.
     */
    QList<QString> m_possiblePatterns;

    /**
     * @brief Informs if current pattern is incorrect
     */
    bool m_incorrect;

};

} //namespace Tokens
} //namespace TKOM_project
#endif
