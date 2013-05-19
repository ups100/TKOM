///////////////////////////////////////////////////////////
//  Log1Base.h
//  Implementation of the Class Log1Base
//  Created on:      19-maj-2013 18:10:40
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_4AEBE7D9_A1C9_4b53_8FEF_62C7D919CB69__INCLUDED_)
#define EA_4AEBE7D9_A1C9_4b53_8FEF_62C7D919CB69__INCLUDED_

#include "Log.h"

class Log1Base : public Log
{

public:
	Log1Base();
	virtual ~Log1Base();

	virtual QMap<QString, QVariant> getValues();
	void setEt(const QString& et);
	void setType(const QString& type);
	void setXx(const QString& xx);

private:
	int m_et;
	QString m_type;
	int m_xx;

};
#endif // !defined(EA_4AEBE7D9_A1C9_4b53_8FEF_62C7D919CB69__INCLUDED_)
