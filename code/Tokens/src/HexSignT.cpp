///////////////////////////////////////////////////////////
//  HexSignT.cpp
//  Implementation of the Class HexSignT
//  Created on:      19-maj-2013 18:12:31
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "HexSignT.h"

namespace TKOM_project {
namespace Tokens {

HexSignT::HexSignT(){

}



HexSignT::~HexSignT(){

}





/**
 * true jak pasuje do 1 chociaz
 */
bool HexSignT::checkNextChar(char character){

	return false;
}


QList<TokenTypes> HexSignT::getTokenTypes(){

	return  QList<TokenTypes>();
}

}//namespace Tokens
}//namespace TKOM_project
