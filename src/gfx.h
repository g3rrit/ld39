#ifndef gfx_H
#define gfx_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
#include"SDL2/SDL.h"
#include"SDL2/SDL_image.h"
typedef struct Sprite Sprite;
typedef struct ASprite ASprite;
struct Sprite {
int32_t x; 
int32_t y; 
int32_t w; 
int32_t h; 
double angle; 
SDL_Texture* tex; 
bool (*init)(Sprite* this,char* path,int32_t _x,int32_t _y,int32_t _w,int32_t _h); 
void (*draw)(Sprite* this); 
void (*delete)(Sprite* this); 
};
Sprite* __new_Sprite();
Sprite __crt_Sprite();
struct ASprite {
int32_t x; 
int32_t y; 
int32_t w; 
int32_t h; 
double angle; 
float frameTime; 
float timePassed; 
int activeFrame; 
List* texList; 
SDL_Texture* activeTex; 
bool (*init)(ASprite* this,char* path,int32_t _x,int32_t _y,int32_t _w,int32_t _h); 
bool (*add)(ASprite* this,char* path); 
void (*update)(ASprite* this,float dt); 
void (*draw)(ASprite* this); 
void (*delete)(ASprite* this); 
};
ASprite* __new_ASprite();
ASprite __crt_ASprite();
void drawTexture(SDL_Texture* tex,int32_t _x,int32_t _y,int32_t _w,int32_t _h,double angle);
SDL_Texture* loadTexture(char* path);
#endif