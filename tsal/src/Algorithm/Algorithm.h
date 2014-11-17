/*
 * Algorithm.h
 *
 *  Created on: 17-11-2014
 *      Author: michal
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_
#include <list>
namespace tsal {

class Algorithm {
public:
	Algorithm();
	virtual ~Algorithm();
	double** readInputData(char* input);
	std::list<int> initialPopulation;
};

} /* namespace tsal */
#endif /* ALGORITHM_H_ */
