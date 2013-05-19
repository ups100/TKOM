///////////////////////////////////////////////////////////
//  UnitT.h
//  Implementation of the Class UnitT
//  Created on:      19-maj-2013 18:12:33
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_B639AD35_D778_4528_A704_65665F46A4D9__INCLUDED_)
#define EA_B639AD35_D778_4528_A704_65665F46A4D9__INCLUDED_

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

class UnitT : public Token
{

public:
    UnitT();
    virtual ~UnitT();

    virtual bool checkNextChar(char character);
    virtual QList<TokenTypes> getTokenTypes();

};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_B639AD35_D778_4528_A704_65665F46A4D9__INCLUDED_)
