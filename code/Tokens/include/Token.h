/**
 * @file Token.h
 *
 * @date 19-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::Token
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_02E3FF6B_AFD2_4d43_BD90_710C8144E679__INCLUDED_)
#define EA_02E3FF6B_AFD2_4d43_BD90_710C8144E679__INCLUDED_

#include <QList>
#include <QString>
#include "TokenTypes.h"

namespace TKOM_project {
namespace Tokens {

/**
 * @brief Represents a single token
 */
class Token
{

public:
    /**
     * @brief Constructor
     */
    Token();

    /**
     * @brief Destructor
     */
    virtual ~Token();

    /**
     * @brief Checks if character is suitable as next character in this token.
     *
     * @param[in] character to be checked
     *
     * @return true if character is suitable, false otherwise
     */
    virtual bool checkNextChar(char character) = 0;

    /**
     * @brief Checks if this token is valid now
     *
     * @return true if token is now completed and valid, false otherwise
     */
    virtual bool isValidNow() = 0;

    /**
     * @brief Gets the current pattern completed by checkNextChar
     *
     * @return current pattern
     */
    virtual const QString& getCurrentPattern();

    /**
     * @brief Gets the length of current pattern string
     */
    virtual int getTokenLength();

    /**
     * @brief Gets the token types to which this token belongs to.
     *
     * @brief list of groups
     */
    virtual const QList<TokenTypes>& getTokenTypes();

protected:
    /**
     * @brief Current pattern.
     */
    QString m_currentPattern;

    /**
     * @brief Groups to which this token belongs to.
     */
    QList<TokenTypes> m_types;

};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_02E3FF6B_AFD2_4d43_BD90_710C8144E679__INCLUDED_)
