//============================================================================
// Name        : tsal.cpp
// Author      : Michał Zdrodowski
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>



using namespace std;


bool verbose = false;
char * in_file_loc ;
string out_file_loc = "output.file";// lokalizacja pliku wyjściowego
int init_pop_num = 10; // rozmiar populacji początkowej
string recom_oper = "EAX"; //operator krzyżowania
string mutat_oper = "inversion"; //operator mutacji
double ** adjacencyMatrix;


void printUsage(){

	cout << "\nOpcje\n";
	cout << "\nUżycie: tsal PLIK_WEJŚCIOWY [opcje]\n";
	cout << "  -v \t\t\t wypisanie przebiegu działania programu\n";
	cout << "  -o PLIK_WYNIKOWY \t nazwa pliku wynikowego \n";
	cout << "  -l LICZBA_POCZ \t liczba osobników w populacji początkowej\n";
	cout << "  -r [EAX|PX|EX]\t wybór operatora krzyżowania(rekombinacji)\n";
	cout << "  -m [inversion|scramble]\t wybór operatora mutacji\n";

}

double ** readAdjacencyMatrixFromFile(char * input_file){
	double ** outputMatrix;

	ifstream inFile;

	inFile.open(input_file);

	if(inFile.fail()){
		cerr << "Błąd podczas otwierania pliku\n";
	}

	inFile.close();
	return outputMatrix;
}

int main(int argc, char** argv) {
	cout << "\nProblem komiwojażera - algorytm ewolucyjny\n";

	if(argc<2){
       	cout << "\nNiepoprawna liczba argumentów\n";
		printUsage();
		return 1;
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
                            cout << "Brak nazwy pliku wyjściowego!\n";
                            printUsage();
                            return 1;
                        }
                    break;
                    case 'l'    :           //liczba populacji początkowej
                        if(argc>=(i+2)){
                            init_pop_num = atoi(argv[i+1]);
                            i++;
                        }else{
                            cout << "Za mało argumentów";
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
                                cout << "Nieznany argument!\n";
                                exit(1);
                            }
                            i++;
                        } else {
                            cout << "Za mało argumentów!\n";
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
                                cout << "Nieznany argument!\n";
                                exit(1);
                            }
                            i++;
                        } else {
                            cout << "Za mało argumentów!\n";
                            printUsage();
                            exit(1);
                        }
                    break;
                    default     :
                    cout << "Niepoprawna opcja!\n";
                    break;
                }
            }else{                  //wczytywanie parametrów
                in_file_loc = argv[i];
            }
        } //koniec pętli przeglądającej argumenty

    	// Wydrukowanie parametrów algorytmu

        cout << "\nParametry programu:\n";
        cout << "  Plik wejściowy: " <<  in_file_loc << endl;
        cout << "  Plik wyjściowy: "<< out_file_loc << endl;
        cout << "  Liczba populacji początkowej: " << init_pop_num << endl;
        cout << "  Operator krzyżowania: " << recom_oper << endl;
        cout << "  Operator mutacji: " << mutat_oper << endl;

        // wczytanie danych z pliku
        adjacencyMatrix = readAdjacencyMatrixFromFile(in_file_loc);
        /* Utworzenie nowego obiektu algorytmu*/

        // inicjalizacja populacji za pomocą losowych rozwiązań;
        // ocena każdego kandydata
        // while(warunek końcowy){
            //wybór rodziców
            //rekombinacja par rodziców;
            //mutacja  potomstwa;
            //ocena nowych kandydatów;
            //wybór kandydatów do następnego pokolenia;

        //}

        // zapisanie danych do pliku wyjściowego

        return 0;

    } // koniec if(liczba argumentów >2)
}
