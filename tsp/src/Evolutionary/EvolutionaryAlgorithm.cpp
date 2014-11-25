/*
 * EvolutionaryAlgorithm.cpp
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#include "EvolutionaryAlgorithm.h"

EvolutionaryAlgorithm::EvolutionaryAlgorithm() {
	// TODO Auto-generated constructor stub

}

EvolutionaryAlgorithm::~EvolutionaryAlgorithm() {
	// TODO Auto-generated destructor stub
}

int EvolutionaryAlgorithm::performAlgorithm(){

    // inicjalizacja populacji za pomocą losowych rozwiązań;
   // a.initializePopulation();
    // ocena każdego kandydata
    //while(warunek końcowy){
        //wybór rodziców
        //rekombinacja par rodziców;
        //mutacja  potomstwa;
        //ocena nowych kandydatów;
        //wybór kandydatów do następnego pokolenia;

    //}
	return 0;
}
void EvolutionaryAlgorithm::setCrossoverOperator(CrossoverOperator co){
	this->crossoverOperator= &co;
}
void EvolutionaryAlgorithm::setMutationOperator(MutationOperator mo){
	this->mutationOperator= &mo;
}
