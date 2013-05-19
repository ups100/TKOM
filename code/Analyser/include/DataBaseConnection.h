///////////////////////////////////////////////////////////
//  DataBaseConnection.h
//  Implementation of the Class DataBaseConnection
//  Created on:      19-maj-2013 18:10:39
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_196A09A8_4AFD_4e95_84A5_5488DF95BD35__INCLUDED_)
#define EA_196A09A8_4AFD_4e95_84A5_5488DF95BD35__INCLUDED_

namespace TKOM_project {
namespace Analyser {

class Header;
class Log;

class DataBaseConnection
{

public:
    DataBaseConnection();
    virtual ~DataBaseConnection();

    void addHeader(Header * header);
    void addLog(Log* log);
    void commit();
    void rollback();

};

} //namespace Analyser
} //namespace TKOM_project

#endif // !defined(EA_196A09A8_4AFD_4e95_84A5_5488DF95BD35__INCLUDED_)
