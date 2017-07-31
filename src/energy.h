#ifndef energy_H
#define energy_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
#include"SDL2/SDL.h"
typedef struct Energy Energy;
struct Energy {
int maxEnergy; 
int currentEnergy; 
double displayEnergy; 
SDL_Rect displayR; 
SDL_Rect rect; 
int maxWidth; 
void (*init)(Energy* this); 
void (*update)(Energy* this,float dt); 
void (*draw)(Energy* this); 
void (*delete)(Energy* this); 
};
Energy* __new_Energy();
Energy __crt_Energy();
#endif