#include"objectmanager.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"gameState.h"
#include"player.h"
#include"background.h"
#include"fontmanager.h"
void __ObjectManager_init();
void __ObjectManager_update(float dt);
void __ObjectManager_draw();
void __ObjectManager_delete();
ObjectManager objectManager={.init=&__ObjectManager_init,.update=&__ObjectManager_update,.draw=&__ObjectManager_draw,.delete=&__ObjectManager_delete};
void __ObjectManager_init()
{
player.init();
background.init();}
void __ObjectManager_update(float dt)
{
player.update(dt);
background.update(dt);}
void __ObjectManager_draw()
{
background.draw();
player.draw();
fontManager.draw();}
void __ObjectManager_delete()
{
background.delete();
player.delete();
fontManager.delete();}
ObjectManager* __new_ObjectManager()
{ 
ObjectManager *this = malloc(sizeof(ObjectManager));
this->init = &__ObjectManager_init; 
this->update = &__ObjectManager_update; 
this->draw = &__ObjectManager_draw; 
this->delete = &__ObjectManager_delete; 
return this;
} 
ObjectManager __crt_ObjectManager()
{ 
ObjectManager this;
this.init = &__ObjectManager_init; 
this.update = &__ObjectManager_update; 
this.draw = &__ObjectManager_draw; 
this.delete = &__ObjectManager_delete; 
return this;
} 
