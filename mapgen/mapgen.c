/*
Generator mapy losowych współrzędnych miast
Mapgen przyjmuje jako parametry: rozmiar tablicy i ilość miast. Na wyjściu generuje plik tekstowy który na początku posiada rozmiary x i y tablicy i wygenerowane współrzędne miast.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int x_dim = 0;
int y_dim = 0;
int cit_num = 0;
char * output_file = "output";

int** cities;

//inicjalizowanie macieży o zadanej liczie wierszy i kolumn
int** allocateMatrix(int rows, int columns){
	int** matrix;
	matrix =  malloc ((rows) * sizeof(int *));
	if(matrix==NULL){
        printf("Brak pamięci!");
        return NULL;
        }else{
			int i;
			for(i=0; i<rows; i++){
				matrix[i] =  malloc((columns) * sizeof(int));
				if(matrix[i]==NULL){
                    printf("Brak pamięci!");
                    return NULL;
                }
			}
		}
	return matrix;
}


// zwalnianie pamięci danej macierzy
int freeMatrix(int** matrix, int rows, int columns){

    int i;
	for (i = 0; i<rows; i++){
        printf("Pętla zwaniania nr: %d\n", i);
        free(matrix[i]);
        printf("zwolniono %d", i);
	}
	printf("zwolniono wiersze");
	free(matrix);
	printf("zwolniono matrix");
	return 0;
}

// tworzenie macierzy sąsiedztwa
int createAdjacencyMatrix(){
	return 0;
}

int main(int argc, char ** argv){
	printf("Generator współrzędnych miast\n\n");

	if(argc < 4)
	{
		printf("Użycie:");
		printf("\t mapgen rozmiar_x rozmiar_y liczba_miast [plik_wyjściowy]\n");
		return(1);
	}else{
		x_dim = atoi(argv[1]);
		printf("Wymiar X\t: %d;\n", x_dim);
		y_dim = atoi(argv[2]);
		printf("Wymiar Y\t: %d;\n", y_dim);
		cit_num = atoi(argv[3]);
		printf("Liczba miast\t: %d;\n",cit_num);
		if(argc > 4){
			output_file = argv[4];
		}
		printf("Plik wyjściowy\t: %s;\n", output_file);
		if((x_dim * y_dim) < cit_num){
			printf("\nUżycie:\n");
			return 1;
		}else{
			//alokacja tablicy miast
			cities = allocateMatrix(cit_num, 2);

			//losowanie współrzędnych miast
			srand(time(NULL));
            bool exists;
            int i;
			for(i=0; i<cit_num; i++){
				do{
                    exists = false; // czy istnieje miasto o danych współrzędnych
					cities[i][0] = (rand() % x_dim);
					cities[i][1] = (rand() % y_dim);

					printf("Losowanie %d. Wylosowano (%d, %d)\n", i, cities[i][0], cities[i][1]);
					int j;

					for(j=0; j<i; j++){

                        if( (cities[j][0] == cities[i][0])&&(cities[j][1]== cities[i][1])){
                            exists=true;
                            printf("Powtórzenie\n");
                            break;
                        }
                    }
				}while(exists);
			}

            int j;
            for(i=0; i<cit_num; i++){
                for(j=0; j<2; j++){
                    printf("%d ", cities[i][j]);
                }
                printf("\n");
            }
			//obliczanie macierzy sąsiedztwa
			createAdjacencyMatrix();
			//zapisywanie danych do pliku

			//zwalnianie pamięci tablicy miast
            freeMatrix(cities, cit_num, 2);

		}
	}

	return 0;

}
