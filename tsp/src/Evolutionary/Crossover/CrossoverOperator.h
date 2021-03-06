/*
 * CrossoverOperator.h
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#ifndef EVOLUTIONARY_CROSSOVEROPERATOR_H_
#define EVOLUTIONARY_CROSSOVEROPERATOR_H_
#include "../../Model/Path.h"
#include <vector>



class CrossoverOperator {

public:
	CrossoverOperator();
	virtual std::vector<GraphModel::Path* > performMating(std::vector<GraphModel::Path* > population);
	virtual ~CrossoverOperator();

	virtual GraphModel::Path* crossover(GraphModel::Path* Parent1, GraphModel::Path* Parent2) = 0;
};

#endif /* EVOLUTIONARY_CROSSOVEROPERATOR_H_ */
