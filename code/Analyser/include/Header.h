/**
 * @file Header.h
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

    QMap<QString, QVariant> getValues();
    void setIpmiVersion(const QString& version);
    void setIpmiUtilVersion(const QString& version);
    void setIsensorVersion(const QString& version);
    void setBmcVersion(const QString& version);
    void setNodeIP(const QString& nodeIP);
    void setNodeName(const QString& nodeName);

private:
    QString m_ipmiVersion;
    QString m_ipmiUtilVersion;
    QString m_isensorVersion;
    QString m_bmcVersion;
    QString m_nodeIP;
    QString m_nodeName;

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_172C0622_69A9_4beb_B999_C42034E02C51__INCLUDED_)
