#ifndef perso_H
#define perso_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


		

		
typedef struct {
	SDL_Rect position;
        SDL_Rect frame;
	SDL_Surface * image;
        int curframe;
        int vie;
	int direction; 
	int score; 
        int running;
        int previousmvt;
        double acceleration;
        double decelere;
        double vitesse;
        double v_x;
        int velocity;

    double v_grav ;
    double v_saut ;

    double v_y ;
       
	
	
}perso;



void initialisePerso(perso * p);
void initialisePerso2(perso * p);
void afficherPerso (perso * p,SDL_Surface *screen);

void freesurf(SDL_Surface *img,SDL_Surface *img2);
int moveperso2(perso *p ,SDL_Surface* screen,SDL_Event ev);
int moveperso(perso *p ,SDL_Surface* screen,SDL_Event event);
void animationperso(perso *p ,SDL_Surface* screen);
int collisionBoundingBox(SDL_Rect first,SDL_Rect second);
void sautpersonnage(SDL_Event ev,perso *p);
void vitessepersonnage(SDL_Event ev,perso *p);
int dep_souris(perso *p ,SDL_Event ev,int xscrol);
#endif
