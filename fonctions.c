#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fonctions.h"
#include "struct.h"
#include <math.h>
int init(){

     SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
     if ((SDL_Init(SDL_INIT_VIDEO) == -1) || ((SDL_INIT_AUDIO) == -1))
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
        return -1;
    }
    else
        return 0;
}
void pause(){

    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
void HP(){

    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *perso = NULL , *vie1 = NULL, *vie2 = NULL, *vie3 = NULL, *gg = NULL;
    SDL_Rect positionFond, positionperso, pos1, pos2, pos3, go;
int i=0 ;
    positionFond.x = 0;
    positionFond.y = 0;
    positionperso.x=0;
    positionperso.y=0;
    pos1.x=500;
    pos1.y=0;
    pos2.x=500;
    pos2.y=0;
    pos3.x=500;
    pos3.y=0;
    go.x=0;
    go.y=0;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);

    ecran = SDL_SetVideoMode(1000,390,32, SDL_HWSURFACE);

    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

    imageDeFond = IMG_Load("55802425_2113073908778379_3648462241348452352_n.png");

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    perso=IMG_Load("1.png");

    SDL_BlitSurface(perso, NULL, ecran, &positionperso);

    SDL_Flip(ecran);

    gg=IMG_Load("33.png");

    vie1=IMG_Load("Untitled-1.png");
    vie2=IMG_Load("Untitled-2.png");
    vie3=IMG_Load("Untitled-3.png");

    while(i<3){
      if(i==0)
      {
         SDL_BlitSurface(vie3, NULL, ecran, &pos1);
         SDL_Flip(ecran);
         SDL_Delay(1500);
         i++; 
      }
      if(i == 1){
         SDL_BlitSurface(vie2, NULL, ecran, &pos2);
         SDL_Flip(ecran);
         SDL_Delay(1500);
         i++; 
      }
      if(i==2){
        SDL_BlitSurface(vie1, NULL, ecran, &pos3);
        SDL_Flip(ecran);
        SDL_Delay(1500);i++;
      }
    }
      if(i==3)
      {
        SDL_BlitSurface(gg, NULL, ecran, &go) ;
        SDL_Flip(ecran);
        SDL_Delay(1000);
      }

    SDL_Flip(ecran);
    pause();
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(perso); 
    SDL_FreeSurface(vie1);
    SDL_FreeSurface(vie2);
    SDL_FreeSurface(vie3);
    SDL_FreeSurface(gg);
    SDL_Quit();
}
void mouvement(){

    SDL_Surface *ecran = NULL, *zozor = NULL,*fond = NULL;
    SDL_Rect positionZozor, pos;
    SDL_Event event;
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(1000, 390, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption("Gestion des évènements en SDL", NULL);

    fond = IMG_Load("55802425_2113073908778379_3648462241348452352_n.png");

    zozor = IMG_Load("1c.png");

    positionZozor.x = 0;
    positionZozor.y = 260;
    pos.x=0;
    pos.y=0;
    SDL_EnableKeyRepeat(10, 10);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        positionZozor.y--;
                        break;
                    case SDLK_DOWN:
                        positionZozor.y++;
                        break;
                    case SDLK_RIGHT:
                        positionZozor.x++;
                        break;
                    case SDLK_LEFT:
                        positionZozor.x--;
                        break;
                }
                break;
        }


        SDL_BlitSurface(fond,NULL,ecran,&pos);
        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(fond);
    SDL_FreeSurface(zozor);
    SDL_Quit();
}
void ennemi(){
SDL_Surface *ecran = NULL, *imageDeFond = NULL;
    SDL_Rect positionFond, pos;
    SDL_Surface *walk[5], *backk[5];
    int i = 0,j = 0;

    walk[0]=IMG_Load("1.png");
    walk[1]=IMG_Load("2.png");
    walk[2]=IMG_Load("3.png");
    walk[3]=IMG_Load("4.png");
    walk[4]=IMG_Load("5.png");

    backk[0]=IMG_Load("1_b.png");
    backk[1]=IMG_Load("2_b.png");
    backk[2]=IMG_Load("3_b.png");
    backk[3]=IMG_Load("4_b.png");
    backk[4]=IMG_Load("5_b.png");

   int done = 1, k = 0;
    positionFond.x = 0;
    positionFond.y =0;
    pos.x=0;
    pos.y=0;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(1000, 390, 32, SDL_HWSURFACE);

    SDL_WM_SetCaption("SKRRRRRRRRRRRRRRRRRRRRRRT", NULL);

    imageDeFond = IMG_Load("55802425_2113073908778379_3648462241348452352_n.png");

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    SDL_Flip(ecran);

   while(done){

    j = 4;
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_BlitSurface(walk[i], NULL, ecran, &pos);
    SDL_Flip(ecran);
    SDL_Delay(100);
    pos.x += 10;
    i++;

    if(i >= 4){
      i = 0;
    }

    if(pos.x >= 400){

   while(j>=0){

     SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
     SDL_BlitSurface(backk[j], NULL, ecran, &pos);
     SDL_Flip(ecran);
     SDL_Delay(100);
     pos.x -= 10;
     j++;

       if(j>=4){
          j = 0;
       }
   
    
       if(pos.x == 0){
         break;
       }
   }
   }
k++;

/*if(k==2)
{


    done=0;
}*/
   }
    SDL_FreeSurface(imageDeFond);
    SDL_Quit();
}
int affichage (char temps[]){

    SDL_Surface *screen= NULL;
    SDL_Surface *image= NULL;
    SDL_Rect positionecran;
  
    positionecran.x= 0;
    positionecran.y= 0;

    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(1217,701,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    image = IMG_Load (temps);
      if (image == NULL)
      {
         printf("unable to load bitmap: %s \n",SDL_GetError());
         return 1;
      }

     while (image != NULL)
     {
         SDL_BlitSurface (image,NULL,screen,&positionecran);
         SDL_Flip (screen);
     }

  SDL_FreeSurface (image);
  SDL_Quit();
  return 0;
}
void scrolling(SDL_Surface *ecran, SDL_Surface *imageDeFond , int continuer, SDL_Rect positionFond, char temps[])
   {
    positionFond.x = 0;
    positionFond.y = 0;
    positionFond.h =701;
    positionFond.w =1217;
     if(affichage(temps) == 0)
     {
      imageDeFond = IMG_Load(temps);
   
      SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
      SDL_Flip(ecran);
      SDL_Event event;
      SDL_EnableKeyRepeat(10, 10);
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
          case SDL_QUIT:
              continuer = 0;
              break;
          case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
              {
               case SDLK_RIGHT:
                   if  ( positionFond.x<=3651)
                           positionFond.x += 100;

                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
                SDL_Flip(ecran);

                break;

            case SDLK_LEFT:
            	if ( positionFond.x>=0)
                       positionFond.x -= 100;

                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
                SDL_Flip(ecran);

                break;
        }

        break;    
        }
      
    SDL_Flip(ecran);
    }
  }
}
void init_ecran()
{ 
 SDL_Surface *ecran = NULL, *imageDeFond = NULL, *sapin = NULL;
    SDL_Rect positionFond, positionSapin;

    positionFond.x = 0;
    positionFond.y = 0;
    positionSapin.x = 500;
    positionSapin.y = 260;
}
int collision_rec(SDL_Rect* rect1, SDL_Rect* rect2)
{
	if(rect1->y >= rect2->y + rect2->h)
		return 0;
	if(rect1->x >= rect2->x + rect2->w)
		return 0;
	if(rect1->y + rect1->h <= rect2->y)
		return 0;
	if(rect1->x + rect1->w <= rect2->x)
		return 0;
	return 1;
}
int Collision_cer(int x,int y,Cercle C)
{
   int d2 = (x-C.x)*(x-C.x) + (y-C.y)*(y-C.y);
   if (d2>C.rayon*C.rayon)
      return 0;
   else
      return 1;

}
int Collision_laby(Laby L,AABB box)
{
   int xmin,xmax,ymin,ymax;
   int i;
   int j;
   GetPointPosition(L, box.x, box.y, &xmin, &ymin);
   GetPointPosition(L, box.x+box.w-1, box.y+box.h-1, &xmin, &ymin);
   for(i = xmin; i<= xmax; i++)
   {
     for(j = ymin; j<= ymax; j++)
     {
       if ((i != xmin) && (L.Tableau[i][j].murgauche == 1))
          return 1;
       if ((j != ymin) && (L.Tableau[i][j].murhaut == 1))
          return 1;
     }
   }
   return 0;
}


