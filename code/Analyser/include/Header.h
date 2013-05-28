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

/**
 * @brief Class created to aggregate data from file header.
 */
class Header
{

public:
    /**
     * @brief Constructor
     */
    Header();
    /**
     * @brief Destructor
     */
    virtual ~Header();

    /**
     * @brief Gets the map with field name and value.
     *
     * @return map of pairs
     */
    QMap<QString, QVariant> getValues();

    /**
     * @brief Sets the ipmi version
     *
     * @param[in] version to be set
     */
    void setIpmiVersion(const QString& version);

    /**
     * @brief Sets the ipmiutil version
     *
     * @param[in] version to be set
     */
    void setIpmiUtilVersion(const QString& version);

    /**
     * @brief Sets the isensor version
     *
     * @param[in] version to be set
     */
    void setIsensorVersion(const QString& version);

    /**
     * @brief Sets the ipmi version
     *
     * @param[in] version to be set
     */
    void setBmcVersion(const QString& version);

    /**
     * @brief Sets the node ip
     *
     * @param[in] nodeIP to be set
     */
    void setNodeIP(const QString& nodeIP);

    /**
     * @brief Sets the node name
     *
     * @param[in] nodeName to be set
     */
    void setNodeName(const QString& nodeName);

private:
    /**
     * @brief Version of ipmi
     */
    QString m_ipmiVersion;

    /**
     * @brief Version of ipmiutil
     */
    QString m_ipmiUtilVersion;

    /**
     * @brief Version of isensor
     */
    QString m_isensorVersion;

    /**
     * @brief Version of BMC
     */
    QString m_bmcVersion;

    /**
     * @brief Node Ip
     */
    QString m_nodeIP;

    /**
     * @brief Name of node
     */
    QString m_nodeName;

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_172C0622_69A9_4beb_B999_C42034E02C51__INCLUDED_)
