/*
Ten plik będzie zawierał sam kod związany z samą obsługą użytkownika - pobranie informacji, wczytanie danych
wejściowych itp.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <fstream>
#include <vector>
#include <limits>
#include <math.h>

#include "Algorithm.h"
#include "Heuristic/HeuristicAlgorithm.h"
#include "Evolutionary/EvolutionaryAlgorithm.h"
#include "Hybrid/HybridAlgorithm.h"
#include "Evolutionary/Crossover/PartiallyMatchedCrossover.h"
#include "Evolutionary/Crossover/CrossoverOperator.h"
#include "Evolutionary/Crossover/EdgeCrossover.h"
#include "Evolutionary/Crossover/OrderCrossover.h"
#include "Evolutionary/Mutation/InversionMutation.h"
#include "Evolutionary/Mutation/MutationOperator.h"
#include "Evolutionary/Mutation/ScrambleMutation.h"
#include "Model/Edge.h"
#include "Model/Graph.h"
#include "Model/Vertex.h"
#include "RandomPathGenerator.h"



using namespace std;
using namespace GraphModel;



bool verbose			=	0;
string in_file_loc		=	"";
string out_file_loc		=	"output";
int init_pop_num 		=	{10}; 	// rozmiar populacji początkowej
string crossover_oper 	=	"PMX"; 	//operator krzyżowania
string mutation_oper 	=	"inversion"; //operator mutacji
char algorythm_type 	=	{'e'};
int generation_number 	=	{100};

// zmienne przechwujące dane pliku wejściowego *.tsp
int dimension 			= 	{0};
string name				=	"";
string node_coord_type	=	"";
string comment			=	"";



/**
 * Funkcja ta ma wczytać dane z pliku wejściowego. Na podstawie koordynatów zawartych w pliku wejściowym
 * zostanie utworzona macierz sąsiedztwa - AdjacencyMatrix
 */
void readDataFromFile(const char * file_path){

	std::ifstream ifs;
	ifs.open(file_path);
	if (!ifs.is_open()){
		cout << "Nie udało się otworzyć pliku!" << endl;
		cout << "Zakończenie działania programu..." << endl;
		exit(1);
	}


	/* WCZYTANIE METADANYCH Z PLIKU WEJŚCIOWEGO (na podst. dokumentacji tslib)*/


	string s		= 	"";
	string s_tmp 	=	"";
	ifs >> s;


	while((s.compare("NODE_COORD_SECTION")!=0)&&(!ifs.eof())){
		if(s.compare("NAME")==0){
			ifs >> s_tmp; // wczytywanie dwukropka
			ifs >> name;
		}else if(s.compare("COMMENT")==0){
			ifs >> s_tmp;
			char c;

			while((c = ifs.get())!='\n'){
				comment+=c;
			}
			comment+='\n';


		}else if(s.compare("DIMENSION")==0){
			ifs >> s_tmp;
			ifs >> dimension;
		}else if(s.compare("CAPACITY")==0){
			ifs >> s_tmp;
			ifs >> s_tmp;
		}else if(s.compare("EDGE_WEIGHT_TYPE")==0){
			ifs >> s_tmp;
			ifs >> s_tmp;
		}else if(s.compare("EDGE_WEIGHT_FORMAT")==0){
			ifs >> s_tmp;
			ifs >> s_tmp;
		}else if(s.compare("EDGE_DATA_FORMAT")==0){
			ifs >> s_tmp;
			ifs >> s_tmp;
		}else if(s.compare("NODE_COORD_TYPE")==0){
			ifs >> s_tmp;
			ifs >> node_coord_type;
		}else if(s.compare("DISPLAY_DATA_TYPE")==0){
			ifs >> s_tmp;
			ifs >> s_tmp;
		}else{
			ifs >> s_tmp;
			ifs >> s_tmp;
		}

		ifs >> s;

	}
	ifs.clear();


	// WCZYTYWANIE KOORDYNATÓW DO LISTY

	int a = {0};
	ifs >> s;
	double b, c;
	while((s.compare("EOF")!=0)&&(!ifs.eof())){

		a = atoi(s.c_str());

		ifs >> s;
		b = atof(s.c_str());

		ifs >> s;
		c = atof(s.c_str());

		ifs >> s;

		// dodanie wierzchołka do grafu
		Graph::getInstance()->addVertex(a,b,c);

		if(verbose){
			cout << "Vertex no.\t"<< a << ":\t";
			cout.precision(std::numeric_limits<double>::digits10);
			cout << "x = " << b << ";\t";
			cout << "y = " << c << endl;
		}

	} // koniec wczytywania

	ifs.close();


	// wypisanie zawartości macierzy sąsiedztwa

	if(verbose){
		cout << endl << "\t ********** ZAWARTOŚĆ MACIERZY SĄSIEDZTWA ***********" << endl;

		int size = Graph::getInstance()->getVertexCount();
		Edge* edge;
		for(int i=1; i<=size; i++ ){
			for(int j=1; j<=size; j++){
				if(i==j){
					cout << "BRAK\t";
				}else{
					edge = Graph::getInstance()->getEdge(i,j);
					cout << edge->getId() << "\t";
				}
			}
			cout << endl;
		}
		cout << endl << "\t ********** ZAWARTOŚĆ LISTY KRAWĘDZI ***********" << endl;
		cout <<	"--------------------------------------------"<< endl;
		cout << "id | City_A | City_B | distance" << endl;
		cout <<	"--------------------------------------------"<< endl;
		for(int i=1; i<=(Graph::getInstance()->getEdgeCount()); i++ ){
			Edge* e = Graph::getInstance()->getEdge(i);
			cout << e->getId() << "\t";
			cout << e->getCityA()->getId() << "\t";
			cout << e->getCityB()->getId() << "\t";
			cout << e->getLength() << endl;

		}
	}

} // End of read data from file


void printUsage(){

	printf("\nUżycie:\n");
	printf(" tsp [opcje] <plik wejściowy .tsp>\n");
	printf("\nOpcje:\n");
	printf(" -t [=<typ>]\t\t\t typ algorytmu 'e' (ewolucyjny), 'h'(heurystyczny) lub 'y' (hybrydowy)\n" );
	printf(" -o <plik wynikowy> \t\t nazwa pliku wynikowego \n");
	printf(" -v \t\t\t\t wypisanie przebiegu działania programu\n");
	printf("\n");
	printf(" -l <number> \t\t\t liczba osobników w populacji początkowej\n");
	printf(" -p <number>\t\t\t liczba pokoleń (generacji) domyślnie 100\n");
	printf(" -r [=<oper_krzyżowania>]\t operator krzyżowania(rekombinacji): 'PMX', 'OX' lub 'EX'\n");
	printf(" -m [=<oper_mutacji>]\t\t operator mutacji: 'inversion', 'scramble'\n");

	printf("\n");

}



int main(int argc, char ** argv){


	/* przetwarzanie argumentów */
	if(argc<2){
        printf("\nNiepoprawna liczba argumentów!\n");
		printUsage();
		exit(1);
    }else{
        int i;
        for(i=0; i<argc; i++){
            if(argv[i][0]=='-'){ //wczytywanie opcji
                char c = argv[i][1];
                switch(c){
                    case 'v'    :
                        verbose = true;
                    break;
                    case 'o'    :
                        if(argc>=(i+2)){
                            out_file_loc = argv[i+1];
                            i++;
                        }
                        else{
                            printf("Brak nazwy pliku wyjściowego!\n");
                            printUsage();
                            exit(1);
                        }
                    break;
                    case 'l'    :           //liczba populacji początkowej
                        if(argc>=(i+2)){
                            init_pop_num = atoi(argv[i+1]);
                            i++;
                        }else{
                            printf("Za mało argumentów!\n");
                            printUsage();
                            exit(1);
                        }
                    break;
                    case 'p'    :           //liczba generacji
                        if(argc>=(i+2)){
                            generation_number = atoi(argv[i+1]);
                            i++;
                        }else{
                            printf("Za mało argumentów!\n");
                            printUsage();
                            exit(1);
                        }
                    break;

                    case 't'	:
                    	if(argc>=(i+2)){
                    		if(argv[i+1][0]=='e'){
                    			algorythm_type = 'e';
                    		}else if(argv[i+1][0]=='h'){
                    			algorythm_type = 'h';
                    		}else if(argv[i+1][0]=='y'){
                    			algorythm_type = 'y';
                    		}else  {
                    			printf("Nieznany argument!\n");
                    		}
                    		i++;
                        } else {
                            printf("Za mało argumentów!\n");
                            printUsage();
                            exit(1);
                        }
                    break;


                    case 'r'    :           //operator krzyżowania
                        if(argc>=(i+2)){
                            if(strcmp(argv[i+1], "PMX")==0){
                                crossover_oper = "PMX";
                            }else if (strcmp(argv[i+1],"OX")==0){
                                crossover_oper = "OX";
                            }else if (strcmp(argv[i+1],"EX")==0){
                                crossover_oper = "EX";
                            }else {
                                printf("Nieznany argument!\n");
                                exit(1);
                            }
                            i++;
                        } else {
                            printf("Za mało argumentów!\n");
                            printUsage();
                            exit(1);
                        }
                    break;
                    case 'm'    :           //operator mutacji
                        if(argc>=(i+2)){
                            if(strcmp(argv[i+1], "inversion")==0){
                                mutation_oper = "inversion";
                            }else if (strcmp(argv[i+1], "scramble")==0){
                                mutation_oper = "scramble";
                            }else{
                                printf("Nieznany argument!\n");
                                exit(1);
                            }
                            i++;
                        } else {
                            printf("Za mało argumentów!\n");
                            printUsage();
                            exit(1);
                        }
                    break;
                    default     :
                    printf("Niepoprawna opcja!\n");
                    break;
                }
            }else{                  //wczytywanie parametrów
                in_file_loc = argv[i];
            }
        } //koniec pętli przeglądającej argumenty

/* USTAWIENIE WYBORU ALGORYTMU*/

        RandomPathGenerator::getInstance()->setVerbose(verbose);

        readDataFromFile(in_file_loc.c_str());

        Algorithm *a;

        switch(algorythm_type)	{
        				case 'e'	:
        				{
        					printf("Algorytm ewolucyjny\n");


        					a = new EvolutionaryAlgorithm();
        					//ustawienie parametrów typowych dla algorytmu ewolucyjnego
        					EvolutionaryAlgorithm* ea = (EvolutionaryAlgorithm*)a;

        					ea->setInitialPopCount(init_pop_num);
        					ea->setGenerationNum(generation_number);
        					// USTAWIENIE OPERATORA KRZYŻOWANIA
        					if(strcmp(crossover_oper.c_str(), "PMX")==0){

                                ea->setCrossoverOperator(new PartiallyMatchedCrossover());
                            }else if (strcmp(crossover_oper.c_str(), "OX")==0){
                            	ea->setCrossoverOperator(new OrderCrossover());
                            }else if (strcmp(crossover_oper.c_str(), "EX")==0){
                            	ea->setCrossoverOperator(new EdgeCrossover());
                            }
        					// USTAWIENIE OPERATORA MUTACJI
        					if(strcmp(mutation_oper.c_str(), "inversion")==0){
                                ea->setMutationOperator(new InversionMutation());
                            }else if (strcmp(mutation_oper.c_str(), "scramble")==0){
                            	ea->setMutationOperator(new ScrambleMutation());
                            }

        				}	// algorytm ewolucyjny
        					break;
        				case 'h'	:
        				{
        					printf("Algorytm heurystyczny\n");
        					a = new HeuristicAlgorithm();
        					//ustawienie parametrów typowych dla algorytmu heurystycznego
        				}
        					break;
        				case 'y'	:
        				{
        					printf("Algorytm hybrydowy\n");
        					a = new HybridAlgorithm();
        					//ustawienie parametrów typowych dla algorytmu hybrydowego
        				}
        					break;
        				default		:
							break;

        } // switch algorithm type

        a->setVerbose(verbose);



        a->setGraph(Graph::getInstance());
        a->performAlgorithm();

    	// Wydrukowanie parametrów algorytmu
        if(verbose){
        	printf("\nParametry programu:\n");
        	printf("  Plik wejściowy: %s\n", in_file_loc.c_str());
        	printf("  Plik wyjściowy: %s\n", out_file_loc.c_str());
        	printf("  Liczba populacji początkowej: %d\n", init_pop_num);
        	printf("  Operator krzyżowania: %s\n", crossover_oper.c_str());
        	printf("  Operator mutacji: %s\n", mutation_oper.c_str());

        	cout << endl << "Metadane pliku wejściowego:" << endl;
        	cout << "\tNazwa zbioru:\t\t" << name << endl;
        	cout << "\t" << comment << endl;
        	cout << "\tTyp węzłów współrzędnych:\t" << node_coord_type << endl;
        	cout << "\tLiczba węzłów(miast):\t" << dimension << endl;
        }








       // a.printResults();



        // zapisanie danych do pliku wyjściowego


        delete a;
        return 0;

    } // koniec if(liczba argumentów >2)

}   // koniec funkcji main
