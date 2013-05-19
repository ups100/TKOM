///////////////////////////////////////////////////////////
//  Lexer.h
//  Implementation of the Class Lexer
//  Created on:      19-maj-2013 18:10:40
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_708417AD_3237_49de_9A7E_424BF36E3E9B__INCLUDED_)
#define EA_708417AD_3237_49de_9A7E_424BF36E3E9B__INCLUDED_

class Lexer
{

public:
	Lexer();
	virtual ~Lexer();

	Token * getNextToken();

};
#endif // !defined(EA_708417AD_3237_49de_9A7E_424BF36E3E9B__INCLUDED_)
