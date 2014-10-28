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
			double a = (rand() % (int)(max_x*10000+1))/10000;
			double b = (rand() % (int)(max_y*10000+1))/10000;

			output[i][0] = ((double)a);
			output[i][1] = ((double)b);

			printf("\tLosowanie nr %d: wylosowano (%f, %f);\n", i, output[i][0], output[i][1]);
			int j;

			for(j=0; j<i; j++){
                if( (output[j][0] == output[i][0])&&(output[j][1]== output[i][1])){
                    exists=true;
                    printf("\t!Powtórzenie\n");
                    break;
                }
            }
		}while(exists);
    } // for (i=0; i<num; i++);
    return output;
}

// tworzenie macierzy sąsiedztwa na podstawie macierzy współrzędnych miast
//
double ** createAdjacencyMatrix(int l, double ** coormatrix){
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
            printf("%f ", output[i][j]);
        }
        printf("\n");
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



int main(int argc, char ** argv){

    double x_dim = 0;
    double y_dim = 0;
    int cit_num = 0;
    char * output_file = "output";
    double ** cities;
    double ** adjmat;

	printf("Generator współrzędnych miast\n\n");

	if(argc < 4)
	{
		printf("Użycie:");
		printf("\t mapgen rozmiar_x rozmiar_y liczba_miast [plik_wyjściowy]\n");
		return(1);
	}else{
		x_dim = atoi(argv[1]);
		printf("Wymiar X\t: %f;\n", x_dim);
		y_dim = atoi(argv[2]);
		printf("Wymiar Y\t: %f;\n", y_dim);
		cit_num = atoi(argv[3]);
		printf("Liczba miast\t: %d;\n", cit_num);
		if(argc > 4){
			output_file = argv[4];
		}
		printf("Plik wyjściowy\t: %s;\n", output_file);
		if((x_dim * y_dim) < cit_num){
			printf("\nUżycie:\n");
			return 1;
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
