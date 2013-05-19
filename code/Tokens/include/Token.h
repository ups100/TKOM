///////////////////////////////////////////////////////////
//  Token.h
//  Implementation of the Class Token
//  Created on:      19-maj-2013 18:12:33
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_02E3FF6B_AFD2_4d43_BD90_710C8144E679__INCLUDED_)
#define EA_02E3FF6B_AFD2_4d43_BD90_710C8144E679__INCLUDED_

#include <QList>
#include <QString>
#include "TokenTypes.h"

namespace TKOM_project {
namespace Tokens {

class Token
{

public:
	Token();
	virtual ~Token();

	virtual bool checkNextChar(char character);
	virtual const QString& getCurrentPattern();
	virtual int getTokenLength() =0;
	virtual QList<TokenTypes> getTokenTypes() =0;

protected:
	QString m_currentPattern;

};

}//namespace Tokens
}//namespace TKOM_project
#endif // !defined(EA_02E3FF6B_AFD2_4d43_BD90_710C8144E679__INCLUDED_)
