/**
 * @file StringT.h
 *
 * @date 19-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::StringT
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_26C3ECD1_37CD_440d_9BBA_02B60831982F__INCLUDED_)
#define EA_26C3ECD1_37CD_440d_9BBA_02B60831982F__INCLUDED_

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

class StringT : public Token
{

public:
    StringT();
    virtual ~StringT();

    virtual bool isValidNow();
    virtual bool checkNextChar(char character);

private:
    bool m_wasWhite;
};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_26C3ECD1_37CD_440d_9BBA_02B60831982F__INCLUDED_)
