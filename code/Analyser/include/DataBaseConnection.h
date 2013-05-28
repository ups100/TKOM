/**
 * @file DataBaseConnection.h
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
#if !defined(EA_196A09A8_4AFD_4e95_84A5_5488DF95BD35__INCLUDED_)
#define EA_196A09A8_4AFD_4e95_84A5_5488DF95BD35__INCLUDED_

#include <QString>
#include <QtSql/QtSql>

namespace TKOM_project {
namespace Analyser {

class Header;
class Log;

/**
 * @brief Instance of connection with database
 */
class DataBaseConnection
{

public:
    /**
     * @brief Constructor
     *
     * @param[in, out] dbPath path to database (SQLite3)
     */
    DataBaseConnection(const QString& dbPath);

    /**
     * @brief Destructor
     */
    virtual ~DataBaseConnection();

    /**
     * @brief Adds a header to database and starts the transaction
     *
     * @param[in] header to be added
     *
     * @note This object takes the ownership of it's parameter
     */
    void addHeader(Header * header);

    /**
     * @brief Adds log to database
     *
     * @param[in] log to be added
     */
    void addLog(Log* log);

    /**
     * @brief Commits the transaction
     */
    void commit();

    /**
     * @brief Rollbacks the transaction
     */
    void rollback();

private:
    /**
     * @brief target database
     */
    QSqlDatabase m_db;

    /**
     * @brief SQLite do not support foreign keys so we have to keep id of header.
     */
    qlonglong m_id;

};

} //namespace Analyser
} //namespace TKOM_project

#endif // !defined(EA_196A09A8_4AFD_4e95_84A5_5488DF95BD35__INCLUDED_)
