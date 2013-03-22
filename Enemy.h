//This is the abstract class for our enemies
#ifndef ENEMY_H
#define ENEMY_H
#include "SDL/SDL.h"
#include "Sprite.h"
#include <iostream>
#include <string>
using namespace std;



class Enemy: public Sprite {
public:
	Enemy(int, int, int, int, int, string);
	virtual void move()=0;
	void spawn();
	void die();
	int attack();
	int isColliding();
	int getEnemyHealth();	
	void getHit(int);
	int isDead();
private:
	int xpos;
	int ypos;
	int health;
	int power;
	int speed;
};

#endif

