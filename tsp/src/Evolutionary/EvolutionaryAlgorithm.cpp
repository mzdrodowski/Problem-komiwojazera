/*
 * EvolutionaryAlgorithm.cpp
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#include "EvolutionaryAlgorithm.h"
#include "../Model/Path.h"
#include <list>

#include "../PathGenerator.h"

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
    	cout<< endl<<"Pokolenie nr " << current_population_num;
        //ocena i wybór osobników
    	breedingPopulation = parentSelection->selectParents(&initialPopulation);
        //Kojarzenie rodziców w pary i krzyżowanie par rodziców;

    	//wypisanie najlepszego osobnika w populacji
      	if(bestSpecimen!=NULL){

    	cout<< "\tDługość najlepszego osobnika: " <<
    			bestSpecimen->getLenght() << endl;
      	}

      	// w czasie tej operacji następuje alokacja pamięci dla nowych osobników
    	offspringPopulation = crossoverOperator->performMating(breedingPopulation);
        //mutacja  potomstwa;

    	mutationOperator->performMutation(&offspringPopulation);


    	/* zwalnianie pamięci dla ścierzek - osobników starej populacji*/

    	for (int i = 0; i<initialPopulation.size(); i++){
    		delete initialPopulation.at(i);
    	}
        /*mutacja powstała w wyniku krzyżowania i mutacji
    	// zastępuje oryginalną populację*/

    	initialPopulation = offspringPopulation;
    	current_population_num++;
    }

    // ocena populacji końcowej
	breedingPopulation = parentSelection->selectParents(&initialPopulation);

    //wypisanie najlepszego osobnike -- przed zwalnianiem pamięci !
		cout << "   Najlepszy osobnik:  "<< endl;;
		list<Vertex*> vl = bestSpecimen->getVertexList();
		list<Vertex*>::iterator it2;
		cout<< "  " << bestSpecimen->getId() << "  ";
		for (it2=vl.begin(); it2 != vl.end(); it2++){
			cout << (*it2)->getId() << " --> ";
		}


		for (int i = 0; i<initialPopulation.size(); i++){
    		delete initialPopulation.at(i);
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
		population.push_back(PathGenerator::getInstance()->generateRandomPath());
	}
	return population;
}

