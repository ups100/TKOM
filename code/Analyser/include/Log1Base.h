/**
 * @file Log1Base.h
 *
 * @date 23-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log1Base
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_4AEBE7D9_A1C9_4b53_8FEF_62C7D919CB69__INCLUDED_)
#define EA_4AEBE7D9_A1C9_4b53_8FEF_62C7D919CB69__INCLUDED_

#include "Log.h"
#include <QMap>
#include <QVariant>
#include <QString>

namespace TKOM_project {
namespace Analyser {

/**
 * @brief Base class for logs of type 1
 */
class Log1Base : public Log
{

public:
    /**
     * @brief Constructor
     */
    Log1Base();

    /**
     * @brief Destructor
     */
    virtual ~Log1Base();

    virtual QMap<QString, QVariant> getValues();

    /**
     * @brief Sets the Et value
     *
     * @param[in] et value to be set
     */
    void setEt(const QString& et);

    /**
     * @brief Sets the type value
     *
     * @param[in] type value to be set
     */
    void setType(const QString& type);

    /**
     * @brief Sets the xx value
     *
     * @param[in] xx value to be set
     */
    void setXx(const QString& xx);

private:
    /**
     * @brief Et value
     */
    int m_et;

    /**
     * @brief Type of log
     */
    QString m_type;

    /**
     * @brief XX log value
     */
    int m_xx;

};
} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_4AEBE7D9_A1C9_4b53_8FEF_62C7D919CB69__INCLUDED_)
