#include"gamestate.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
GameState gameState={.WIDTH=640,.HEIGHT=480,.dt=0};
GameState* __new_GameState()
{ 
GameState *this = malloc(sizeof(GameState));
this->WIDTH = 640; 
this->HEIGHT = 480; 
this->dt = 0; 
return this;
} 
GameState __crt_GameState()
{ 
GameState this;
this.WIDTH = 640; 
this.HEIGHT = 480; 
this.dt = 0; 
return this;
} 
