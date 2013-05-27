/**
 * @file Log4Base.cpp
 *
 * @date 22-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log4Base
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "Log4Base.h"

namespace TKOM_project {
namespace Analyser {

Log4Base::Log4Base()
{

}

Log4Base::~Log4Base()
{

}

QMap<QString, QVariant> Log4Base::getValues()
{
    QMap<QString, QVariant> map = Log::getValues();
    map.insert("SensorDescription", m_sensDesc);
    map.insert("S_Num", m_snum);
    map.insert("SensorStatus", m_status);
    return map;
}

void Log4Base::setSensDesc(const QString& description)
{
    m_sensDesc = description;
}

void Log4Base::setSnum(const QString& snum)
{
    bool ok;

    m_snum = snum.toInt(&ok, 16);

    if (!ok) {
        throw QString("Bad cast:") + snum;
    }
}

void Log4Base::setStatus(const QString& status)
{
    m_status = status;
}

} //namespace Analyser
} //namespace TKOM_project
