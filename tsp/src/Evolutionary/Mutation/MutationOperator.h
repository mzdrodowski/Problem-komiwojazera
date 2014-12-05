/*
 * MutationOperator.h
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#ifndef EVOLUTIONARY_MUTATIONOPERATOR_H_
#define EVOLUTIONARY_MUTATIONOPERATOR_H_

#include "../../global.h"

using namespace MyTypes;

class MutationOperator {
public:
	MutationOperator();
	virtual ~MutationOperator();
	virtual void mutate(Specimen* s) = 0;
};

#endif /* EVOLUTIONARY_MUTATIONOPERATOR_H_ */
