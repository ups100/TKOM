/**
 * @file Reading.cpp
 *
 * @date 23-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Reading
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "Reading.h"

namespace TKOM_project {
namespace Analyser {

Reading::Reading()
: m_value(-1.0)
{

}

Reading::~Reading()
{

}

QMap<QString, QVariant> Reading::getReadingData()
{
    QMap<QString, QVariant> map;
    map.insert("ReadingUnit", m_unit);
    map.insert("ReadingValue", m_value);
    return QMap<QString, QVariant>();
}

void Reading::setUnit(const QString& unit)
{
    m_unit = unit;
}

void Reading::setValue(const QString& value)
{
    bool ok = false;

    m_value = value.toFloat(&ok);

    if(!ok) {
        throw QString("Bad cast:") + value;
    }
}

} //namespace Analyser
} //namespace TKOM_project
