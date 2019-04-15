#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include "fonctions.h"
#include "struct.h"
int main(int argc, char *argv[]){
   SDL_Surface ecran;
   SDL_Surface imageDeFond;
   SDL_Rect positionFond;
    if(init == 0){
      while(1){
	mouvement();
	HP();
	ennemi();
	scrolling(&ecran, &imageDeFond, 1, positionFond, "past.png");	


      pause();
      }
    }
    return EXIT_SUCCESS;
}
