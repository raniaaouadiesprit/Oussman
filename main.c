#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
#define LARGEUR 1100
#define HAUTEUR 400

SDL_Surface* screen=NULL;
SDL_Rect screenrect={0,0,0,0};
SDL_Surface* backg=NULL;
SDL_Rect backgrect={0,0,0,0};
SDL_Surface* tmp=NULL;

int main()
{

SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
int running=1;

screen=SDL_SetVideoMode(LARGEUR,HAUTEUR,bpp,SDL_HWSURFACE);
SDL_WM_SetCaption("Enigme",NULL);

//background
tmp=SDL_LoadBMP("res/background.bmp");
backg=SDL_DisplayFormat(tmp);
SDL_FreeSurface(tmp);
SDL_GetClipRect(backg,&backgrect);
enigme e;
generation_question(&e);
init_enigme(&e);


while(running)
{
SDL_Event event;
SDL_PollEvent(&event);
SDL_BlitSurface(backg,NULL,screen,&backgrect);

affichage(&e,screen);
running=resolution(&e,event);

SDL_Flip(screen);
}
freesur(&e);
SDL_FreeSurface(backg);
SDL_Quit();
return 0;
}
