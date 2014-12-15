/*
 * Vertex.cpp
 *
 *  Created on: 14 gru 2014
 *      Author: michal
 */

#include "Vertex.h"

namespace GraphModel{

Vertex::~Vertex() {
	// TODO Auto-generated destructor stub
}
/**
 * Creating new vertex
 */
Vertex::Vertex(int id, double x, double y)
{
	x_coord=x;
	y_coord=y;
	Vertex::id= id;
}

double Vertex::getX(){
	return x_coord;
}
double Vertex::getY(){
	return y_coord;
}
int Vertex::getId(){
	return id;
}

}// namespace GraphModel
