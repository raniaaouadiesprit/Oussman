#ifndef SCORE_INCLUDED
#define SCORE_INCLUDED


typedef struct 
{


TTF_Font *police;
SDL_Rect position ;  
SDL_Surface *texte;
int tempsActuel;
int  tempsPrecedent ;
int  compteur;
char chaine[20];
}score; 


score intialiser_score(score s);
score  gestion_score(score s,SDL_Surface *ecran);
void afficher_score(score s,SDL_Surface *ecran);
void free_score(score s,SDL_Surface *ecran);





#endif
