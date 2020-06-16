typedef struct 
{
int vie;
int keys;
int temp;
SDL_Rect menurect;
SDL_Surface * menu;
SDL_Surface * menu1;
int persox;
int persoy;
int camx;
}saved;
void initsave(saved *save );
void save(int vie , int keys,SDL_Event ev,SDL_Surface *screen,saved * save,int time,int x , int y ,int camx);
void save1(int vie , int keys,SDL_Event evv,SDL_Surface *screen,saved * save,int time,int x , int y ,int camx,int vie1 , int keys1,int time1,int x1 , int y1 ,int camx1);
void load(saved *save,SDL_Surface *screen);
void load1(saved *save,saved *save1,SDL_Event ev;);

