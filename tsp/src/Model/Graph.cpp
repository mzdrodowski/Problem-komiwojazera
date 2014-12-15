/*
 * Graph.cpp
 *
 *  Created on: 14 gru 2014
 *      Author: michal
 */


#include "Graph.h"

using namespace std;

namespace GraphModel{


Graph::Graph() {
	vertexCount = 0;
	edgeCount = 0;

}

Graph::~Graph() {
	for (int i =0; i<vertexCount; i++){
		Vertex* vertex = vertexVector.at(i);
		delete vertex;
		delete adjacencyMatrix[i];
	}
	for (int i =0; i<edgeCount; i++){
		Edge* edge = edgeVector.at(i);
		delete edge;
	}

}

void Graph::addVertex(int id, double x, double y){
	/*DODANIE WIERZCHOŁKA DO LISTY*/
	vertexCount++;
	// identyfikatory przydzielane od 1
	// nowy wierzchołek miasto A, w porównaniu z każdym innym miastem
	// będzie miało największy identyfikator
	Vertex* cityA = new Vertex(id, x , y);
	vertexVector.push_back(cityA);

	/* DODANIE WSZYSTKICH MOŻLIWYCH KRAWĘDZI*/

	vector<Edge*>* row = new vector<Edge*>();
	adjacencyMatrix.push_back(row);
	for(int i=0; i<(vertexCount-1); i++){
		edgeCount++;
		Vertex* cityB = vertexVector.at(i);
		// obliczanie odległości
		double distance;
		distance = sqrt(pow(cityA->getX() - cityB->getX(), 2)+pow(cityA->getY()-cityB->getY(), 2));
		// tworzenie nowej krawędzi
		Edge* newEdge = new Edge(edgeCount, cityA, cityB, distance);
		row->push_back(newEdge);
		edgeVector.push_back(newEdge);
	}

}
Vertex* Graph::getVertex(int id){

	return vertexVector.at(id);
}
Edge* Graph::getEdge(int idVertexA, int idVertexB){
	if((idVertexA > vertexCount) || (idVertexB > vertexCount)){
		cout << "Graph: niepoprawne numery wierzchołków" << endl;
	}else if(idVertexA > idVertexB){

	}else if(idVertexA < idVertexB){
		int tmp;
		tmp = idVertexA ;
		idVertexA = idVertexB;
		idVertexB = tmp;
	}else{
		cout << "Graph: wierzchołek nie ma drogi do samego siebie" << endl;
	}
	return adjacencyMatrix[idVertexA]->at(idVertexB);
}

Edge* Graph::getEdge(int index){
	return edgeVector.at(index);
}

int Graph::getEdgeCount(){
	return edgeCount;
}
int Graph::getVertexCount(){
	return vertexCount;
}

} // GraphModel namespace
