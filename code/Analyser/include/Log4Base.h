///////////////////////////////////////////////////////////
//  Log4Base.h
//  Implementation of the Class Log4Base
//  Created on:      19-maj-2013 18:10:41
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_74FE7AFC_A5B5_4cb0_B7B5_F243DE26F020__INCLUDED_)
#define EA_74FE7AFC_A5B5_4cb0_B7B5_F243DE26F020__INCLUDED_

#include "Log.h"
#include <QMap>
#include <QVariant>
#include <QString>

namespace TKOM_project {
namespace Analyser {

class Log4Base : public Log
{

public:
	Log4Base();
	virtual ~Log4Base();

	virtual QMap<QString, QVariant> getValues();
	void setSensDesc(const QString& description);
	void setSnum(const QString& snum);
	void setStatus(const QString& status);

private:
	QString m_sensDesc;
	int m_snum;
	QString m_status;

};

}//namespace Analyser
}//namespace TKOM_project
#endif // !defined(EA_74FE7AFC_A5B5_4cb0_B7B5_F243DE26F020__INCLUDED_)
