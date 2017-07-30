#ifndef objectmanager_H
#define objectmanager_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
typedef struct ObjectManager ObjectManager;
ObjectManager objectManager;
struct ObjectManager {
void (*init)(); 
void (*update)(float dt); 
void (*draw)(); 
void (*delete)(); 
};
ObjectManager* __new_ObjectManager();
ObjectManager __crt_ObjectManager();
#endif