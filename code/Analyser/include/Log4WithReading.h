///////////////////////////////////////////////////////////
//  Log4WithReading.h
//  Implementation of the Class Log4WithReading
//  Created on:      19-maj-2013 18:10:41
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_074134B4_A17C_4b8c_9439_571A446638F9__INCLUDED_)
#define EA_074134B4_A17C_4b8c_9439_571A446638F9__INCLUDED_

#include "Log4Base.h"
#include "Reading.h"

class Log4WithReading : public Log4Base, public Reading
{

public:
	Log4WithReading();
	virtual ~Log4WithReading();

	virtual QMap<QString, QVariant> getValues();

};
#endif // !defined(EA_074134B4_A17C_4b8c_9439_571A446638F9__INCLUDED_)
