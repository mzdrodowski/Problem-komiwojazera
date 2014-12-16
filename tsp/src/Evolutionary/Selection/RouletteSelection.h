/*
 * RouletteSelection.h
 *
 *  Created on: 16 gru 2014
 *      Author: michal
 */

#ifndef EVOLUTIONARY_SELECTION_ROULETTESELECTION_H_
#define EVOLUTIONARY_SELECTION_ROULETTESELECTION_H_

#include "ParentSelection.h"
#include "../../Model/Path.h"
class RouletteSelection: public ParentSelection {
public:
	RouletteSelection();
	virtual ~RouletteSelection();
	virtual std::vector<GraphModel::Path*> selectParents(std::vector< GraphModel::Path* >* population);
};

#endif /* EVOLUTIONARY_SELECTION_ROULETTESELECTION_H_ */
