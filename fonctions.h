#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "struct.h"
int init();
void pause();
void HP();
void mouvement();
void ennemi();
int affichage(char temps[]);
void scrolling(SDL_Surface *ecran, SDL_Surface *imageDeFond , int continuer, SDL_Rect positionFond, char temps[]);
void init_ecran();
int collision_rec(SDL_Rect* rect1, SDL_Rect* rect2);
int Collision_cer(int x,int y,Cercle C);
int Collision_laby(Laby L,AABB box);
#endif

