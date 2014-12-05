/*
 * ScrambleMutation.h
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#ifndef EVOLUTIONARY_MUTATION_SCRAMBLEMUTATION_H_
#define EVOLUTIONARY_MUTATION_SCRAMBLEMUTATION_H_

#include "MutationOperator.h"

class ScrambleMutation: public MutationOperator {
public:
	ScrambleMutation();
	virtual ~ScrambleMutation();
	virtual void mutate(Specimen* s);
};

#endif /* EVOLUTIONARY_MUTATION_SCRAMBLEMUTATION_H_ */
