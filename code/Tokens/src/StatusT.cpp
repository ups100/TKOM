///////////////////////////////////////////////////////////
//  StatusT.cpp
//  Implementation of the Class StatusT
//  Created on:      19-maj-2013 18:12:32
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "StatusT.h"

namespace TKOM_project {
namespace Tokens {

StatusT::StatusT(){

}



StatusT::~StatusT(){

}





/**
 * true jak pasuje do 1 chociaz
 */
bool StatusT::checkNextChar(char character){

	return false;
}


QList<TokenTypes> StatusT::getTokenTypes(){

	return  QList<TokenTypes>();
}

}//namespace Tokens
}//namespace TKOM_project
