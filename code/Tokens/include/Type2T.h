/**
 * @file Type2T.h
 *
 * @date 21-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::Type2T
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_9CCA7186_60E6_4b30_B0DC_6C387FA356AC__INCLUDED_)
#define EA_9CCA7186_60E6_4b30_B0DC_6C387FA356AC__INCLUDED_

#include "Token.h"
#include "MultiOptionToken.h"

namespace TKOM_project {
namespace Tokens {

class Type2T : public MultiOptionToken
{

public:
    /**
     * @brief Constructor
     */
    Type2T();

    /**
     * @brief Destructor
     */
    virtual ~Type2T();
};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_9CCA7186_60E6_4b30_B0DC_6C387FA356AC__INCLUDED_)
