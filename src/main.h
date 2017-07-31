#ifndef main_H
#define main_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
#include"SDL2/SDL.h"
#include"objectmanager.h"
#include"gamestate.h"
#include"scenemanager.h"
#include"SDL2/SDL_ttf.h"
typedef struct GameContainer GameContainer;
GameContainer gameContainer;
typedef struct Window Window;
Window window;
int main();
struct GameContainer {
void (*start)(); 
void (*stop)(); 
void (*draw)(); 
void (*update)(float dt); 
};
GameContainer* __new_GameContainer();
GameContainer __crt_GameContainer();
struct Window {
SDL_Window* win; 
SDL_Renderer* ren; 
TTF_Font* font; 
bool (*init)(); 
void (*delete)(); 
};
Window* __new_Window();
Window __crt_Window();
char* randStr(uint32_t length);
#endif