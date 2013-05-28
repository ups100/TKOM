/**
 * @file SingleOptionToken.cpp
 *
 * @date 19-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Tokens::SingleOptionToken
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "SingleOptionToken.h"
#include "TokenTypes.h"
#include <QDebug>
namespace TKOM_project {
namespace Tokens {

SingleOptionToken::SingleOptionToken(const QList<TokenTypes>& types,
        const QString& pattern)
        :  m_incorrect(false), m_targetPattern(pattern)
{
    m_types = types;
}

SingleOptionToken::~SingleOptionToken()
{

}

bool SingleOptionToken::isValidNow()
{
    return m_targetPattern == m_currentPattern;
}

bool SingleOptionToken::checkNextChar(char character)
{
    if (m_incorrect)
        return false;
    //qDebug()<<character;
    //qDebug()<<m_targetPattern;
    //qDebug()<<m_targetPattern[m_currentPattern.length()];
    if (character == m_targetPattern[m_currentPattern.length()]) {
        m_currentPattern.append(character);
        return true;
    } else {
        m_currentPattern.clear();
        m_incorrect = true;
        return false;
    }
}

QList<Token*> SingleOptionToken::getAllSigleOptionTokens()
{
    QList<Token*> tokens;

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << TITLE_T,
                    QString(
                            "_ID_ SDR_Type_xx ET Own Typ S_Num   Sens_Description   Hex & Interp Reading")));

    tokens.append(
            new SingleOptionToken(QList<TokenTypes>() << NL_T,
                    QString("\n")));

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << IPMIUTIL_T,
                    QString("ipmiutil ver")));

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << DOT_T, QString(".")));

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << ISENSOR_T,
                    QString("isensor: version")));

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << OPENNING_T,
                    QString("Opening lan connection to node")));

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << DOT3_T, QString("...")));

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << CONNECTING_T,
                    QString("Connecting to node")));

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << BMC_T, QString("-- BMC version")));

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << POINT_T, QString(",")));

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << IPMIV_T, QString("IPMI version")));

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << SDR_T, QString("SDR")));

    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << EQ_T, QString("=")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << OEMC0_T, QString("OEM  c0")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << INTEL_T, QString("Intel:")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << FANCTL_T, QString("FanCtl")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << DEV_T, QString("dev:")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << SNUM_T, QString("snum")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << MINUS_T, QString("-")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << LKW_T, QString("[")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << RKW_T, QString("]")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << VERT_T, QString("|")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << IPMI_T, QString("IPMI")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << SENSORPOH_T,
                    QString("sensor: Power On Hours")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << HOURS_T, QString("hours")));
    tokens.append(
            new SingleOptionToken(
                    QList<TokenTypes>() << STRING_T
                            << TAILER_T,
                    QString("ipmiutil sensor, completed successfully")));

    return tokens;

}

} //namespace Tokens
} //namespace TKOM_project
