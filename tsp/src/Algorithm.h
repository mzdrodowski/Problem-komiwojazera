/*
 * Algorithm.h
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

class Algorithm {
public:
	Algorithm();
	virtual ~Algorithm();
	int readDataFromFile(char* inputFile);
	int performAlgorithm();
	int writeResultsToFile(char* outputFile);

};

#endif /* ALGORITHM_H_ */
