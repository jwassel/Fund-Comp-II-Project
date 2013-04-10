
#include "Rmachamp.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rmachamp::Rmachamp(string filename, int x, int y, int w, int h, int xV, int yV, int hea):Enemy(filename,x,y,w,h,xV,yV,hea)
{
	setClips();
}

void Rmachamp::move()
{
 if(ypos<550)
	ypos+=yVel;
else
	xpos+=xVel;

}

//shows the enemy on the screen
void Rmachamp::show(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Rmachamp::setClips()
{
  //Clip range for the Rmachamp clips
  clips[0].x = 88;
  clips[0].y = 302;
  clips[0].w = 78;
  clips[0].h = 105;

  clips[1].x = 166;
  clips[1].y = 302;
  clips[1].w = 64;
  clips[1].h = 105;

  clips[2].x = 230;
  clips[2].y = 302;
  clips[2].w = 80;
  clips[2].h = 105;

}


