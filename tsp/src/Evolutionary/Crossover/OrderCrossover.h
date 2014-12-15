/*
 * PartiallyMatchedCrossover.h
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#ifndef EVOLUTIONARY_CROSSOVER_ORDERCROSSOVER_H_
#define EVOLUTIONARY_CROSSOVER_ORDERCROSSOVER_H_

#include "CrossoverOperator.h"
#include "../../Model/Path.h"


class OrderCrossover: public CrossoverOperator {
public:
	OrderCrossover();
	virtual ~OrderCrossover();
	GraphModel::Path* crossover(GraphModel::Path* Parent1, GraphModel::Path* Parent2);
};

#endif /* EVOLUTIONARY_CROSSOVER_ORDERCROSSOVER_H_ */
