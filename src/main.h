#ifndef main_H
#define main_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
#include"SDL2/SDL.h"
#include"SDL2/SDL_image.h"
#include"objectmanager.h"
#include"gamestate.h"
#include"scenemanager.h"
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
bool (*init)(); 
void (*delete)(); 
};
Window* __new_Window();
Window __crt_Window();
SDL_Texture* loadTexture(char* path);
#endif