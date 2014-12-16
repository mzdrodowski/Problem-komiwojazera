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
#include "Selection/ParentSelection.h"
#include "Selection/RouletteSelection.h"



class EvolutionaryAlgorithm: public Algorithm {
public:
	EvolutionaryAlgorithm();
	virtual ~EvolutionaryAlgorithm();
	int performAlgorithm();
	void setCrossoverOperator(CrossoverOperator * co);
	void setMutationOperator(MutationOperator* mo);
	void setInitialPopulationCount(int popCount);
	void setGenerationCount(int genCount);
private:
	std::list<GraphModel::Path*> initializePopulation(int count);
	bool terminationConditionCheck();
	int init_pop_count;
	int generation_count;
	int current_population_num;
	ParentSelection* parentSelection;
	CrossoverOperator* crossoverOperator;
	MutationOperator* mutationOperator;
	std::list<GraphModel::Path*> initialPopulation;
	std::list<GraphModel::Path*> breedingPopulation;
	std::list<GraphModel::Path*> offspringPopulation;
	std::list<GraphModel::Path*> mutatedPopulation;
};

#endif /* EVOLUTIONARYALGORITHM_H_ */
