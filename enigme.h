#ifndef  ENIGME_H_INCLUDED 
#define ENIGMLE_H_INCLUDED

#include<stdio.h> 
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h> 

typedef struct enigmes_question
{
char reponsevrai[4];
char q[400];
char rep1[4];
char rep2[4];
}enigmes_question;


typedef struct enigme
{
	int reponse;
	enigmes_question EN[30];
	int random ;
	char eng[50];
	char rep1[50];
	char rep2[50];
	SDL_Surface *yes;
	SDL_Surface *no;	
	TTF_Font *fonttexte;
	
	SDL_Surface *question;
	SDL_Surface *re3;
	SDL_Surface *re4;
	SDL_Rect posquestion;
	SDL_Rect posrep3;
	SDL_Rect posrep4;
	SDL_Rect rzlt;
        SDL_Color couleurtexte;
        SDL_Color couleur;
}enigme;

void init_enigme(enigme *E);
void generation_question(enigme *E);
void affichage(enigme *E,SDL_Surface *screen);
int resolution(enigme *E,SDL_Event event);
void freesur(enigme *E);
#endif  /* ENIGME_H_ */


