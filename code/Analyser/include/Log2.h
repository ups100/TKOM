/**
 * @file Log2.h
 *
 * @date 23-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log2
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_090852A5_DC61_4a61_B1E1_0F18BF81C4B3__INCLUDED_)
#define EA_090852A5_DC61_4a61_B1E1_0F18BF81C4B3__INCLUDED_

#include "Log1Base.h"
#include <QMap>
#include <QVariant>
#include <QString>

namespace TKOM_project {
namespace Analyser {

/**
 * @brief Represents logs of type 2
 */
class Log2 : public Log1Base
{

public:
    /**
     * @brief Constructor
     */
    Log2();

    /**
     * @brief Constructor
     *
     * @param[in] log with current data collected
     *
     * @note this object takes the ownership of passed argument
     */
    Log2(Log1Base *log);

    /**
     * @brief Destructor
     */
    virtual ~Log2();

    virtual QMap<QString, QVariant> getValues();

    /**
     * @brief Sets the hex values collected from log
     *
     * @para[in] hex to be set
     */
    void setHex(const QString& hex);

    /**
     * @brief Sets the type of intel sensor
     *
     * @param[in] type to be set
     */
    void setIntelType(const QString& type);

private:

    /**
     * @brief Hex values collected from log
     */
    QString m_hex;

    /**
     * @brief Type of intel sensor
     */
    QString m_intelType;

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_090852A5_DC61_4a61_B1E1_0F18BF81C4B3__INCLUDED_)
