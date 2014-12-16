/*
 * ParentSelection.h
 *
 *  Created on: 16 gru 2014
 *      Author: michal
 */

#ifndef EVOLUTIONARY_SELECTION_PARENTSELECTION_H_
#define EVOLUTIONARY_SELECTION_PARENTSELECTION_H_

#include "../../Model/Path.h"
#include <list>

class ParentSelection {
public:
	ParentSelection();
	virtual ~ParentSelection();
	virtual std::list<GraphModel::Path*> selectParents(std::list< GraphModel::Path* > population) = 0;
};

#endif /* EVOLUTIONARY_SELECTION_PARENTSELECTION_H_ */
