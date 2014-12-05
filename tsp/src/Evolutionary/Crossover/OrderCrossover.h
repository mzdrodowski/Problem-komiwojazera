/*
 * PartiallyMatchedCrossover.h
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#ifndef EVOLUTIONARY_CROSSOVER_ORDERCROSSOVER_H_
#define EVOLUTIONARY_CROSSOVER_ORDERCROSSOVER_H_

#include "CrossoverOperator.h"
#include "../../global.h"

using namespace MyTypes;

class OrderCrossover: public CrossoverOperator {
public:
	OrderCrossover();
	virtual ~OrderCrossover();
	virtual Specimen crossover(Specimen P1, Specimen P2);
};

#endif /* EVOLUTIONARY_CROSSOVER_ORDERCROSSOVER_H_ */
