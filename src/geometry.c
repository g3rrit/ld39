#include"geometry.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"Math.h"
Vec2* __Vec2_add(Vec2* this,Vec2* other);
Vec2* __Vec2_sub(Vec2* this,Vec2* other);
Vec2* __Vec2_mul(Vec2* this,int32_t factor);
int32_t __Vec2_scalar(Vec2* this,Vec2* other);
int32_t __Vec2_length(Vec2* this);
Vec2* __Vec2_rotate(Vec2* this,double rad);
Vec2d* __Vec2d_add(Vec2d* this,Vec2d* other);
Vec2d* __Vec2d_sub(Vec2d* this,Vec2d* other);
Vec2d* __Vec2d_mul(Vec2d* this,double factor);
double __Vec2d_scalar(Vec2d* this,Vec2d* other);
double __Vec2d_length(Vec2d* this);
Vec2d* __Vec2d_rotate(Vec2d* this,double rad);
void __PBody_update(PBody* this,float dt);
void __PBody_addForce(PBody* this,Vec2d* _force);
void __PBody_addForceXY(PBody* this,int32_t _x,int32_t _y);
void __PBody_delete(PBody* this);
Vec2* __Vec2_add(Vec2* this,Vec2* other)
{
this->x+=other->x;
this->y+=other->y;
return this;}
Vec2* __Vec2_sub(Vec2* this,Vec2* other)
{
this->x-=other->x;
this->y-=other->y;
return this;}
Vec2* __Vec2_mul(Vec2* this,int32_t factor)
{
this->x*=factor;
this->y*=factor;
return this;}
int32_t __Vec2_scalar(Vec2* this,Vec2* other)
{
int32_t res = this->x*other->x+this->y*other->y;
return res;}
int32_t __Vec2_length(Vec2* this)
{
return (int32_t)sqrt(this->x*this->x+this->y*this->y);}
Vec2* __Vec2_rotate(Vec2* this,double rad)
{
double ca = cos(rad);
double sa = sin(rad);
return this;}
Vec2* __new_Vec2()
{ 
Vec2 *this = malloc(sizeof(Vec2));
this->x = 0; 
this->y = 0; 
this->add = &__Vec2_add; 
this->sub = &__Vec2_sub; 
this->mul = &__Vec2_mul; 
this->scalar = &__Vec2_scalar; 
this->length = &__Vec2_length; 
this->rotate = &__Vec2_rotate; 
return this;
} 
Vec2 __crt_Vec2()
{ 
Vec2 this;
this.x = 0; 
this.y = 0; 
this.add = &__Vec2_add; 
this.sub = &__Vec2_sub; 
this.mul = &__Vec2_mul; 
this.scalar = &__Vec2_scalar; 
this.length = &__Vec2_length; 
this.rotate = &__Vec2_rotate; 
return this;
} 
Vec2d* __Vec2d_add(Vec2d* this,Vec2d* other)
{
this->x+=other->x;
this->y+=other->y;
return this;}
Vec2d* __Vec2d_sub(Vec2d* this,Vec2d* other)
{
this->x-=other->x;
this->y-=other->y;
return this;}
Vec2d* __Vec2d_mul(Vec2d* this,double factor)
{
this->x*=factor;
this->y*=factor;
return this;}
double __Vec2d_scalar(Vec2d* this,Vec2d* other)
{
double res = this->x*other->x+this->y*other->y;
return res;}
double __Vec2d_length(Vec2d* this)
{
return sqrt(this->x*this->x+this->y*this->y);}
Vec2d* __Vec2d_rotate(Vec2d* this,double rad)
{
double ca = cos(rad);
double sa = sin(rad);
this->x=ca*this->x-sa*this->y;
this->y=sa*this->x+ca*this->y;
return this;}
Vec2d* __new_Vec2d()
{ 
Vec2d *this = malloc(sizeof(Vec2d));
this->x = 0; 
this->y = 0; 
this->add = &__Vec2d_add; 
this->sub = &__Vec2d_sub; 
this->mul = &__Vec2d_mul; 
this->scalar = &__Vec2d_scalar; 
this->length = &__Vec2d_length; 
this->rotate = &__Vec2d_rotate; 
return this;
} 
Vec2d __crt_Vec2d()
{ 
Vec2d this;
this.x = 0; 
this.y = 0; 
this.add = &__Vec2d_add; 
this.sub = &__Vec2d_sub; 
this.mul = &__Vec2d_mul; 
this.scalar = &__Vec2d_scalar; 
this.length = &__Vec2d_length; 
this.rotate = &__Vec2d_rotate; 
return this;
} 
void __PBody_update(PBody* this,float dt)
{
this->force->mul(this->force,1.0/this->mass);
this->acc->x=this->force->x;
this->acc->y=this->force->y;
this->force->x=0;
this->force->y=0;
this->vel->x+=this->acc->x*dt;
this->vel->y+=this->acc->y*dt;
this->dx=this->vel->x*dt;
this->dy=this->vel->y*dt;
this->pos->x+=this->dx;
this->pos->y+=this->dy;}
void __PBody_addForce(PBody* this,Vec2d* _force)
{
this->force->x+=_force->x;
this->force->y+=_force->y;}
void __PBody_addForceXY(PBody* this,int32_t _x,int32_t _y)
{
this->force->x=_x;
this->force->y=_y;}
void __PBody_delete(PBody* this)
{
free(this->pos);
free(this->vel);
free(this->acc);
free(this->force);}
PBody* __new_PBody()
{ 
PBody *this = malloc(sizeof(PBody));
this->mass = 1; 
this->pos = __new_Vec2d(); 
this->vel = __new_Vec2d(); 
this->acc = __new_Vec2d(); 
this->dx = 0; 
this->dy = 0; 
this->force = __new_Vec2d(); 
this->update = &__PBody_update; 
this->addForce = &__PBody_addForce; 
this->addForceXY = &__PBody_addForceXY; 
this->delete = &__PBody_delete; 
return this;
} 
PBody __crt_PBody()
{ 
PBody this;
this.mass = 1; 
this.pos = __new_Vec2d(); 
this.vel = __new_Vec2d(); 
this.acc = __new_Vec2d(); 
this.dx = 0; 
this.dy = 0; 
this.force = __new_Vec2d(); 
this.update = &__PBody_update; 
this.addForce = &__PBody_addForce; 
this.addForceXY = &__PBody_addForceXY; 
this.delete = &__PBody_delete; 
return this;
} 
double toRad(double deg)
{
return deg*(M_PI/180.0);}
double toDeg(double rad)
{
return rad*(180.0/M_PI);}
