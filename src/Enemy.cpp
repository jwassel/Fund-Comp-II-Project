
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
	int i= rand()%2; // random whether the enemy bounces off the dome and continues to attack it or just goes right through it
	if(i)
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
		// pokemon is considered dead if it ran through the dome and out the other side even if the user never shot it
		return 1;
	}

	return 0;
}
//reduces the enemy's health by damage
void Enemy::getAttacked(int damage, int &score, int&money)
{
	health-=damage; // take away health from the enemy equal to the amount of damage of the weapon or bomb that attacks it
	if(isDead())
	{
		dead = 1;
		score+=KILL_BONUS; // give user a score bonus for killing pokemon
		money+=KILL_BONUS; // give user more money for killing pokemon
	}
}

