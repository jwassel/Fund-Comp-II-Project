
#include "Poliwhirl.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Poliwhirl::Poliwhirl(string filename, int x, int y, int w, int h, int xV, int yV):Enemy(filename,x,y,w,h,xV,yV)
{
	setClips();
}

void Poliwhirl::move()
{
    //Move the dot left or right
    xpos += xVel;

    //Move the dot up or down
    ypos += yVel;

}

//shows the enemy on the screen
void Poliwhirl::show(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Poliwhirl::setClips()
{
  //Clip range for the squirtle clips
  clips[0].x = 0;
  clips[0].y = 169;
  clips[0].w = 69;
  clips[0].h = 82;

  clips[1].x = 75;
  clips[1].y = 166;
  clips[1].w = 87;
  clips[1].h = 77;

  clips[2].x = 163;
  clips[2].y = 167;
  clips[2].w = 75;
  clips[2].h = 81;

  clips[3].x = 238;
  clips[3].y = 169;
  clips[3].w = 100;
  clips[3].h = 85;

  clips[4].x = 340;
  clips[4].y = 169;
  clips[4].w = 109;
  clips[4].h = 85;

  clips[5].x = 448;
  clips[5].y = 165;
  clips[5].w = 118;
  clips[5].h = 80;

}


