/**
 * @file Log4WithReading.cpp
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

#include "Log4WithReading.h"

namespace TKOM_project {
namespace Analyser {

Log4WithReading::Log4WithReading()
{

}

Log4WithReading::Log4WithReading(Log4Base *base)
:Log4Base(*base)
{
    delete base;
}


Log4WithReading::~Log4WithReading()
{

}

QMap<QString, QVariant> Log4WithReading::getValues()
{
    return Log4Base::getValues().unite(Reading::getReadingData());
}

} //namespace Analyser
} //namespace TKOM_project
