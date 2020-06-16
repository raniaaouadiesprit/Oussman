#ifndef CLOCK_INCLUDED
#define CLOCK_INCLUDED

typedef struct
{
    int heur1;
    int minute1;
    int seconde1;
    int maxtemp;
    SDL_Color textcolor;
    SDL_Surface *temp;
    SDL_Rect position_temp;
    TTF_Font *police ;
    int tempactuel;
    int tempprecedent;
    SDL_Rect position_imgtemp;
    SDL_Surface *imgtemp;
    char chaine[20];


}tempss;
tempss inisaliser_temp_compteur (tempss temp,int diff);
tempss gestion_temps_compteur(int pause_time_disc,int pause_time_pause,tempss temp,SDL_Surface *ecran);

void free_temps(tempss temp);

tempss inisaliser_temp_decompteur (tempss temp,int diff );
tempss gestion_temps_decompteur(int pause_time_disc,int pause_time_pause,tempss temp,SDL_Surface *ecran);


#endif

