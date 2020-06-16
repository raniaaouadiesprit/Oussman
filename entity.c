#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "entity.h"


void initialise_entity(entity * es){

es->vie=3;
es->direction=0;
es->image=IMG_Load("res/player1.png");
SDL_GetClipRect(es->image,&es->position);//dimention surface image 
es->position.x=700;
es->position.y=200;
}

void afficher_entity (entity * es,SDL_Surface *screen,SDL_Rect* screenrect1)
{
	
	
	SDL_BlitSurface(es->image,NULL,screen,&es->position);// blit image sur screen 	    
}
}
