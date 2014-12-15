/*
 * Graph.h
 *
 *  Created on: 14 gru 2014
 *      Author: michal
 */

#ifndef MODEL_GRAPH_H_
#define MODEL_GRAPH_H_

#include "Vertex.h"
#include "Edge.h"
#include <list>
#include <vector>
#include <iostream>
#include <math.h>

namespace GraphModel{

class Graph {
public:
	static Graph* getInstance();
	int getEdgeCount();
	int getVertexCount();
	std::vector<Vertex*> getVertexVector();
	/**
	 * Dodaje wierzchołek do grafu wszystkie możliwe krawędzie są dodawane
	 * automatycznie
	 */
	void addVertex(int id, double x, double y);
	Vertex* getVertex(int id);
	Edge* getEdge(int city_A, int city_B);
	/**
	 * Zwraca wskaźnik do wierzchołka o zadanym id
	 */
	Edge* getEdge(int id);
	virtual ~Graph();

private:
	Graph();
	Graph(Graph const&);
	Graph& operator=(Graph const&);
	static Graph* instance;
	std::vector<Vertex*> vertexVector;
	std::vector<Edge*> edgeVector;
	std::vector< std::vector<Edge*>* > adjacencyMatrix;
	int vertexCount;
	int edgeCount;
};

} // end of namespace ProblemModel
#endif /* MODEL_GRAPH_H_ */
