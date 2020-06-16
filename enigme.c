#include "enigme.h"

void init_enigme(enigme *e)
{
       TTF_Init();
	e->police = TTF_OpenFont("res/beauty.ttf", 50);
	

	SDL_Color couleureNoire ={0,0,0};

	e->questions.texteQ = TTF_RenderText_Blended (e->police,"what is the gaz that causes climate change?", couleureNoire) ;
	e->questions.texteR = TTF_RenderText_Blended (e->police, "1- azote    2-oxygene    3-CO2", couleureNoire) ;

	
	
	e->posTF.x=50;
	e->posTF.y=30;
	TTF_Quit();
}
