/*
 * EvolutionaryAlgorithm.cpp
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#include "EvolutionaryAlgorithm.h"
#include "../RandomPathGenerator.h"
#include "../Model/Path.h"
#include <list>

using namespace std;
using namespace GraphModel;


GraphModel::Path* EvolutionaryAlgorithm::bestSpecimen=NULL;


EvolutionaryAlgorithm::EvolutionaryAlgorithm(){
	crossoverOperator		= 	NULL;
	mutationOperator		= 	NULL;
	generation_count 		= 	0;
	init_pop_count 			= 	0;
	current_population_num	= 	0;
	parentSelection = new RouletteSelection();

}

EvolutionaryAlgorithm::~EvolutionaryAlgorithm() {

	delete crossoverOperator;
	delete mutationOperator;
	delete parentSelection;


}

/**
 * Główny mechaniz algorytmu ewolucyjnego
 */
int EvolutionaryAlgorithm::performAlgorithm(){


	list<Path*>::iterator it;
    // inicjalizacja populacji za pomocą losowych rozwiązań;
	cout << endl << "Generowanie populacji początkowej:" << endl << endl;
	initialPopulation = initializePopulation(init_pop_count);
    // ocena każdego kandydata

    while(!terminationConditionCheck()){
    	cout<< endl<< endl<<"Pokolenie nr " << current_population_num << endl;
        //wybór rodziców
    	breedingPopulation = parentSelection->selectParents(&initialPopulation);
        //Kojarzenie rodziców w pary i krzyżowanie par rodziców;

    	//wypisanie najlepszego osobnika w populacji
      	if(bestSpecimen==NULL){
    	cout<< "Najlepszy osobnik w populacji:"<<
        			bestSpecimen->getId() << endl << endl;
      	}
    	offspringPopulation = crossoverOperator->performMating(breedingPopulation);
        //mutacja  potomstwa;
    	mutatedPopulation = mutationOperator->performMutation(offspringPopulation);




    	/* zwalnianie pamięci dla ścierzek - osobników starej populacji*/
        while(initialPopulation.size()!=0){
        	delete initialPopulation.at(initialPopulation.size()-1);
        	initialPopulation.pop_back();
        }


        /*mutacja powstała w wyniku krzyżowania i mutacji
    	// zastępuje oryginalną populację*/

    	initialPopulation = mutatedPopulation;
    	current_population_num++;
    }


	return 0;
}

/*sprawdzenie warunku końcowego */
bool EvolutionaryAlgorithm::terminationConditionCheck(){
	bool termination = 0;
	if (current_population_num == generation_count){
		termination = 1;
	}
	return termination;
}


void EvolutionaryAlgorithm::setCrossoverOperator(CrossoverOperator * co){
	EvolutionaryAlgorithm::crossoverOperator = co;
}
void EvolutionaryAlgorithm::setMutationOperator(MutationOperator * mo){
	EvolutionaryAlgorithm::mutationOperator= mo;
}

void EvolutionaryAlgorithm::setInitialPopulationCount(int popCount){
	EvolutionaryAlgorithm::init_pop_count = popCount;
}
void EvolutionaryAlgorithm::setGenerationCount(int genCount){
	EvolutionaryAlgorithm::generation_count = genCount;

}
/**
 * Inicjalizacja populacji początkowej
 */
std::vector<GraphModel::Path*> EvolutionaryAlgorithm::initializePopulation(int count){

	vector<Path*> population;
	for(int i=0; i<count; i++){
		population.push_back(RandomPathGenerator::getInstance()->generatePath());
	}
	return population;
}

