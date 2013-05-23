/**
 * @file SingleOptionToken.h
 *
 * @date 19-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::SingleOptionToken
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_B5F2AAA0_F202_4624_9E27_6EE062FD701C__INCLUDED_)
#define EA_B5F2AAA0_F202_4624_9E27_6EE062FD701C__INCLUDED_

#include "Token.h"
#include <QMap>

namespace TKOM_project {
namespace Tokens {

/**
 * @brief Represents all tokens which may have only one value.
 */
class SingleOptionToken : public Token
{

public:
    /**
     * @brief Constructor
     *
     * @param[in] types of this token
     *
     * @param[in] pattern of this token
     */
    SingleOptionToken(const QList<TokenTypes>& types, const QString& pattern);

    /**
     * @brief Destructor
     */
    virtual ~SingleOptionToken();

    virtual bool isValidNow();

    virtual bool checkNextChar(char character);

    /**
     * @brief Gets all the single option tokens.
     *
     * @return list of tokens
     */
    static QList<Token*> getAllSigleOptionTokens();

private:

    /**
     * @brief Target pattern
     */
    QString m_targetPattern;

    /**
     * @brief Informs if pattern is correct
     */
    bool m_incorrect;

};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_B5F2AAA0_F202_4624_9E27_6EE062FD701C__INCLUDED_)
