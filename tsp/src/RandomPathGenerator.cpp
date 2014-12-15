/*
 * RandomPathGenerator.cpp
 *
 *  Created on: 15 gru 2014
 *      Author: michal
 */

#include "RandomPathGenerator.h"
#include "Model/Graph.h"
#include "Model/Path.h"
#include "ctime"
#include "cstdlib"
#include "iostream"

using namespace std;
using namespace GraphModel;

RandomPathGenerator* RandomPathGenerator::instance = NULL;


RandomPathGenerator::RandomPathGenerator() {

	verbose = 0;


}

RandomPathGenerator::~RandomPathGenerator() {
	// TODO Auto-generated destructor stub
}

RandomPathGenerator* RandomPathGenerator::getInstance(){
	if(instance==NULL){
		instance= new RandomPathGenerator;
	}
	return instance;
}

GraphModel::Path* RandomPathGenerator::generatePath(){

	Path* path = new Path(Graph::getInstance()->getVertexCount());

	int size = Graph::getInstance()->getVertexCount();
	path->addVertex(Graph::getInstance()->getVertex(1));
	cout << "size=" << size;
	srand(time(0));
	for (int i=1; i<size; i++){
		cout<< "losowanie no." << i<< endl;
		int number = 0;
		do{
			number = rand()%size+1;
			cout<< "\t-\twylosowano\t:\t" << number << endl;
		}while((path->vertexExitst(number)));

		Vertex* v = Graph::getInstance()->getVertex(number);
		path->addVertex(v);
		cout<< "dodano "<< number << endl;
		cout<< "długość dotychczasowa: " << path->getLenght()<< endl << endl;
	}
	if(verbose){
		cout << "*********************************************"<< endl
				<<"********** Wylosowano ścieżkę *********"<< endl
				<<"**********************************************"<< endl;
		list<Vertex*> vl = path->getVertexList();
		list<Vertex*>::iterator it;
		for (it=vl.begin(); it != vl.end(); it++){
			cout << (*it)->getId() << " --> ";
		}
		cout << endl << "Całkowita długość tej ścieżki:" << path->getLenght() <<endl;

	}

	return path;
}

void RandomPathGenerator::setVerbose(bool verbose){
	RandomPathGenerator::verbose=verbose;
}
