#ifndef player_H
#define player_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"geometry.h"
#include"gfx.h"
typedef struct Player Player;
Player player;
struct Player {
PBody* pbody; 
ASprite* asprite; 
Vec2d* normal; 
double rotation; 
double rotationR; 
double vel; 
int x; 
int y; 
int w; 
int h; 
void (*init)(); 
void (*update)(float dt); 
void (*draw)(); 
void (*delete)(); 
};
Player* __new_Player();
Player __crt_Player();
#endif