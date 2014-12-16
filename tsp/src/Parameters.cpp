/*
 * Parameters.cpp
 *
 *  Created on: 16 gru 2014
 *      Author: michal
 */

#include "Parameters.h"
#include <iostream>

using namespace std;


Parameters* Parameters::instance = NULL;

Parameters::Parameters() {

	verbose=0;
}

Parameters::~Parameters() {
	// TODO Auto-generated destructor stub
}

Parameters* Parameters::getInstance(){
	if(instance==NULL){
		instance = new Parameters;
	}
	return instance;
}
bool Parameters::isVerbose(){
	return verbose;
}
void Parameters::setVerbose(bool verbose){
	Parameters::verbose = verbose;
}


