/*
 * EvolutionaryAlgorithm.h
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#ifndef EVOLUTIONARYALGORITHM_H_
#define EVOLUTIONARYALGORITHM_H_

#include "../Algorithm.h"
#include "Crossover/CrossoverOperator.h"
#include "Mutation/MutationOperator.h"
#include <list>
#include "../Model/Graph.h"
#include "../Model/Path.h"



class EvolutionaryAlgorithm: public Algorithm {
public:
	EvolutionaryAlgorithm();
	virtual ~EvolutionaryAlgorithm();
	int performAlgorithm();
	void setCrossoverOperator(CrossoverOperator * co);
	void setMutationOperator(MutationOperator* mo);
	void setInitialPopCount(int popCount);
	void setGenerationNum(int genNum);
private:
	int init_pop_cont;
	int generation_num;
	CrossoverOperator* crossoverOperator;
	MutationOperator* mutationOperator;
	std::list<GraphModel::Path*> initialPopulation;

};

#endif /* EVOLUTIONARYALGORITHM_H_ */
