
//Implementation of the abstract enemy class

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Enemy.h"
#include "Sprite.h"
//constructor
Enemy::Enemy(string filename, int x,int y, int w, int h, int xv, int yv, int p, int hea):Sprite(filename,x,y,w,h)
{
	xVel = xv;
	yVel = yv;
	power = p;	
	health = hea;
	dead = 0;
	hasEntered=0;
	int i= rand()%10 + 1;
	if(i<=5)
		isBouncer = true;
	else
		isBouncer = false;

}

int Enemy::getX()
{
	return xpos;
}


int Enemy::attack()
{
	return power;
}

int Enemy::getY()
{
	return ypos;
}

int Enemy::getWidth()
{
	return width;
}

int Enemy::getHeight()
{
	return height;
}

int Enemy::getXVel()
{
	return xVel;
}

int Enemy::isDead()
{
	if(health<=0 )
		return 1;
	if((xpos<0 || xpos >SCREEN_WIDTH) && hasEntered)
	{

		return 1;
	}

	return 0;
}
//reduces the enemy's health by damage
void Enemy::getAttacked(int damage, int &score, int&money)
{
	health-=damage;
	if(isDead())
	{
		dead = 1;
		score+=KILL_BONUS;
		money+=KILL_BONUS;
	}
}

