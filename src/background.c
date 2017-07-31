#include"background.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"gamestate.h"
#include"view.h"
#include"input.h"
#include"math.h"
#include"player.h"
void __Background_init();
void __Background_update(float dt);
void __Background_draw();
void __Background_addStar();
void __Background_delete();
Background background={.starList=NULL,.count=0,.init=&__Background_init,.update=&__Background_update,.draw=&__Background_draw,.addStar=&__Background_addStar,.delete=&__Background_delete};
void __Star_init(Star* this,int _id,int _x,int _y);
void __Star_update(Star* this,float dt);
void __Star_draw(Star* this);
void __Star_delete(Star* this);
void __Background_init()
{
background.starList=__new_List();
for(int i = 0;i<30;i++){
background.addStar();
}}
void __Background_update(float dt)
{
background.starList->forEach(background.starList,&updateStarForEach);
if(input.key[SDL_SCANCODE_Q])background.addStar();}
void __Background_draw()
{
background.starList->forEach(background.starList,&drawStarForEach);}
void __Background_addStar()
{
Star* appStar = __new_Star();
appStar->init(appStar,background.count,view.mx+rand()%gameState.WIDTH-gameState.WIDTH/2,view.my+rand()%gameState.HEIGHT-gameState.HEIGHT/2);
background.starList->add(background.starList,appStar);
background.count++;}
void __Background_delete()
{
background.starList->forEach(background.starList,&deleteStarForEach);
background.starList->delete(background.starList);
free(background.starList);}
Background* __new_Background()
{ 
Background *this = malloc(sizeof(Background));
this->starList = NULL; 
this->count = 0; 
this->init = &__Background_init; 
this->update = &__Background_update; 
this->draw = &__Background_draw; 
this->addStar = &__Background_addStar; 
this->delete = &__Background_delete; 
return this;
} 
Background __crt_Background()
{ 
Background this;
this.starList = NULL; 
this.count = 0; 
this.init = &__Background_init; 
this.update = &__Background_update; 
this.draw = &__Background_draw; 
this.addStar = &__Background_addStar; 
this.delete = &__Background_delete; 
return this;
} 
bool deleteStarForEach(Star* star)
{
star->delete(star);
return true;}
bool updateStarForEach(Star* star)
{
star->update(star,gameState.dt);
return true;}
bool drawStarForEach(Star* star)
{
star->draw(star);
return true;}
void __Star_init(Star* this,int _id,int _x,int _y)
{
this->id=_id;
this->sprite=__new_Sprite();
this->distance=(float)rand()/(float)(RAND_MAX/0.5)+0.5;
this->pos=__new_Vec2d();
this->pos->x=_x;
this->pos->y=_y;
this->dist=__new_Vec2d();
if((this->id%2)==0){
this->sprite->init(this->sprite,"/../res/stars/s1.png",_x,_y,1,1);
}else if((this->id%3)==0){
this->sprite->init(this->sprite,"/../res/stars/s4.png",_x,_y,4,4);
}else{
this->sprite->init(this->sprite,"/../res/stars/s3.png",_x,_y,3,3);
}}
void __Star_update(Star* this,float dt)
{}
void __Star_draw(Star* this)
{
this->sprite->draw(this->sprite);}
void __Star_delete(Star* this)
{
this->sprite->delete(this->sprite);
free(this->sprite);}
Star* __new_Star()
{ 
Star *this = malloc(sizeof(Star));
this->sprite = NULL; 
this->distance = 0.5; 
this->id = 0; 
this->pos = NULL; 
this->dist = NULL; 
this->init = &__Star_init; 
this->update = &__Star_update; 
this->draw = &__Star_draw; 
this->delete = &__Star_delete; 
return this;
} 
Star __crt_Star()
{ 
Star this;
this.sprite = NULL; 
this.distance = 0.5; 
this.id = 0; 
this.pos = NULL; 
this.dist = NULL; 
this.init = &__Star_init; 
this.update = &__Star_update; 
this.draw = &__Star_draw; 
this.delete = &__Star_delete; 
return this;
} 
