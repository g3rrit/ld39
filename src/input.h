#ifndef input_H
#define input_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
typedef struct Input Input;
Input input;
struct Input {
int mouseX; 
int mouseY; 
uint8_t* key; 
bool W; 
void (*update)(float dt); 
};
Input* __new_Input();
Input __crt_Input();
#endif