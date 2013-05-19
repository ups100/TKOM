///////////////////////////////////////////////////////////
//  HexPairT.h
//  Implementation of the Class HexPairT
//  Created on:      19-maj-2013 18:12:31
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_BF514AA3_8E7A_4657_9D84_3FB72FFC2EFE__INCLUDED_)
#define EA_BF514AA3_8E7A_4657_9D84_3FB72FFC2EFE__INCLUDED_

#include "Token.h"

namespace TKOM_project {
namespace Tokens {

class HexPairT : public Token
{

public:
	HexPairT();
	virtual ~HexPairT();

	virtual bool checkNextChar(char character);
	virtual QList<TokenTypes> getTokenTypes();

};

}//namespace Tokens
}//namespace TKOM_project
#endif // !defined(EA_BF514AA3_8E7A_4657_9D84_3FB72FFC2EFE__INCLUDED_)
