
#include "Moltres.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Moltres::Moltres(string filename, int x, int y, int w, int h, int xV, int yV, int p,int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Moltres::move()
{
if(isBouncer){
if (xpos>=DOME_HEAD_X_END)
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
void Moltres::show(SDL_Surface * screen, int count)

{	if(!isDead())
	apply_surface(xpos,ypos,sprite,screen,&clips[count%8]);
}

void Moltres::setClips()
{
  //Clip range for the Moltres clips
  clips[0].x = 4;
  clips[0].y =289;
  clips[0].w = 114;
  clips[0].h = 110;

  clips[1].x =149;
  clips[1].y = 288;
  clips[1].w = 141;
  clips[1].h = 110;

  clips[2].x = 285;
  clips[2].y = 292;
  clips[2].w = 130;
  clips[2].h = 110;

  clips[3].x = 432;
  clips[3].y = 290;
  clips[3].w = 132;
  clips[3].h = 110;

  clips[4].x = 582;
  clips[4].y = 276;
  clips[4].w = 130;
  clips[4].h = 110;

  clips[5].x = 726;
  clips[5].y = 276;
  clips[5].w = 132;
  clips[5].h = 110;

  clips[6].x = 876;
  clips[6].y = 276;
  clips[6].w = 136;
  clips[6].h = 110;

  clips[7].x = 1020;
  clips[7].y = 276;
  clips[7].w = 136;
  clips[7].h = 110;

}



