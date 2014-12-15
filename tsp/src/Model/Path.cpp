/*
 * Path.cpp
 *
 *  Created on: 14 gru 2014
 *      Author: michal
 */

#include "Path.h"
#include "Graph.h"

using namespace std;

namespace GraphModel{

Path::Path(int path_size) {
	Path::lenght		=	0;
	Path::path_size 	=	path_size;
	Path::current_size	=	0;
}

Path::~Path() {
	// TODO Auto-generated destructor stub
}


void 	Path::addVertex(Vertex* vertex){
	current_size++;
	if(vertexList.size()>0){

		list<Vertex*>::iterator it = vertexList.end();
		it--;
		Vertex* v = *it;
		Edge* e =Graph::getInstance()->getEdge(vertex->getId(), v->getId());
		lenght+=(e->getLength());

		//jeżeli ostatni to trzeba zamknąć cykl
		if(path_size==current_size){
			it = Path::vertexList.begin();
			Vertex* v2 =*it;
			lenght+=(Graph::getInstance()->getEdge(vertex->getId() , v2->getId())->getLength());
		}
	}
	Path::vertexList.push_back(vertex);


}

double Path::getLenght(){
	return lenght;
}
/**
 * zwraca nty element nie liczony od 0 tylko od 1
 */
Vertex* Path::getVertex(int num){
	list<Vertex*>::iterator it = vertexList.begin();
	for (int i=0; i<num; i++){
		*it++;
	}
	return *it;
}

std::list<Vertex*> Path::getVertexList(){
	return vertexList;
}

int Path::getCurrentSize(){
	return current_size;
}


bool Path::vertexExitst(int id){
	bool exists = 0;
	list<Vertex*>::iterator it = vertexList.begin();
	for (it=vertexList.begin(); it!=vertexList.end(); it++){
		Vertex* v = (*it);
		if(v->getId()==id){
			exists = 1;
			break;
		}

	}
	return exists;
}


}//namespace GraphModel
