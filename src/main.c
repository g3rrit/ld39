#include"main.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
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
gameContainer.start();
return 0;}
void __GameContainer_start()
{
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("error initing sdl\n");
}
printf("sdl inited\n");
window.init();
SDL_Texture* tex = loadTexture("/../res/char/Sprite.bmp");
SDL_Event event;
bool quit = false;
struct timeval currentTime;
gettimeofday(&currentTime,NULL);
double lastTime = (currentTime.tv_sec*1000000+currentTime.tv_usec)/1000000;
double firstTime = 0;
double passedTime = 0;
double unprocessedTime = 0;
double frameTime = 0;
int frames = 0;
bool render = true;
double frameCap = 1.0/30.0;
int FPS = 0;
while(!quit){
while(SDL_PollEvent(&event)){
if(event.type==SDL_QUIT){
quit=true;
}else if(event.type==SDL_KEYDOWN){
quit=true;
}else if(event.type==SDL_MOUSEBUTTONDOWN){
quit=true;
}
}
gettimeofday(&currentTime,NULL);
firstTime=(currentTime.tv_sec*1000000+currentTime.tv_usec)/1000000;
passedTime=firstTime-lastTime;
lastTime=firstTime;
unprocessedTime=unprocessedTime+passedTime;
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
SDL_RenderCopy(window.ren,tex,NULL,NULL);
SDL_RenderPresent(window.ren);
frames++;
}else{
printf("sleeping \n");
sleep(10);
}
}
SDL_DestroyTexture(tex);
gameContainer.stop();}
void __GameContainer_stop()
{}
void __GameContainer_draw()
{}
void __GameContainer_update(float dt)
{}
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
SDL_Texture* loadTexture(char* path)
{
SDL_Surface* img = IMG_Load(path);
if(img==NULL){
printf("coudnt load img\n");
}
SDL_Texture* tex = SDL_CreateTextureFromSurface(window.ren,img);
SDL_FreeSurface(img);
if(tex==NULL){
printf("error creating texture\n");
return NULL;
}
return tex;}
