
#include "Rarticuno.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rarticuno::Rarticuno(string filename, int x, int y, int w, int h, int xV, int yV, int p,int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Rarticuno::move()
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
void Rarticuno::show(SDL_Surface * screen, int count)
{	if(!isDead())
	apply_surface(xpos,ypos,sprite,screen,&clips[count%3]);
}

void Rarticuno::setClips()
{
  //Clip range for the Rarticuno clips
  clips[0].x = 528;
  clips[0].y = 38;
  clips[0].w = 150;
  clips[0].h = 63;

  clips[1].x = 691;
  clips[1].y = 38;
  clips[1].w = 154;
  clips[1].h = 63;

  clips[2].x = 993;
  clips[2].y = 0;
  clips[2].w = 128;
  clips[2].h = 101;

  clips[3].x = 528;
  clips[3].y = 38;
  clips[3].w = 150;
  clips[3].h = 63;

  clips[4].x = 691;
  clips[4].y = 38;
  clips[4].w = 154;
  clips[4].h = 63;

  clips[5].x = 993;
  clips[5].y = 0;
  clips[5].w = 128;
  clips[5].h = 101;

}



