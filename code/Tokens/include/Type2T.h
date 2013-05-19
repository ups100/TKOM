///////////////////////////////////////////////////////////
//  Type2T.h
//  Implementation of the Class Type2T
//  Created on:      19-maj-2013 18:12:33
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_9CCA7186_60E6_4b30_B0DC_6C387FA356AC__INCLUDED_)
#define EA_9CCA7186_60E6_4b30_B0DC_6C387FA356AC__INCLUDED_

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

class Type2T : public Token
{

public:
    Type2T();
    virtual ~Type2T();

    virtual bool checkNextChar(char character);
    virtual QList<TokenTypes> getTokenTypes();

};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_9CCA7186_60E6_4b30_B0DC_6C387FA356AC__INCLUDED_)
