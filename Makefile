all:
	gcc mapgen/mapgen.c -o bin/mapgen -lm
	gcc trasal/main.c -o bin/trasal

