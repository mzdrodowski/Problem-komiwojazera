/*
 * Algorithm.cpp
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#include "Algorithm.h"
#include <cstdlib>
#include <cstdio>

using namespace GraphModel;


Algorithm::Algorithm() {
	verbose = false;
	graph = NULL;

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

void Algorithm::setGraph(Graph* graph){
	Algorithm::graph = graph;
}
