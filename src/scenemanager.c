#include"scenemanager.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"objectmanager.h"
#include"gamestate.h"
void __SceneManager_init();
void __SceneManager_update(float dt);
void __SceneManager_draw();
void __SceneManager_add(Scene* scene);
SceneManager sceneManager={.activeScene=&gameScene,.init=&__SceneManager_init,.update=&__SceneManager_update,.draw=&__SceneManager_draw,.add=&__SceneManager_add};
void __Scene_init();
void __Scene_update(float dt);
void __Scene_draw();
void __Scene_stop();
void __GameScene_init();
void __GameScene_update(float dt);
void __GameScene_draw();
void __GameScene_stop();
void __GameScene_pause();
GameScene gameScene={.init=&__GameScene_init,.update=&__GameScene_update,.draw=&__GameScene_draw,.stop=&__GameScene_stop,.pause=&__GameScene_pause};
void __SceneManager_init()
{
sceneManager.activeScene->init();}
void __SceneManager_update(float dt)
{
sceneManager.activeScene->update(dt);}
void __SceneManager_draw()
{
sceneManager.activeScene->draw();}
void __SceneManager_add(Scene* scene)
{
sceneManager.activeScene=scene;
scene->init();}
SceneManager* __new_SceneManager()
{ 
SceneManager *this = malloc(sizeof(SceneManager));
this->activeScene = &gameScene; 
this->init = &__SceneManager_init; 
this->update = &__SceneManager_update; 
this->draw = &__SceneManager_draw; 
this->add = &__SceneManager_add; 
return this;
} 
SceneManager __crt_SceneManager()
{ 
SceneManager this;
this.activeScene = &gameScene; 
this.init = &__SceneManager_init; 
this.update = &__SceneManager_update; 
this.draw = &__SceneManager_draw; 
this.add = &__SceneManager_add; 
return this;
} 
void __Scene_init()
{}
void __Scene_update(float dt)
{}
void __Scene_draw()
{}
void __Scene_stop()
{}
Scene* __new_Scene()
{ 
Scene *this = malloc(sizeof(Scene));
this->init = &__Scene_init; 
this->update = &__Scene_update; 
this->draw = &__Scene_draw; 
this->stop = &__Scene_stop; 
return this;
} 
Scene __crt_Scene()
{ 
Scene this;
this.init = &__Scene_init; 
this.update = &__Scene_update; 
this.draw = &__Scene_draw; 
this.stop = &__Scene_stop; 
return this;
} 
void __GameScene_init()
{
objectManager.init();
printf("starting gameScene\n");}
void __GameScene_update(float dt)
{
objectManager.update(dt);}
void __GameScene_draw()
{
objectManager.draw();}
void __GameScene_stop()
{}
void __GameScene_pause()
{}
GameScene* __new_GameScene()
{ 
GameScene *this = malloc(sizeof(GameScene));
this->init = &__GameScene_init; 
this->update = &__GameScene_update; 
this->draw = &__GameScene_draw; 
this->stop = &__GameScene_stop; 
this->pause = &__GameScene_pause; 
return this;
} 
GameScene __crt_GameScene()
{ 
GameScene this;
this.init = &__GameScene_init; 
this.update = &__GameScene_update; 
this.draw = &__GameScene_draw; 
this.stop = &__GameScene_stop; 
this.pause = &__GameScene_pause; 
return this;
} 
