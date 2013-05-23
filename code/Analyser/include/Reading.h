/**
 * @file Reading.h
 *
 * @date 23-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Reading
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_FBA7C0B1_879C_46ef_A585_5ADEA78C21EB__INCLUDED_)
#define EA_FBA7C0B1_879C_46ef_A585_5ADEA78C21EB__INCLUDED_

#include <QMap>
#include <QVariant>
#include <QString>

namespace TKOM_project {
namespace Analyser {

/**
 * @brief Represents reading from sensor
 */
class Reading
{

public:
    /**
     * @brief Constructor
     */
    Reading();

    /**
     * @brief Destructor
     */
    virtual ~Reading();

    /**
     * @brief Gets the map with unit and value from reading
     *
     * @return map with key-value pairs
     */
    QMap<QString, QVariant> getReadingData();

    /**
     * @brief Sets the unit of reading
     */
    void setUnit(const QString& unit);

    /**
     * @brief Sets the value from reading.
     */
    void setValue(const QString& value);

private:
    /**
     * @brief Unit of reading
     */
    QString m_unit;

    /**
     * @brief Read value.
     */
    float m_value;

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_FBA7C0B1_879C_46ef_A585_5ADEA78C21EB__INCLUDED_)
