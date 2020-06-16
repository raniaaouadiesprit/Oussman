#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "temp.h"

tempss inisaliser_temp_compteur (tempss temp,int diff)
{
if(diff==1)
{
temp.heur1=0;
temp.minute1=0;
temp.seconde1=0;

temp.tempactuel=0;
SDL_Color textcolor={33,33,33};/*couleurNoire = {33, 33, 33},couleurBlanche = {255, 255, 255},violet = {146, 87, 226} */
temp.temp=NULL;

temp.tempprecedent=0;
strcpy(temp.chaine,"");
temp.position_temp.x=200;
temp.position_temp.y=0;
temp.police=TTF_OpenFont("arial.ttf",40);
temp.imgtemp=IMG_Load("img.jpg");
temp.position_imgtemp.x=0;
temp.position_imgtemp.y=0;
temp.maxtemp=300;  
    return temp;
}
else if(diff==2)
{
temp.heur1=0;
temp.minute1=0;
temp.seconde1=0;

temp.tempactuel=0;
SDL_Color textcolor={33, 33, 33} ;  /*couleurNoire = {33, 33, 33}, couleurBlanche = {255, 255, 255}, rose = {85.1, 50.6, 57.3},violet = {146, 87, 226} */
temp.temp=NULL;

temp.tempprecedent=0;
strcpy(temp.chaine,"");
temp.position_temp.x=400;
temp.position_temp.y=0;
temp.police=TTF_OpenFont("arial.ttf",40);
temp.imgtemp=IMG_Load("img.jpg");
temp.position_imgtemp.x=400;
temp.position_imgtemp.y=0;
temp.maxtemp=600;  
    return temp;
}

}

tempss gestion_temps_compteur(int pause_time_disc,int pause_time_pause,tempss temp,SDL_Surface *ecran)
{              
      if((pause_time_disc==0)&&(pause_time_pause==0)&&(temp.maxtemp!=0))     
   {    //      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));   

        temp.tempactuel = SDL_GetTicks();
        if (temp.tempactuel - temp.tempprecedent >=500)
        {

            temp.seconde1 += 1;
           
            if(temp.seconde1 == 60)
            {
               temp.seconde1 = 0;
               temp.minute1+=1;
            }
            if(temp.minute1==60)
            {
               temp.seconde1 =0;
              
               temp.minute1 =0;
               temp.heur1+=1;
            }
            if(temp.heur1==60)
            {
               temp.seconde1 = 0;
               
               temp.minute1 =0;
               temp.heur1=0;

            }

           sprintf(temp.chaine, "%02d : %02d : %02d ",temp.heur1,temp.minute1,temp.seconde1 );
           
           temp.temp = TTF_RenderText_Solid(temp.police, temp.chaine, temp.textcolor);
           temp.tempprecedent=temp.tempactuel;
        }
     
        SDL_BlitSurface(temp.imgtemp, NULL, ecran,&temp.position_imgtemp);   
        SDL_BlitSurface(temp.temp, NULL, ecran, &temp.position_temp);
        SDL_Flip(ecran);
        
    return temp;
  }
return temp;           
}

void free_temps(tempss temp)
{
TTF_CloseFont(temp.police);
TTF_Quit();
SDL_FreeSurface(temp.temp);
SDL_FreeSurface(temp.imgtemp);
printf("free temps => done \n");
}



