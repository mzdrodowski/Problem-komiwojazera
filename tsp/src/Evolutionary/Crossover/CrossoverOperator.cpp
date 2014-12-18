/*
 * CrossoverOperator.cpp
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#include "CrossoverOperator.h"
#include <vector>
#include <iostream>
#include "../../Parameters.h"
#include "../../Model/Path.h"

using namespace std;
using namespace GraphModel;

CrossoverOperator::CrossoverOperator() {
	// TODO Auto-generated constructor stub

}

CrossoverOperator::~CrossoverOperator() {
	// TODO Auto-generated destructor stub
}

/**
 * Ta metoda łączy w pary po dwa kolejne osobniki i tworzy populację końcową
 *
 */

std::vector<GraphModel::Path* > CrossoverOperator::performMating(std::vector<GraphModel::Path* > population){
	vector<Path* > outcome;
	int iter= 0;
	int j = 0;
	Path* tmp;
	iter = population.size();

	for(int i=0; i<iter; i=i+2){
		j=i+1;

		Path* specimen1 = population.at(i);
		Path* specimen2 = population.at(j);

		if(Parameters::getInstance()->isVerbose()){


			cout <<endl << endl << "Krzyżowanie osobników:  "<< endl;;
			list<Vertex*> vl = specimen1->getVertexList();
			list<Vertex*>::iterator it;
			cout<< "\t" << specimen1->getId() << "\t";
			for (it=vl.begin(); it != vl.end(); it++){
				cout  << (*it)->getId() << " --> ";
			}
			cout <<"1"<< "\t\tDługość: " << specimen1->getLenght() <<endl;
			vl = specimen2->getVertexList();

			cout<< "\t" << specimen2->getId() << " \t";
			for (it=vl.begin(); it != vl.end(); it++){
				cout << (*it)->getId() << " --> ";
			}
			cout <<"1"<< "\t\tDługość: " << specimen2->getLenght() <<endl;

		}


		tmp = crossover(specimen1, specimen2);

		outcome.push_back(tmp);


	}


	return outcome;
}
