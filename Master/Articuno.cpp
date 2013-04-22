
#include "Articuno.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Articuno::Articuno(string filename, int x, int y, int w, int h, int xV, int yV, int p,int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Articuno::move()
{
if(isBouncer){
if (xpos>=DOME_HEAD_X_END)
	xpos+=xVel;
else 
	xpos+=BOUNCE;

}
else
	xpos+=xVel;
	if(xpos>0 && xpos<SCREEN_WIDTH)
	{
		hasEntered = 1;
	}


}

//shows the enemy on the screen
void Articuno::show(SDL_Surface * screen, int count)

{	if(!isDead())
	apply_surface(xpos,ypos,sprite,screen,&clips[count%7]);
}

void Articuno::setClips()
{
  //Clip range for the Articuno clips
  clips[0].x = 204;
  clips[0].y =44;
  clips[0].w = 144;
  clips[0].h = 64;

  clips[1].x = 356;
  clips[1].y = 39;
  clips[1].w = 141;
  clips[1].h = 65;

  clips[2].x = 508;
  clips[2].y = 40;
  clips[2].w = 150;
  clips[2].h = 59;

  clips[3].x = 673;
  clips[3].y = 40;
  clips[3].w = 152;
  clips[3].h = 60;

  clips[4].x = 830;
  clips[4].y = 34;
  clips[4].w = 150;
  clips[4].h = 60;

  clips[5].x = 992;
  clips[5].y = 37;
  clips[5].w = 152;
  clips[5].h = 60;

  clips[6].x = 60;
  clips[6].y = 0;
  clips[6].w = 136;
  clips[6].h = 99;

}



