///////////////////////////////////////////////////////////
//  TypeT.h
//  Implementation of the Class TypeT
//  Created on:      19-maj-2013 18:12:33
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_9C4B560F_4082_44c3_AB2A_B07229807675__INCLUDED_)
#define EA_9C4B560F_4082_44c3_AB2A_B07229807675__INCLUDED_

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

class TypeT : public Token
{

public:
	TypeT();
	virtual ~TypeT();

	virtual bool checkNextChar(char character);
	virtual QList<TokenTypes> getTokenTypes();

};

}//namespace Tokens
}//namespace TKOM_project
#endif // !defined(EA_9C4B560F_4082_44c3_AB2A_B07229807675__INCLUDED_)
