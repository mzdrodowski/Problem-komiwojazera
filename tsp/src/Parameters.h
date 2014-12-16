/*
 * Parameters.h
 *
 *  Created on: 16 gru 2014
 *      Author: michal
 */

#ifndef PARAMETERS_H_
#define PARAMETERS_H_



/**
 * Klasa typu singleton która przechowuje parametry programu
 */
class Parameters {
public:
	static Parameters* getInstance();
	bool isVerbose();
	void setVerbose(bool verbose);
	virtual ~Parameters();
private:
	Parameters();
	Parameters(Parameters const&); // prywatny konstruktor kopiowania
	Parameters& operator=(Parameters const&); //operator przypisania jest prywatny
	static Parameters* instance;
	bool verbose;
};



#endif /* PARAMETERS_H_ */
