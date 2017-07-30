#ifndef fontmanager_H
#define fontmanager_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
#include"SDL2/SDL_ttf.h"
#include"geometry.h"
typedef struct FontManager FontManager;
FontManager fontManager;
typedef struct Text Text;
struct FontManager {
Map* fontMap; 
void (*add)(char* id,char* txt,int _x,int _y,int _w,int _h); 
Text* (*get)(char* id); 
void (*setText)(char* id,char* txt); 
void (*remove)(char* id); 
void (*draw)(); 
void (*delete)(); 
};
FontManager* __new_FontManager();
FontManager __crt_FontManager();
struct Text {
char* txt; 
Vec2* pos; 
int w; 
int h; 
SDL_Texture* tex; 
void (*setText)(Text* this,char* txt); 
bool (*draw)(Text* this); 
void (*delete)(Text* this); 
};
Text* __new_Text();
Text __crt_Text();
#endif