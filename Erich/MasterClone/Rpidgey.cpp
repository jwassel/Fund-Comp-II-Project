
#include "Rpidgey.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rpidgey::Rpidgey(string filename, int x, int y, int w, int h, int xV, int yV, int p, int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{	isPikachu=false;
	setClips();
}

void Rpidgey::move()
{

if(isBouncer){
if (xpos+width<=DOME_HEAD_X_BEG)
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
void Rpidgey::show(SDL_Surface * screen, int count)
{
	if(!isDead())
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Rpidgey::setClips()
{
  //Clip range for the squirtle clips
  clips[0].x = 1;
  clips[0].y = 137;
  clips[0].w = 37;
  clips[0].h = 30;

  clips[1].x = 48;
  clips[1].y = 137;
  clips[1].w = 37;
  clips[1].h = 30;

  clips[2].x = 88;
  clips[2].y = 137;
  clips[2].w = 37;
  clips[2].h = 30;

  clips[3].x = 131;
  clips[3].y = 137;
  clips[3].w = 37;
  clips[3].h = 30;

  clips[4].x = 1;
  clips[4].y = 137;
  clips[4].w = 37;
  clips[4].h = 30;

  clips[5].x = 48;
  clips[5].y = 137;
  clips[5].w = 37;
  clips[5].h = 30;

}


