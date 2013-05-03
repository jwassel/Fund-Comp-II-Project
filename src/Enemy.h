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
	
	int attack(); // returns the power of the pokemon
	int getY(); // returns y coordinate 
	int getWidth(); 
	int getHeight();
	int getXVel();
	void getAttacked(int, int&,int&); //removes from it's health
	int isDead(); //true if health = 0 or if they have moved on past screen

protected:

	int xVel; // how fast pokemon travels in x direction, negative or positive is determined by what side of the screen they enter from
	int yVel; // how quickly pokemon falls from above before it starts moving toward dome
	int power;// how much damgae the pokemon does to the dome
	int health; // how much health the pokemon has before it gets killed
	int dead; // 1 if its dead, 0 otherwise
	int hasEntered; // needed to make sure a level doesn't end before every pokemon has entered the screen
	bool isBouncer; // determines if pokemon continually attacks dome or just runs through it once
	//SDL_Rect *currentClip;
};

#endif

