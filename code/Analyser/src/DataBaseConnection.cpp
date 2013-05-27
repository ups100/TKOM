/**
 * @file DataBaseConnection.cpp
 *
 * @date 26-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::DataBaseConnection
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#include "DataBaseConnection.h"
#include "Header.h"
#include "Log.h"
#include <QtSql>
#include <iostream>

namespace TKOM_project {
namespace Analyser {

DataBaseConnection::DataBaseConnection(const QString& dbPath)
        : m_id(-1)
{
    qDebug() << dbPath;
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbPath);
    if (!m_db.open())
        throw QString("Unable to open database");
}

DataBaseConnection::~DataBaseConnection()
{
    m_db.close();
}

void DataBaseConnection::addHeader(Header * header)
{
    QMap<QString, QVariant> map = header->getValues();
    delete header;

    m_db.transaction();
    QString queryStr =
            "INSERT INTO read (IPMI_Version, IPMIUtil_Version, ISensor_Version, BMC_Version, NodeName, NodeIP) ";
    QString values =
            "VALUES (:IPMI_Version, :IPMIUtil_Version, :ISensor_Version, :BMC_Version, :NodeName, :NodeIP)";

    QSqlQuery query(queryStr.append(values), m_db);
    if (!query.prepare(queryStr)) {
        throw query.lastError().text();
    }
    query.bindValue(":IPMI_Version", map["IPMI_Version"]);
    query.bindValue(":IPMIUtil_Version", map["IPMIUtil_Version"]);
    query.bindValue(":ISensor_Version", map["ISensor_Version"]);
    query.bindValue(":BMC_Version", map["BMC_Version"]);
    query.bindValue(":NodeName", map["NodeName"]);
    query.bindValue(":NodeIP", map["NodeIP"]);
    if (query.exec()) {
        m_id = query.lastInsertId().toLongLong();
    } else {
        throw query.lastError().text();
    }
}

void DataBaseConnection::addLog(Log* log)
{
    QMap<QString, QVariant> map = log->getValues();

    QString queryStr = "INSERT INTO log (readID";
    QString values = "VALUES (:readID";

    foreach(QString key, map.keys()) {
        queryStr += QString(", ") + key;
        values += QString(", :") + key;
    }

    queryStr += ") ";
    values += ")";

    QSqlQuery query(queryStr.append(values), m_db);
    if (!query.prepare(queryStr)) {
        throw query.lastError().text();
    }
    query.bindValue(":readID", m_id);
    foreach(QString key, map.keys()) {
        query.bindValue(":" + key, map[key]);
    }
    if (!query.exec()) {
        throw query.lastError().text();
    }
}

void DataBaseConnection::commit()
{
    qDebug() << "COMMIT";
    m_db.commit();
}

void DataBaseConnection::rollback()
{
    m_db.rollback();
}

} //namespace Analyser
} //namespace TKOM_project
