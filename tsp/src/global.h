/*
 * global.h
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <list>

namespace MyTypes
{
	using namespace std;

	typedef list<int> Specimen;
	typedef std::list<Specimen> InitialPopulation;
	typedef std::list<std::list<double> > AdjacencyMatrix;
	typedef list<Specimen> Population;

}

#endif /* GLOBAL_H_ */
