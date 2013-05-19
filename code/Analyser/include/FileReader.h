///////////////////////////////////////////////////////////
//  FileReader.h
//  Implementation of the Class FileReader
//  Created on:      19-maj-2013 18:10:39
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_C5749D62_4930_4767_9B73_45CB2D0E0467__INCLUDED_)
#define EA_C5749D62_4930_4767_9B73_45CB2D0E0467__INCLUDED_

#include "Lexer.h"

class FileReader
{

public:
	FileReader();
	virtual ~FileReader();
	Lexer *m_Lexer;

	void adjustPosition(int offset);
	char getNextChar();

};
#endif // !defined(EA_C5749D62_4930_4767_9B73_45CB2D0E0467__INCLUDED_)
