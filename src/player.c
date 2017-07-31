#include"player.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
#include"input.h"
#include"math.h"
#include"view.h"
#include"objectmanager.h"
void __Player_init();
void __Player_update(float dt);
void __Player_processInput(float dt);
void __Player_draw();
void __Player_delete();
Player player={.pbody=NULL,.asprite=NULL,.normal=NULL,.rotation=0,.rotationR=0,.vel=100.0,.x=100,.y=100,.w=32,.h=32,.energy=NULL,.init=&__Player_init,.update=&__Player_update,.processInput=&__Player_processInput,.draw=&__Player_draw,.delete=&__Player_delete};
void __Bullet_init(Bullet* this,double _x,double _y,double xd,double yd,double _angle);
void __Bullet_update(Bullet* this,float dt);
void __Bullet_draw(Bullet* this);
void __Bullet_delete(Bullet* this);
void __Player_init()
{
player.normal=__new_Vec2d();
player.pbody=__new_PBody();
player.pbody->pos->x=player.x;
player.pbody->pos->y=player.y;
player.asprite=__new_ASprite();
if(!player.asprite->init(player.asprite,"/../res/ship/ship1.png",0,0,player.w,player.h))printf("couldnt init player asprite\n");
if(!player.asprite->add(player.asprite,"/../res/ship/ship2.png"))printf("couldnt add sprite to player\n");
player.energy=__new_Energy();
player.energy->init(player.energy);}
void __Player_update(float dt)
{
player.processInput(dt);
player.pbody->update(player.pbody,dt);
player.x=player.pbody->pos->x;
player.y=player.pbody->pos->y;
player.asprite->x=player.x-player.w/2;
player.asprite->y=player.y-player.h/2;
player.asprite->angle=player.rotation;
player.asprite->update(player.asprite,dt);
view.destX=player.x;
view.destY=player.y;
player.energy->update(player.energy,dt);}
void __Player_processInput(float dt)
{
if(input.key[SDL_SCANCODE_W]){
player.pbody->addForce(player.pbody,player.normal);
}
if(input.key[SDL_SCANCODE_A]){
player.rotation-=(double)dt*100;
player.rotationR=toRad(player.rotation);
player.normal->x=sin(-player.rotationR-M_PI)*player.vel;
player.normal->y=cos(-player.rotationR-M_PI)*player.vel;
}
if(input.key[SDL_SCANCODE_D]){
player.rotation+=(double)dt*100;
player.rotationR=toRad(player.rotation);
player.normal->x=sin(-player.rotationR-M_PI)*player.vel;
player.normal->y=cos(-player.rotationR-M_PI)*player.vel;
}
if(input.key[SDL_SCANCODE_SPACE]){
Bullet* appBullet = __new_Bullet();
appBullet->init(appBullet,player.x,player.y,player.normal->x,player.normal->y,player.rotation);
}}
void __Player_draw()
{
player.asprite->draw(player.asprite);
player.energy->draw(player.energy);}
void __Player_delete()
{
free(player.normal);
player.asprite->delete(player.asprite);
free(player.asprite);
player.pbody->delete(player.pbody);
free(player.pbody);
player.energy->delete(player.energy);
free(player.energy);}
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
this->w = 32; 
this->h = 32; 
this->energy = NULL; 
this->init = &__Player_init; 
this->update = &__Player_update; 
this->processInput = &__Player_processInput; 
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
this.w = 32; 
this.h = 32; 
this.energy = NULL; 
this.init = &__Player_init; 
this.update = &__Player_update; 
this.processInput = &__Player_processInput; 
this.draw = &__Player_draw; 
this.delete = &__Player_delete; 
return this;
} 
void __Bullet_init(Bullet* this,double _x,double _y,double xd,double yd,double _angle)
{
this->id=randStr(20);
this->pos->x=_x;
this->pos->y=_y;
this->dir->x=xd;
this->dir->y=yd;
this->sprite=__new_Sprite();
this->sprite->init(this->sprite,"/../res/ship/shot.png",_x,_y,2,4);
this->sprite->angle=_angle;
objectManager.addObject(this,this->id);}
void __Bullet_update(Bullet* this,float dt)
{
this->pos->x=this->dir->x*dt;
this->pos->y=this->dir->y*dt;
this->sprite->x=this->pos->x;
this->sprite->y=this->pos->y;
this->time+=dt;
if(this->time>=this->lifeTime){
this->delete(this);
}}
void __Bullet_draw(Bullet* this)
{
this->sprite->draw(this->sprite);}
void __Bullet_delete(Bullet* this)
{
this->sprite->delete(this->sprite);
free(this->sprite);
free(this->pos);
free(this->dir);
char* tempID = this->id;
objectManager.removeObject(this->id);
free(tempID);}
Bullet* __new_Bullet()
{ 
Bullet *this = malloc(sizeof(Bullet));
this->sprite = NULL; 
this->pos = __new_Vec2d(); 
this->dir = __new_Vec2d(); 
this->lifeTime = 5; 
this->time = 0; 
this->init = &__Bullet_init; 
this->update = &__Bullet_update; 
this->draw = &__Bullet_draw; 
this->delete = &__Bullet_delete; 
return this;
} 
Bullet __crt_Bullet()
{ 
Bullet this;
this.sprite = NULL; 
this.pos = __new_Vec2d(); 
this.dir = __new_Vec2d(); 
this.lifeTime = 5; 
this.time = 0; 
this.init = &__Bullet_init; 
this.update = &__Bullet_update; 
this.draw = &__Bullet_draw; 
this.delete = &__Bullet_delete; 
return this;
} 
