/**
 * @file Log.cpp
 *
 * @date 23-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "Log.h"

namespace TKOM_project {
namespace Analyser {

Log::Log()
: m_id(-1)
{

}

Log::~Log()
{

}

QMap<QString, QVariant> Log::getValues()
{
    QMap<QString, QVariant> pairs;
    if(m_id != -1) pairs.insert(QString("LogID"), m_id);
    pairs.insert(QString("SensorType"), m_sensorType);
    return QMap<QString, QVariant>();
}

void Log::setID(const QString& id)
{
    bool ok;

    m_id = id.toInt(&ok, 16);

    if(!ok) {
        throw QString("Bad cast:") + id;
    }
}

void Log::setSensorType(const QString& type)
{
    m_sensorType = type;
}

} //namespace Analyser
} //namespace TKOM_project
