//This is the abstract class for our enemies
#ifndef WEAPON_H
#define WEAPON_H
#include "SDL/SDL.h"
#include <iostream>
#include <string>
using namespace std;



class Weapon {
public:
	Weapon(int, int, int, int, int, int, string);
	void fire(int, int);
	int hit();
	virtual void display()=0;
private:
	int clipSize;
	int price;
	int ammoPrice;
	int damage;
	int fireRate;
	int reloadRate;
	SDL_Surface crosshair;
	
};

#endif

