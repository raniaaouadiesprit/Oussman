#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "vie.h"

vie init_vie(vie v) 
{

 (v.position.x)=400;
 (v.position.y)=0;
 (v.val)=0 ;
  v.image[0]=IMG_Load("v0.png") ;
 v.image[1]=IMG_Load("v1.png") ;
 v.image[2]=IMG_Load("v2.png") ;
 v.image[3]=IMG_Load("v3.png") ;
 v.image[4]=IMG_Load("v4.png") ;
return v;
}
/*
 int calcul_vie(vie vie,perso *pers,ennemis *E)
{
  int colli=0;
  colli=collision2entite(pers->image,E->fond1,pers->position,E->position);
  if (colli==1)
    {vie.val--;
      pers->position.x-=100;
      E->position.x=E->spawn.x+10;
    }
return v.val;    
}
*/
vie updatevie(vie v,int test,SDL_Surface *ecran) 
{

test=
printf("avant %d v.val ",v.val);
if((test==1 )&& (v.val <4) )
{   (v.val)++;
  printf( " apres %d v.val ",v.val);
	 }
return v;
}

void displayvie(vie v ,SDL_Surface *ecran) 
{
SDL_BlitSurface(v.image[v.val],NULL,ecran,&v.position);
SDL_Flip(ecran);

}

void vie_freevie(vie v ) 
{
SDL_FreeSurface(v.image[0]);
SDL_FreeSurface(v.image[1]);
SDL_FreeSurface(v.image[2]);
SDL_FreeSurface(v.image[3]);
SDL_FreeSurface(v.image[4]);
}
/*
void calcul(vie *vie,perso *pers,ennemis *E)
{
  int colli=0;
  colli=collision2entite(pers->image,E->fond1,pers->position,E->position);
  if (colli==1)
    {vie->nb--;
      pers->position.x=100;
      E->position.x=E->spawn.x+10;
    }
}
*/
/**************************************************/
/* void gestion_vie_score(vie *v,score *s,perso *p,background *b,enemie *e)
{
int c;
c=collision_ennemi(&p,&e,&b,&v,&s);
 if (c!=0)
{
v->nb--;
switch(c)//selon el massa
{
case 1:
{
s->nb-=100;
break;
} //1 collision avec obstacle ennemi

//fazet el msg moins 100 bel a7mer blitsurface w delay
case 2:
{
s->nb-=50; 
break;
}//2 collision avec obstacle
}
if (s<=0)
{v->nb--;}
}

}
*/ 



 			
