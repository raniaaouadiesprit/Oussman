#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "condition.h"

void initcond(condition * a) {
a->over.x=0;
a->over.y=0;
a->over.w=1100;
a->over.h=400;
a->pause=1;
a->ba=IMG_Load("res/black.png");
a->pause=0;
}
int conditionn(int key , condition* c,int vie,SDL_Surface* screen,int timeTemps,int x){

char tt[150];
char op[150];
int minute = 0;
int seconde = 0;
minute = (timeTemps / 1000) / 60;
seconde = (timeTemps / 1000) % 60;
sprintf(tt, "You Cleared the Game in:%dmin and %dsec", minute, seconde);
sprintf(op, "Game Over in:%dmin and %dsec", minute, seconde);
if(key==3||vie==0){
c->pause=1;
while(c->pause){
SDL_PollEvent(&c->event);
switch(c->event.type)
{case SDL_QUIT:
c->pause=0;
return 0;
break;}
if(key==3){
	TTF_Init();
SDL_BlitSurface(c->ba,NULL,screen,&c->over);
c->font=TTF_OpenFont("res/o.ttf",80);
	SDL_Color couleurtexte = {250,0,0};
c->ch=TTF_RenderText_Solid(c->font,tt ,couleurtexte);
	SDL_BlitSurface(c->ch, NULL,screen,&c->over); 
SDL_Flip(screen);
x=0;

SDL_FreeSurface(c->ch);
TTF_CloseFont(c->font);
	TTF_Quit();
}
if(vie==0){
	TTF_Init();
SDL_BlitSurface(c->ba,NULL,screen,&c->over);
c->font=TTF_OpenFont("res/o.ttf",80);
	SDL_Color couleurtexte = {250,0,0};
c->ch=TTF_RenderText_Solid(c->font,op ,couleurtexte);
	SDL_BlitSurface(c->ch, NULL,screen,&c->over); 
SDL_Flip(screen);
x=0;
SDL_FreeSurface(c->ch);

TTF_CloseFont(c->font);

	TTF_Quit();}

}
}
	}
