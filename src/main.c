#include"main.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"gfx.h"
#include"input.h"
void __GameContainer_start();
void __GameContainer_stop();
void __GameContainer_draw();
void __GameContainer_update(float dt);
GameContainer gameContainer={.start=&__GameContainer_start,.stop=&__GameContainer_stop,.draw=&__GameContainer_draw,.update=&__GameContainer_update};
bool __Window_init();
void __Window_delete();
Window window={.win=NULL,.ren=NULL,.init=&__Window_init,.delete=&__Window_delete};
int main()
{
window.init();
sceneManager.init();
gameContainer.start();
event.delete();
return 0;}
void __GameContainer_start()
{
SDL_Texture* tex = loadTexture("/../res/char/Sprite.bmp");
SDL_Event sdlevent;
bool quit = false;
struct timeval currentTime;
gettimeofday(&currentTime,NULL);
double lastTime = (currentTime.tv_sec*1000000+currentTime.tv_usec)/1000000.0;
double firstTime = 0;
float passedTime = 0;
float unprocessedTime = 0;
float frameTime = 0;
int frames = 0;
bool render = true;
float frameCap = 1.0/30.0;
int FPS = 0;
while(!quit){
while(SDL_PollEvent(&sdlevent)){
if(sdlevent.type==SDL_QUIT){
quit=true;
}else if(sdlevent.type==SDL_KEYDOWN){
}else if(sdlevent.type==SDL_MOUSEBUTTONDOWN){
}
}
gettimeofday(&currentTime,NULL);
firstTime=(currentTime.tv_sec*1000000+currentTime.tv_usec)/1000000.0;
passedTime=firstTime-lastTime;
lastTime=firstTime;
unprocessedTime=unprocessedTime+(float)passedTime;
frameTime=frameTime+passedTime;
while(unprocessedTime>=frameCap){
gameContainer.update((float)frameCap);
unprocessedTime=unprocessedTime-frameCap;
render=true;
if(frameTime>=1){
printf("FPS: %i \n",FPS);
frameTime=0;
FPS=frames;
frames=0;
}
}
if(render){
SDL_RenderClear(window.ren);
gameContainer.draw();
SDL_RenderPresent(window.ren);
frames++;
render=false;
}else{
usleep(10000);
}
}
SDL_DestroyTexture(tex);
gameContainer.stop();}
void __GameContainer_stop()
{
event.dispatch("stop",NULL);}
void __GameContainer_draw()
{
sceneManager.draw();
event.dispatch("draw",NULL);}
void __GameContainer_update(float dt)
{
input.update(dt);
gameState.dt=dt;
sceneManager.update(dt);
event.dispatch("update",NULL);}
GameContainer* __new_GameContainer()
{ 
GameContainer *this = malloc(sizeof(GameContainer));
this->start = &__GameContainer_start; 
this->stop = &__GameContainer_stop; 
this->draw = &__GameContainer_draw; 
this->update = &__GameContainer_update; 
return this;
} 
GameContainer __crt_GameContainer()
{ 
GameContainer this;
this.start = &__GameContainer_start; 
this.stop = &__GameContainer_stop; 
this.draw = &__GameContainer_draw; 
this.update = &__GameContainer_update; 
return this;
} 
bool __Window_init()
{
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("error initing sdl\n");
}
printf("sdl inited\n");
SDL_Window* sdlwindow = SDL_CreateWindow("Explore",100,100,640,480,SDL_WINDOW_SHOWN);
if(sdlwindow==NULL){
printf("Error creating window");
SDL_Quit();
return false;
}
printf("SDL window created \n");
SDL_Renderer* sdlren = SDL_CreateRenderer(sdlwindow,-1,SDL_RENDERER_ACCELERATED);
if(sdlren==NULL){
printf("Error creating renderer");
SDL_DestroyWindow(sdlwindow);
SDL_Quit();
return false;
}
printf("sdl renderer created \n");
window.win=sdlwindow;
window.ren=sdlren;
return true;}
void __Window_delete()
{
SDL_DestroyWindow(window.win);
SDL_DestroyRenderer(window.ren);}
Window* __new_Window()
{ 
Window *this = malloc(sizeof(Window));
this->win = NULL; 
this->ren = NULL; 
this->init = &__Window_init; 
this->delete = &__Window_delete; 
return this;
} 
Window __crt_Window()
{ 
Window this;
this.win = NULL; 
this.ren = NULL; 
this.init = &__Window_init; 
this.delete = &__Window_delete; 
return this;
} 
