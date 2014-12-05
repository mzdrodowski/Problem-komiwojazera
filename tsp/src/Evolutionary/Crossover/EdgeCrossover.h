/*
 * EdgeCrossover.h
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#ifndef EVOLUTIONARY_CROSSOVER_EDGECROSSOVER_H_
#define EVOLUTIONARY_CROSSOVER_EDGECROSSOVER_H_

#include "CrossoverOperator.h"
#include "../../global.h"

using namespace MyTypes ;

class EdgeCrossover: public CrossoverOperator {
public:
	EdgeCrossover();
	virtual ~EdgeCrossover();
	virtual Specimen crossover(Specimen P1, Specimen P2);
};



#endif /* EVOLUTIONARY_CROSSOVER_EDGECROSSOVER_H_ */
