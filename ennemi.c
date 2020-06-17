#include "ennemi.h"


int init_ennemi(Ennemi* E, char* path)
{
	int OK;

	OK = loadEnnemiImages(E, path);
	if (OK != -1)
	{
		initEnnemiAttributes(E);
	}
	
	return OK;
}


int loadEnnemiImages(Ennemi * A, char* path)
{
	A->image = IMG_Load(path);

	if(A->image == NULL) {
		printf("Unable to load Ennemi png:%s\n", SDL_GetError());
		return (-1);
	}
	return (0);
}


void initEnnemiAttributes(Ennemi* E)
{	
	int i, j;	

	E->positionAbsolue.x = 800;
	E->positionAbsolue.y = 300;
	E->positionAbsolue.w = Ennemi_WIDTH;
	E->positionAbsolue.h = Ennemi_HEIGHT;
	
	E->Frame.i = 1;
	E->Frame.j = 0;
	
        // Faire le calcul des SDL_Rect des positions de toutes 
	// les imagettes une seule fois à l'initialisation
	for (i = 0; i < SPRITE_ENNEMI_NbL; i++)
	{	for(j = 0; j < SPRITE_ENNEMI_NbCol; j++)
		{	
			E->positionAnimation[i][j].x = j * Ennemi_WIDTH;
			E->positionAnimation[i][j].y = i * Ennemi_HEIGHT;
			E->positionAnimation[i][j].w = Ennemi_WIDTH;  
			E->positionAnimation[i][j].h = Ennemi_HEIGHT;
		}
	}
	E->Direction = 1;
	E->State = WAITING;
	
}

void display_ennemi(Ennemi *E, SDL_Surface* screen)
{
	SDL_BlitSurface(E->image, &E->positionAnimation[E->Frame.i][E->Frame.j], screen, &E->positionAbsolue);
}

void animateEnnemi(Ennemi* E,int distEH)
{


	// mise a jour du numero de ligne de l'imagette 
	// si l'ennemi n'est pas en train d'attaquer --> ligne = 1

	/* Completer le code ici */
	 switch(E->State)
    	{            
                       
            		
                     
        	
        	        case FOLLOWING :
        	         { 
                        E->Frame.i = 1;
			E->Frame.j ++;    
			if (E->Frame.j == SPRITE_ENNEMI_NbCol)   
		 	E->Frame.j = 0;
                             
                        if(distEH<0)
                        {
                           E->Frame.i = 0;
			E->Frame.j ++;    
			if (E->Frame.j == SPRITE_ENNEMI_NbCol)   
		 	E->Frame.j = 0;
                        } 
                          break;
                         }
                       
	// si l'ennemi est  en train d'attaquer --> ligne = 3

	/* Completer le code ici */
	case ATTACKING :
                      {
                         E->Frame.i = 3;
			E->Frame.j ++;    
			if (E->Frame.j == SPRITE_ENNEMI_NbCol)   
		 	E->Frame.j = 0;
                            
                          if(distEH<0)
                        {
                           E->Frame.i = 2;
			E->Frame.j ++;    
			if (E->Frame.j == SPRITE_ENNEMI_NbCol)   
		 	E->Frame.j = 0;
                        } 
                          break;
                         }
                      }

	 
	// mise a jour du numero de colonne de l'imagette pour avoir l'effet de l'animation
	E->Frame.j ++;    
	if (E->Frame.j == SPRITE_ENNEMI_NbCol)   
		 E->Frame.j = 0;  
	SDL_Delay(50);	
}


void moveEnnemi(Ennemi *E, SDL_Rect posHero)
{
	if (posHero.x<E->positionAbsolue.x) //hero à gauche de l'ennemi
	{
        	E->positionAbsolue.x -= 8; 
	} 
            else 

       if (posHero.x>E->positionAbsolue.x) //hero à droite de l'ennemi
	{
        	E->positionAbsolue.x += 8; 
	}
}

void update_ennemi(Ennemi* E, SDL_Rect posHero)
{
	int distEH = E->positionAbsolue.x - (posHero.x);
	//printf("distEH = %d\t E->State = %d\n", distEH,E->State);
    	switch(E->State)
    	{
        	case WAITING :
        	{
            		animateEnnemi(E,distEH);
            		break;
        	}

        	case FOLLOWING :
        	{
            		animateEnnemi(E,distEH);
            		moveEnnemi(E,posHero);
            		break;
        	}

        	case ATTACKING :
        	{
			// Attaque en se déplaçant vers l'ennemi
		    	animateEnnemi(E,distEH);
			moveEnnemi(E,posHero);
			break;
        	}       
    	}

	updateEnnemiState(E, distEH);	
}


void updateEnnemiState(Ennemi* E, int distEH)
{
	// Selon l'état courant de l'ennemi, implementer les transitions t2, t4 et t6
   	

	/* Completer le code ici */
         if((distEH>400)||(distEH<-400))
             
               E->State= WAITING ;  
             
        else 
           if(((distEH<400)&&(distEH>100))||((distEH>-400)&&(distEH<-100)))
           
             E->State= FOLLOWING ;
           
        else 
           if((distEH<100)||(distEH>-100))
           
             E->State= ATTACKING ;
         
	
}

/*********************************************************/
void freeEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
}
