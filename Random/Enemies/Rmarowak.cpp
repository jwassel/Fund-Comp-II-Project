
#include "Rmarowak.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rmarowak::Rmarowak(string filename, int x, int y, int w, int h, int xV, int yV, int hea):Enemy(filename,x,y,w,h,xV,yV,hea)
{
	setClips();
}

void Rmarowak::move()
{
 if(ypos<550)
	ypos+=yVel;
else
	xpos+=xVel;

}

//shows the enemy on the screen
void Rmarowak::show(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Rmarowak::setClips()
{
  //Clip range for the Rmarowak clips
  clips[0].x = 0;
  clips[0].y = 207;
  clips[0].w = 100;
  clips[0].h = 115;

  clips[1].x = 102;
  clips[1].y = 204;
  clips[1].w = 109;
  clips[1].h = 116;

  clips[2].x = 214;
  clips[2].y = 204;
  clips[2].w = 105;
  clips[2].h = 115;

}



