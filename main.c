#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "ennemi.h"

#define LARGEUR 1100
#define HAUTEUR 400
//declaration SDL
SDL_Surface* screen=NULL;
SDL_Rect screenrect={0,0,0,0};
SDL_Surface* backg=NULL;
SDL_Rect backgrect={0,0,0,0};
SDL_Rect test={450,200,0,0};
SDL_Surface* tmp=NULL;
SDL_Event ev;
SDL_Event ev2;

int main(int argc, char** argv)
{
    
//Declaration

Ennemi E;

SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
int now=0;
int ex=0;
int pfps=33;
int dt=0;
int running=1;


int ie;
char path_ennemi [500] = "res/ennemi_spr.png";

screen=SDL_SetVideoMode(LARGEUR,HAUTEUR,bpp,SDL_HWSURFACE);
SDL_WM_SetCaption("Game",NULL);
//background
tmp=IMG_Load("res/gamebackg.png");

/***************************************************************************************************************/
//backg=SDL_DisplayFormat(tmp);

//SDL_FreeSurface(tmp);


SDL_GetClipRect(backg,&backgrect);

//inti


ie=init_ennemi(&E,path_ennemi);







//boucle Game.x
while(running)
{
now=SDL_GetTicks();
dt=now-ex;
SDL_BlitSurface(backg,NULL,screen,&backgrect);
display_ennemi(&E,screen);
update_ennemi(&E, test);
if(dt>=pfps)
{
backg=SDL_DisplayFormat(tmp);

//affichage
SDL_PollEvent(&ev2);
test.x++;



//display #ALL
SDL_Flip(screen);



}
else 
 SDL_Delay(pfps-dt);
}



/***************************************************************************************************************/


//#FREE!!!!!!!!!!!!!!!
SDL_FreeSurface(screen);
freeEnnemi(&E);




SDL_Quit();
return 0;
}

