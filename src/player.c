#include"player.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
#include"input.h"
#include"math.h"
void __Player_init();
void __Player_update(float dt);
void __Player_draw();
void __Player_delete();
Player player={.pbody=NULL,.asprite=NULL,.normal=NULL,.rotation=0,.rotationR=0,.vel=100.0,.x=100,.y=100,.init=&__Player_init,.update=&__Player_update,.draw=&__Player_draw,.delete=&__Player_delete};
void __Player_init()
{
player.normal=__new_Vec2d();
player.pbody=__new_PBody();
player.pbody->pos->x=player.x;
player.pbody->pos->y=player.y;
player.asprite=__new_ASprite();
if(!player.asprite->init(player.asprite,"/../res/ship/ship1.png",0,0,64,64))printf("couldnt init player asprite\n");
if(!player.asprite->add(player.asprite,"/../res/ship/ship2.png"))printf("couldnt add sprite to player\n");}
void __Player_update(float dt)
{
if(input.key[SDL_SCANCODE_W]){
player.pbody->addForce(player.pbody,player.normal);
}
if(input.key[SDL_SCANCODE_A]){
player.rotation-=(double)dt*100;
player.rotationR=toRad(player.rotation);
printf("rotation: %f, rotationR: %f\n",player.rotation,player.rotationR);
player.normal->x=sin(-player.rotationR-M_PI)*player.vel;
player.normal->y=cos(-player.rotationR-M_PI)*player.vel;
}
if(input.key[SDL_SCANCODE_D]){
player.rotation+=(double)dt*100;
player.rotationR=toRad(player.rotation);
printf("rotation: %f, rotationR: %f\n",player.rotation,player.rotationR);
player.normal->x=sin(-player.rotationR-M_PI)*player.vel;
player.normal->y=cos(-player.rotationR-M_PI)*player.vel;
}
player.pbody->update(player.pbody,dt);
player.x=player.pbody->pos->x;
player.y=player.pbody->pos->y;
player.asprite->x=player.x;
player.asprite->y=player.y;
player.asprite->angle=player.rotation;
player.asprite->update(player.asprite,dt);}
void __Player_draw()
{
player.asprite->draw(player.asprite);}
void __Player_delete()
{
free(player.normal);
player.asprite->delete(player.asprite);
free(player.asprite);
player.pbody->delete(player.pbody);
free(player.pbody);}
Player* __new_Player()
{ 
Player *this = malloc(sizeof(Player));
this->pbody = NULL; 
this->asprite = NULL; 
this->normal = NULL; 
this->rotation = 0; 
this->rotationR = 0; 
this->vel = 100.0; 
this->x = 100; 
this->y = 100; 
this->init = &__Player_init; 
this->update = &__Player_update; 
this->draw = &__Player_draw; 
this->delete = &__Player_delete; 
return this;
} 
Player __crt_Player()
{ 
Player this;
this.pbody = NULL; 
this.asprite = NULL; 
this.normal = NULL; 
this.rotation = 0; 
this.rotationR = 0; 
this.vel = 100.0; 
this.x = 100; 
this.y = 100; 
this.init = &__Player_init; 
this.update = &__Player_update; 
this.draw = &__Player_draw; 
this.delete = &__Player_delete; 
return this;
} 
