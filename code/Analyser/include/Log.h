/**
 * @file Log.h
 *
 * @date 23-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_D80A9CC5_BF46_4ad7_BE0C_7DF7D96C180E__INCLUDED_)
#define EA_D80A9CC5_BF46_4ad7_BE0C_7DF7D96C180E__INCLUDED_

#include <QMap>
#include <QString>
#include <QVariant>

namespace TKOM_project {
namespace Analyser {

/**
 * @brief Base Log class.
 */
class Log
{

public:
    /**
     * @brief Constructor
     */
    Log();

    /**
     * @brief Destructor
     */
    virtual ~Log();

    /**
     * @brief Gets the map with field name and value.
     *
     * @return map of pairs
     */
    virtual QMap<QString, QVariant> getValues();

    /**
     * @brief Sets the log ID.
     *
     * @param[in] id in hex.
     */
    void setID(const QString& id);

    /**
     * @brief Sets sensor type
     *
     * @param[in] type of sensor
     */
    void setSensorType(const QString& type);

private:

    /**
     * @brief Log ID
     */
    int m_id;

    /**
     * @brief Sensor type
     */
    QString m_sensorType;

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_D80A9CC5_BF46_4ad7_BE0C_7DF7D96C180E__INCLUDED_)
