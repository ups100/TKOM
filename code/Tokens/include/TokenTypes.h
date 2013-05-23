/**
 * @file TokenTypes.h
 *
 * @date 19-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::TokenTypes
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_33F6AE29_4A5B_49e6_9E92_495CFDF77CA9__INCLUDED_)
#define EA_33F6AE29_4A5B_49e6_9E92_495CFDF77CA9__INCLUDED_

namespace TKOM_project {
namespace Tokens {

enum TokenTypes
{
    TITLE_T,
    NL_T,
    IPMIUTIL_T,
    DOT_T,
    ISENSOR_T,
    OPENNING_T,
    DOT3_T,
    CONNECTING_T,
    BMC_T,
    POINT_T,
    IPMIV_T,
    SDR_T,
    EQ_T,
    OEMC0_T,
    INTEL_T,
    FANCTL_T,
    DEV_T,
    SNUM_T,
    MINUS_T,
    LKW_T,
    RKW_T,
    VERT_T,
    IPMI_T,
    SENSORPOH_T,
    HOURS_T,
    TAILER_T,
    DIGIT_T,
    DIGIT2_T,
    SENSOR_T,
    EOF_T,

    //multi values tokens
    TYPESIGN_T,
    UNIT_T,
    STATUS_T,
    HEXSIGN_T,
    HEXPAIR_T,
    TYPE2_T,
    TYPE_T,
    STRING_T,
    SENSORTYPE_T,
};

} //namespace Tokens
} //namespace TKOM_project
#endif // !defined(EA_33F6AE29_4A5B_49e6_9E92_495CFDF77CA9__INCLUDED_)
