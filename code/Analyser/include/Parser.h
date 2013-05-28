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

/**
 * @brief Main class of this project
 */
class Parser
{

public:
    /**
     * @brief Constructor
     *
     * @param[in] lexer source of tokens
     *
     * @param[in] connection to database
     *
     * @note This object takes the ownership of passed parameters
     */
    Parser(Lexer *lexer, DataBaseConnection *connection);

    /**
     * @brief Destructor
     */
    virtual ~Parser();

    /**
     * @brief Main function used to parse whole file and send it to database
     */
    void parse();

private:
    /**
     * @brief Parse the version of BMC
     */
    void bmcVer();
    /**
     * @brief Parse the connecting fragment of header
     */
    void connecting();
    /**
     * @brief Parse the sequence of digits
     *
     * @return sequence of digits
     */
    QString digits();
    /**
     * @brief Parse the Et log value
     */
    void et();
    /**
     * @brief Parse the file header
     */
    void header();

    /**
     * @brief Parse the Hex&Reading log part
     */
    void hexAndReading();
    /**
     * @brief Parse the string of hex signs
     *
     * @return hex signs
     */
    QString hexSigns();
    /**
     * @brief Parse the id log value
     */
    void id();
    /**
     * @brief Parse the IP address
     */
    void ipAddr();
    /**
     * @brief Parse the correct number form if
     *
     * @return number
     */
    QString ipAddrNmb();
    /**
     * @brief Parse the version of ipmi util
     */
    void ipmiUtil();
    /**
     * @brief Parse the version of isensor
     */
    void isensor();
    /**
     * @brief Parse logs from first group
     */
    void logs1();
    /**
     * @brief Parse log of type 1
     */
    void log1();
    /**
     * @brief Parse log of type 2
     */
    void log2();
    /**
     * @brief Parse log of type 3
     */
    void log3();
    /**
     * @brief Parse log of type 4
     */
    void logs4();
    /**
     * @brief Parse the opening header value
     */
    void openning();
    /**
     * @brief Parse the XX log value
     */
    void own();
    /**
     * @brief Parse power on log
     */
    void powerOn();
    /**
     * @brief Parse the whole file
     */
    void read();
    /**
     * @brief Parse sensor reading
     */
    void reading();
    /**
     * @brief Parse S_Num log value
     *
     * @param[in] isLog4 informs if currently parsed log is type4
     */
    void s_num(bool isLog4);
    /**
     * @brief Parse sensor description
     *
     * @return Sensor description
     */
    QString sensDescription();

    /**
     * @brief Parse host name
     *
     * @return Host name
     */
    QString hostName();
    /**
     * @brief Parse the typ log value
     */
    void typ();
    /**
     * @brief Parse the XX log value
     */
    void xx();

    /**
     * @brief Source of tokens
     */
    Lexer *m_lexer;

    /**
     * @brief Output database
     */
    DataBaseConnection *m_connection;
    /**
     * @brief File header
     */
    Header *m_header;
    /**
     * @brief current log
     */
    Log *m_log;
    /**
     * @brief Current token
     */
    boost::shared_ptr<Tokens::Token> m_currentT;
};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_0495BE45_8C08_4c44_A3EF_FDDB64038647__INCLUDED_)
