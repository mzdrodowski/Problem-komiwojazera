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
	static	GraphModel::Path* bestSpecimen;

private:
	std::vector<GraphModel::Path*> initializePopulation(int count);
	bool terminationConditionCheck();
	int init_pop_count;
	int generation_count;
	int current_population_num;
	ParentSelection* parentSelection;
	CrossoverOperator* crossoverOperator;
	MutationOperator* mutationOperator;
	std::vector<GraphModel::Path*> initialPopulation;
	std::vector<GraphModel::Path*> breedingPopulation;
	std::vector<GraphModel::Path*> offspringPopulation;
	std::vector<GraphModel::Path*> mutatedPopulation;

};

#endif /* EVOLUTIONARYALGORITHM_H_ */
