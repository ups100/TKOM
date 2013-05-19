///////////////////////////////////////////////////////////
//  TypeSignT.h
//  Implementation of the Class TypeSignT
//  Created on:      19-maj-2013 18:12:33
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_8B83C433_88C1_4608_A01C_11B3E9C93BB9__INCLUDED_)
#define EA_8B83C433_88C1_4608_A01C_11B3E9C93BB9__INCLUDED_

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

class TypeSignT : public Token
{

public:
    TypeSignT();
    virtual ~TypeSignT();

    virtual bool checkNextChar(char character);
    virtual QList<TokenTypes> getTokenTypes();

};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_8B83C433_88C1_4608_A01C_11B3E9C93BB9__INCLUDED_)
