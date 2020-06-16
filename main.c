#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "entity.h"

#include "scrol.h"
#define LARGEUR 1100
#define HAUTEUR 400
//declaration SDL
SDL_Surface* screen=NULL;
SDL_Rect screenrect={0,0,0,0};
SDL_Surface* backg=NULL;
SDL_Surface* backg1=NULL;
SDL_Rect backgrect={0,0,0,0};
SDL_Surface* tmp=NULL;
SDL_Event ev;


int main()
{
//Declaration

entity es;
scr s;

int keys=2;
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
int now=0;
int ex=0;
int pfps=33;
int dt=0;
int test;
screen=SDL_SetVideoMode(LARGEUR,HAUTEUR,bpp,SDL_HWSURFACE);
SDL_WM_SetCaption("Perso",NULL);
//background
tmp=IMG_Load("res/gamebackg.png");
backg=SDL_DisplayFormat(tmp);

SDL_GetClipRect(backg,&backgrect);

initialise_entity(&es);

initscrol(&s);

//boucle Game.x
while(1)
{
now=SDL_GetTicks();
dt=now-ex;
backg=SDL_DisplayFormat(tmp);
if(dt>=pfps)
{


//affichage
SDL_PollEvent(&ev);


afficher_entity(&es,backg,&backgrect);
scrolling(&s,screen,backg,0,backgrect);


deplacement_alea_ennemi(&es);



//display #ALL
SDL_Flip(screen);
SDL_FreeSurface(backg);
}
else 
 SDL_Delay(pfps-dt);
}

//#FREE!!!!!!!!!!!!!!!




SDL_Quit();
return 0;
}

