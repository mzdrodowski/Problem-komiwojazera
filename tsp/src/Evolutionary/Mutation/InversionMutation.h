/*
 * InversionMutation.h
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#ifndef EVOLUTIONARY_MUTATION_INVERSIONMUTATION_H_
#define EVOLUTIONARY_MUTATION_INVERSIONMUTATION_H_

#include "MutationOperator.h"
#include "../../global.h"

using namespace MyTypes;

class InversionMutation: public MutationOperator {
public:
	InversionMutation();
	virtual ~InversionMutation();
	virtual void mutate(Specimen* s);
};



#endif /* EVOLUTIONARY_MUTATION_INVERSIONMUTATION_H_ */
