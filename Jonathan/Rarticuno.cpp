
#include "Rarticuno.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rarticuno::Rarticuno(string filename, int x, int y, int w, int h, int xV, int yV, int hea):Enemy(filename,x,y,w,h,xV,yV,hea)
{
	setClips();
}

void Rarticuno::move()
{
 if(ypos<550)
	ypos+=yVel;
else
	xpos+=xVel;

}

//shows the enemy on the screen
void Rarticuno::show(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Rarticuno::setClips()
{
  //Clip range for the Rarticuno clips
  clips[0].x = 528;
  clips[0].y = 38;
  clips[0].w = 154;
  clips[0].h = 63;

  clips[1].x = 691;
  clips[1].y = 38;
  clips[1].w = 154;
  clips[1].h = 63;

  clips[2].x = 993;
  clips[2].y = 0;
  clips[2].w = 128;
  clips[2].h = 101;

}


