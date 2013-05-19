///////////////////////////////////////////////////////////
//  Log2.h
//  Implementation of the Class Log2
//  Created on:      19-maj-2013 18:10:41
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_090852A5_DC61_4a61_B1E1_0F18BF81C4B3__INCLUDED_)
#define EA_090852A5_DC61_4a61_B1E1_0F18BF81C4B3__INCLUDED_

#include "Log1Base.h"

class Log2 : public Log1Base
{

public:
	Log2();
	virtual ~Log2();

	virtual QMap<QString, QVariant> getValues();
	void setHex(const const QString& hex);
	void setIntelType(const QString& type);

private:
	QString m_hex;
	QString m_intelType;

};
#endif // !defined(EA_090852A5_DC61_4a61_B1E1_0F18BF81C4B3__INCLUDED_)
