/*
 * Algorithm.h
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "global.h"

using namespace MyTypes;

class Algorithm {
public:
	Algorithm();
	virtual ~Algorithm();
	int readDataFromFile(char* inputFile);
	int performAlgorithm();
	int writeResultsToFile(char* outputFile);
	void setVerbose(bool verbose);
	void setAdjacencyMatrix(AdjacencyMatrix am);
private:
	AdjacencyMatrix adjacencyMatrix;
	bool verbose;

};

#endif /* ALGORITHM_H_ */
