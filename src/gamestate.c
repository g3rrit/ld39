#include"gamestate.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
GameState gameState={.dt=0};
GameState* __new_GameState()
{ 
GameState *this = malloc(sizeof(GameState));
this->dt = 0; 
return this;
} 
GameState __crt_GameState()
{ 
GameState this;
this.dt = 0; 
return this;
} 
