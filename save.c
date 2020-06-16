#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "save.h"

void initsave(saved *save ){
save->menu=IMG_Load("res/submenu.jpg");
save->menu1=IMG_Load("res/loula.jpg");
save->menurect.x=0;
save->menurect.y=0;
save->menurect.w=1100;
save->menurect.h=400;
}
void save(int vie , int keys,SDL_Event evv,SDL_Surface *screen,saved * save,int time,int x , int y ,int camx)
{
int cont;
SDL_Event ev;
switch(evv.type)
{
case SDL_KEYDOWN:
 if(evv.key.keysym.sym==SDLK_ESCAPE){
cont=1;
while(cont){
SDL_BlitSurface(save->menu,NULL,screen,&save->menurect);
SDL_Flip(screen);
SDL_PollEvent(&ev);
switch(ev.type)
{case SDL_MOUSEBUTTONDOWN:
if( ev.button.button == SDL_BUTTON_LEFT )
		{
if(260<ev.button.y&&ev.button.y<300)
{if(130<ev.button.x&&ev.button.x<250)
{
cont=0;
    FILE *f;
    f=fopen("save2.txt","w");
        fprintf(f,"%d %d %d %d %d %d",vie, keys,time,x,y,camx);
    fclose(f);
SDL_Delay(500);

}else if(760<ev.button.x&&ev.button.x<880)
{
    FILE *f;
    f=fopen("save2.txt","w");
        fprintf(f, "3 0 0 0 200 0 \n");
    fclose(f);
cont=0;
SDL_Delay(500);

}
}
}
break;
}
}
break;
}

}
}
/*********************************************************/
void save1(int vie , int keys,SDL_Event evv,SDL_Surface *screen,saved * save,int time,int x , int y ,int camx,int vie1 , int keys1,int time1,int x1 , int y1 ,int camx1)
{
int cont;
SDL_Event ev;
switch(evv.type)
{
case SDL_KEYDOWN:
 if(evv.key.keysym.sym==SDLK_ESCAPE){
cont=1;
while(cont){
SDL_BlitSurface(save->menu,NULL,screen,&save->menurect);
SDL_Flip(screen);
SDL_PollEvent(&ev);
switch(ev.type)
{case SDL_MOUSEBUTTONDOWN:
if( ev.button.button == SDL_BUTTON_LEFT )
		{
if(260<ev.button.y&&ev.button.y<300)
{if(130<ev.button.x&&ev.button.x<250)
{
cont=0;
    FILE *f;
    f=fopen("save.txt","w");
        fprintf(f,"%d %d %d %d %d %d",vie, keys,time,x,y,camx);
    f=fopen("save1.txt","w");
        fprintf(f,"%d %d %d %d %d %d",vie1, keys1,time1,x1,y1,camx1);
    fclose(f);
SDL_Delay(500);

}else if(760<ev.button.x&&ev.button.x<880)
{
    FILE *f;
    f=fopen("save.txt","w");
        fprintf(f, "3 0 0 0 200 0 \n");
    f=fopen("save1.txt","w");
        fprintf(f, "3 0 0 0 200 0 \n");
    fclose(f);
cont=0;
SDL_Delay(500);

}
}
}
break;
}
}
break;
}

}
}

/***********************************************************/
void load(saved *save,SDL_Surface *screen)
{

int cont=1;
SDL_Event ev;
while(cont){
SDL_BlitSurface(save->menu1,NULL,screen,&save->menurect);
SDL_Flip(screen);
SDL_PollEvent(&ev);
switch(ev.type)
{case SDL_MOUSEBUTTONDOWN:
if( ev.button.button == SDL_BUTTON_LEFT )
		{

if(280<ev.button.x&&ev.button.x<800)
{if(60<ev.button.y&&ev.button.y<100)
{
cont=0;
        FILE *f;
    f=fopen("save3.txt","r");
    fscanf(f," %d %d %d %d %d %d", &save->vie, &save->keys,&save->temp,&save->persox,&save->persoy,&save->camx);
    fclose(f);


}else if(210<ev.button.y&&ev.button.y<260)
{
    cont=0;
        FILE *f;
    f=fopen("save2.txt","r");
    fscanf(f," %d %d %d %d %d %d", &save->vie, &save->keys,&save->temp,&save->persox,&save->persoy,&save->camx);
    fclose(f);

}
}
}
break;
}
}


}
void load1(saved *save,saved *save1,SDL_Surface *screen)
{


int cont=1;
SDL_Event ev;
while(cont){
SDL_BlitSurface(save->menu1,NULL,screen,&save->menurect);
SDL_Flip(screen);
SDL_PollEvent(&ev);
switch(ev.type)
{case SDL_MOUSEBUTTONDOWN:
if( ev.button.button == SDL_BUTTON_LEFT )
		{

if(280<ev.button.x&&ev.button.x<800)
{if(60<ev.button.y&&ev.button.y<100)
{
cont=0;
    FILE *f;
    f=fopen("save3.txt","r");
    fscanf(f," %d %d %d %d %d %d", &save->vie, &save->keys,&save->temp,&save->persox,&save->persoy,&save->camx);
    f=fopen("save3.txt","r");
    fscanf(f," %d %d %d %d %d %d", &save1->vie, &save1->keys,&save1->temp,&save1->persox,&save1->persoy,&save1->camx);
    fclose(f);


}else if(210<ev.button.y&&ev.button.y<260)
{
    cont=0;
     FILE *f;
    f=fopen("save.txt","r");
    fscanf(f," %d %d %d %d %d %d", &save->vie, &save->keys,&save->temp,&save->persox,&save->persoy,&save->camx);
    f=fopen("save1.txt","r");
    fscanf(f," %d %d %d %d %d %d", &save1->vie, &save1->keys,&save1->temp,&save1->persox,&save1->persoy,&save1->camx);
    fclose(f);


}
}
}
break;
}
}


}
