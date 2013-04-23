
#include "Rpoliwhirl.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rpoliwhirl::Rpoliwhirl(string filename, int x, int y, int w, int h, int xV, int yV, int p, int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Rpoliwhirl::move()
{

 if(ypos+height<GROUND)
	ypos+=yVel;
else if (xpos+width<=DOME_BASE_X_BEG)
	xpos+=xVel;
else 
	xpos-=BOUNCE;

}

//shows the enemy on the screen
void Rpoliwhirl::show(SDL_Surface * screen, int count)
{
	if(!isDead())
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Rpoliwhirl::setClips()
{
  //Clip range for the clips
  clips[0].x = 898;
  clips[0].y = 169;
  clips[0].w = 76;
  clips[0].h = 82;

  clips[1].x = 813;
  clips[1].y = 166;
  clips[1].w = 90;
  clips[1].h = 77;

  clips[2].x = 736;
  clips[2].y = 167;
  clips[2].w = 75;
  clips[2].h = 81;

  clips[3].x = 636;
  clips[3].y = 169;
  clips[3].w = 100;
  clips[3].h = 85;

  clips[4].x = 526;
  clips[4].y = 169;
  clips[4].w = 109;
  clips[4].h = 85;

  clips[5].x = 409;
  clips[5].y = 165;
  clips[5].w = 115;
  clips[5].h = 80;

}


