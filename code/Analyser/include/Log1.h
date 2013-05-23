/**
 * @file Log1.h
 *
 * @date 23-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log1
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_940C978A_7D43_44bc_B7FB_91EAD5D96A77__INCLUDED_)
#define EA_940C978A_7D43_44bc_B7FB_91EAD5D96A77__INCLUDED_

#include "Reading.h"
#include "Log1Base.h"
#include <QMap>
#include <QVariant>
#include <QString>

namespace TKOM_project {
namespace Analyser {

/**
 * @brief Represents Log type 1
 */
class Log1 : public Reading, public Log1Base
{

public:
    /**
     * @brief Constructor
     */
    Log1();

    /**
     * @brief Constructor
     *
     * @param[in] log collected earlier
     *
     * @note This object takes the ownership of passed parameter
     */
    Log1(Log1Base *log);

    /**
     * @brief Destructor
     */
    virtual ~Log1();

    virtual QMap<QString, QVariant> getValues();

    /**
     * @brief Sets the hex value of this log
     *
     * @param[in] hex to be set
     */
    void setHex(const QString& hex);

    /**
     * @brief Sets the own value of this log
     *
     * @param[in] own to be set
     */
    void setOwn(const QString& own);

    /**
     * @brief Sets the sensor description
     *
     * @param[in] desc to be set
     */
    void setSensDesc(const QString& desc);

    /**
     * @brief Sets the snum value of this log
     *
     * @param[in] snum to be set
     */
    void setSnum(const QString& snum);

    /**
     * @brief Sets the typ of this log
     *
     * @param[in] typ to be set
     */
    void setTyp(const QString& typ);

    /**
     * @brief Sets the status value of this log
     *
     * @param[in] status to be set
     */
    void setStatus(const QString& status);

private:
    /**
     * @brief Hex value
     */
    QString m_hex;

    /**
     * @brief own value
     */
    int m_own;

    /**
     * @brief Sensor description
     */
    QString m_sensDesc;

    /**
     * @brief Snum value
     */
    int m_snum;

    /**
     * @brief typ value
     */
    QString m_typ;

    /**
     * @brief Status value
     */
    QString m_status;

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_940C978A_7D43_44bc_B7FB_91EAD5D96A77__INCLUDED_)
