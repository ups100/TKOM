///////////////////////////////////////////////////////////
//  TypeSignT.cpp
//  Implementation of the Class TypeSignT
//  Created on:      19-maj-2013 18:12:33
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "TypeSignT.h"

namespace TKOM_project {
namespace Tokens {

TypeSignT::TypeSignT(){

}



TypeSignT::~TypeSignT(){

}





/**
 * true jak pasuje do 1 chociaz
 */
bool TypeSignT::checkNextChar(char character){

	return false;
}


QList<TokenTypes> TypeSignT::getTokenTypes(){

	return  QList<TokenTypes>();
}

}//namespace Tokens
}//namespace TKOM_project
