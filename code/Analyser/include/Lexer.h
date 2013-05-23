/**
 * @file Lexer.h
 *
 * @date 19-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Lexer
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_708417AD_3237_49de_9A7E_424BF36E3E9B__INCLUDED_)
#define EA_708417AD_3237_49de_9A7E_424BF36E3E9B__INCLUDED_

#include <boost/shared_ptr.hpp>

namespace TKOM_project {

namespace Tokens {
class Token;
}

namespace Analyser {
class FileReader;

/**
 * @brief Forms the tokens
 */
class Lexer
{

public:
    /**
     * @brief Constructor
     *
     * @param[in,out] source of text. This object takes ownership of it.
     */
    Lexer(FileReader *source);

    /**
     * @brief Destructor
     */
    virtual ~Lexer();

    /**
     * @brief Gets next token from source
     *
     * @return token
     */
    boost::shared_ptr<Tokens::Token> getNextToken();

private:
    FileReader *m_source;
};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_708417AD_3237_49de_9A7E_424BF36E3E9B__INCLUDED_)
