/*
 * MutationOperator.h
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#ifndef EVOLUTIONARY_MUTATIONOPERATOR_H_
#define EVOLUTIONARY_MUTATIONOPERATOR_H_

#include "../../Model/Path.h"
#include <vector>


class MutationOperator {
public:
	MutationOperator();
	virtual ~MutationOperator();
	virtual void performMutation(std::vector<GraphModel::Path*>* population);
	virtual void mutate(GraphModel::Path* specimen) = 0;
private:
	double probability;
};

#endif /* EVOLUTIONARY_MUTATIONOPERATOR_H_ */
