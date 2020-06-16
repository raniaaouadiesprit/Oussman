#ifndef  ENIGME_H_INCLUDED 
#define ENIGMLE_H_INCLUDED

#include<stdio.h> 
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h> 


typedef struct enigme
{
	int reponse;

	int random ;
	char eng[50];//question
	char rep1[50];
	char rep2[50];
	SDL_Surface *yes;
	SDL_Surface *no;	
	TTF_Font *fonttexte;
	
	SDL_Surface *question;//addition ques+ttf font
	SDL_Surface *re3;
	SDL_Surface *re4;
	SDL_Rect posquestion;// mettre surface question dans son rectangle
	SDL_Rect posrep3;
	SDL_Rect posrep4;
	SDL_Rect rzlt;
        SDL_Color couleurtexte;
        SDL_Color couleur;
}enigme;

void init_enigme(enigme *E);
void generation_question(enigme *E,int dif);
void affichage(enigme *E,SDL_Surface *screen,int *vie,int *key);
int resolution(enigme *E,SDL_Event event);
void freesur(enigme *E);
#endif  /* ENIGME_H_ */


