///////////////////////////////////////////////////////////
//  Log.h
//  Implementation of the Class Log
//  Created on:      19-maj-2013 18:10:40
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_D80A9CC5_BF46_4ad7_BE0C_7DF7D96C180E__INCLUDED_)
#define EA_D80A9CC5_BF46_4ad7_BE0C_7DF7D96C180E__INCLUDED_

#include <QMap>
#include <QString>
#include <QVariant>

namespace TKOM_project {
namespace Analyser {

class Log
{

public:
	Log();
	virtual ~Log();

	virtual QMap<QString, QVariant> getValues();
	void setID(const QString& id);
	void setSensorType(QString type);

private:
	int m_id;
	QString m_sensorType;

};

}//namespace Analyser
}//namespace TKOM_project
#endif // !defined(EA_D80A9CC5_BF46_4ad7_BE0C_7DF7D96C180E__INCLUDED_)
