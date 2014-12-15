/*
 * PartiallyMatchedCrossover.h
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#ifndef EVOLUTIONARY_CROSSOVER_PARTIALLYMATCHEDCROSSOVER_H_
#define EVOLUTIONARY_CROSSOVER_PARTIALLYMATCHEDCROSSOVER_H_

#include "CrossoverOperator.h"
#include "../../Model/Path.h"



class PartiallyMatchedCrossover: public CrossoverOperator {
public:
	PartiallyMatchedCrossover();
	virtual ~PartiallyMatchedCrossover();
	GraphModel::Path* crossover(GraphModel::Path* Parent1, GraphModel::Path* Parent2);
};

#endif /* EVOLUTIONARY_CROSSOVER_PARTIALLYMATCHEDCROSSOVER_H_ */
