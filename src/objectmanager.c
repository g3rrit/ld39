#include"objectmanager.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"gameState.h"
#include"player.h"
void __ObjectManager_init();
void __ObjectManager_update(float dt);
void __ObjectManager_draw();
ObjectManager objectManager={.init=&__ObjectManager_init,.update=&__ObjectManager_update,.draw=&__ObjectManager_draw};
void __ObjectManager_init()
{
player.init();}
void __ObjectManager_update(float dt)
{
player.update(dt);}
void __ObjectManager_draw()
{
player.draw();}
ObjectManager* __new_ObjectManager()
{ 
ObjectManager *this = malloc(sizeof(ObjectManager));
this->init = &__ObjectManager_init; 
this->update = &__ObjectManager_update; 
this->draw = &__ObjectManager_draw; 
return this;
} 
ObjectManager __crt_ObjectManager()
{ 
ObjectManager this;
this.init = &__ObjectManager_init; 
this.update = &__ObjectManager_update; 
this.draw = &__ObjectManager_draw; 
return this;
} 
