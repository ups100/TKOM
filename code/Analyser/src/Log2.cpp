/**
 * @file Log2.cpp
 *
 * @date 23-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log2
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "Log2.h"

namespace TKOM_project {
namespace Analyser {

Log2::Log2()
{

}

Log2::Log2(Log1Base *log)
:Log1Base(*log)
{
    delete log;
}

Log2::~Log2()
{

}

QMap<QString, QVariant> Log2::getValues()
{
    QMap<QString, QVariant> map = Log1Base::getValues();
    map.insert("Hex", m_hex);
    map.insert("IntelType", m_intelType);
    return map;
}

void Log2::setHex(const QString& hex)
{
    m_hex = hex;
}

void Log2::setIntelType(const QString& type)
{
    m_intelType = type;
}

} //namespace Analyser
} //namespace TKOM_project
