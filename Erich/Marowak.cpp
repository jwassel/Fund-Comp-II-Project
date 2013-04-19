
#include "Marowak.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Marowak::Marowak(string filename, int x, int y, int w, int h, int xV, int yV,int p, int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Marowak::move()
{
 if(ypos<550)
	ypos+=yVel;
else
	xpos+=xVel;

	if(xpos>0 && xpos<SCREEN_WIDTH)
	{
		hasEntered = 1;
	}
}

//shows the enemy on the screen
void Marowak::show(SDL_Surface * screen, int count)
{	if(!isDead())
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Marowak::setClips()
{
  //Clip range for the Marowak clips
  clips[0].x = 0;
  clips[0].y = 92;
  clips[0].w = 95;
  clips[0].h = 107;

  clips[1].x = 100;
  clips[1].y = 92;
  clips[1].w = 111;
  clips[1].h = 107;

  clips[2].x = 212;
  clips[2].y = 92;
  clips[2].w = 111;
  clips[2].h = 107;

}



