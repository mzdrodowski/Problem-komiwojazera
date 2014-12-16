/*
 * MutationOperator.h
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#ifndef EVOLUTIONARY_MUTATIONOPERATOR_H_
#define EVOLUTIONARY_MUTATIONOPERATOR_H_

#include "../../Model/Path.h"


class MutationOperator {
public:
	MutationOperator();
	virtual ~MutationOperator();
	virtual std::list<GraphModel::Path*> performMutation(std::list<GraphModel::Path*> population);
	virtual void mutate(GraphModel::Path* specimen) = 0;
};

#endif /* EVOLUTIONARY_MUTATIONOPERATOR_H_ */
