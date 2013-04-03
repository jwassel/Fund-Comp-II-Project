
//This is the abstract class for our enemies
#ifndef ENEMY_H
#define ENEMY_H
#include "SDL/SDL.h"
#include "Sprite.h"
#include <iostream>
#include <string>
using namespace std;
class Enemy:public Sprite{
public:
	Enemy( string, int, int, int, int); //constructor
	virtual void move()=0; //moves the enemy; diff for every enemy so virtual
  	virtual void show(SDL_Surface *); //shows the enemy on the screen
	int getX();

protected:
	int xpos;
	int ypos;
	int xVel;
	int yVel;
};

#endif

