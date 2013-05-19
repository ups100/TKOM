///////////////////////////////////////////////////////////
//  Log3.h
//  Implementation of the Class Log3
//  Created on:      19-maj-2013 18:10:41
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_95756016_BCB8_42d0_ACCD_AECE2452B249__INCLUDED_)
#define EA_95756016_BCB8_42d0_ACCD_AECE2452B249__INCLUDED_

#include "Log1Base.h"
#include <QMap>
#include <QVariant>
#include <QString>

namespace TKOM_project {
namespace Analyser {

class Log3 : public Log1Base
{

public:
    Log3();
    virtual ~Log3();

    virtual QMap<QString, QVariant> getValues();
    void setDev(const QString& dev);
    void setHex(const QString& hex);
    void setSensDesc(const QString& sensDesc);

private:
    QString m_dev;
    QString m_hex;
    QString m_sensDesc;

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_95756016_BCB8_42d0_ACCD_AECE2452B249__INCLUDED_)
