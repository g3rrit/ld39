#include"main.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"gfx.h"
#include"input.h"
#include"view.h"
#include"fontmanager.h"
void __GameContainer_start();
void __GameContainer_stop();
void __GameContainer_draw();
void __GameContainer_update(float dt);
GameContainer gameContainer={.start=&__GameContainer_start,.stop=&__GameContainer_stop,.draw=&__GameContainer_draw,.update=&__GameContainer_update};
bool __Window_init();
void __Window_delete();
Window window={.win=NULL,.ren=NULL,.font=NULL,.init=&__Window_init,.delete=&__Window_delete};
int main()
{
window.init();
sceneManager.init();
gameContainer.start();
sceneManager.delete();
window.delete();
event.delete();
return 0;}
void __GameContainer_start()
{
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
fontManager.add("fpstxt","FPS:",gameState.WIDTH-100,5,60,15);
fontManager.add("fpsnum","00",gameState.WIDTH-40,5,40,15);
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
char fpsnum[12];
snprintf(fpsnum,12,"%d",FPS);
fontManager.setText("fpsnum",&fpsnum);
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
view.update(dt);
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
TTF_Init();
window.font=TTF_OpenFont("/../res/font/BitFont.ttf",30);
if(!window.font){
printf("error loading font\n");
SDL_Quit();
TTF_Quit();
return false;
}
SDL_Window* sdlwindow = SDL_CreateWindow("Explore",100,100,gameState.WIDTH,gameState.HEIGHT,SDL_WINDOW_SHOWN);
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
TTF_CloseFont(window.font);
TTF_Quit();
SDL_DestroyWindow(window.win);
SDL_DestroyRenderer(window.ren);
SDL_Quit();}
Window* __new_Window()
{ 
Window *this = malloc(sizeof(Window));
this->win = NULL; 
this->ren = NULL; 
this->font = NULL; 
this->init = &__Window_init; 
this->delete = &__Window_delete; 
return this;
} 
Window __crt_Window()
{ 
Window this;
this.win = NULL; 
this.ren = NULL; 
this.font = NULL; 
this.init = &__Window_init; 
this.delete = &__Window_delete; 
return this;
} 
char* randStr(uint32_t length)
{
char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* res = malloc(sizeof(char)*(length));
res[length-1]=0;
length--;
while(length>0){
uint32_t index = (double)rand()/RAND_MAX*(sizeof(charset)-1);
res[length-1]=charset[index];
length--;
}
printf("random string: %s\n",res);
return res;}
