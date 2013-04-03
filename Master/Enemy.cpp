
//implementation of the abstract enemy class

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Enemy.h"
#include "Sprite.h"
Enemy::Enemy(string filename, int x,int y, int w, int h, int xv, int yv):Sprite(filename,x,y,w,h)
{
	xVel = xv;
	yVel = yv;		
}

int Enemy::getX()
{
	return xpos;
}


