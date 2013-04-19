
#include "Squirtle.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Squirtle::Squirtle(string filename, int x, int y, int w, int h, int xV, int yV, int p,int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Squirtle::move()
{
 if(ypos+height<GROUND)
	ypos+=yVel;
else if (isbouncer){
if(xpos>=DOME_BASE_X_END)
	xpos+=xVel;
else 
	xpos+=BOUNCE;
}
else 
	xpos+=xVel;

if(xpos>0 && xpos<SCREEN_WIDTH)
	{
		hasEntered = 1;
	}
}

//shows the enemy on the screen
void Squirtle::show(SDL_Surface * screen, int count)
{
	if(!isDead())
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Squirtle::setClips()
{
  //Clip range for the squirtle clips
  clips[0].x = 0;
  clips[0].y = 108;
  clips[0].w = 38;
  clips[0].h = 36;

  clips[1].x = 38;
  clips[1].y = 108;
  clips[1].w = 38;
  clips[1].h = 36;

  clips[2].x = 76;
  clips[2].y = 108;
  clips[2].w = 40;
  clips[2].h = 36;

  clips[3].x = 115;
  clips[3].y = 108;
  clips[3].w = 39;
  clips[3].h = 38;

  clips[4].x = 155;
  clips[4].y = 108;
  clips[4].w = 37;
  clips[4].h = 36;

  clips[5].x = 192;
  clips[5].y = 108;
  clips[5].w = 39;
  clips[5].h = 36;

}


