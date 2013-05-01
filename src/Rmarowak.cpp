
#include "Rmarowak.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rmarowak::Rmarowak(string filename, int x, int y, int w, int h, int xV, int yV, int p, int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Rmarowak::move()
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
void Rmarowak::show(SDL_Surface * screen, int count)
{	if(!isDead())
	apply_surface(xpos,ypos,sprite,screen,&clips[count%3]);
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



