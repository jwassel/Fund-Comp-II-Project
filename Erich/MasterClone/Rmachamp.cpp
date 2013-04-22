
#include "Rmachamp.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rmachamp::Rmachamp(string filename, int x, int y, int w, int h, int xV, int yV, int p,int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{	isPikachu=false;
	setClips();
}

void Rmachamp::move()
{
 if(ypos+height<GROUND)
	ypos+=yVel;
else if (isBouncer){
if(xpos+width<=DOME_BASE_X_BEG)
	xpos+=xVel;
else 
	xpos-=BOUNCE;
}
else 
	xpos+=xVel;

if(xpos>0 && xpos<SCREEN_WIDTH)
	{
		hasEntered = 1;
	}

}

//shows the enemy on the screen
void Rmachamp::show(SDL_Surface * screen, int count)
{	if(!isDead())
	apply_surface(xpos,ypos,sprite,screen,&clips[count%3]);
}

void Rmachamp::setClips()
{
  //Clip range for the Machamp clips
  clips[0].x = 88;
  clips[0].y = 306;
  clips[0].w = 76;
  clips[0].h = 100;

  clips[1].x = 168;
  clips[1].y =298;
  clips[1].w = 62;
  clips[1].h = 109;

  clips[2].x = 231;
  clips[2].y = 300;
  clips[2].w = 75;
  clips[2].h = 106;

}



