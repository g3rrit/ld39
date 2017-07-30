#ifndef gamestate_H
#define gamestate_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
typedef struct GameState GameState;
GameState gameState;
struct GameState {
float dt; 
};
GameState* __new_GameState();
GameState __crt_GameState();
#endif