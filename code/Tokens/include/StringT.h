///////////////////////////////////////////////////////////
//  StringT.h
//  Implementation of the Class StringT
//  Created on:      19-maj-2013 18:12:32
//  Original author: kopasiak
///////////////////////////////////////////////////////////

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

    virtual bool checkNextChar(char character);
    virtual QList<TokenTypes> getTokenTypes();

};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_26C3ECD1_37CD_440d_9BBA_02B60831982F__INCLUDED_)
