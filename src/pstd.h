#ifndef pstd_H
#define pstd_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"stdio.h"
#include"stdbool.h"
#include"stdint.h"
#include"stdlib.h"
#include"string.h"
typedef struct List List;
typedef struct ListNode ListNode;
typedef struct Map Map;
typedef struct MapNode MapNode;
typedef struct EventList EventList;
EventList event;
typedef bool (*__forEach_fun)(void* data);
struct List {
ListNode* start; 
int32_t size; 
void* (*add)(List* this,void* data); 
void* (*get)(List* this,int32_t i); 
void* (*remove)(List* this,int32_t i); 
bool (*forEach)(List* this,__forEach_fun fun); 
void (*delete)(List* this); 
};
List* __new_List();
List __crt_List();
struct ListNode {
void* data; 
ListNode* next; 
};
ListNode* __new_ListNode();
ListNode __crt_ListNode();
typedef bool (*__forEach_fun)(void* data);
struct Map {
MapNode* start; 
int32_t size; 
void* (*add)(Map* this,char* key,void* data); 
void* (*get)(Map* this,char* key); 
void* (*remove)(Map* this,char* key); 
bool (*forEach)(Map* this,__forEach_fun fun); 
void (*delete)(Map* this); 
};
Map* __new_Map();
Map __crt_Map();
struct MapNode {
void* data; 
char* key; 
MapNode* next; 
};
MapNode* __new_MapNode();
MapNode __crt_MapNode();
typedef bool (*__add_fun)(void* data);
struct EventList {
Map* map; 
void (*add)(char* name,char* id,__add_fun fun); 
bool (*dispatch)(char* name,void* data); 
void (*remove)(char* name); 
void (*removeID)(char* name,char* id); 
void (*delete)(); 
};
EventList* __new_EventList();
EventList __crt_EventList();
typedef bool (*____eventDispatchForEach_fun)();
bool __eventDispatchForEach(____eventDispatchForEach_fun fun,void* data);
bool __eventDeleteForEach(void* data);
#endif