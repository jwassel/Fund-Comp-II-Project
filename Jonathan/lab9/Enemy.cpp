
//implementation of the abstract enemy class

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Enemy.h"
#include "Sprite.h"
Enemy::Enemy(string filename, int x,int y, int w, int h, int xv, int yv, int p):Sprite(filename,x,y,w,h)
{
	xVel = xv;
	yVel = yv;
	power = p;		
}

int Enemy::getX()
{
	return xpos;
}

int Enemy::isCollidingWithDome(int x, int y, int width, int height)
{
	if(xpos>x && xpos<(x+width) && ypos>y && ypos<(y+height))
		return 1;

	return 0;
}

int Enemy::attack()
{
	return power;
}

