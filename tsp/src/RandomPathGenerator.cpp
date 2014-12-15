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

	vector<Vertex*> vvec = Graph::getInstance()->getVertexVector();
	vvec.erase(vvec.begin()); // usuwamy zerowy czyli pierwszy bo od niego będziemy zaczynać
	srand(time(0));
	int number = {0};
	int remain_elems = {0};
	for (int i=1; i<size; i++){
		//cout<< "Losowanie no." << i<< endl;

		remain_elems = vvec.size();
		//cout<< "Rozmiar vektora =" << remain_elems <<endl;

		number = rand()%remain_elems;
		//do{
			//number = rand()%size+1;
			//cout<< "\t-\twylosowano liczbę\t:\t" << number << endl;
		//}while((path->vertexExitst(number)));

		Vertex* v = vvec.at(number);
		//cout << "pod tym numerem znajduje się " << v->getId() << endl;
		path->addVertex(v);

		//cout << "coś" << endl;
		vector<Vertex*>::iterator it = vvec.begin();

		for (int j=0; j<number; j++){
		//	cout << "przes "<< endl;
			it++;
		}
		vvec.erase(it);

		//ut<< "Dodano wierzchołek nr: "<< number << endl;
		//cout<< "Całkowita dotychczasowa długość: " << path->getLenght()<< endl << endl;
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
		cout <<"1"<< endl << "Całkowita długość tej ścieżki:\t" << path->getLenght() <<endl;

	}

	return path;
}

void RandomPathGenerator::setVerbose(bool verbose){
	RandomPathGenerator::verbose=verbose;
}
