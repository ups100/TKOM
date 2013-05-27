/**
 * @file PowerOnLog.h
 *
 * @date 22-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::PowerOnLog
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */
#ifndef __POWER_ON_LOH_H__
#define __POWER_ON_LOH_H__

#include "Log.h"

namespace TKOM_project {
namespace Analyser {

class PowerOnLog: public Log
{
public:
    /**
     * @brief Constructor
     */
    PowerOnLog();

    /**
     * @brief Description of log
     *
     * @param[in] description of log
     */
    void setSensDesc(const QString& description);

    /**
     * @brief Sets the power on hours
     *
     * @param[in] hours of power on
     */
    void setPowerOnHours(const QString& hours);

    virtual QMap<QString, QVariant> getValues();

private:
    /**
     * @brief Description of sensor
     */
    QString m_sensDesc;

    /**
     * @brief Power on time
     */
    int m_powerOn;
};

}
}
#endif
