#include"gfx.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"main.h"
#include"view.h"
bool __Sprite_init(Sprite* this,char* path,int32_t _x,int32_t _y,int32_t _w,int32_t _h);
void __Sprite_draw(Sprite* this);
void __Sprite_delete(Sprite* this);
bool __ASprite_init(ASprite* this,char* path,int32_t _x,int32_t _y,int32_t _w,int32_t _h);
bool __ASprite_add(ASprite* this,char* path);
void __ASprite_update(ASprite* this,float dt);
void __ASprite_draw(ASprite* this);
void __ASprite_delete(ASprite* this);
bool __Sprite_init(Sprite* this,char* path,int32_t _x,int32_t _y,int32_t _w,int32_t _h)
{
this->tex=loadTexture(path);
if(!this->tex)return false;
this->x=_x;
this->y=_y;
this->w=_w;
this->h=_h;
return true;}
void __Sprite_draw(Sprite* this)
{
drawTexture(this->tex,this->x,this->y,this->w,this->h,this->angle);}
void __Sprite_delete(Sprite* this)
{
SDL_DestroyTexture(this->tex);}
Sprite* __new_Sprite()
{ 
Sprite *this = malloc(sizeof(Sprite));
this->x = 0; 
this->y = 0; 
this->w = 0; 
this->h = 0; 
this->angle = 0; 
this->tex = NULL; 
this->init = &__Sprite_init; 
this->draw = &__Sprite_draw; 
this->delete = &__Sprite_delete; 
return this;
} 
Sprite __crt_Sprite()
{ 
Sprite this;
this.x = 0; 
this.y = 0; 
this.w = 0; 
this.h = 0; 
this.angle = 0; 
this.tex = NULL; 
this.init = &__Sprite_init; 
this.draw = &__Sprite_draw; 
this.delete = &__Sprite_delete; 
return this;
} 
bool __ASprite_init(ASprite* this,char* path,int32_t _x,int32_t _y,int32_t _w,int32_t _h)
{
this->activeTex=loadTexture(path);
if(!this->activeTex)return false;
this->texList=__new_List();
this->texList->add(this->texList,this->activeTex);
this->x=_x;
this->y=_y;
this->w=_w;
this->h=_h;
return true;}
bool __ASprite_add(ASprite* this,char* path)
{
SDL_Texture* tempTex = loadTexture(path);
if(!tempTex)return false;
this->texList->add(this->texList,tempTex);
return true;}
void __ASprite_update(ASprite* this,float dt)
{
this->timePassed+=dt;
if(this->timePassed>=this->frameTime){
this->timePassed-=this->frameTime;
this->activeFrame++;
if(this->activeFrame>=this->texList->size)this->activeFrame=0;
this->activeTex=this->texList->get(this->texList,this->activeFrame);
}}
void __ASprite_draw(ASprite* this)
{
drawTexture(this->activeTex,this->x,this->y,this->w,this->h,this->angle);}
void __ASprite_delete(ASprite* this)
{
this->texList->delete(this->texList);
free(this->texList);}
ASprite* __new_ASprite()
{ 
ASprite *this = malloc(sizeof(ASprite));
this->x = 0; 
this->y = 0; 
this->w = 0; 
this->h = 0; 
this->angle = 0; 
this->frameTime = 0.1; 
this->timePassed = 0; 
this->activeFrame = 0; 
this->texList = NULL; 
this->activeTex = NULL; 
this->init = &__ASprite_init; 
this->add = &__ASprite_add; 
this->update = &__ASprite_update; 
this->draw = &__ASprite_draw; 
this->delete = &__ASprite_delete; 
return this;
} 
ASprite __crt_ASprite()
{ 
ASprite this;
this.x = 0; 
this.y = 0; 
this.w = 0; 
this.h = 0; 
this.angle = 0; 
this.frameTime = 0.1; 
this.timePassed = 0; 
this.activeFrame = 0; 
this.texList = NULL; 
this.activeTex = NULL; 
this.init = &__ASprite_init; 
this.add = &__ASprite_add; 
this.update = &__ASprite_update; 
this.draw = &__ASprite_draw; 
this.delete = &__ASprite_delete; 
return this;
} 
void drawTexture(SDL_Texture* tex,int32_t _x,int32_t _y,int32_t _w,int32_t _h,double angle)
{
int xres = _x-view.x;
int yres = _y-view.y;
SDL_Rect tempRect;
tempRect.x=xres;
tempRect.y=yres;
tempRect.w=_w;
tempRect.h=_h;
if(angle==0){
SDL_RenderCopy(window.ren,tex,NULL,&tempRect);
}else{
SDL_RenderCopyEx(window.ren,tex,NULL,&tempRect,angle,NULL,NULL);
}}
SDL_Texture* loadTexture(char* path)
{
SDL_Surface* img = IMG_Load(path);
if(img==NULL){
printf("coudnt load img\n");
}
SDL_Texture* tex = SDL_CreateTextureFromSurface(window.ren,img);
SDL_FreeSurface(img);
if(tex==NULL){
printf("error creating texture\n");
return NULL;
}
return tex;}
