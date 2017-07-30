#ifndef view_H
#define view_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
typedef struct View View;
View view;
struct View {
int x; 
int y; 
int mx; 
int my; 
int destX; 
int destY; 
double dx; 
double dy; 
float factor; 
void (*update)(float dt); 
};
View* __new_View();
View __crt_View();
#endif