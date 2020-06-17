prog: main.o ennemi.o 
	gcc main.o ennemi.o -o prog -g -lSDL -lSDL_image -lm  
main.o: main.c
	gcc -c main.c -g -lSDL -lSDL_image 
ennemi.o: ennemi.c
	gcc -c ennemi.c -g -lSDL -lSDL_image 


