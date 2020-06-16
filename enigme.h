#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#ifndef ENIGMES_H_INCLUDED
#define ENIGMES_H_INCLUDED

typedef struct {
	SDL_Surface *texteQ, *texteR;
}question;

typedef struct {
	SDL_Rect posTF;
	question questions;
	TTF_Font *police;
	SDL_Rect posQ,posR;
}enigme;

void init_enigme(enigme *e);
void afficherEnigme(enigme *e,SDL_Surface *screen);
#endif
