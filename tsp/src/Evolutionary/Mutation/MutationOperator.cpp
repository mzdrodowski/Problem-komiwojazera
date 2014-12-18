/*
 * MutationOperator.cpp
 *
 *  Created on: 25 lis 2014
 *      Author: michal
 */

#include "MutationOperator.h"
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace GraphModel;



MutationOperator::MutationOperator() {
	probability = 0.001;

}


MutationOperator::~MutationOperator() {
	// TODO Auto-generated destructor stub
}

void MutationOperator::performMutation(std::vector<GraphModel::Path*>* population){
	//mutacja może zajść z prawdopodobieństwem  0.001
	//cout << "Mutacja" << endl;
	srand(time(NULL));
	for(int i=0; i< population->size(); ++i){
		double d = (double)(rand()%RAND_MAX/(double)RAND_MAX);
		if(d<probability){
			cout << "Wystąpiła mutacja" << endl;
			mutate(population->at(i));
		}
	}

}
