/*
 * global.h
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <list>
#include <vector>

namespace MyTypes
{
	using namespace std;

	typedef list<int> Specimen;
	typedef std::list<Specimen> InitialPopulation;


	 struct Edge {
		int num;
		double value;
	};

	typedef std::vector<std::vector<Edge*> *> AdjacencyMatrix;

	struct Coordinate {
		int num;
		double x;
		double y;
	};

	typedef list<Specimen> Population;

}

#endif /* GLOBAL_H_ */
