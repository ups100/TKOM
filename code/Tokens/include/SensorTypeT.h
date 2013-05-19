///////////////////////////////////////////////////////////
//  SensorTypeT.h
//  Implementation of the Class SensorTypeT
//  Created on:      19-maj-2013 18:12:32
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_F7E8C339_CFA4_49f2_B4A0_D96307CB66D8__INCLUDED_)
#define EA_F7E8C339_CFA4_49f2_B4A0_D96307CB66D8__INCLUDED_

#include "Token.h"

class SensorTypeT : public Token
{

public:
	SensorTypeT();
	virtual ~SensorTypeT();

	virtual bool checkNextChar(char character);
	virtual QList<TokenTypes> getTokenTypes();

};
#endif // !defined(EA_F7E8C339_CFA4_49f2_B4A0_D96307CB66D8__INCLUDED_)
