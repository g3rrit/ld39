#ifndef background_H
#define background_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
#include"gfx.h"
#include"geometry.h"
typedef struct Background Background;
Background background;
typedef struct Star Star;
struct Background {
List* starList; 
int count; 
void (*init)(); 
void (*update)(float dt); 
void (*draw)(); 
void (*addStar)(); 
void (*delete)(); 
};
Background* __new_Background();
Background __crt_Background();
bool deleteStarForEach(Star* star);
bool updateStarForEach(Star* star);
bool drawStarForEach(Star* star);
struct Star {
Sprite* sprite; 
float distance; 
int id; 
Vec2d* pos; 
Vec2d* dist; 
void (*init)(Star* this,int _id,int _x,int _y); 
void (*update)(Star* this,float dt); 
void (*draw)(Star* this); 
void (*delete)(Star* this); 
};
Star* __new_Star();
Star __crt_Star();
#endif