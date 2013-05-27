/**
 * @file Log3.h
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

#if !defined(EA_95756016_BCB8_42d0_ACCD_AECE2452B249__INCLUDED_)
#define EA_95756016_BCB8_42d0_ACCD_AECE2452B249__INCLUDED_

#include "Log1Base.h"
#include <QMap>
#include <QVariant>
#include <QString>

namespace TKOM_project {
namespace Analyser {

/**
 * @brief Represents log class 3
 */
class Log3 : public Log1Base
{

public:
    /**
     * @brief Constructor
     */
    Log3();

    /**
     * @brief Constructor
     */
    Log3(Log1Base *log);

    /**
     * @brief Destructor
     */
    virtual ~Log3();

    virtual QMap<QString, QVariant> getValues();

    /**
     * @brief Sets the hex values collected from log
     *
     * @param[in] hex to be set
     */
    void setHex(const QString& hex);

    /**
     * @brief Sets the sensor description
     *
     * @param[in] desc to be set
     */
    void setSensDesc(const QString& desc);

private:
    /**
     * @brief Hex value from log
     */
    QString m_hex;

    /**
     * @brief Sensor description
     */
    QString m_sensDesc;

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_95756016_BCB8_42d0_ACCD_AECE2452B249__INCLUDED_)
