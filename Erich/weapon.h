
//This is the abstract class for our weapons
#ifndef WEAPON_H
#define WEAPON_H
#include "SDL/SDL.h"
#include <iostream>
#include <string>
using namespace std;
class weapon{
public:
	weapon(int,int,int,int,int,int,int); //constructor
	virtual void fire()=0; //moves the enemy; diff for every enemy so virtual
	virtual void setClips()=0;
	virtual void show(SDL_Surface *) = 0; //shows the weapon on the screen
	void apply_surface(int, int, SDL_Surface *,SDL_Surface *,SDL_Rect * = NULL); //applies new surface
	SDL_Surface * load_image(string); //takes in image of sprite

protected:
	
	SDL_Surface * Weapon;
	int power;
	int clipsize;
	int price;
	int ammoPrice;
	int damage;
	int fireRate;

        int xpos;
	int ypos;
	
};

#endif
