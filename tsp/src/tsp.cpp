/*
Ten plik będzie zawierał sam kod związany z samą obsługą użytkownika - pobranie informacji, wczytanie danych
wejściowych itp.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Algorithm.h"
#include "HeuristicAlgorithm.h"
#include "Evolutionary/EvolutionaryAlgorithm.h"

using namespace std;

bool verbose = false;
char * in_file_loc;
char * out_file_loc = "output.file";
int init_pop_num = 10; // rozmiar populacji początkowej
char * recom_oper = {"EAX"}; //operator krzyżowania
char * mutat_oper = {"inversion"}; //operator mutacji
bool evolutionary = true;


void printUsage(){

	printf("\nOpcje\n");
	printf("\nUżycie: trasal PLIK_WEJŚCIOWY [opcje]\n");
	printf("  -v \t\t\t wypisanie przebiegu działania programu\n");
	printf("  -o PLIK_WYNIKOWY \t nazwa pliku wynikowego \n");
	printf("  -l LICZBA_POCZ \t liczba osobników w populacji początkowej\n");
	printf("  -r [EAX|PX|EX]\t wybór operatora krzyżowania(rekombinacji)\n");
	printf("  -m [inversion|scramble]\t wybór operatora mutacji\n");

}

double ** readDataFromFile(char* inFile){
	return NULL;
}

int main(int argc, char ** argv){

	printf("\nProblem komiwojażera - algorytm ewolucyjny\n");

	if(argc<2){
        printf("\nNiepoprawna liczba argumentów\n");
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
                            printf("Za mało argumentów");
                            printUsage();
                            exit(1);
                        }
                    break;
                    case 'r'    :           //operator krzyżowania
                        if(argc>=(i+2)){
                            if(strcmp(argv[i+1], "EAX")==0){
                                recom_oper = "EAX";
                            }else if (strcmp(argv[i+1],"PX")==0){
                                recom_oper = "PX";
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


        if(evolutionary){
        	a = new EvolutionaryAlgorithm();
        	//ustawianie parametrów

        }else{
        	a = new HeuristicAlgorithm();
        	//ustawianie parametrów
        }
        a->readDataFromFile(in_file_loc);
        a->performAlgorithm();
        a->writeResultsToFile(out_file_loc);

       // a.printResults();



        // zapisanie danych do pliku wyjściowego

        return 0;

    } // koniec if(liczba argumentów >2)

}   // koniec funkcji main
