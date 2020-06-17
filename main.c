/**
* @file main.c
* @brief Integration Finale
* @author Yosri Ghaba
* @version Final
* @date Juin 16, 2020
*
* *main Functions
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include<time.h>
#include <string.h>
#include "perso.h"
#include "entity.h"
#include "gestion.h"
#include "scrol.h"
#include "ennemi.h"
#include "work.h"
#include "gestiontemp.h"
#include "save.h"
#include "enigme.h"
#include "condition.h"
#include "menu.h"
#include "mode.h"

#define LARGEUR 1100
#define HAUTEUR 400
//declaration SDL
SDL_Surface* screen=NULL;
SDL_Rect screenrect={0,0,0,0};
SDL_Surface* screen1=NULL;
SDL_Rect screenrect1={0,0,0,0};
SDL_Surface* backg=NULL;
SDL_Surface* backg1=NULL;
SDL_Surface* backg4=NULL;
SDL_Rect backgrect4={0,0,0,0};
SDL_Rect backgrect={0,0,550,400};
SDL_Rect backgrect1={570,0,550,400};
SDL_Surface* tmp=NULL;
SDL_Surface* tmp1=NULL;
SDL_Event ev;
SDL_Event ev2;


int main(int argc, char** argv)
{

//Declaration
mini e;
mini e2;

perso p;
perso p2;

entity es;
entity es1;

scr s;
scr s2;
//gestion score
gestion a;
gestion a2;

temp tempp;

Ennemi ennemi;
Ennemi ennemi1;

saved savee;
saved savee1;

enigme enig;

condition cond;
menu men;
mode modee;
SDL_Event event;
	SDL_Surface *rotation;
	double angle;
    	double zoom ;
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
int now=0;
int ex=0;
int pfps=33;
int dt=0;
int test=0;
int test1=0;
int test2=0;
int test3=0;
int posy;
int testp=1;
int running;

int ie,x=0,x1=550,y=20;
char path_ennemi [500] = "res/ennemi_spr.png";
char path1 [500] = "res/perso1.png";
char path [500] = "res/perso.png";

screen=SDL_SetVideoMode(LARGEUR,HAUTEUR,bpp,SDL_HWSURFACE);
SDL_WM_SetCaption("Oussman Game",NULL);
init_menu(&men);
afficher_menu(screen,&men);
//background
tmp=IMG_Load("res/gamebackg.png");

if(men.mode==2)
{
backg=SDL_DisplayFormat(tmp);
backg1=SDL_DisplayFormat(tmp);
//SDL_FreeSurface(tmp);

//SDL_GetClipRect(backg,&backgrect);
SDL_SetClipRect(backg,&backgrect);
SDL_SetClipRect(backg1,&backgrect1);
//inti
backg4=IMG_Load("res/background.jpg");
SDL_GetClipRect(backg4,&backgrect4);

ie = init_ennemi(&ennemi, path_ennemi);
ie = init_ennemi(&ennemi1, path_ennemi);

init_temp(&tempp);

//initmode(&modee );
//modegame1(screen,&modee);

initcond(&cond);

init_positions(&e,x,y);
init_positions1(&e2,x1,y);

initialisePerso(&p,path);

initialisePerso2(&p2,path1);
initsave(&savee);
load1(&savee,&savee1,screen);

p.vie=savee.vie;
p.score=savee.keys;
p.position.x=savee.persox;
p.position.y=savee.persoy;
s.camera.x=savee.camx;
tempp.timeTemps=savee.temp;

p2.vie=savee1.vie;
p2.score=savee1.keys;
p2.position.x=savee1.persox;
p2.position.y=savee1.persoy;
s2.camera.x=savee1.camx;
tempp.timeTemps=savee1.temp;

init_affich(&e,screen);
init_affich(&e2,screen);



initialise_entity(&es,1000,200);
initialise_entity(&es1,1000,200);

initgestiondeviescore(&a);
initgestiondeviescore2(&a2);

initscrol(&s);
initscrol(&s2);
//boucle Game.x
while(p.running)
{
now=SDL_GetTicks();
tempp.timeTemps=savee1.temp+now;
dt=now-ex;
backg=SDL_DisplayFormat(tmp);
backg1=SDL_DisplayFormat(tmp);
if(dt>=pfps)
{


//affichage
SDL_PollEvent(&ev2);
afficherPerso (&p,backg);
display_ennemi(&ennemi,backg);
display_ennemi(&ennemi1,backg1);
SDL_BlitSurface(p2.image,&p2.frame,backg1,&p2.position);
/**/
afficherPerso (&p2,backg1);

afficher_entity(&es,backg,&backgrect);
afficher_entity(&es1,backg1,&backgrect1);

update_ennemi(&ennemi, p.position);
update_ennemi(&ennemi1, p2.position);

scrolling(&s,screen,backg,p.position.x,backgrect);
scrolling(&s2,screen,backg1,p2.position.x,backgrect1);


p.running=moveperso2(&p2 ,screen,ev2);
p.running=moveperso(&p ,screen,ev2);

save1(p.vie,p.score,ev2,screen,&savee,tempp.timeTemps,p.position.x , p.position.y ,s.camera.x,p2.vie,p2.score,tempp.timeTemps,p2.position.x , p2.position.y ,s2.camera.x);
dep_souris(&p ,ev2,s.camera.x);
animationperso(&p ,screen);
animationperso(&p2 ,screen);

deplacement_alea_ennemi(&es);
deplacement_alea_ennemi(&es1);

gestiondevieetscore(&a,p.vie ,p.score ,screen);
gestiondevieetscore(&a2,p2.vie ,p2.score ,screen);
/*minimap*/
key_event (&e,screen,p.position.x);
key_event1 (&e2,screen,p2.position.x);
/*minimap*/
conditionn(p.score,&cond,p.vie,screen,tempp.timeTemps,&p.running);
conditionn(p2.score,&cond,p2.vie,screen,tempp.timeTemps,&p.running);

test=collisionBoundingBox(p.position,es.position);

animationentity(&es ,screen);
//sautpersonnage(ev,&p);

printf("x= %d x1=%d\n",p2.position.x,p.position.x);
/***************************enigme1*********************/
if(test==1)
{

running=1;
angle = 200;
zoom = 0;

while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}



//background





generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);

affichage(&enig,screen,&p.vie,&p.score);
SDL_Delay(35);
SDL_Flip(screen);

}


if(enig.falsee==1){
p.vie--;
}
else
if(enig.truee==1){
p.score++;
}
p.position.x+=700;
}
/***************************enigme1*********************/
test1=collisionBoundingBox(p.position,ennemi.positionAbsolue);

/***************************enigme2*********************/

if(test1==1)
{

running=1;
angle = 200;
zoom = 0;
while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}
generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);
affichage(&enig,screen,&p.vie,&p.score);
SDL_Delay(35);
SDL_Flip(screen);

}


if(enig.falsee==1){
p.vie--;
}
else
if(enig.truee==1){
p.score++;
}
p.position.x+=700;
}
/***************************enigme2*********************/
/***************************enigme3*********************/

if(p.position.x>3850)
{


running=1;
angle = 200;
zoom = 0;
while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}

generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);
affichage(&enig,screen,&p.vie,&p.score);
SDL_Delay(35);
SDL_Flip(screen);

}


if(enig.falsee==1){
p.vie--;
}
else
if(enig.truee==1){
p.score++;
}

p.position.x=3800;
}
/***************************enigme3*********************/
test2=collisionBoundingBox(p2.position,es1.position);
/***************************enigme4*********************/
if(test2==1)
{

running=1;
angle = 200;
zoom = 0;

while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}



//background





generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);

affichage(&enig,screen,&p2.vie,&p2.score);
SDL_Delay(35);
SDL_Flip(screen);

}


if(enig.falsee==1){
p2.vie--;
}
else
if(enig.truee==1){
p2.score++;
}
p2.position.x+=700;
}
/***************************enigme4*********************/
test3=collisionBoundingBox(p2.position,ennemi1.positionAbsolue);
/***************************enigme5*********************/
if(test3==1)
{

running=1;
angle = 200;
zoom = 0;

while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}



//background





generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);

affichage(&enig,screen,&p2.vie,&p2.score);
SDL_Delay(35);
SDL_Flip(screen);

}


if(enig.falsee==1){
p2.vie--;
}
else
if(enig.truee==1){
p2.score++;
}
p2.position.x+=700;
}
/***************************enigme5*********************/
/***************************enigme6*********************/

if(p2.position.x>3850)
{


running=1;
angle = 200;
zoom = 0;
while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}

generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);
affichage(&enig,screen,&p2.vie,&p2.score);
SDL_Delay(35);
SDL_Flip(screen);

}


if(enig.falsee==1){
p2.vie--;
}
else
if(enig.truee==1){
p2.score++;
}

p2.position.x=3800;
}
/***************************enigme6*********************/

gestion_temp(&tempp,screen);

//display #ALL
SDL_Flip(screen);
SDL_FreeSurface(backg);
SDL_FreeSurface(backg1);

}
else
 SDL_Delay(pfps-dt);
}
}
else
if(men.mode==3)
{
backg=SDL_DisplayFormat(tmp);
backg1=SDL_DisplayFormat(tmp);
//SDL_FreeSurface(tmp);

//SDL_GetClipRect(backg,&backgrect);
SDL_SetClipRect(backg,&backgrect);
SDL_SetClipRect(backg1,&backgrect1);
//inti
backg4=IMG_Load("res/background.jpg");
SDL_GetClipRect(backg4,&backgrect4);

ie = init_ennemi(&ennemi, path_ennemi);
ie = init_ennemi(&ennemi1, path_ennemi);

init_temp(&tempp);

initcond(&cond);

init_positions(&e,x,y);
init_positions1(&e2,x1,y);

initialisePerso(&p,path);
initialisePerso2(&p2,path);

initsave(&savee);
load1(&savee,&savee1,screen);

p.vie=savee.vie;
p.score=savee.keys;
p.position.x=savee.persox;
p.position.y=savee.persoy;
s.camera.x=savee.camx;
tempp.timeTemps=savee.temp;

p2.vie=savee1.vie;
p2.score=savee1.keys;
p2.position.x=savee1.persox;
p2.position.y=savee1.persoy;
s2.camera.x=savee1.camx;
tempp.timeTemps=savee1.temp;

init_affich(&e,screen);
init_affich(&e2,screen);



initialise_entity(&es,1000,200);
initialise_entity(&es1,1000,200);

initgestiondeviescore(&a);
initgestiondeviescore2(&a2);
r
initscrol(&s);
initscrol(&s2);
//boucle Game.x
while(p.running)
{
now=SDL_GetTicks();
tempp.timeTemps=savee1.temp+now;
dt=now-ex;
backg=SDL_DisplayFormat(tmp);
backg1=SDL_DisplayFormat(tmp);
if(dt>=pfps)
{


//affichage
SDL_PollEvent(&ev2);
afficherPerso (&p,backg);
display_ennemi(&ennemi,backg);
display_ennemi(&ennemi1,backg1);
SDL_BlitSurface(p2.image,&p2.frame,backg1,&p2.position);

afficherPerso (&p2,backg1);
afficher_entity(&es,backg,&backgrect);
afficher_entity(&es1,backg1,&backgrect1);

update_ennemi(&ennemi, p.position);
update_ennemi(&ennemi1, p2.position);

scrolling(&s,screen,backg,p.position.x,backgrect);
scrolling(&s2,screen,backg1,p2.position.x,backgrect1);
p2.direction=1;
if(men.dif==1){
p2.position.x+=2;
}
else
if(men.dif==2)
{
p2.position.x+=6;
}
else
if(men.dif==3){
p2.position.x+=10;
}
p.running=moveperso(&p ,screen,ev2);

save1(p.vie,p.score,ev2,screen,&savee,tempp.timeTemps,p.position.x , p.position.y ,s.camera.x,p2.vie,p2.score,tempp.timeTemps,p2.position.x , p2.position.y ,s2.camera.x);

animationperso(&p ,screen);
animationperso(&p2 ,screen);

deplacement_alea_ennemi(&es);
deplacement_alea_ennemi(&es1);

gestiondevieetscore(&a,p.vie ,p.score ,screen);
gestiondevieetscore(&a2,p2.vie ,p2.score ,screen);

key_event (&e,screen,p.position.x);
key_event1 (&e2,screen,p2.position.x);
conditionn(p.score,&cond,p.vie,screen,tempp.timeTemps,&p.running);
conditionn(p2.score,&cond,p2.vie,screen,tempp.timeTemps,&p.running);

test=collisionBoundingBox(p.position,es.position);
dep_souris(&p ,ev,s.camera.x);
animationentity(&es ,screen);
//sautpersonnage(ev,&p);

printf("x= %d x1=%d\n",p2.position.x,p.position.x);
/***************************enigme1*********************/
if(test==1)
{

running=1;
angle = 200;
zoom = 0;

while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}



//background





generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);

affichage(&enig,screen,&p.vie,&p.score);
SDL_Delay(35);
SDL_Flip(screen);

}


if(enig.falsee==1){
p.vie--;
}
else
if(enig.truee==1){
p.score++;
}
p.position.x+=700;
}
/***************************enigme1*********************/
test1=collisionBoundingBox(p.position,ennemi.positionAbsolue);

/***************************enigme2*********************/

if(test1==1)
{

running=1;
angle = 200;
zoom = 0;
while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}
generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);
affichage(&enig,screen,&p.vie,&p.score);
SDL_Delay(35);
SDL_Flip(screen);

}


if(enig.falsee==1){
p.vie--;
}
else
if(enig.truee==1){
p.score++;
}
p.position.x+=700;
}
/***************************enigme2*********************/
/***************************enigme3*********************/

if(p.position.x>3850)
{


running=1;
angle = 200;
zoom = 0;
while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}

generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);
affichage(&enig,screen,&p.vie,&p.score);
SDL_Delay(35);
SDL_Flip(screen);

}


if(enig.falsee==1){
p.vie--;
}
else
if(enig.truee==1){
p.score++;
}

p.position.x=3800;
}
/***************************enigme3*********************/
test2=collisionBoundingBox(p2.position,es1.position);
/***************************enigme4*********************/
if(test2==1)
{
generation_question(&enig,men.dif);
init_enigme(&enig);


enig.reponse=rand() %1+0;
affichage(&enig,screen,&p2.vie,&p2.score);

if(enig.falsee==1){
p2.vie--;
}
else
if(enig.truee==1){
p2.score++;
}
p2.position.x+=700;
}
/***************************enigme4*********************/
test3=collisionBoundingBox(p2.position,ennemi1.positionAbsolue);
/***************************enigme5*********************/
if(test3==1)
{

generation_question(&enig,men.dif);
init_enigme(&enig);


enig.reponse=rand() %1+0;
affichage(&enig,screen,&p2.vie,&p2.score);

if(enig.falsee==1){
p2.vie--;
}
else
if(enig.truee==1){
p2.score++;
}
p2.position.x+=700;
}
/***************************enigme5*********************/
/***************************enigme6*********************/

if(p2.position.x>3850)
{


generation_question(&enig,men.dif);
init_enigme(&enig);


enig.reponse=rand() %1+0;;
affichage(&enig,screen,&p2.vie,&p2.score);

if(enig.falsee==1){
p2.vie--;
}
else
if(enig.truee==1){
p2.score++;
}

p2.position.x=3800;
}
/***************************enigme6*********************/

gestion_temp(&tempp,screen);

//display #ALL
SDL_Flip(screen);
SDL_FreeSurface(backg);
SDL_FreeSurface(backg1);

}
else
 SDL_Delay(pfps-dt);
}
}
else
if(men.mode==1)
{
/************************************************SOLOOOOOOOOOOOOOOOOOOO***************************************************************/
/************************************************SOLOOOOOOOOOOOOOOOOOOO***************************************************************/
/************************************************SOLOOOOOOOOOOOOOOOOOOO***************************************************************/
/************************************************SOLOOOOOOOOOOOOOOOOOOO***************************************************************/
backg=SDL_DisplayFormat(tmp);

//SDL_FreeSurface(tmp);


SDL_GetClipRect(backg,&backgrect);

//inti
backg4=IMG_Load("res/background.jpg");
SDL_GetClipRect(backg4,&backgrect4);
ie = init_ennemi(&ennemi, path_ennemi);
initsave(&savee);
initialisePerso(&p,path);
load(&savee,screen);
p.vie=savee.vie;
p.score=savee.keys;
p.position.x=savee.persox;
p.position.y=savee.persoy;
s.camera.x=savee.camx;
tempp.timeTemps=savee.temp;

init_positions(&e,x,y);
init_affich(&e,screen);



init_temp(&tempp);

initialise_entity(&es,1000,200);

initgestiondeviescore(&a);


initscrol(&s);

//boucle Game.x
while(p.running)
{
now=SDL_GetTicks();
tempp.timeTemps=savee.temp+now;
dt=now-ex;
backg=SDL_DisplayFormat(tmp);

if(dt>=pfps)
{


//affichage
SDL_PollEvent(&ev2);
afficherPerso (&p,backg);
display_ennemi(&ennemi,backg);

afficher_entity(&es,backg,&backgrect);
p.running=moveperso(&p ,screen,ev2);



update_ennemi(&ennemi, p.position);
scrolling(&s,screen,backg,p.position.x,backgrect);


save(p.vie,p.score,ev2,screen,&savee,tempp.timeTemps,p.position.x,p.position.y,s.camera.x);




animationperso(&p ,screen);


deplacement_alea_ennemi(&es);

gestiondevieetscore(&a,p.vie ,p.score ,screen);
key_event (&e,screen,p.position.x);
conditionn(p.score,&cond,p.vie,screen,tempp.timeTemps,&p.running);

test=collisionBoundingBox(p.position,es.position);

dep_souris(&p ,ev,s.camera.x);
animationentity(&es ,screen);
//sautpersonnage(ev,&p);

printf("x= %d x1=%d\n",p2.position.x,p.position.x);
/***************************enigme1*********************/
if(test==1)
{

running=1;
angle = 200;
zoom = 0;

while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}



//background





generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);

affichage(&enig,screen,&p.vie,&p.score);
SDL_Delay(35);
SDL_Flip(screen);

}


if(enig.falsee==1){
p.vie--;
}
else
if(enig.truee==1){
p.score++;
}
p.position.x+=700;
}
/***************************enigme1*********************/
test1=collisionBoundingBox(p.position,ennemi.positionAbsolue);

/***************************enigme2*********************/

if(test1==1)
{

running=1;
angle = 200;
zoom = 0;
while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}
generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);
affichage(&enig,screen,&p.vie,&p.score);
SDL_Delay(50);
SDL_Flip(screen);

}


if(enig.falsee==1){
p.vie--;
}
else
if(enig.truee==1){
p.score++;
}
p.position.x+=700;
}
/***************************enigme2*********************/
/***************************enigme3*********************/

if(p.position.x>3260)
{


running=1;
angle = 200;
zoom = 0;
while(zoom<1 || angle >0)
	{
		angle-=4;
		zoom+=0.02;
		rotation = rotozoomSurface(backg4, angle, zoom, 0);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(rotation,NULL,screen,NULL);
		SDL_FreeSurface(rotation);
		SDL_Delay(50);
		SDL_Flip(screen);
	}

generation_question(&enig,men.dif);
init_enigme(&enig);


while(running)
{

SDL_PollEvent(&event);
SDL_BlitSurface(backg4,NULL,screen,&backgrect4);

running=resolution(&enig,event);
affichage(&enig,screen,&p.vie,&p.score);
SDL_Delay(35);
SDL_Flip(screen);

}


if(enig.falsee==1){
p.vie--;
}
else
if(enig.truee==1){
p.score++;
}

p.position.x=3170;
}
/***************************enigme3*********************/
gestion_temp(&tempp ,screen);

//display #ALL
SDL_Flip(screen);
SDL_FreeSurface(backg);
SDL_FreeSurface(backg1);

}

else
 SDL_Delay(pfps-dt);
}



/***************************************************************************************************************/

}
//#FREE!!!!!!!!!!!!!!!
SDL_FreeSurface(p.image);
//freeEnnemi(&ennemi);




SDL_Quit();
return 0;
}

