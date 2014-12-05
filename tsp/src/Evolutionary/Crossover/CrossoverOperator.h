/*
 * CrossoverOperator.h
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#ifndef EVOLUTIONARY_CROSSOVEROPERATOR_H_
#define EVOLUTIONARY_CROSSOVEROPERATOR_H_
#include "../../global.h"

using namespace MyTypes;

class CrossoverOperator {

public:
	CrossoverOperator();
	virtual ~CrossoverOperator();
	virtual Specimen crossover(Specimen P1, Specimen P2) = 0;
};

#endif /* EVOLUTIONARY_CROSSOVEROPERATOR_H_ */
