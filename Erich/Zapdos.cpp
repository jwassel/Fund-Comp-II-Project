
#include "Zapdos.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Zapdos::Zapdos(string filename, int x, int y, int w, int h, int xV, int yV, int p, int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Zapdos::move()
{
 if(ypos<550)
	ypos+=yVel;
else
	xpos+=xVel;

}

//shows the enemy on the screen
void Zapdos::show(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[count%3]);
}

void Zapdos::setClips()
{
  //Clip range for the Zapdos clips
  clips[0].x = 30;
  clips[0].y = 326;
  clips[0].w = 79;
  clips[0].h = 100;

  clips[1].x = 109;
  clips[1].y =326;
  clips[1].w = 79;
  clips[1].h = 100;

  clips[2].x = 195;
  clips[2].y = 326;
  clips[2].w = 79;
  clips[2].h = 100;
}



