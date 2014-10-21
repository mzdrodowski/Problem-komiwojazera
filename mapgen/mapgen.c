/*
Generator mapy losowych współrzędnych miast
Mapgen przyjmuje jako parametry: rozmiar tablicy i ilość miast. Na wyjściu generuje plik tekstowy który na początku posiada rozmiary x i y tablicy i wygenerowane współrzędne miast.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int i;
int x_dim = 0;
int y_dim = 0;
int cit_num = 0;
char * output_file = "output.txt";

struct City {
	int x_dim;
	int y_dim;
	char * nazwa;
};

struct City ** cities;

int main(int argc, char ** argv){
	printf("Generator współrzędnych miast\n\n");

	if(argc < 4)
	{
		printf("Błąd: Niepoprawna liczba argumentów!\n\n");
		printf("Poprawne użycie:\n");
		printf("\tmapgen rozmiar_x rozmiar_y liczba_miast [plik_wyjściowy]\n");
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
		if(x_dim*y_dim<cit_num){
			printf("\nBłąd: Niepoprawne dane wejściowe!\n");
			return 1;
		}else{
			//alokacja tablicy miast
			cities = malloc(cit_num * (sizeof( struct City *)));
			for(i=0; i<cit_num; i++){
				cities[i] = malloc(sizeof(struct City));
			}

			//losowanie lokalizacji miast
			srand(time(NULL));
            bool exists;
			for(i=0; i<cit_num; i++){
				do{
                    exists = false;
					int a = rand() % x_dim;
					int b = rand() % y_dim;
					cities[i]->x_dim = a;
					cities[i]->y_dim = b;

					printf("Wylosowano (%d, %d ) dla %d-go miasta\n", cities[i]->x_dim, cities[i]->y_dim, i);
					int j;
					for(j=0; j<i; j++){
                       if( (cities[j]->x_dim == cities[i]->x_dim)&&(cities[j]->y_dim == cities[i]->y_dim)){exists=true; printf("Powtórzenie\n");break;}
                    }
				}while(exists);
			}
			//zwalnianie pamięci tablicy miast
			for(i=0; i<cit_num; i++){
				free(cities[i]);
			}
			free(cities);

		}
	}





	return 0;

}
