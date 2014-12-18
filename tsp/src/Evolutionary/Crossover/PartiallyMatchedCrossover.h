/*
 * PartiallyMatchedCrossover.h
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#ifndef EVOLUTIONARY_CROSSOVER_PARTIALLYMATCHEDCROSSOVER_H_
#define EVOLUTIONARY_CROSSOVER_PARTIALLYMATCHEDCROSSOVER_H_

#include "CrossoverOperator.h"
#include "../../Model/Path.h"
#include "../../Model/Vertex.h"
#include <vector>



class PartiallyMatchedCrossover: public CrossoverOperator {
public:
	PartiallyMatchedCrossover();
	virtual ~PartiallyMatchedCrossover();
	GraphModel::Path* crossover(GraphModel::Path* Parent1, GraphModel::Path* Parent2);
private:
	int findPositionToPut(int id);
	int a;
	int b;
	std::vector<GraphModel::Vertex*>* parent1;
	std::vector<GraphModel::Vertex*>* parent2;
};

#endif /* EVOLUTIONARY_CROSSOVER_PARTIALLYMATCHEDCROSSOVER_H_ */
