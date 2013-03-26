//This is the abstract class for our enemies
#ifndef ENEMY_H
#define ENEMY_H
#include "SDL/SDL.h"
#include <iostream>
#include <string>
using namespace std;



class Enemy{
public:
	Enemy(int = 0, int  = 0, int = 0, int = 0, int = 0,int = 0);
	virtual void move() = 0;
	void spawn();
	void die();
	int attack();
	int isColliding();
	int getEnemyHealth();	
	void getHit(int);
	int isDead();
	int getX();
	int getY();
protected:
	int xpos;
	int ypos;
	int health;
	int power;
	int xVel;
	int yVel;
};

#endif

