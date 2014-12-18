/*
 * PartiallyMatchedCrossover.cpp
 *
 *  Created on: 5 gru 2014
 *      Author: john
 */

#include "PartiallyMatchedCrossover.h"
#include "../../Model/Path.h"
#include <list>
#include <vector>
#include <iostream>
#include "../../PathGenerator.h"
#include <cstdlib>
#include "../../Parameters.h"

using namespace std;
using namespace GraphModel;

PartiallyMatchedCrossover::PartiallyMatchedCrossover() {
	// TODO Auto-generated constructor stub

}

PartiallyMatchedCrossover::~PartiallyMatchedCrossover() {
	// TODO Auto-generated destructor stub
}

Path* PartiallyMatchedCrossover::crossover(Path* Parent1, Path* Parent2){


	Path* descendant = PathGenerator::getInstance()->getNewPath();

	int pathSize =0;
	a = 0;
	b =0;

	vector<int> uncopiedInxs;



	pathSize = Parent1->getCurrentSize();


	list<Vertex*> l1 = Parent1->getVertexList();
	list<Vertex*> l2 = Parent2->getVertexList();
	vector<Vertex*> p1(l1.begin(), l1.end());
	vector<Vertex*> p2(l2.begin(), l2.end());
	parent1 = &p1;
	parent2 = &p2;

	vector<Vertex*> outcome(pathSize);

	//srand(time(NULL));

	b= rand()%pathSize;

	a= rand()%pathSize;

	if(a>b){
		int tmp;
		tmp =b;
		b=a;
		a=tmp;
	}

	vector<int>::iterator it;

	if(Parameters::getInstance()->isVerbose()){
		cout << "  Krzyżowanie PMX" << endl << endl;
		cout << "    Wylosowano punkty krzyżowania: " << a << " i " << b << endl <<endl;
	}

	/*  wybieranie elementów nieskopiowanych - należących do przedziału ab w p2 a nie należących do ab w p1*/
	for(int i=a; i<=b; i++){
		outcome[i] = p1[i];

		//cout << "kopiowanie wierzch: " << outcome[i]->getId() << " na poz " << i << " do potomka."<< endl;


		bool exists = 0;

		for(int j=a;j<=b;j++){
			//cout << "     porównanie " <<p2[i]->getId() << " z " << (p1[j])->getId() << endl;
			if(p2[i]->getId()==(p1[j]->getId())){
				exists = 1;
				break;
			}
		}


		if(!exists){
			uncopiedInxs.push_back(i);
			//cout << "dodano do listy nieskopiowanych" <<endl <<endl;
		}

	}

	// na liście uncopiedIndxs  znajdą się indexy wierzchłków które nie zostały skopiowane

	for(it=uncopiedInxs.begin(); it!=uncopiedInxs.end(); it++){
		//numery wierzchołków
		int ii=p2.at(*it)->getId(), jj=p1.at(*it)->getId();

		//cout << "  Wierzchołek z pozycji " << (*it) << " o nr " << ii <<endl;
		int pos = findPositionToPut(jj);


		outcome[pos]= p2.at(*it);
		//cout << "  Na pozycje potomka " << pos <<" wstawiamy "<< outcome[pos]->getId() <<endl;

	}

	/* PRZEPISANIE DANYCH DO NOWO UTOWRZONEJ ŚCIEŻKI */

	vector<Vertex*>::iterator it2;
	for(int i =0; i<pathSize; i++){
		Vertex* vp;
		if(outcome[i]==NULL){
			//cout << " NULL outcome[" << i << "]=" << outcome[i]<< endl;
			vp = parent2->at(i);
		}else{
			vp=outcome[i];
			//cout << " outcome[" << i << "]=" << outcome[i]<< endl;
			//cout << "Przepisywanie do descendant- iteracja nr " << i << endl;
		}
		descendant->addVertex(vp);
	}


	/* WYDRUKOWANIE NA EKRANIE NOWEGO POTOMKA */

	if(Parameters::getInstance()->isVerbose()){

		cout << "    Nowo utworzony potomek:  "<< endl;;
		list<Vertex*> vl = descendant->getVertexList();
		list<Vertex*>::iterator it;
		cout<< "  " << descendant->getId() << "  ";
		for (it=vl.begin(); it != vl.end(); it++){
			cout << (*it)->getId() << " --> ";
		}
		cout <<"1"<< "\t\tDługość: " << descendant->getLenght() <<endl;

	}


	return descendant;
}



int PartiallyMatchedCrossover::findPositionToPut(int id){
	int pos =0;
	// szukamy indexu rodzica o podanym id w rodzicu 2
	vector<Vertex*>::iterator it2;
	it2=parent2->begin();
	while(id!=((*it2)->getId())){
		it2++;
		pos++;
	}
	//cout <<"    Znaleziono pozycje = " << pos << endl;

	//sprawdzamy czy w przedziale ab
	if((pos>=a) && (pos<=b)){
		//szukamy dalej
		//cout<< "pozycja w przedziale ab = " << a <<"-" << b << endl;
		pos = findPositionToPut(parent1->at(pos)->getId());
	}


	return pos;
}
















