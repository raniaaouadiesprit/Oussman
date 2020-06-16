typedef struct 
{
SDL_Rect over;
TTF_Font * font;
SDL_Surface *ch;
SDL_Surface *ba;
SDL_Event event;
int pause;
}condition;


void initcond(condition * a) ;
int conditionn(int key , condition* c,int vie,SDL_Surface* screen,int timeTemps,int x);

