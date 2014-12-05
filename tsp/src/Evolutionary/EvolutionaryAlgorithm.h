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
#include "../global.h"

using namespace MyTypes;


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
	int init_pop_cont = 0;
	int generation_num = 0;
	CrossoverOperator* crossoverOperator;
	MutationOperator* mutationOperator;
	InitialPopulation * initialPopulation;

};

#endif /* EVOLUTIONARYALGORITHM_H_ */
