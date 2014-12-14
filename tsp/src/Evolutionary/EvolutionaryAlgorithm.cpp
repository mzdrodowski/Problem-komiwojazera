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

	delete crossoverOperator;
	delete mutationOperator;


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
void EvolutionaryAlgorithm::setCrossoverOperator(CrossoverOperator * co){
	EvolutionaryAlgorithm::crossoverOperator = co;
}
void EvolutionaryAlgorithm::setMutationOperator(MutationOperator * mo){
	EvolutionaryAlgorithm::mutationOperator= mo;
}
void EvolutionaryAlgorithm::setInitialPopCount(int popCount){
	EvolutionaryAlgorithm::init_pop_cont=popCount;
}

void EvolutionaryAlgorithm::setGenerationNum(int genNum){
	EvolutionaryAlgorithm::generation_num=genNum;
}

