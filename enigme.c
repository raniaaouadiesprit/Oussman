#include<stdio.h> 
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>
#include "enigme.h"
void generation_question(enigme *E)
{



srand( time(NULL) );
int a=0,b=0,c=0,d=0;
E->random=1;
E->random= rand() %2+1;
a=rand() %50+1;
b=rand() %90+1;
c=a*b;
d=rand()%c;
if(E->random==1){
sprintf(E->eng, "%dx%d=?",b, a );
sprintf(E->rep1, "%d",c);
sprintf(E->rep2, "%d",d);
}
else if(E->random==2){
sprintf(E->eng, "%dx%d=?",b, a );
sprintf(E->rep1, "%d",d);
sprintf(E->rep2, "%d",c);
}
}

void init_enigme(enigme *E)
{
	E->reponse=-1;
	TTF_Init();
E->yes=IMG_Load("a.jpg");
E->no=IMG_Load("b.jpg");
	E->posquestion.x=255;
	E->posquestion.y=100;
	E->posrep3.x=100;
	E->posrep3.y=250;
	E->posrep3.h=100;
	E->posrep3.w=100;
	E->posrep4.x=355;
	E->posrep4.y=250;
	E->posrep4.h=100;
	E->posrep4.w=100;
	E->rzlt.x=0;
	E->rzlt.y=0;
	E->rzlt.h=705;
	E->rzlt.w=1300;
	E->couleurtexte.r = 0;
	E->couleurtexte.g = 0;
	E->couleurtexte.b = 0;

	E->couleur.r = 255;
	E->couleur.g = 255;
	E->couleur.b = 255;
	E->fonttexte=TTF_OpenFont("res/o.ttf",30);
 	E->re3=TTF_RenderText_Solid(E->fonttexte,E->rep1,E->couleurtexte);
 	E->re4=TTF_RenderText_Solid(E->fonttexte,E->rep2,E->couleurtexte);
        E->question=TTF_RenderText_Solid(E->fonttexte,E->eng,E->couleurtexte);


	TTF_Quit();



}


int resolution(enigme *E,SDL_Event event)
{
switch(event.type)
{
case SDL_QUIT:
return 0;
break;
case SDL_MOUSEBUTTONDOWN:
if( event.button.button == SDL_BUTTON_LEFT )
{
if(100<event.button.x&&event.button.x<200)
{if(250<event.button.y&&event.button.y<350)
{
E->reponse=1;
}
}
if(355<event.button.x&&event.button.x<455)
{if(250<event.button.y&&event.button.y<350)
{
E->reponse=0;
}
}
}
break;}

}

void affichage(enigme *E,SDL_Surface *screen)
{


SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));



	SDL_BlitSurface(E->re3, NULL,screen,&E->posrep3);
	SDL_BlitSurface(E->re4, NULL,screen,&E->posrep4);

	SDL_BlitSurface(E->question, NULL,screen,&E->posquestion); 
if(E->random==1){

if(E->reponse==0){
	SDL_BlitSurface(E->no, NULL,screen,&E->rzlt);
}
if(E->reponse==1){
	SDL_BlitSurface(E->yes, NULL,screen,&E->rzlt);
}
}
if(E->random==2){

if(E->reponse==0){
	SDL_BlitSurface(E->yes, NULL,screen,&E->rzlt);
}
if(E->reponse==1){
	SDL_BlitSurface(E->no, NULL,screen,&E->rzlt);
}
}
}


void freesur(enigme *E)
{
TTF_CloseFont(E->fonttexte);
SDL_FreeSurface(E->question);
SDL_FreeSurface(E->re3);
SDL_FreeSurface(E->re4);
SDL_FreeSurface(E->yes);
SDL_FreeSurface(E->no);	
SDL_Quit();
}



