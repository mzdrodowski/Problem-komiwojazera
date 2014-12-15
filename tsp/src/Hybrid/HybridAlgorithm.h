/*
 * HybridAlgorithm.h
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#ifndef HYBRID_HYBRIDALGORITHM_H_
#define HYBRID_HYBRIDALGORITHM_H_
#include "../Algorithm.h"

class HybridAlgorithm: public Algorithm {
public:
	HybridAlgorithm();
	virtual int performAlgorithm();
	virtual ~HybridAlgorithm();
};

#endif /* HYBRID_HYBRIDALGORITHM_H_ */
