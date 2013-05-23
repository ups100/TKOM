/**
 * @file Parser.h
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

#if !defined(EA_0495BE45_8C08_4c44_A3EF_FDDB64038647__INCLUDED_)
#define EA_0495BE45_8C08_4c44_A3EF_FDDB64038647__INCLUDED_

#include "Lexer.h"
#include "DataBaseConnection.h"
#include "Header.h"
#include "Log.h"
#include <boost/shared_ptr.hpp>

namespace TKOM_project {
namespace Tokens {
class Token;
}
namespace Analyser {

class Parser
{

public:
    Parser(Lexer *lexer, DataBaseConnection *connection);
    virtual ~Parser();


    void parse();

private:
    void bmcVer();
    void connecting();
    QString digits();
    void et();
    void header();
    void hexAndReading();
    QString hexSigns();
    void id();
    void ipAddr();
    QString ipAddrNmb();
    void ipmiUtil();
    void isensor();
    void logs1();
    void log1();
    void log2();
    void log3();
    void logs4();
    void openning();
    void own();
    void powerOn();
    void read();
    void reading();
    void s_num(bool isLog4);
    QString sensDescription();
    void typ();
    void xx();

    Lexer *m_lexer;
    DataBaseConnection *m_connection;
    Header *m_header;
    Log *m_log;
    boost::shared_ptr<Tokens::Token> m_currentT;
};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_0495BE45_8C08_4c44_A3EF_FDDB64038647__INCLUDED_)
