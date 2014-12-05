/*
Ten plik będzie zawierał sam kod związany z samą obsługą użytkownika - pobranie informacji, wczytanie danych
wejściowych itp.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include "Algorithm.h"
#include "HeuristicAlgorithm.h"
#include "Evolutionary/EvolutionaryAlgorithm.h"
#include "Hybrid/HybridAlgorithm.h"
#include "global.h"
#include "Evolutionary/Crossover/PartiallyMatchedCrossover.h"
#include "Evolutionary/Crossover/CrossoverOperator.h"
#include "Evolutionary/Crossover/EdgeCrossover.h"
#include "Evolutionary/Crossover/OrderCrossover.h"
#include "Evolutionary/Mutation/InversionMutation.h"
#include "Evolutionary/Mutation/MutationOperator.h"
#include "Evolutionary/Mutation/ScrambleMutation.h"


using namespace std;



bool verbose = false;
char * in_file_loc;
char * out_file_loc = "output.file";
int init_pop_num = 10; // rozmiar populacji początkowej
char * recom_oper = {"PMX"}; //operator krzyżowania
char * mutat_oper = {"inversion"}; //operator mutacji
char algorythm_type = 'e';
int generation_number = 100;

AdjacencyMatrix readFromFile(char* filename){
	AdjacencyMatrix am;
	// IMPLEMENTACJA WCZYTYWANIA Z PLIKU MACIERZY SĄSIEDZTWA

	return am;
}
void printUsage(){

	printf("\nUżycie:\n");
	printf(" tsp [opcje] <plik macierzy sąsiedztwa>\n");
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

double ** readDataFromFile(char* inFile){
	return NULL;
}

int main(int argc, char ** argv){

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
                                recom_oper = "PMX";
                            }else if (strcmp(argv[i+1],"OX")==0){
                                recom_oper = "OX";
                            }else if (strcmp(argv[i+1],"EX")==0){
                                recom_oper = "EX";
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
                                mutat_oper = "inversion";
                            }else if (strcmp(argv[i+1], "scramble")==0){
                                mutat_oper = "scramble";
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

    	// Wydrukowanie parametrów algorytmu

        printf("\nParametry programu:\n");
        printf("  Plik wejściowy: %s\n", in_file_loc);
        printf("  Plik wyjściowy: %s\n", out_file_loc);
        printf("  Liczba populacji początkowej: %d\n", init_pop_num);
        printf("  Operator krzyżowania: %s\n", recom_oper);
        printf("  Operator mutacji: %s\n", mutat_oper);

        Algorithm *a;

        switch(algorythm_type)	{
        				case 'e'	:
        				{
        					printf("Algorytm ewolucyjny");

        					EvolutionaryAlgorithm *ea = new EvolutionaryAlgorithm;

        					a=ea;
        					//ustawienie parametrów typowych dla algorytmu ewolucyjnego

        					ea->setInitialPopCount(init_pop_num);
        					ea->setGenerationNum(generation_number);
        					// USTAWIENIE OPERATORA KRZYŻOWANIA
        					if(strcmp(recom_oper, "PMX")==0){
                                ea->setCrossoverOperator(new PartiallyMatchedCrossover());
                            }else if (strcmp(recom_oper, "OX")==0){
                            	ea->setCrossoverOperator(new OrderCrossover());
                            }else if (strcmp(recom_oper, "EX")==0){
                            	ea->setCrossoverOperator(new EdgeCrossover());
                            }
        					// USTAWIENIE OPERATORA MUTACJI
        					if(strcmp(recom_oper, "inversion")==0){
                                ea->setMutationOperator(new InversionMutation());
                            }else if (strcmp(recom_oper, "scramble")==0){
                            	ea->setMutationOperator(new ScrambleMutation());
                            }

        				}	// algorytm ewolucyjny
        					break;
        				case 'h'	:
        				{
        					printf("Algorytm heurystyczny");
        					a = new HeuristicAlgorithm();
        					//ustawienie parametrów typowych dla algorytmu heurystycznego
        				}
        					break;
        				case 'y'	:
        				{
        					printf("Algorytm hybrydowy");
        					a = new HybridAlgorithm();
        					//ustawienie parametrów typowych dla algorytmu hybrydowego
        				}
        					break;
        				default		:
							break;

        }

        a->setVerbose(verbose);
        a->readDataFromFile(in_file_loc);
        a->performAlgorithm();
        a->writeResultsToFile(out_file_loc);

       // a.printResults();



        // zapisanie danych do pliku wyjściowego

        return 0;

    } // koniec if(liczba argumentów >2)

}   // koniec funkcji main
