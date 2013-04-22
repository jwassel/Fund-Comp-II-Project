
#include "Pikachu.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Pikachu::Pikachu(string filename, int x, int y, int w, int h, int xV, int yV, int p, int hea):Enemy(filename,x,y,w,h,xV,yV,p,hea)
{
	setClips();
}

void Pikachu::move()
{
 if(ypos<550)
	ypos+=yVel;
else
	xpos+=xVel;

}

//shows the enemy on the screen
void Pikachu::show(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[count%6]);
}

void Pikachu::showAttack(SDL_Surface * screen, int count)
{
	apply_surface(xpos,ypos,sprite,screen,&clips[(count%4)+7]);
}

void Pikachu::setClips()
{
  //Clip range for the Pikachu clips
  clips[0].x = 5;
  clips[0].y = 162;
  clips[0].w = 53;
  clips[0].h = 32;

  clips[1].x = 60;
  clips[1].y = 162;
  clips[1].w = 54;
  clips[1].h = 32;

  clips[2].x = 117;
  clips[2].y = 162;
  clips[2].w = 54;
  clips[2].h = 32;

  clips[3].x = 175;
  clips[3].y = 162;
  clips[3].w = 54;
  clips[3].h = 32;
  
  clips[4].x = 17;
  clips[4].y = 285;
  clips[4].w = 43;
  clips[4].h = 40;
  
  clips[5].x = 115;
  clips[5].y = 274;
  clips[5].w = 43;
  clips[5].h = 60;
  
  clips[6].x = 320;
  clips[6].y = 15;
  clips[6].w = 34;
  clips[6].h = 225;
  
  clips[7].x = 372;
  clips[7].y = 15;
  clips[7].w = 34;
  clips[7].h = 225;
  
  clips[8].x = 422;
  clips[8].y = 15;
  clips[8].w = 50;
  clips[8].h = 225;
  
  clips[9].x = 479;
  clips[9].y = 15;
  clips[9].w = 67;
  clips[9].h = 225;
  
  clips[10].x = 553;
  clips[10].y = 15;
  clips[10].w = 65;
  clips[10].h = 225;
}



