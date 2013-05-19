///////////////////////////////////////////////////////////
//  HexSignT.h
//  Implementation of the Class HexSignT
//  Created on:      19-maj-2013 18:12:31
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_0C9B86F5_4FD7_464e_B452_94ED16A169C7__INCLUDED_)
#define EA_0C9B86F5_4FD7_464e_B452_94ED16A169C7__INCLUDED_

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

class HexSignT : public Token
{

public:
    HexSignT();
    virtual ~HexSignT();

    virtual bool checkNextChar(char character);
    virtual QList<TokenTypes> getTokenTypes();

};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_0C9B86F5_4FD7_464e_B452_94ED16A169C7__INCLUDED_)
