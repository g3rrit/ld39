#ifndef scenemanager_H
#define scenemanager_H
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"pstd.h"
typedef struct SceneManager SceneManager;
SceneManager sceneManager;
typedef struct Scene Scene;
typedef struct GameScene GameScene;
GameScene gameScene;
struct SceneManager {
Scene* activeScene; 
void (*init)(); 
void (*update)(float dt); 
void (*draw)(); 
void (*add)(Scene* scene); 
};
SceneManager* __new_SceneManager();
SceneManager __crt_SceneManager();
struct Scene {
void (*init)(); 
void (*update)(float dt); 
void (*draw)(); 
void (*stop)(); 
};
Scene* __new_Scene();
Scene __crt_Scene();
struct GameScene {
void (*init)(); 
void (*update)(float dt); 
void (*draw)(); 
void (*stop)(); 
void (*pause)(); 
};
GameScene* __new_GameScene();
GameScene __crt_GameScene();
#endif