/**
 * @file PowerOnLog.cpp
 *
 * @date 22-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::PowerOnLog
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "PowerOnLog.h"

namespace TKOM_project {
namespace Analyser {

PowerOnLog::PowerOnLog()
{

}

void PowerOnLog::setSensDesc(const QString& description)
{
    this->m_sensDesc = description;
}

void PowerOnLog::setPowerOnHours(const QString& hours)
{
    bool ok = false;

    m_powerOn = hours.toInt(&ok, 10);

    if(!ok) {
        throw QString("Bad cast: ") + hours;
    }
}

QMap<QString, QVariant> PowerOnLog::getValues()
{
    QMap<QString, QVariant> map = Log::getValues();
    map.insert("SensorDescription", m_sensDesc);
    map.insert("ReadingValue", m_powerOn);
    map.insert("ReadingUnit", "hours");
    return map;
}

}
}
