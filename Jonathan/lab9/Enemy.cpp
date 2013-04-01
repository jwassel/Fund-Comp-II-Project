
//implementation of the abstract enemy class

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Enemy.h"
#include "Sprite.h"
Enemy::Enemy(string filename, int x,int y, int xv, int yv):Sprite(filename)
{
	xpos = x;
	ypos = y;
	xVel = xv;
	yVel = yv;		
}

//shows the enemy on the screen
void Enemy::show(SDL_Surface * screen)
{
	Sprite::apply_surface(xpos,ypos,sprite,screen);
}


