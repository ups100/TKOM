/**
 * @file Log1Base.cpp
 *
 * @date 23-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log1Base
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "Log1Base.h"
#include <QDebug>
namespace TKOM_project {
namespace Analyser {

Log1Base::Log1Base()
        : m_et(-1), m_xx(-1)
{

}

Log1Base::~Log1Base()
{

}

QMap<QString, QVariant> Log1Base::getValues()
{
    QMap<QString, QVariant> map = Log::getValues();
    map.insert("Et", m_et);
    map.insert("xx", m_xx);
    return map;
}

void Log1Base::setEt(const QString& et)
{
    bool ok = false;

    m_et = et.toInt(&ok, 16);

    if (!ok) {
        throw QString("Bad cast: ") + et;
    }
}

void Log1Base::setXx(const QString& xx)
{
    bool ok = false;

    m_xx = xx.toInt(&ok, 16);

    if (!ok) {
        throw QString("Bad cast: ") + xx;
    }
}

} //namespace Analyser
} //namespace TKOM_project
