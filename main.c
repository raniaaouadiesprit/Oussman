#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
#include <SDL/SDL_rotozoom.h>
#include<time.h>
#define LARGEUR 1100
#define HAUTEUR 400

SDL_Surface* screen=NULL;
SDL_Rect screenrect={0,0,0,0};
SDL_Surface* backg=NULL;
SDL_Rect backgrect={0,0,0,0};
SDL_Surface* tmp=NULL;

int main()
{
int dif=3;
SDL_Init(SDL_INIT_VIDEO);//debut de utilisation sdl 
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
generation_question(&e,dif);
init_enigme(&e);
int vie=3;
int keys=0;
SDL_Surface *rotation;
	double angle = 200;
    	double zoom = 0;

	while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}
while(running)
{
SDL_Event event;
SDL_PollEvent(&event);
SDL_BlitSurface(backg,NULL,screen,&backgrect);

affichage(&e,screen,&vie,&keys);
running=resolution(&e,event);

SDL_Flip(screen);
}
freesur(&e);
SDL_FreeSurface(backg);
SDL_Quit();
return 0;
}
