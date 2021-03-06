
#include "Rzapdos.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rzapdos::Rzapdos(string filename, int x, int y, int w, int h, int xV, int yV, int p, int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Rzapdos::move()
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
void Rzapdos::show(SDL_Surface * screen, int count)
{	
	if(!isDead())
	apply_surface(xpos,ypos,sprite,screen,&clips[count%3]);
}

void Rzapdos::setClips()
{
  //Clip range for the Rzapdos clips
  clips[0].x = 44;
  clips[0].y = 235;
  clips[0].w = 58;
  clips[0].h = 90;

  clips[1].x = 102;
  clips[1].y = 235;
  clips[1].w = 75;
  clips[1].h = 90;

  clips[2].x = 177;
  clips[2].y = 235;
  clips[2].w = 95;
  clips[2].h = 90;

}



