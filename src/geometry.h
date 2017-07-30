#ifndef geometry_H
#define geometry_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
typedef struct Vec2 Vec2;
typedef struct Vec2d Vec2d;
typedef struct PBody PBody;
struct Vec2 {
int32_t x; 
int32_t y; 
Vec2* (*add)(Vec2* this,Vec2* other); 
Vec2* (*sub)(Vec2* this,Vec2* other); 
Vec2* (*mul)(Vec2* this,int32_t factor); 
int32_t (*scalar)(Vec2* this,Vec2* other); 
int32_t (*length)(Vec2* this); 
Vec2* (*rotate)(Vec2* this,double rad); 
};
Vec2* __new_Vec2();
Vec2 __crt_Vec2();
struct Vec2d {
double x; 
double y; 
Vec2d* (*add)(Vec2d* this,Vec2d* other); 
Vec2d* (*sub)(Vec2d* this,Vec2d* other); 
Vec2d* (*mul)(Vec2d* this,double factor); 
double (*scalar)(Vec2d* this,Vec2d* other); 
double (*length)(Vec2d* this); 
Vec2d* (*rotate)(Vec2d* this,double rad); 
};
Vec2d* __new_Vec2d();
Vec2d __crt_Vec2d();
struct PBody {
int32_t mass; 
Vec2d* pos; 
Vec2d* vel; 
Vec2d* acc; 
double dx; 
double dy; 
Vec2d* force; 
void (*update)(PBody* this,float dt); 
void (*addForce)(PBody* this,Vec2d* _force); 
void (*addForceXY)(PBody* this,int32_t _x,int32_t _y); 
void (*delete)(PBody* this); 
};
PBody* __new_PBody();
PBody __crt_PBody();
double toRad(double deg);
double toDeg(double rad);
#endif