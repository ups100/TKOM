/**
 * @file Log4WithReading.h
 *
 * @date 22-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Log4WithReading
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_074134B4_A17C_4b8c_9439_571A446638F9__INCLUDED_)
#define EA_074134B4_A17C_4b8c_9439_571A446638F9__INCLUDED_

#include "Log4Base.h"
#include "Reading.h"
#include <QMap>
#include <QVariant>
#include <QString>

namespace TKOM_project {
namespace Analyser {

/**
 * @brief Represents log type 4 with reading.
 */
class Log4WithReading : public Log4Base, public Reading
{

public:
    /**
     * @brief Constructor
     */
    Log4WithReading();

    /**
     * @brief Constructor
     *
     * @brief base log to extend
     *
     * @note This object takes the ownership of its parameter.
     */
    Log4WithReading(Log4Base *base);

    /**
     * @brief Destructor
     */
    virtual ~Log4WithReading();

    virtual QMap<QString, QVariant> getValues();

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_074134B4_A17C_4b8c_9439_571A446638F9__INCLUDED_)
