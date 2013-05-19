///////////////////////////////////////////////////////////
//  StatusT.h
//  Implementation of the Class StatusT
//  Created on:      19-maj-2013 18:12:32
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_5B500C13_3A96_42a9_852C_3A75EFFF646E__INCLUDED_)
#define EA_5B500C13_3A96_42a9_852C_3A75EFFF646E__INCLUDED_

#include "Token.h"

class StatusT : public Token
{

public:
	StatusT();
	virtual ~StatusT();

	virtual bool checkNextChar(char character);
	virtual QList<TokenTypes> getTokenTypes();

};
#endif // !defined(EA_5B500C13_3A96_42a9_852C_3A75EFFF646E__INCLUDED_)
