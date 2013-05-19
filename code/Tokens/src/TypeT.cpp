///////////////////////////////////////////////////////////
//  TypeT.cpp
//  Implementation of the Class TypeT
//  Created on:      19-maj-2013 18:12:33
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "TypeT.h"

namespace TKOM_project {
namespace Tokens {

TypeT::TypeT(){

}



TypeT::~TypeT(){

}





/**
 * true jak pasuje do 1 chociaz
 */
bool TypeT::checkNextChar(char character){

	return false;
}


QList<TokenTypes> TypeT::getTokenTypes(){

	return  QList<TokenTypes>();
}

}//namespace Tokens
}//namespace TKOM_project
