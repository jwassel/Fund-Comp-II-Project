
#include "Rsquirtle.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rsquirtle::Rsquirtle(string filename, int x, int y, int w, int h, int xV, int yV, int hea):Enemy(filename,x,y,w,h,xV,yV,hea)
{
	setClips();
}

void Rsquirtle::move()
{
 if(ypos<550)
	ypos+=yVel;
else
	xpos+=xVel;

}

//shows the enemy on the screen
void Rsquirtle::show(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Rsquirtle::setClips()
{
  //Clip range for the Rsquirtle clips
  clips[0].x = 115;
  clips[0].y = 110;
  clips[0].w = 37;
  clips[0].h = 36;

  clips[1].x = 153;
  clips[1].y = 110;
  clips[1].w = 39;
  clips[1].h = 36;

  clips[2].x = 192;
  clips[2].y = 108;
  clips[2].w = 38;
  clips[2].h = 36;

  clips[3].x = 230;
  clips[3].y = 108;
  clips[3].w = 39;
  clips[3].h = 38;

  clips[4].x = 268;
  clips[4].y = 108;
  clips[4].w = 37;
  clips[4].h = 36;

  clips[5].x = 307;
  clips[5].y = 108;
  clips[5].w = 39;
  clips[5].h = 36;

}



