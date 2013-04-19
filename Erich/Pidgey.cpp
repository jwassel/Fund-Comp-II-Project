
#include "Pidgey.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Pidgey::Pidgey(string filename, int x, int y, int w, int h, int xV, int yV, int p,int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Pidgey::move()
{
 if(ypos+height<GROUND)
	ypos+=yVel;
else
	xpos+=xVel;


	if(xpos>0 && xpos<SCREEN_WIDTH)
	{
		hasEntered = 1;
	}

}

//shows the enemy on the screen
void Pidgey::show(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Pidgey::setClips()
{
  //Clip range for the Pidgey clips
clips[0].x = 8;
  clips[0].y = 7;
  clips[0].w = 37;
  clips[0].h = 30;

  clips[1].x = 48;
  clips[1].y = 7;
  clips[1].w = 37;
  clips[1].h = 30;

  clips[2].x = 88;
  clips[2].y = 7;
  clips[2].w = 37;
  clips[2].h = 30;

  clips[3].x = 131;
  clips[3].y = 7;
  clips[3].w = 37;
  clips[3].h = 30;


}



