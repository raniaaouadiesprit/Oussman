#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"


void initialisePerso(perso * p){
p->score=0;
p->vie=3;
p->direction=0;

p->image=IMG_Load("res/perso.png");
	Uint32 color=SDL_MapRGB(p->image->format, 255, 255, 255);
       SDL_SetColorKey(p->image, SDL_SRCCOLORKEY,color);



p->position.x=0;
p->position.y=200;

p->frame.w=100;
p->frame.h=200;
p->frame.x=0;
p->frame.y=0;

p->curframe=0;
p->running=1;
p->direction=0;
p->previousmvt=0;

p->v_x = 4;
p->v_grav = 0.3;
p->v_saut = -6.5;
p->v_y = p->v_saut;

p->acceleration=0.5;
p->vitesse=0;
p->decelere=-0.5;
p->velocity=0;
}

void initialisePerso2(perso * p){
p->score=0;
p->vie=3;
p->direction=0;

p->image=IMG_Load("res/perso.png");
	Uint32 color=SDL_MapRGB(p->image->format, 255, 255, 255);
       SDL_SetColorKey(p->image, SDL_SRCCOLORKEY,color);



p->position.x=0;
p->position.y=200;

p->frame.w=100;
p->frame.h=200;
p->frame.x=0;
p->frame.y=0;

p->curframe=0;
p->running=1;
p->direction=0;
p->previousmvt=0;

p->v_x = 4;
p->v_grav = 0.3;
p->v_saut = -6.5;
p->v_y = p->v_saut;

p->acceleration=0.5;
p->vitesse=0;
p->decelere=-0.5;
p->velocity=0;
}

void afficherPerso (perso * p,SDL_Surface *screen)
{
	
	
	SDL_BlitSurface(p->image,&p->frame,screen,&p->position);
      
}

void freesurf(SDL_Surface *img,SDL_Surface *img2){
SDL_FreeSurface(img);
SDL_FreeSurface(img2);
}
int moveperso(perso *p ,SDL_Surface* screen,SDL_Event ev)
{  
  if(p->direction != p->previousmvt)
	{
		p->direction=0;
		p->previousmvt = p->direction;
	}
switch(ev.type)
{
case SDL_QUIT:
return p->running =0;
break;

case SDL_KEYDOWN:
 {
switch (ev.key.keysym.sym)
 {
   case SDLK_ESCAPE:
   return p->running =0;
   break;
   case SDLK_s:
    while(p->position.y<200) 
    { 
     p->position.y+=3;
    
    }
     

     break;
   
   case SDLK_d:
   p->position.x+=p->vitesse;
   p->direction=1;
   
  break;
   case SDLK_q:
   p->position.x-=p->vitesse;
   p->direction=2;
   
    break;
   case SDLK_SPACE:
   p->position.y-=2;

    break;
  case SDLK_UP:
       SDL_Delay(10);
       
         p->vitesse+=p->acceleration;
         p->position.x+=p->vitesse;
         p->direction=1;
         if(p->vitesse>=30)
         {
          p->vitesse=30;
         }
            break;
         
              case SDLK_DOWN:
               
                p->vitesse=0;  
               
                break;
                 
                    
                     

 
}

}

}
if(p->position.y<200){
       
   p->position.x += p->v_x;
   p->position.y+= p->v_y;
   p->v_y += p->v_grav;
   
  if (p->position.y> 200)
    p->v_y = p->v_saut;
 
}
}
void animationperso(perso *p ,SDL_Surface* screen){



if(p->direction==1)
{
   p->frame.y=0;
   p->curframe++;
    if(p->curframe>=2)
   {
       p->curframe=0;
   }
       p->frame.x=p->curframe * p->frame.h;  
  

}
else
if(p->direction==2)
{ 
  p->frame.y=200;
 p->curframe++;
    if(p->curframe>=2)
   {
       p->curframe=0;
   }
       p->frame.x=p->curframe * p->frame.h;  
  

}
else 
if(p->direction==0)
{

	p->frame.x=0;
}

}
int collisionBoundingBox(SDL_Rect first,SDL_Rect second)
{
	int collision;
	if ( (first.x + first.w < second.x) || (first.x > second.x + second.w) 
	|| (first.y + first.h < second.y) || (first.y > second.y + second.h) )
		collision=0;
	else 
		collision=1;
	return collision;
}

int dep_souris(perso *p ,SDL_Event ev,int xscrol)
{
switch(ev.type)
{
case SDL_MOUSEBUTTONDOWN:
 {
if( ev.button.button == SDL_BUTTON_RIGHT ){

if(ev.button.x<100)
{
   p->position.x-=10;
break;
}
if((xscrol+ev.button.x)>p->position.x)
{
   p->position.x+=10;
}

    }
break;
}
}
}
/*void sautpersonnage(SDL_Event ev,perso *p){
    int stop=1;
    

if(ev.key.keysym.sym==SDLK_SPACE)
 {
  p->position.x += p->v_x;
  p->position.y+= p->v_y;

// evolution de la vitesse verticale
 p->v_y += p->v_grav;
 }
if (p->position.y> 200)

p->v_y = p->v_saut;
                       

}
void vitessepersonnage(SDL_Event ev,perso *p){
    

switch(ev.key.keysym.sym)
 {
   case SDL_KEYUP:
   {
   case SDLK_UP:
        do{
        SDL_Delay(10);
       
         p->vitesse+=p->decelere;
         p->position.x+=p->vitesse;
         p->direction=1;
           }while( p->vitesse<0);
    break;
   }
 }
}*/
int moveperso2(perso *p ,SDL_Surface* screen,SDL_Event ev)
{  
  if(p->direction != p->previousmvt)
	{
		p->direction=0;
		p->previousmvt = p->direction;
	}
switch(ev.type)
{
case SDL_QUIT:
return p->running =0;
break;

case SDL_KEYDOWN:
 {
switch (ev.key.keysym.sym)
 {
   case SDLK_ESCAPE:
   return p->running =0;
   break;
   case SDLK_l:
    while(p->position.y<200) 
    { 
     p->position.y+=3;
    
    }
     

     break;
   
   case SDLK_m:
   p->position.x+=p->vitesse;
   p->direction=1;
   
  break;
   case SDLK_k:
   p->position.x-=p->vitesse;
   p->direction=2;
   
    break;
   case SDLK_o:
   p->position.y-=2;

    break;
  case SDLK_u:
       SDL_Delay(10);
       
         p->vitesse+=p->acceleration;
         p->position.x+=p->vitesse;
         p->direction=1;
         if(p->vitesse>=30)
         {
          p->vitesse=30;
         }
            break;
         
              case SDLK_j:
               
                p->vitesse=0;  
               
                break;
                 
                    
                     

 
}
   
}

}
if(p->position.y<200){
       
   p->position.x += p->v_x;
   p->position.y+= p->v_y;
   p->v_y += p->v_grav;
   
  if (p->position.y> 200)
    p->v_y = p->v_saut;
 
}
}
