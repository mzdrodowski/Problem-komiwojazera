/*
Generator mapy losowych współrzędnych miast
Mapgen przyjmuje jako parametry: rozmiar tablicy i ilość miast. Na wyjściu generuje plik tekstowy który na początku posiada rozmiary x i y tablicy i wygenerowane współrzędne miast.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>


bool verbose = false;



//inicjalizowanie macieży o zadanej liczie wierszy i kolumn
double** allocateMatrix(double rows, double columns){
	double** matrix;
	matrix =  malloc ((rows) * sizeof(double *));
	if(matrix==NULL){
        printf("Brak pamięci!");
        return NULL;
        }else{
			int i;
			for(i=0; i<rows; i++){
				matrix[i] =  malloc((columns) * sizeof(double));
				if(matrix[i]==NULL){
                    printf("Brak pamięci!");
                    return NULL;
                }
			}
		}
	return matrix;
}

// zwalnianie pamięci danej macierzy
int freeMatrix(double** matrix, int rows, int columns){
    int i;
	for (i = 0; i<rows; i++){
        free(matrix[i]);
	}
	free(matrix);
	return 0;
}

/* Alokowanie pamięci i generowanie współrzędnych miast o zadanej ilości
i w określonym zakresie */
double ** generateCitiesCoordinates(double max_x, double max_y, int num){
    //alokacja tablicy miast
    double ** output = allocateMatrix(num, 2);

    srand(time(NULL));
    bool exists;
    int i;
	for(i=0; i<num; i++){
		do{
            exists = false; // czy istnieje miasto o danych współrzędnych
			double a = (rand() % (int)(max_x*10000+1));
			double b = (rand() % (int)(max_y*10000+1));
            a = a/10000;
            b = b/10000;
			output[i][0] = ((double)a);
			output[i][1] = ((double)b);
            if(verbose){
                printf("\tLosowanie nr %d: wylosowano (%f, %f);\n", i, output[i][0], output[i][1]);
			}
			int j;

			for(j=0; j<i; j++){
                if( (output[j][0] == output[i][0])&&(output[j][1]== output[i][1])){
                    exists=true;
                    if(verbose){
                        printf("\t!Powtórzenie\n");
                    }
                    break;
                }
            }
		}while(exists);
    } // for (i=0; i<num; i++);
    return output;
}

// tworzenie macierzy sąsiedztwa na podstawie macierzy współrzędnych miast
//
double ** createAdjacencyMatrix(const int l, double ** coormatrix){

    printf("\nTworzenie macierzy sąsiedztwa:\n\n");

    double ** output = allocateMatrix(l,l);
    int i,j;
    for(i=0; i<l; i++){
        for(j=0; j<l; j++){
            if(i==j){
                output[i][j]=0;
            }else{
                double d = coormatrix[i][0] - coormatrix[i][1];
                d = d*d;
                double e = coormatrix[j][0] - coormatrix[j][1];
                e = e*e;
                output[i][j]=sqrt(d+e);
            }
        }
    }
    if(verbose){
            for(i=0;i<l; i++){
                for(j=0;j<l; j++){
                    printf("%f ", output[i][j]);
                }
                printf("\n");
            }
    }
	return output;
}
/* zapisujemy zadaną macierz do pliku o określonej nazwie. num jest liczbą miast
rozmiarem tablicy */
int saveAdjacencyMatrix(double** adjmat, int num, char* name){
    FILE * fp;
    if((fp = fopen(name, "w"))==NULL){
        printf("Nie można otworzyć pliku: \"%s\" do odczytu.\n",name);
        exit(1);
    }
    int i, j;
    for(i=0; i<num; i++){
        for(j=0; j<num; j++){
            fprintf(fp, "%f", adjmat[i][j]);
            if(j!=(num-1)){
                fprintf(fp," ");
            }
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("\nWygenerowaną macierz sąsiedztwa zapisano do pliku: \"%s\".\n ", name);
    return 0;
}
// wydrukowanie instrukcji poprawnego użycia
void printUsage(){
    printf("\nUżycie: ");
	printf("mapgen rozmiar_x rozmiar_y liczba_miast [plik_wyjściowy]\n");
	printf("\nOpcje:\n");
	printf("  -v \t\t\t wypisywanie \n");
	printf("  -o NAZWA_PLIKU \t ustawienie nazwy pliku wyjściowego \n\n");

}



int main(int argc, char ** argv){

    double x_dim = 0;
    double y_dim = 0;
    int cit_num = 0;
    char * output_file = "output";
    double ** cities;
    double ** adjmat;

	printf("Generator współrzędnych miast\n");

	if(argc < 4)
	{
        printf("\nNiepoprawna liczba argumentów!\n");
        printUsage();
		exit(1);
	}else{
        int i, par_n;
        par_n = 0;
        for(i=1; i<argc; i++){
            if(argv[i][0]=='-'){        //jeżeli opcja
                char opt = argv[i][1];
                switch(opt){
                    case 'v' :
                        verbose = true;
                        break;
                    case 'o' :
                        if(argc<(i+2)){
                            printf("Brak nazwy pliku");
                            printUsage();
                            exit(1);
                            break;
                        }else{
                            output_file = argv[i+1];
                            i++;
                            break;
                        }
                    default :
                        printf("Nieznana opcja\n");
                        printUsage();
                        exit(1);
                }
                printf("opcja: %c \n", argv[i][1]);
            }
            else{                   // jeżeli parametr
                switch(par_n){
                case 0  :
                    x_dim = atoi(argv[i]);
                    break;
                case 1  :
                    y_dim = atoi(argv[i]);
                    break;
                case 2  :
                    cit_num = atoi(argv[i]);
                    break;
                default :
                    printf("Nie poprawna liczba parametrów\n");
                    exit(1);
                break;
                }
                par_n++;
            }
        }

		printf("Wymiar X\t: %f;\n", x_dim);
		printf("Wymiar Y\t: %f;\n", y_dim);
		printf("Liczba miast\t: %d;\n", cit_num);


		printf("Plik wyjściowy\t: %s;\n", output_file);
		if((x_dim * y_dim) < cit_num){
			printUsage();
			exit(1);
		}else{


			//losowanie współrzędnych miast
			cities = generateCitiesCoordinates(x_dim, y_dim, cit_num);
			//obliczanie macierzy sąsiedztwa
			adjmat = createAdjacencyMatrix(cit_num, cities);
			//zapisywanie danych do pliku
            saveAdjacencyMatrix(adjmat, cit_num, output_file);
			//zwalnianie pamięci tablicy miast
            freeMatrix(cities, cit_num, 2);
            freeMatrix(adjmat, cit_num, cit_num);
		}
	}
	return 0;
}
