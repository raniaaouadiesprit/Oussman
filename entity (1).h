#ifndef entity_H
#define entity_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


		

		
typedef struct {
	SDL_Rect position;
	SDL_Surface * image;
	int vie;
	int direction; //0:right 1:left 2:up
	
}entity;



void initialise_entity(entity * es);
void afficher_entity (entity * es,SDL_Surface *screen,SDL_Rect* screenrect1);
#endif
