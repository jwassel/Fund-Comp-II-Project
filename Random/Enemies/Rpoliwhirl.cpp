
#include "Rpoliwhirl.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rpoliwhirl::Rpoliwhirl(string filename, int x, int y, int w, int h, int xV, int yV, int hea):Enemy(filename,x,y,w,h,xV,yV,hea)
{
	setClips();
}

void Rpoliwhirl::move()
{
 if(ypos<550)
	ypos+=yVel;
else
	xpos+=xVel;

}

//shows the enemy on the screen
void Rpoliwhirl::show(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Rpoliwhirl::setClips()
{
  //Clip range for the Rpoliwhirl clips
  clips[0].x = 199;
  clips[0].y = 165;
  clips[0].w = 103;
  clips[0].h = 95;

  clips[1].x = 302;
  clips[1].y = 165;
  clips[1].w = 107;
  clips[1].h = 95;

  clips[2].x = 409;
  clips[2].y = 165;
  clips[2].w = 118;
  clips[2].h = 95;

  clips[3].x = 527;
  clips[3].y = 165;
  clips[3].w = 108;
  clips[3].h = 95;

  clips[4].x = 635;
  clips[4].y = 165;
  clips[4].w = 100;
  clips[4].h = 95;

  clips[5].x = 735;
  clips[5].y = 165;
  clips[5].w = 75;
  clips[5].h = 95;

}



