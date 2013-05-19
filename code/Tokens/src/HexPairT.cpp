///////////////////////////////////////////////////////////
//  HexPairT.cpp
//  Implementation of the Class HexPairT
//  Created on:      19-maj-2013 18:12:31
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "HexPairT.h"

namespace TKOM_project {
namespace Tokens {

HexPairT::HexPairT(){

}



HexPairT::~HexPairT(){

}





/**
 * true jak pasuje do 1 chociaz
 */
bool HexPairT::checkNextChar(char character){

	return false;
}


QList<TokenTypes> HexPairT::getTokenTypes(){

	return  QList<TokenTypes>();
}

}//namespace Tokens
}//namespace TKOM_project
