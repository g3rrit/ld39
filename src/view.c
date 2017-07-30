#include"view.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"player.h"
#include"gamestate.h"
void __View_update(float dt);
View view={.x=0,.y=0,.mx=0,.my=0,.destX=0,.destY=0,.dx=0,.dy=0,.factor=10.0,.update=&__View_update};
void __View_update(float dt)
{
view.x=player.x-gameState.WIDTH/2+player.w/2;
view.y=player.y-gameState.HEIGHT/2+player.h/2;
view.mx=view.x+gameState.WIDTH/2;
view.my=view.y+gameState.HEIGHT/2;}
View* __new_View()
{ 
View *this = malloc(sizeof(View));
this->x = 0; 
this->y = 0; 
this->mx = 0; 
this->my = 0; 
this->destX = 0; 
this->destY = 0; 
this->dx = 0; 
this->dy = 0; 
this->factor = 10.0; 
this->update = &__View_update; 
return this;
} 
View __crt_View()
{ 
View this;
this.x = 0; 
this.y = 0; 
this.mx = 0; 
this.my = 0; 
this.destX = 0; 
this.destY = 0; 
this.dx = 0; 
this.dy = 0; 
this.factor = 10.0; 
this.update = &__View_update; 
return this;
} 
