#ifndef STRUCT_H
#define STRUCT_H
typedef struct
{
   int x;
   int y;
   int w;
   int h;
}AABB;
typedef struct 
{
   int x,y;
   int rayon;
}Cercle;
typedef struct
{
   int murgauche: 1;
   int murhaut: 1;
}Case;
typedef struct
{
   Case **Tableau;
   int X, Y;
   int LARGEURCASE, HAUTEURCASE;
   int orx, ory;
}Laby;
#endif
