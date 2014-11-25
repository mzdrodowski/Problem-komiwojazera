/*
 * EvolutionaryAlgorithm.h
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#ifndef EVOLUTIONARYALGORITHM_H_
#define EVOLUTIONARYALGORITHM_H_

#include "../Algorithm.h"
#include "CrossoverOperator.h"
#include "MutationOperator.h"
#include <list>
#include <map>
typedef std::list<int> Specimen;
typedef std::list<Specimen> InitialPopulation;


class EvolutionaryAlgorithm: public Algorithm {
public:
	EvolutionaryAlgorithm();
	virtual ~EvolutionaryAlgorithm();
	int performAlgorithm();
	void setCrossoverOperator(CrossoverOperator co);
	void setMutationOperator(MutationOperator mo);
private:
	CrossoverOperator* crossoverOperator;
	MutationOperator* mutationOperator;
	InitialPopulation initialPopulation;
};

#endif /* EVOLUTIONARYALGORITHM_H_ */
