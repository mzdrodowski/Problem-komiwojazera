/*
 * RouletteSelection.cpp
 *
 *  Created on: 16 gru 2014
 *      Author: michal
 */

#include "RouletteSelection.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <deque>
#include "../../Parameters.h"
#include "../../PathGenerator.h"
#include "../EvolutionaryAlgorithm.h"



using namespace std;
using namespace GraphModel;

RouletteSelection::RouletteSelection() {
	// TODO Auto-generated constructor stub

}

RouletteSelection::~RouletteSelection() {
	// TODO Auto-generated destructor stub
}

vector<Path*> RouletteSelection::selectParents(vector<Path* >* population){
	vector <Path*> outcome;
	// lista wartości przypisanych odcinków przystosowania
	deque <double> segmentDeque;
	deque <double> adjustmentDeque;

	/* Evaluacja osobników*/

	// policzenie sumy wszystkich wierzchołków

	double pos = 0;
	double sectionLength = 0;
	double adj = 0;
	double adjSum = 0;
	double bestAdjustment = 0;

	/* policzenie przystosowania dla każdego osobnika - czyli odwrotność całkowitej długości (im krótszy tym lepszy)*/
	if(Parameters::getInstance()->isVerbose()){
		cout<<endl<< "Ocena przystosowania osobników" << endl;
	}
	int popsize = population->size();
	for(int i=0; i<popsize; i++){

		Path* p = population->at(i);
		adj = 1/(p->getLenght());
		adjSum+=adj;
		adjustmentDeque.push_back(adj);

		if(adj>bestAdjustment){
			bestAdjustment=adj;
			EvolutionaryAlgorithm::bestSpecimen=p;
		}

		if(Parameters::getInstance()->isVerbose()){
			cout << " " << p->getId();
			cout << "  długość ścieżki: " << p->getLenght() ;
			cout << "  przystosowanie: " << adj << endl;
		}
	}

	if(Parameters::getInstance()->isVerbose()){
		cout<<endl<< "Podział procentowy odcinka wg przystosowania" << endl<<endl;
	}
	/*	policzenie punktów dzielących odcinek o długości 1*/
	while(adjustmentDeque.size()!=0){
		adj = adjustmentDeque.at(0);
		adjustmentDeque.pop_front();

		sectionLength = adj/adjSum; // długość odcinka przydzielonego dla itego osobnika
		pos += sectionLength; // punkt na odcinku przydzielony dla osobnika
		segmentDeque.push_back(pos);
		if(Parameters::getInstance()->isVerbose()){
			cout<< "  długość odcinka " << sectionLength ;
			cout<< "  pozycja "<< pos<< endl ;
		}

	}

	if(Parameters::getInstance()->isVerbose()){
		cout<<endl<< "Losowanie liczb z przedziału 0-1" << endl<<endl;
	}

	int breadSize = 0;
	breadSize = (population->size())*2;
	double d =0;


	srand(time(0));
	for ( int i=0; i<breadSize; i++){

		d=((double) (rand()%RAND_MAX)/(double)RAND_MAX);
		//d= gen(rng);
		int j = 0;
		while(true){
			double tmp = segmentDeque.at(j);
			if(d<tmp){
				if(Parameters::getInstance()->isVerbose()){
					cout << "  Wylosowano:  "<< d << " z przedziału: " << j <<endl;
				}
				outcome.push_back(population->at(j));
				break;
			}
			j++;
		}

	}

	/*	Test zsumowanie wszystkich elementów czy  */
	if(Parameters::getInstance()->isVerbose()){
		cout << endl<< "Do populacji krzyżowania wybrano osobniki:"<<endl;
		int s =outcome.size();
		for(int i=0; i<s;i++){
			Path* p = outcome.at(i);
			cout << "  " <<p->getId() << "  " <<p->getLenght() <<endl;
		}
	}



	return outcome;
}
