///////////////////////////////////////////////////////////
//  Header.h
//  Implementation of the Class Header
//  Created on:      19-maj-2013 18:10:40
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_172C0622_69A9_4beb_B999_C42034E02C51__INCLUDED_)
#define EA_172C0622_69A9_4beb_B999_C42034E02C51__INCLUDED_

#include "Parser.h"
#include <QString>
#include <QMap>
#include <QVariant>
#include <QHostAddress>

namespace TKOM_project {
namespace Analyser {

class Parser;

class Header
{

public:
    Header();
    virtual ~Header();
    Parser *m_Parser;

    QMap<QString, QVariant> getValues();
    void setIpmiVersion(const QString& version);
    void setIpmiUtilVersion(const QString& version);
    void setIsensorVersion(const QString& version);
    void setBmcVersion(const QString& version);
    void setNodeIP(const QString& nodeIP);
    void setNodeName(const QString& nodeName);

private:
    QString m_ipmiVersion;
    QString m_isensorVersion;
    //QHostAddress m_nodeIP;
    QString m_nodeName;

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_172C0622_69A9_4beb_B999_C42034E02C51__INCLUDED_)
