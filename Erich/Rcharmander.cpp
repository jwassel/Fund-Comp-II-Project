
#include "Rcharmander.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rcharmander::Rcharmander(string filename, int x, int y, int w, int h, int xV, int yV, int p, int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Rcharmander::move()
{
 if(ypos+height<GROUND)
	ypos+=yVel;
else if (xpos+width<DOME_BASE_X_BEG)
	xpos+=xVel;
<<<<<<< HEAD
	
	if(xpos>0 && xpos<SCREEN_WIDTH)
	{
		hasEntered = 1;
	}
=======
else 
	xpos+=BOUNCE;
>>>>>>> 6dbdf64e70989ff50dc8b4a2ad87aadeec74bccd

}

//shows the enemy on the screen
void Rcharmander::show(SDL_Surface * screen, int count)
<<<<<<< HEAD
{	if(!isDead())
=======
{if(!isDead())
>>>>>>> 6dbdf64e70989ff50dc8b4a2ad87aadeec74bccd
	apply_surface(xpos,ypos,sprite,screen,&clips[count%4]);
}

void Rcharmander::setClips()
{
  //Clip range for the Rcharmander clips
  clips[0].x = 149;
  clips[0].y = 4;
  clips[0].w = 31;
  clips[0].h = 30;

  clips[1].x = 180;
  clips[1].y = 4;
  clips[1].w = 31;
  clips[1].h = 30;

  clips[2].x = 214;
  clips[2].y = 4;
  clips[2].w = 31;
  clips[2].h = 30;

  clips[3].x = 246;
  clips[3].y = 4;
  clips[3].w = 31;
  clips[3].h = 30;

}



