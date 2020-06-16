#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "score.h"

score intialiser_score(score s)
{
   
    SDL_Color textcolor={33, 33, 33} ; 
    strcpy(s.chaine,"");
    s.tempsActuel = 0;
    s.tempsPrecedent = 0;
    s.compteur =0;
    s.police = TTF_OpenFont("texte.ttf", 60); 
    s.position.x = 100;
    s.position.y = 0;
    return s;     
}

score  gestion_score(score s,SDL_Surface *ecran)
{
      SDL_Color couleurNoire = {30, 30, 30};
      SDL_Color  couleurBlanche = {255, 255, 255};
        
      sprintf(s.chaine, "score : %04d", s.compteur); 
      s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 

      s.tempsActuel = SDL_GetTicks();
        if (s.tempsActuel - s.tempsPrecedent >= 1000) 
        {
            s.compteur += 10;
            sprintf(s.chaine, "score : %04d", s.compteur); 
            SDL_FreeSurface(s.texte);
            s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 
            s.tempsPrecedent = s.tempsActuel; 
	}

return s;
}

void afficher_score(score s,SDL_Surface *ecran)
{    sprintf(s.chaine, "score : %04d", s.compteur); 
      s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 
    SDL_BlitSurface(s.texte, NULL, ecran, &s.position);
    SDL_Flip(ecran);   
}

void free_score(score s,SDL_Surface *ecran)
{
TTF_CloseFont(s.police);
TTF_Quit();
SDL_FreeSurface(s.texte);
printf("free score => done \n");
}

