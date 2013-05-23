/**
 * @file Log1.h
 *
 * @date 23-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log1
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "Log1.h"

namespace TKOM_project {
namespace Analyser {

Log1::Log1()
        : m_own(-1), m_snum(-1)
{

}

Log1::Log1(Log1Base *log)
        : Log1Base(*log), m_own(-1), m_snum(-1)
{
    delete log;
}

Log1::~Log1()
{

}

QMap<QString, QVariant> Log1::getValues()
{
    QMap<QString, QVariant> map = Log1Base::getValues();
    map.insert("HexValues", m_hex);
    map.insert("Own", m_own);
    map.insert("SensorDescription", m_sensDesc);
    map.insert("S_Num", m_snum);
    map.insert("Typ", m_typ);
    map.insert("SensorStatus", m_status);
    return map.unite(Reading::getReadingData());
}

void Log1::setHex(const QString& hex)
{
    m_hex = hex;
}

void Log1::setOwn(const QString& own)
{
    bool ok = false;

    m_own = own.toInt(&ok, 16);

    if (!ok) {
        throw QString("Bad cast: ") + own;
    }
}

void Log1::setSensDesc(const QString& desc)
{
    m_sensDesc = desc;
}

void Log1::setSnum(const QString& snum)
{
    bool ok = false;

    m_own = snum.toInt(&ok, 16);

    if (!ok) {
        throw QString("Bad cast: ") + snum;
    }
}

void Log1::setTyp(const QString& typ)
{
    m_typ = typ;
}

void Log1::setStatus(const QString& status)
{
    m_status = status;
}

} //namespace Analyser
} //namespace TKOM_project
