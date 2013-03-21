//implementation of the abstract enemy class

#include "Enemy.h"

Enemy::Enemy(int x,int y, int h, int p, int s, string imageName)
{
	xpos = x;
	ypos = y;
	health = h;
	power = p;
	speed = s;
		
}
//moves the enemy across the screen, uses speed, xpos, ypos
void Enemy::move(){

}

//when an enemy first enters the map it may fall from the sky and not begin to move for 2 or 3 seconds to give the user time to prepare
void Enemy::spawn(){
}

//when health reaches zero, the enemy falls over and dies, or just disappears
void Enemy::die(){
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


