/*
 * Vertex.h
 *
 *  Created on: 14 gru 2014
 *      Author: michal
 */

#ifndef MODEL_VERTEX_H_
#define MODEL_VERTEX_H_
/**
 * Klasa ta reprezentuje wierzchołek grafu czyli miasto. Zawiera
 * współrzędne i identyfikator miesta(wierzchołka).
 */
class Vertex {

public:
	Vertex();
	Vertex(int id, double x, double y);
	double getX();
	double getY();
	int getId();
	virtual ~Vertex();
private:
	double x_coord;
	double y_coord;
	int id;
};

#endif /* MODEL_VERTEX_H_ */
