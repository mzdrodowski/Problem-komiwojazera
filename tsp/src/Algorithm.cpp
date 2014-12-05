/*
 * Algorithm.cpp
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#include "Algorithm.h"
#include <cstdlib>
#include <cstdio>

Algorithm::Algorithm() {
	// TODO Auto-generated constructor stub

}

Algorithm::~Algorithm() {
	// TODO Auto-generated destructor stub
}



int Algorithm::performAlgorithm(){
	return 0;
}



void Algorithm::setVerbose(bool verbose){
	Algorithm::verbose = verbose;
}
void Algorithm::setAdjacencyMatrix(AdjacencyMatrix* am){

	this->adjacencyMatrix = am;
}
