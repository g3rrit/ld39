#ifndef player_H
#define player_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"geometry.h"
#include"gfx.h"
#include"energy.h"
typedef struct Player Player;
Player player;
typedef struct Bullet Bullet;
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
Energy* energy; 
void (*init)(); 
void (*update)(float dt); 
void (*processInput)(float dt); 
void (*draw)(); 
void (*delete)(); 
};
Player* __new_Player();
Player __crt_Player();
struct Bullet {
Sprite* sprite; 
Vec2d* pos; 
Vec2d* dir; 
double lifeTime; 
double time; 
char* id; 
void (*init)(Bullet* this,double _x,double _y,double xd,double yd,double _angle); 
void (*update)(Bullet* this,float dt); 
void (*draw)(Bullet* this); 
void (*delete)(Bullet* this); 
};
Bullet* __new_Bullet();
Bullet __crt_Bullet();
#endif