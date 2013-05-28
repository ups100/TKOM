/**
 * @file Header.cpp
 *
 * @date 26-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Header
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */


#include "Header.h"
#include <QDebug>

namespace TKOM_project {
namespace Analyser {

Header::Header()
{

}

Header::~Header()
{

}

QMap<QString, QVariant> Header::getValues()
{
    QMap<QString, QVariant> map;
    map.insert("IPMI_Version", m_ipmiVersion);
    map.insert("IPMIUtil_Version", m_ipmiUtilVersion);
    map.insert("ISensor_Version", m_isensorVersion);
    map.insert("BMC_Version", m_bmcVersion);
    map.insert("NodeName", m_nodeName);
    map.insert("NodeIP", m_nodeIP);
    return map;
}

void Header::setIpmiVersion(const QString& version)
{
    m_ipmiVersion = version;
}

void Header::setIpmiUtilVersion(const QString& version)
{
    m_ipmiUtilVersion = version;
}

void Header::setIsensorVersion(const QString& version)
{
    m_isensorVersion = version;
}

void Header::setBmcVersion(const QString& version)
{
    m_bmcVersion = version;
}

void Header::setNodeIP(const QString& nodeIP)
{
    m_nodeIP = nodeIP;
}

void Header::setNodeName(const QString& nodeName)
{
    m_nodeName = nodeName;
}

} //namespace Analyser
} //namespace TKOM_project
