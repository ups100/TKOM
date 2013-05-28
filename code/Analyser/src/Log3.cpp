/**
 * @file Log3.cpp
 *
 * @date 23-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log3
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "Log3.h"

namespace TKOM_project {
namespace Analyser {

Log3::Log3()
{

}

Log3::Log3(Log1Base *log)
: Log1Base(*log)
{
    delete log;
}

Log3::~Log3()
{

}

QMap<QString, QVariant> Log3::getValues()
{
    QMap<QString, QVariant> map = Log1Base::getValues();
    map.insert("HexValues", m_hex);
    map.insert("SensorDescription", m_sensDesc);
    return map;
}


void Log3::setHex(const QString& hex)
{
    m_hex = hex;
}

void Log3::setSensDesc(const QString& sensDesc)
{
    this->m_sensDesc = sensDesc;
}

} //namespace Analyser
} //namespace TKOM_project
