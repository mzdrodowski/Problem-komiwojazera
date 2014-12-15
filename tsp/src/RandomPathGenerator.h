/*
 * RandomPathGenerator.h
 *
 *  Created on: 15 gru 2014
 *      Author: michal
 */

#ifndef RANDOMPATHGENERATOR_H_
#define RANDOMPATHGENERATOR_H_

#include <iostream>
#include "Model/Path.h"

class RandomPathGenerator {
public:
	static RandomPathGenerator* getInstance();
	virtual ~RandomPathGenerator();
	GraphModel::Path* generatePath();
	void setVerbose(bool verbose);
private:
	RandomPathGenerator();
	RandomPathGenerator(RandomPathGenerator const&);
	RandomPathGenerator& operator=(RandomPathGenerator const&);
	static RandomPathGenerator* instance;
	bool verbose;
};


#endif /* RANDOMPATHGENERATOR_H_ */
