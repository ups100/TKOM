///////////////////////////////////////////////////////////
//  Parser.h
//  Implementation of the Class Parser
//  Created on:      19-maj-2013 18:10:41
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_0495BE45_8C08_4c44_A3EF_FDDB64038647__INCLUDED_)
#define EA_0495BE45_8C08_4c44_A3EF_FDDB64038647__INCLUDED_

#include "Lexer.h"
#include "DataBaseConnection.h"
#include "Header.h"
#include "Log.h"

class Parser
{

public:
	Parser();
	virtual ~Parser();
	Lexer *m_Lexer;
	DataBaseConnection *m_DataBaseConnection;
	Header *m_Header;
	Log *m_Log;

	void parse();

private:
	void bmcVer();
	void connecting();
	void et();
	void header();
	void hexAndReading();
	void hexSigns();
	void id();
	void ipAddr();
	void ipAddrNmb();
	void ipmiUtil();
	void isensor();
	void logs1();
	void logs4();
	void openning();
	void own();
	void powerOn();
	void read();
	void reading();
	void s_num();
	void sensDescription();
	void typ();

};
#endif // !defined(EA_0495BE45_8C08_4c44_A3EF_FDDB64038647__INCLUDED_)
