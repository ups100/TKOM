/**
 * @file Parser.cpp
 *
 * @date 22-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::Parser
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "Parser.h"
#include "Token.h"
#include "TokenTypes.h"
#include "Log4Base.h"
#include "Log4WithReading.h"
#include "Log1Base.h"
#include "Log1.h"
#include "Reading.h"
#include "Log2.h"
#include "Log3.h"
#include "PowerOnLog.h"

#include <boost/lexical_cast.hpp>

using namespace TKOM_project::Tokens;

namespace TKOM_project {
namespace Analyser {

Parser::Parser(Lexer *lexer, DataBaseConnection *connection)
        : m_lexer(lexer), m_connection(connection)
{

}

Parser::~Parser()
{

}

void Parser::bmcVer()
{
    if (m_currentT->getTokenTypes().contains(BMC_T)) {
        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DIGIT_T)) {
            throw QString("Expected DIGIT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        QString version = m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DOT_T)) {
            throw QString("Expected DOT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        version += m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DIGIT2_T)) {
            throw QString("Expected DIGIT2_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        version += m_currentT->getCurrentPattern();
        m_header->setBmcVersion(version);
        version.clear();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(POINT_T)) {
            throw QString("Expected POINT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(IPMIV_T)) {
            throw QString("Expected IPMIV_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DIGIT_T)) {
            throw QString("Expected DIGIT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        version = m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DOT_T)) {
            throw QString("Expected DOT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        version += m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (!(m_currentT->getTokenTypes().contains(DIGIT2_T)
                || m_currentT->getTokenTypes().contains(DIGIT_T))) {
            throw QString("Expected DIGIT2_T or DIGIT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        version += m_currentT->getCurrentPattern();
        m_header->setIpmiVersion(version);
    } else {
        throw QString("Expected BMC_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::connecting()
{
    if (m_currentT->getTokenTypes().contains(CONNECTING_T)) {
        m_currentT = m_lexer->getNextToken();
        if (!(m_currentT->getTokenTypes().contains(DIGIT_T)
                || m_currentT->getTokenTypes().contains(DIGIT2_T))) {
            throw QString("Expected DIGIT_T or DIGIT2_T but got:3 ")
                    + m_currentT->getCurrentPattern();
        }

        ipAddr();

        if (!m_currentT->getTokenTypes().contains(NL_T)) {
            throw QString("Expected NL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }
    } else {
        throw QString("Expected CONNECTING_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

QString Parser::digits()
{
    if (m_currentT->getTokenTypes().contains(DIGIT_T)
            || m_currentT->getTokenTypes().contains(DIGIT2_T)) {

        QString value = m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (m_currentT->getTokenTypes().contains(DIGIT2_T)
                || m_currentT->getTokenTypes().contains(DIGIT_T)) {
            return value + digits();
        } else {
            return value;
        }
    } else {
        throw QString("Expected DIGIT_T or DIGIT2_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::et()
{
    if (m_currentT->getTokenTypes().contains(HEXPAIR_T)) {

        QString value = m_currentT->getCurrentPattern();

        static_cast<Log1Base*>(m_log)->setEt(value);
    } else {
        throw QString("Expected HEXPAIR_T or HEXSIGN_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::header()
{
    if (m_currentT->getTokenTypes().contains(IPMIUTIL_T)) {
        ipmiUtil();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(ISENSOR_T)) {
            throw QString("Expected ISENSOR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        isensor();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(OPENNING_T)) {
            throw QString("Expected OPENNING_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        openning();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(CONNECTING_T)) {
            throw QString("Expected CONNECTING_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        connecting();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(BMC_T)) {
            throw QString("Expected CONNECTING_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        bmcVer();

        m_currentT = m_lexer->getNextToken();
        if (!(m_currentT->getTokenTypes().contains(NL_T)
                || m_currentT->getTokenTypes().contains(TITLE_T))) {
            throw QString("Expected NL_T or TITLE_T but got: ")
                    + m_currentT->getCurrentPattern();
        }
    } else {
        throw QString("Expected IPMIUTIL_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::hexAndReading()
{
    if (m_currentT->getTokenTypes().contains(HEXPAIR_T)
            || m_currentT->getTokenTypes().contains(HEXSIGN_T)) {

        Log1 *log = static_cast<Log1*>(m_log);
        log->setHex(hexSigns());

        if (!m_currentT->getTokenTypes().contains(STATUS_T)) {
            throw QString("Expected STATUS_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        log->setStatus(m_currentT->getCurrentPattern());

        m_currentT = m_lexer->getNextToken();
        if (m_currentT->getTokenTypes().contains(MINUS_T)
                || m_currentT->getTokenTypes().contains(DIGIT_T)
                || m_currentT->getTokenTypes().contains(DIGIT2_T)) {
            reading();
        } else if (m_currentT->getTokenTypes().contains(NL_T)
                || m_currentT->getTokenTypes().contains(STATUS_T)
                || m_currentT->getTokenTypes().contains(STRING_T)) {
            return;
        } else {
            throw QString(
                    "Expected MINUS_T, DIGIT_T, DIGIT2_T, NL_T, STATUS_T or STRING_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

    } else {
        throw QString("Expected HEXPAIR_T or HEXSIGN_T but got:2 ")
                + m_currentT->getCurrentPattern();
    }
}

QString Parser::hexSigns()
{
    if (m_currentT->getTokenTypes().contains(HEXPAIR_T)
            || m_currentT->getTokenTypes().contains(HEXSIGN_T)) {

        QString signs = m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (m_currentT->getTokenTypes().contains(HEXPAIR_T)
                || m_currentT->getTokenTypes().contains(HEXSIGN_T)) {
            return signs + hexSigns();
        } else if (m_currentT->getTokenTypes().contains(NL_T)
                || m_currentT->getTokenTypes().contains(STATUS_T)
                || m_currentT->getTokenTypes().contains(STRING_T)) {
            return signs;
        } else {
            throw QString(
                    "Expected HEXPAIR_T, HEXSIGN_T, NL_T, STATUS_T OR STRING_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

    } else {
        throw QString("Expected HEXPAIR_T or HEXSIGN_T but got:2 ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::id()
{
    if (m_currentT->getTokenTypes().contains(HEXPAIR_T)) {

        QString id = m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            throw QString("Expected HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        id += m_currentT->getCurrentPattern();

        m_log->setID(id);
    } else {
        throw QString("Expected HEXPAIR_T but got:2 ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::ipAddr()
{
    if (m_currentT->getTokenTypes().contains(DIGIT_T)
            || m_currentT->getTokenTypes().contains(DIGIT2_T)) {

        QString ip = ipAddrNmb();

        if (!m_currentT->getTokenTypes().contains(DOT_T)) {
            throw QString("Expected DOT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }
        ip += m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        ip += ipAddrNmb();

        if (!m_currentT->getTokenTypes().contains(DOT_T)) {
            throw QString("Expected DOT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }
        ip += m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        ip += ipAddrNmb();

        if (!m_currentT->getTokenTypes().contains(DOT_T)) {
            throw QString("Expected DOT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }
        ip += m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        ip += ipAddrNmb();

        m_header->setNodeIP(ip);
    } else {
        throw QString("Expected DIGIT_T or DIGIT2_T but got:2 ")
                + m_currentT->getCurrentPattern();
    }
}

QString Parser::ipAddrNmb()
{
    if (m_currentT->getTokenTypes().contains(DIGIT_T)
            || m_currentT->getTokenTypes().contains(DIGIT2_T)) {

        QString nmbToCheck = m_currentT->getCurrentPattern();

        if (m_currentT->getTokenTypes().contains(DIGIT2_T)) {
            m_currentT = m_lexer->getNextToken();
            if (m_currentT->getTokenTypes().contains(DIGIT_T)) {
                nmbToCheck += m_currentT->getCurrentPattern();
                m_currentT = m_lexer->getNextToken();
            }
        } else {
            m_currentT = m_lexer->getNextToken();
        }

        int nmb = boost::lexical_cast<int>(nmbToCheck.toStdString());
        if (nmb > 255) {
            throw QString("Incorrect IP number: ") + nmbToCheck;
        }

        return nmbToCheck;
    } else {
        throw QString("Expected DIGIT_T or DIGIT2_T but got:1 ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::ipmiUtil()
{
    if (m_currentT->getTokenTypes().contains(IPMIUTIL_T)) {
        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DIGIT_T)) {
            throw QString("Expected DIGIT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        QString version = m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DOT_T)) {
            throw QString("Expected DOT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        version += m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DIGIT2_T)) {
            throw QString("Expected DIGIT2_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        version += m_currentT->getCurrentPattern();
        m_header->setIpmiUtilVersion(version);

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(NL_T)) {
            throw QString("Expected NL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }
    } else {
        throw QString("Expected IPMIUTIL_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::isensor()
{
    if (m_currentT->getTokenTypes().contains(ISENSOR_T)) {
        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DIGIT_T)) {
            throw QString("Expected DIGIT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        QString version = m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DOT_T)) {
            throw QString("Expected DOT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        version += m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DIGIT2_T)) {
            throw QString("Expected DIGIT2_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        version += m_currentT->getCurrentPattern();
        m_header->setIsensorVersion(version);

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(NL_T)) {
            throw QString("Expected NL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }
    } else {
        throw QString("Expected ISENSOR_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::log1()
{
    if (m_currentT->getTokenTypes().contains(TYPE_T)) {

        Log1 *log = static_cast<Log1*>(m_log);
        log->setType(m_currentT->getCurrentPattern());

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            throw QString("Expected HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        xx();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            throw QString("Expected HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        et();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            throw QString("Expected HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        own();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(TYPESIGN_T)) {
            throw QString("Expected TYPESIGN_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        typ();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(SNUM_T)) {
            throw QString("Expected SNUM_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        s_num(false);

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(STRING_T)) {
            throw QString("Expected STRING_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        log->setSensDesc(sensDescription());

        if (!(m_currentT->getTokenTypes().contains(HEXSIGN_T)
                || m_currentT->getTokenTypes().contains(HEXPAIR_T))) {
            throw QString("Expected HEXSIGN_T or HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        hexAndReading();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(NL_T)) {
            throw QString("Expected NL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

    } else {
        throw QString("Expected TYPE_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::log2()
{
    if (m_currentT->getTokenTypes().contains(OEMC0_T)) {

        Log2 *log = static_cast<Log2*>(m_log);
        log->setType(m_currentT->getCurrentPattern().left(3));
        log->setXx(m_currentT->getCurrentPattern().right(2));

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            throw QString("Expected HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        et();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(INTEL_T)) {
            throw QString("Expected INTEL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        QString description = m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (m_currentT->getTokenTypes().contains(FANCTL_T)) {
            description += QString(" ") + m_currentT->getCurrentPattern();
            m_currentT = m_lexer->getNextToken();
        }

        log->setIntelType(description);

        if (!(m_currentT->getTokenTypes().contains(HEXPAIR_T)
                || m_currentT->getTokenTypes().contains(HEXSIGN_T))) {
            hexSigns();
        } else {
            throw QString("Expected FANCTL_T, HEXSIGN_T or HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        if (!m_currentT->getTokenTypes().contains(NL_T)) {
            throw QString("Expected NL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

    } else {
        throw QString("Expected OEMC0_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::log3()
{
    if (m_currentT->getTokenTypes().contains(TYPE2_T)) {

        Log3 *log = static_cast<Log3*>(m_log);
        log->setType(m_currentT->getCurrentPattern());

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            throw QString("Expected HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        xx();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            throw QString("Expected HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        et();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DEV_T)) {
            throw QString("Expected INTEL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        if (!(m_currentT->getTokenTypes().contains(HEXPAIR_T)
                || m_currentT->getTokenTypes().contains(HEXSIGN_T))) {
            hexSigns();
        } else {
            throw QString("Expected FANCTL_T, HEXSIGN_T or HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        if (!m_currentT->getTokenTypes().contains(STRING_T)) {
            throw QString("Expected NL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        log->setSensDesc(sensDescription());

        if (!m_currentT->getTokenTypes().contains(NL_T)) {
            throw QString("Expected NL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

    } else {
        throw QString("Expected OEMC0_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::logs1()
{
    if (m_currentT->getTokenTypes().contains(HEXPAIR_T)) {

        id();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(SDR_T)) {
            throw QString("Expected SDR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (m_currentT->getTokenTypes().contains(TYPE_T)) {
            m_log = new Log1(static_cast<Log1Base*>(m_log));
            log1();
        } else if (m_currentT->getTokenTypes().contains(OEMC0_T)) {
            m_log = new Log2(static_cast<Log1Base*>(m_log));
            log2();
        } else if (m_currentT->getTokenTypes().contains(TYPE2_T)) {
            m_log = new Log3(static_cast<Log1Base*>(m_log));
            log3();
        } else {
            throw QString("Expected TYPE_T, OEMC0_T or TYPE2_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        if (!m_currentT->getTokenTypes().contains(NL_T)) {
            throw QString("Expected NL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (m_currentT->getTokenTypes().contains(TAILER_T)) {
            return;
        } else if (m_currentT->getTokenTypes().contains(SDR_T)) {
            m_connection->addLog(m_log);
            m_log = new PowerOnLog();
            powerOn();
            m_currentT = m_lexer->getNextToken();
            if (!m_currentT->getTokenTypes().contains(TAILER_T)) {
                throw QString("Expected TAILER_T but got: ")
                        + m_currentT->getCurrentPattern();
            }
            return;
        } else if (m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            m_connection->addLog(m_log);
            m_log = new Log1Base();
            logs1();
        } else {
            throw QString("Expected HEXPAIR_T, SDR_T or TAILER_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

    } else {
        throw QString("Expected HEXPAIR_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::logs4()
{
    if (m_currentT->getTokenTypes().contains(SENSORTYPE_T)) {
        Log4Base *log = static_cast<Log4Base*>(m_log);
        log->setSensorType(m_currentT->getCurrentPattern());

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(LKW_T)) {
            throw QString("Expected LKW_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            throw QString("Expected HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        id();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(RKW_T)) {
            throw QString("Expected RKW_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(VERT_T)) {
            throw QString("Expected VERT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(SNUM_T)) {
            throw QString("Expected SNUM_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        s_num(true);

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(VERT_T)) {
            throw QString("Expected VERT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(STRING_T)) {
            throw QString("Expected STRING_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        log->setSensDesc(sensDescription());

        if (!m_currentT->getTokenTypes().contains(VERT_T)) {
            throw QString("Expected VERT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(STATUS_T)) {
            throw QString("Expected STATUS_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        log->setStatus(m_currentT->getCurrentPattern());

        m_currentT = m_lexer->getNextToken();
        if (m_currentT->getTokenTypes().contains(VERT_T)) {
            m_currentT = m_lexer->getNextToken();

            if (!(m_currentT->getTokenTypes().contains(MINUS_T)
                    || m_currentT->getTokenTypes().contains(DIGIT_T)
                    || m_currentT->getTokenTypes().contains(DIGIT2_T))) {
                throw QString("Expected MINUS_T, DIGIT_T or DIGIT2_T but got: ")
                        + m_currentT->getCurrentPattern();
            }
            m_log = new Log4WithReading(static_cast<Log4Base*>(m_log));
            reading();

            m_currentT = m_lexer->getNextToken();
            if (!m_currentT->getTokenTypes().contains(NL_T)) {
                throw QString("Expected NL_T but got: ")
                        + m_currentT->getCurrentPattern();
            }

            m_currentT = m_lexer->getNextToken();

            if (m_currentT->getTokenTypes().contains(SENSORTYPE_T)) {
                m_connection->addLog(m_log);
                m_log = new Log4Base();
                logs4();
            } else if (m_currentT->getTokenTypes().contains(SDR_T)) {
                return;
            } else if (m_currentT->getTokenTypes().contains(TAILER_T)) {
                return;
            } else {
                throw QString(
                        "Expected SENSORTYPE_T, SDR_T or TAILER_T but got: ")
                        + m_currentT->getCurrentPattern();
            }
        } else if (m_currentT->getTokenTypes().contains(NL_T)) {
            m_currentT = m_lexer->getNextToken();

            if (m_currentT->getTokenTypes().contains(SENSORTYPE_T)) {
                logs4();
            } else if (m_currentT->getTokenTypes().contains(SDR_T)) {
                return;
            } else if (m_currentT->getTokenTypes().contains(TAILER_T)) {
                return;
            } else {
                throw QString(
                        "Expected SENSORTYPE_T, SDR_T or TAILER_T but got: ")
                        + m_currentT->getCurrentPattern();
            }
        } else {
            throw QString("Expected VERT_T or NL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }
    } else {
        throw QString("Expected IPMIUTIL_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::openning()
{
    if (m_currentT->getTokenTypes().contains(OPENNING_T)) {
        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(STRING_T)) {
            throw QString("Expected STRING_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_header->setNodeName(m_currentT->getCurrentPattern());

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(DOT3_T)) {
            throw QString("Expected DOT3_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(NL_T)) {
            throw QString("Expected NL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }
    } else {
        throw QString("Expected IPMIUTIL_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::own()
{
    if (m_currentT->getTokenTypes().contains(HEXPAIR_T)) {

        QString value = m_currentT->getCurrentPattern();

        static_cast<Log1*>(m_log)->setOwn(value);
    } else {
        throw QString("Expected HEXPAIR_T or HEXSIGN_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::parse()
{

    try {
        m_currentT = m_lexer->getNextToken();

        if (m_currentT->getTokenTypes().contains(IPMIUTIL_T)) {
            read();
        } else {
            throw QString("Expected IPMIUTIL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_connection->commit();
    } catch (QString &exc) {
        qDebug() << exc;
        m_connection->rollback();
    }
}

void Parser::powerOn()
{
    if (m_currentT->getTokenTypes().contains(SDR_T)) {
        m_currentT = m_lexer->getNextToken();

        if (m_currentT->getTokenTypes().contains(IPMI_T)) {
            throw QString("Expected IPMI_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (m_currentT->getTokenTypes().contains(SENSOR_T)) {
            throw QString("Expected SENSOR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (m_currentT->getTokenTypes().contains(STRING_T)) {
            throw QString("Expected STRING_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        PowerOnLog *log = static_cast<PowerOnLog*>(m_log);
        log->setSensDesc(sensDescription());

        if (m_currentT->getTokenTypes().contains(EQ_T)) {
            throw QString("Expected EQ_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (!(m_currentT->getTokenTypes().contains(DIGIT_T)
                || m_currentT->getTokenTypes().contains(DIGIT2_T))) {
            throw QString("Expected DIGIT_T or DIGIT2_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        log->setPowerOnHours(digits());

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(STRING_T)) {
            throw QString("Expected STRING_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(NL_T)) {
            throw QString("Expected NL_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

    } else {
        throw QString("Expected SDR_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::read()
{
    if (m_currentT->getTokenTypes().contains(IPMIUTIL_T)) {
        m_header = new Header();
        header();
        m_connection->addHeader(m_header);
        m_header = 0L;

        m_currentT = m_lexer->getNextToken();

        if (m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            m_log = new Log1Base();
            logs1();
        } else if (m_currentT->getTokenTypes().contains(SENSORTYPE_T)) {
            m_log = new Log4Base();
            logs4();
        } else {
            throw QString("Expected HEXPAIR_T or SENSORTYPE_T but got: ")
                    + m_currentT->getCurrentPattern();
        }
    } else {
        throw QString("Expected IPMIUTIL_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::reading()
{
    if (m_currentT->getTokenTypes().contains(MINUS_T)
            || m_currentT->getTokenTypes().contains(DIGIT_T)
            || m_currentT->getTokenTypes().contains(DIGIT2_T)) {

        QString value;

        if (m_currentT->getTokenTypes().contains(MINUS_T)) {
            m_currentT = m_lexer->getNextToken();

            value = m_currentT->getCurrentPattern();

            if (!(m_currentT->getTokenTypes().contains(DIGIT_T)
                    || m_currentT->getTokenTypes().contains(DIGIT2_T))) {
                throw QString("Expected DIGIT_T or DIGIT2_T but got: ")
                        + m_currentT->getCurrentPattern();
            }
            value += digits();
        } else {
            value = digits();
        }

        if (!m_currentT->getTokenTypes().contains(DOT_T)) {
            throw QString("Expected DOT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        value += m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();

        if (!m_currentT->getTokenTypes().contains(DIGIT2_T)) {
            throw QString("Expected DIGIT2_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        Reading *reading = dynamic_cast<Reading*>(m_log);
        reading->setValue(value);

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(UNIT_T)) {
            throw QString("Expected UNIT_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        reading->setUnit(m_currentT->getCurrentPattern());

    } else {
        throw QString("Expected MINUS_T, DIGIT_T, DIGIT2_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::s_num(bool isLog4)
{
    if (m_currentT->getTokenTypes().contains(SNUM_T)) {

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            throw QString("Expected HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

        if (isLog4) {
            static_cast<Log4Base*>(m_log)->setSnum(
                    m_currentT->getCurrentPattern());
        } else {
            static_cast<Log1*>(m_log)->setSnum(m_currentT->getCurrentPattern());
        }

    } else {
        throw QString("Expected SNUM_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

QString Parser::sensDescription()
{
    if (m_currentT->getTokenTypes().contains(STRING_T)) {
        QString description = m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (m_currentT->getTokenTypes().contains(EQ_T)) {
            return description;
        } else if (m_currentT->getTokenTypes().contains(NL_T)) {
            return description;
        } else if (m_currentT->getTokenTypes().contains(VERT_T)) {
            return description;
        } else if (m_currentT->getTokenTypes().contains(STRING_T)) {
            return description + QString(" ") + sensDescription();
        } else {
            throw QString("Expected EQ_T, NL_T, VERT_T or STRING_T but got: ")
                    + m_currentT->getCurrentPattern();
        }

    } else {
        throw QString("Expected STRING_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::typ()
{
    if (m_currentT->getTokenTypes().contains(TYPESIGN_T)) {

        QString typ = m_currentT->getCurrentPattern();

        m_currentT = m_lexer->getNextToken();
        if (!m_currentT->getTokenTypes().contains(HEXPAIR_T)) {
            throw QString("Expected HEXPAIR_T but got: ")
                    + m_currentT->getCurrentPattern();
        }
        static_cast<Log1*>(m_log)->setTyp(
                typ + m_currentT->getCurrentPattern());
    } else {
        throw QString("Expected HEXPAIR_T or HEXSIGN_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

void Parser::xx()
{
    if (m_currentT->getTokenTypes().contains(HEXPAIR_T)) {

        QString value = m_currentT->getCurrentPattern();

        static_cast<Log1Base*>(m_log)->setXx(value);
    } else {
        throw QString("Expected HEXPAIR_T or HEXSIGN_T but got: ")
                + m_currentT->getCurrentPattern();
    }
}

} //namespace Analyser
} //namespace TKOM_project
