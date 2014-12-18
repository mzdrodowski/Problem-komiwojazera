/*
 * RandomPathGenerator.h
 *
 *  Created on: 15 gru 2014
 *      Author: michal
 */

#ifndef PATHGENERATOR_
#define PATHGENERATOR_

#include <iostream>
#include "Model/Path.h"

class PathGenerator {
public:
	static PathGenerator* getInstance();
	virtual ~PathGenerator();
	GraphModel::Path* generateRandomPath();
	GraphModel::Path* getNewPath();
	void setVerbose(bool verbose);
private:
	PathGenerator();
	PathGenerator(PathGenerator const&);
	PathGenerator& operator=(PathGenerator const&);
	static PathGenerator* instance;
	bool verbose;
	int pathCount;
};


#endif /* PATHGENERATOR_ */
