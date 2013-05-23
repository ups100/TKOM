/**
 * @file Log4Base.h
 *
 * @date 22-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log4Base
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_74FE7AFC_A5B5_4cb0_B7B5_F243DE26F020__INCLUDED_)
#define EA_74FE7AFC_A5B5_4cb0_B7B5_F243DE26F020__INCLUDED_

#include "Log.h"
#include <QMap>
#include <QVariant>
#include <QString>

namespace TKOM_project {
namespace Analyser {

/**
 * @brief Represents basic log type 4
 */
class Log4Base : public Log
{

public:
    /**
     * @brief Constructor
     */
    Log4Base();

    /**
     * @brief Destructor
     */
    virtual ~Log4Base();

    virtual QMap<QString, QVariant> getValues();

    /**
     * @brief Sets description of sensor
     */
    void setSensDesc(const QString& description);

    /**
     * @brief Sets the snum of sensor
     */
    void setSnum(const QString& snum);

    /**
     * @brief Sets sensor status
     */
    void setStatus(const QString& status);

private:
    /**
     * @brief Sensor description
     */
    QString m_sensDesc;

    /**
     * @brief Snum value
     */
    int m_snum;

    /**
     * @brief Sensor status
     */
    QString m_status;

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_74FE7AFC_A5B5_4cb0_B7B5_F243DE26F020__INCLUDED_)
