/*
 * Path.h
 *
 *  Created on: 14 gru 2014
 *      Author: michal
 */

#ifndef MODEL_PATH_H_
#define MODEL_PATH_H_
#include <list>
#include "Edge.h"
#include "Vertex.h"

namespace GraphModel{
/**
 * Jest to klasa obudowująca listę kreawędzi
 */
class Path {
public:
	Path(int path_size, int id);
	virtual ~Path();

	void addVertex(Vertex* vertex);
	bool vertexExitst(int id);
	/**
	 * Zwraca całkowitą długość ścieżki
	 */
	double getLenght();
	int getCurrentSize();
	Vertex* getVertex(int num);
	std::list<Vertex*> getVertexList();
	int getId();

private:
	std::list<Vertex*> vertexList;
	double lenght;
	int path_size;
	int current_size;
	int id;

};

} //GraphModel namespace

#endif /* MODEL_PATH_H_ */
