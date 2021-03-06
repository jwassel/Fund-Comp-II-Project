
#include "Charmander.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Charmander::Charmander(string filename, int x, int y, int w, int h, int xV, int yV, int p, int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Charmander::move()
{
 if(ypos+height<GROUND)
	ypos+=yVel;
else if (isBouncer){
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
void Charmander::show(SDL_Surface * screen, int count)

{if(!isDead())

	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Charmander::setClips()
{
  //Clip range for the Charmander clips
  clips[0].x = 0;
  clips[0].y = 0;
  clips[0].w = 34;
  clips[0].h = 32;

  clips[1].x = 200;
  clips[1].y = 0;
  clips[1].w = 34;
  clips[1].h = 32;

  clips[2].x = 264;
  clips[2].y = 0;
  clips[2].w = 34;
  clips[2].h = 32;

  clips[3].x = 300;
  clips[3].y = 0;
  clips[3].w = 34;
  clips[3].h = 32;

  clips[4].x = 331;
  clips[4].y = 0;
  clips[4].w = 34;
  clips[4].h = 32;

  clips[5].x = 364;
  clips[5].y = 0;
  clips[5].w = 34;
  clips[5].h = 32;

}



