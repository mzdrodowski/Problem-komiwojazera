/*
 * Edge.h
 *
 *  Created on: 14 gru 2014
 *      Author: michal
 */

#ifndef MODEL_EDGE_H_
#define MODEL_EDGE_H_

#include "Vertex.h"

namespace GraphModel{

class Edge {
public:

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

} // namespace

#endif /* MODEL_EDGE_H_ */
