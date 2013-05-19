///////////////////////////////////////////////////////////
//  Header.cpp
//  Implementation of the Class Header
//  Created on:      19-maj-2013 18:10:40
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#include "Header.h"

namespace TKOM_project {
namespace Analyser {

Header::Header(){

}



Header::~Header(){

}





QMap<QString, QVariant> Header::getValues(){

	return  QMap<QString, QVariant>();
}


void Header::setIpmiVersion(const QString& version){

}


void Header::setIsensorVersion(const QString& version){

}


void Header::setNodeIP(const QString& nodeIP){

}


void Header::setNodeName(const QString& nodeName){

}

}//namespace Analyser
}//namespace TKOM_project
