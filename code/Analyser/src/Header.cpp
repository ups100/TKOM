///////////////////////////////////////////////////////////
//  Header.cpp
//  Implementation of the Class Header
//  Created on:      19-maj-2013 18:10:40
//  Original author: kopasiak
///////////////////////////////////////////////////////////

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

    return QMap<QString, QVariant>();
}

void Header::setIpmiVersion(const QString& version)
{
    qDebug()<<"IPMI version:\t\t\t"<<version;
}

void Header::setIpmiUtilVersion(const QString& version)
{
    qDebug()<<"IPMI util version:\t\t\t"<<version;
}

void Header::setIsensorVersion(const QString& version)
{
    qDebug()<<"Isensor version:\t\t\t"<<version;
}

void Header::setBmcVersion(const QString& version)
{
    qDebug()<<"BMC version:\t\t\t"<<version;
}

void Header::setNodeIP(const QString& nodeIP)
{
    qDebug()<<"IP : \t\t\t"<<nodeIP;
}

void Header::setNodeName(const QString& nodeName)
{
    qDebug()<<"name\t\t\t"<<nodeName;
}

} //namespace Analyser
} //namespace TKOM_project
