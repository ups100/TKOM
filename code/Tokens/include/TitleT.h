///////////////////////////////////////////////////////////
//  TitleT.h
//  Implementation of the Class TitleT
//  Created on:      19-maj-2013 18:12:32
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_D7B28D31_018C_4d6f_85CF_0CFC220E117E__INCLUDED_)
#define EA_D7B28D31_018C_4d6f_85CF_0CFC220E117E__INCLUDED_

#include "Token.h"

class TitleT : public Token
{

public:
	TitleT();
	virtual ~TitleT();

	virtual bool checkNextChar(char character);
	virtual QList<TokenTypes> getTokenTypes();

};
#endif // !defined(EA_D7B28D31_018C_4d6f_85CF_0CFC220E117E__INCLUDED_)
