///////////////////////////////////////////////////////////
//  nlT.h
//  Implementation of the Class nlT
//  Created on:      19-maj-2013 18:12:31
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_2516163A_E25C_4b40_AAAA_46D8055D6013__INCLUDED_)
#define EA_2516163A_E25C_4b40_AAAA_46D8055D6013__INCLUDED_

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

class nlT : public Token
{

public:
	nlT();
	virtual ~nlT();

	virtual bool checkNextChar(char character);
	virtual QList<TokenTypes> getTokenTypes();

};

}//namespace Tokens
}//namespace TKOM_project
#endif // !defined(EA_2516163A_E25C_4b40_AAAA_46D8055D6013__INCLUDED_)
