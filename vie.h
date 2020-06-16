#ifndef VIE_H_INCLUDED
#define VIE_H_INCLUDED



typedef struct 
{
SDL_Rect position ;  
int val ;
SDL_Surface *image[5]; 
} vie ;



vie init_vie(vie v) ; 
vie updatevie(vie v,int test,SDL_Surface *ecran); 
void displayvie(vie v ,SDL_Surface *ecran) ;  
void vie_freevie(vie v ) ;  
//int calcul_vie();
#endif