#include"input.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"SDL2/SDL.h"
void __Input_update(float dt);
Input input={.mouseX=0,.mouseY=0,.key=NULL,.W=false,.update=&__Input_update};
void __Input_update(float dt)
{
input.key=SDL_GetKeyboardState(NULL);
SDL_GetMouseState(&input.mouseX,&input.mouseY);
if(input.key[SDL_SCANCODE_UP]){
input.W=true;
}else{
input.W=false;
}}
Input* __new_Input()
{ 
Input *this = malloc(sizeof(Input));
this->mouseX = 0; 
this->mouseY = 0; 
this->W = false; 
this->update = &__Input_update; 
return this;
} 
Input __crt_Input()
{ 
Input this;
this.mouseX = 0; 
this.mouseY = 0; 
this.W = false; 
this.update = &__Input_update; 
return this;
} 
