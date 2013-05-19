///////////////////////////////////////////////////////////
//  SingleOptionToken.h
//  Implementation of the Class SingleOptionToken
//  Created on:      19-maj-2013 18:12:32
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_B5F2AAA0_F202_4624_9E27_6EE062FD701C__INCLUDED_)
#define EA_B5F2AAA0_F202_4624_9E27_6EE062FD701C__INCLUDED_

#include "Token.h"

class SingleOptionToken : public Token
{

public:
	SingleOptionToken();
	virtual ~SingleOptionToken();

	virtual bool checkNextChar(char character);
	virtual QList<TokenTypes> getTokenTypes();

private:
	QMap<TokenTypes, QString> m_possiblePatterns;

};
#endif // !defined(EA_B5F2AAA0_F202_4624_9E27_6EE062FD701C__INCLUDED_)
