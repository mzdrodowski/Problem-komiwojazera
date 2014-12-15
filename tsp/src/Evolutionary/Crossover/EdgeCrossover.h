/*
 * EdgeCrossover.h
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#ifndef EVOLUTIONARY_CROSSOVER_EDGECROSSOVER_H_
#define EVOLUTIONARY_CROSSOVER_EDGECROSSOVER_H_

#include "CrossoverOperator.h"
#include "../../Model/Path.h"


class EdgeCrossover: public CrossoverOperator {
public:
	EdgeCrossover();
	virtual ~EdgeCrossover();

	virtual GraphModel::Path* crossover(GraphModel::Path* Parent1, GraphModel::Path* Parent2);
};



#endif /* EVOLUTIONARY_CROSSOVER_EDGECROSSOVER_H_ */
