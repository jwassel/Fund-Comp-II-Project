//implementation of the abstract enemy class

#include "Enemy.h"

Enemy::Enemy(int x,int y, int h, int p, int xv, int yv)
{
	xpos = x;
	ypos = y;
	health = h;
	power = p;
	xVel = xv;
	yVel = yv;
		
}


//when an enemy first enters the map it may fall from the sky and not begin to move for 2 or 3 seconds to give the user time to prepare
void Enemy::spawn(){
}

//when health reaches zero, the enemy falls over and dies, or just disappears
void Enemy::die(){
}

void Enemy::move()
{
    //Move the dot left or right
    xpos += xVel;

    //If the dot went too far to the left or right
    if( ( xpos < 0 ) || ( xpos > 1200 ) )
    {
        //move back
        xpos -= xVel;
    }

    //Move the dot up or down
    ypos += yVel;

    //If the dot went too far up or down
    if( ( ypos < 0 ) || ( ypos > 600 ) )
    {
        //move back
        ypos -= yVel;
    }
}


//returns the amount of damage the pokemon does to the dome
int Enemy::attack(){
return power;
}

//checks to see if pokemon is close enough to attack
int Enemy::isColliding(){

}

//if enemy is shot, take away health points
void Enemy::getHit(int value){
health-=value;
}

//returns the amount of health left for the enemy
int Enemy::getEnemyHealth(){
return health;
}

//checks to see if enemy is dead
int Enemy::isDead(){
if(health<=0)
return 1;

return 0;
}

int Enemy::getX()
{
	return xpos;
}

int Enemy::getY()
{
	return ypos;
}


