/*
 * Algorithm.h
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_


#include "Model/Graph.h"


class Algorithm {
public:
	Algorithm();
	virtual ~Algorithm();

	virtual int performAlgorithm()=0;

	void setVerbose(bool verbose);
	void setGraph(GraphModel::Graph* graph);
private:
	GraphModel::Graph* graph;
	bool verbose;

};

#endif /* ALGORITHM_H_ */
