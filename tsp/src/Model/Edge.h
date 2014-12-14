/*
 * Edge.h
 *
 *  Created on: 14 gru 2014
 *      Author: michal
 */

#ifndef MODEL_EDGE_H_
#define MODEL_EDGE_H_

#include "Vertex.h"

class Edge {
public:
	Edge();
	Edge(int id, Vertex* cityA, Vertex* cityB, double length);
	int getId();
	Vertex* getCityA();
	Vertex* getCityB();
	double getLength();
	virtual ~Edge();
private:
	int id;
	Vertex* cityA;
	Vertex* cityB;
	double length;
};

#endif /* MODEL_EDGE_H_ */
