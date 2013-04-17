
#include "Articuno.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Articuno::Articuno(string filename, int x, int y, int w, int h, int xV, int yV, int hea):Enemy(filename,x,y,w,h,xV,yV,hea)
{
	setClips();
}

void Articuno::move()
{
 if(ypos<550)
	ypos+=yVel;
else
	xpos+=xVel;

}

//shows the enemy on the screen
void Articuno::show(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Articuno::setClips()
{
  //Clip range for the Articuno clips
  clips[0].x = 58;
  clips[0].y = 0;
  clips[0].w = 134;
  clips[0].h = 105;

  clips[1].x = 202;
  clips[1].y = 42;
  clips[1].w = 150;
  clips[1].h = 70;

  clips[2].x = 352;
  clips[2].y = 42;
  clips[2].w = 150;
  clips[2].h = 70;

  clips[3].x = 507;
  clips[3].y = 42;
  clips[3].w = 150;
  clips[3].h = 70;

}


