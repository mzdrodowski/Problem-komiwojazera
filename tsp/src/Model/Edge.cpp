/*
 * Edge.cpp
 *
 *  Created on: 14 gru 2014
 *      Author: michal
 */

#include "Edge.h"
namespace GraphModel{
Edge::~Edge() {
	// TODO Auto-generated destructor stub
}

Edge::Edge(int id, Vertex* cityA, Vertex* cityB, double length){
	Edge::id = id;
	Edge::cityA = cityA;
	Edge::cityB = cityB;
	Edge::length = length;
}

int Edge::getId(){
	return id;
}

Vertex* Edge::getCityA(){
	return cityA;
}

Vertex* Edge::getCityB(){
	return cityB;
}

double Edge::getLength(){
	return length;
}
}// namespace
