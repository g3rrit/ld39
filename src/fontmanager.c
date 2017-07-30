#include"fontmanager.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"main.h"
void __FontManager_add(char* id,char* txt,int _x,int _y,int _w,int _h);
Text* __FontManager_get(char* id);
void __FontManager_setText(char* id,char* txt);
void __FontManager_remove(char* id);
void __FontManager_draw();
void __FontManager_delete();
FontManager fontManager={.fontMap=NULL,.add=&__FontManager_add,.get=&__FontManager_get,.setText=&__FontManager_setText,.remove=&__FontManager_remove,.draw=&__FontManager_draw,.delete=&__FontManager_delete};
void __Text_setText(Text* this,char* txt);
bool __Text_draw(Text* this);
void __Text_delete(Text* this);
void __FontManager_add(char* id,char* txt,int _x,int _y,int _w,int _h)
{
if(!fontManager.fontMap)fontManager.fontMap=__new_Map();
Text* appText = __new_Text();
appText->setText(appText,txt);
appText->pos->x=_x;
appText->pos->y=_y;
appText->w=_w;
appText->h=_h;
fontManager.fontMap->add(fontManager.fontMap,id,appText);}
Text* __FontManager_get(char* id)
{
return fontManager.fontMap->get(fontManager.fontMap,id);}
void __FontManager_setText(char* id,char* txt)
{
Text* tempTxt = fontManager.fontMap->get(fontManager.fontMap,id);
tempTxt->setText(tempTxt,txt);}
void __FontManager_remove(char* id)
{
Text* tempTxt = fontManager.fontMap->remove(fontManager.fontMap,id);
tempTxt->delete(tempTxt);
free(tempTxt);}
void __FontManager_draw()
{
fontManager.fontMap->forEach(fontManager.fontMap,&__Text_draw);}
void __FontManager_delete()
{
fontManager.fontMap->forEach(fontManager.fontMap,&__Text_delete);
fontManager.fontMap->delete(fontManager.fontMap);
free(fontManager.fontMap);}
FontManager* __new_FontManager()
{ 
FontManager *this = malloc(sizeof(FontManager));
this->fontMap = NULL; 
this->add = &__FontManager_add; 
this->get = &__FontManager_get; 
this->setText = &__FontManager_setText; 
this->remove = &__FontManager_remove; 
this->draw = &__FontManager_draw; 
this->delete = &__FontManager_delete; 
return this;
} 
FontManager __crt_FontManager()
{ 
FontManager this;
this.fontMap = NULL; 
this.add = &__FontManager_add; 
this.get = &__FontManager_get; 
this.setText = &__FontManager_setText; 
this.remove = &__FontManager_remove; 
this.draw = &__FontManager_draw; 
this.delete = &__FontManager_delete; 
return this;
} 
void __Text_setText(Text* this,char* txt)
{
if(this->tex)SDL_DestroyTexture(this->tex);
if(this->txt&&(strlen(this->txt)!=strlen(txt))){
free(this->txt);
this->txt=malloc(sizeof(char)*(strlen(txt)+1));
}else if(!this->txt){
this->txt=malloc(sizeof(char)*(strlen(txt)+1));
}
strcpy(this->txt,txt);
SDL_Color color;
color.r=255;
color.g=255;
color.b=255;
color.a=255;
SDL_Surface* surface = TTF_RenderText_Solid(window.font,this->txt,color);
this->tex=SDL_CreateTextureFromSurface(window.ren,surface);
SDL_FreeSurface(surface);}
bool __Text_draw(Text* this)
{
if(!this->tex)return true;
SDL_Rect tempRect;
tempRect.x=this->pos->x;
tempRect.y=this->pos->y;
tempRect.w=this->w;
tempRect.h=this->h;
SDL_RenderCopy(window.ren,this->tex,NULL,&tempRect);
return true;}
void __Text_delete(Text* this)
{
free(this->pos);
SDL_DestroyTexture(this->tex);
free(this->txt);}
Text* __new_Text()
{ 
Text *this = malloc(sizeof(Text));
this->txt = 0; 
this->pos = __new_Vec2(); 
this->w = 100; 
this->h = 10; 
this->tex = NULL; 
this->setText = &__Text_setText; 
this->draw = &__Text_draw; 
this->delete = &__Text_delete; 
return this;
} 
Text __crt_Text()
{ 
Text this;
this.txt = 0; 
this.pos = __new_Vec2(); 
this.w = 100; 
this.h = 10; 
this.tex = NULL; 
this.setText = &__Text_setText; 
this.draw = &__Text_draw; 
this.delete = &__Text_delete; 
return this;
} 
