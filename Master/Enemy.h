//Header file for the Enemy class
//This is the abstract class for our enemies
#ifndef ENEMY_H
#define ENEMY_H
#include "SDL/SDL.h"
#include "Sprite.h"
#include <iostream>
#include <string>
#include "Constants.h"
using namespace std;
class Enemy:public Sprite{
public:
	Enemy( string, int, int, int, int, int, int,int,int); //constructor
	virtual void move()=0; //moves the enemy; diff for every enemy so virtual
	virtual void setClips() = 0; //sets the clips on the sprite sheet
  	virtual void show(SDL_Surface *, int) = 0; //shows the enemy on the screen
	int getX();
	
	int attack(); //returns the attack variable
	int getY();
	int getWidth();
	int getHeight();
	int getXVel();
	void getAttacked(int, int&,int&); //removes from it's health
	int isDead(); //true if health = 0 or if they have moved on past screen

protected:

	int xVel;
	int yVel;
	int power;
	int health;
	int dead;
	//SDL_Rect *currentClip;
};

#endif

