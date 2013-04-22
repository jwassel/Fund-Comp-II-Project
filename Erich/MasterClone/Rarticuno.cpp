
#include "Rarticuno.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rarticuno::Rarticuno(string filename, int x, int y, int w, int h, int xV, int yV, int p,int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{	isPikachu=false;
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
	apply_surface(xpos,ypos,sprite,screen,&clips[count%7]);
}

void Rarticuno::setClips()
{
  //Clip range for the Rarticuno clips
  clips[0].x = 45;
  clips[0].y = 37;
  clips[0].w = 152;
  clips[0].h = 59;

  clips[1].x = 208;
  clips[1].y = 35;
  clips[1].w = 151;
  clips[1].h = 58;

  clips[2].x = 364;
  clips[2].y = 39;
  clips[2].w = 152;
  clips[2].h = 59;

  clips[3].x = 528;
  clips[3].y = 38;
  clips[3].w = 154;
  clips[3].h = 63;

  clips[4].x = 691;
  clips[4].y = 38;
  clips[4].w = 143;
  clips[4].h = 66;

  clips[5].x = 841;
  clips[5].y = 43;
  clips[5].w = 145;
  clips[5].h = 65;

  clips[6].x = 995;
  clips[6].y = 0;
  clips[6].w = 133;
  clips[6].h = 99;

}



