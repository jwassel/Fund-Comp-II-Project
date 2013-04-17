
#include "Machamp.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Machamp::Machamp(string filename, int x, int y, int w, int h, int xV, int yV, int p,int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Machamp::move()
{
 if(ypos<550)
	ypos+=yVel;
else
	xpos+=xVel;

}

//shows the enemy on the screen
void Machamp::show(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Machamp::setClips()
{
  //Clip range for the Machamp clips
  clips[0].x = 97;
  clips[0].y = 303;
  clips[0].w = 67;
  clips[0].h = 100;

  clips[1].x = 169;
  clips[1].y =303;
  clips[1].w = 67;
  clips[1].h = 100;

  clips[2].x = 238;
  clips[2].y = 303;
  clips[2].w = 67;
  clips[2].h = 100;

}


