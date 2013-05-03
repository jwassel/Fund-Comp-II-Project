//Header file for the abstract class for our weapons
#ifndef WEAPON_H
#define WEAPON_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Constants.h"
#include "Item.h"
#include "Crosshairs.h"
#include <iostream>
#include <string>
#include "Enemy.h"
using namespace std;
class Weapon:public Item{
public:
	Weapon(string,string,string,int,int,int,int,int,int,int,int,int,int,int); //constructor
	virtual void fire()=0; 
	virtual void setClips()=0; //sets the clip fo the weapon (how it will look on the store screen)
	virtual void showInStore(SDL_Surface *)=0; //shows the weapon on the screen
	virtual void apply_surface(int, int, SDL_Surface *,SDL_Surface *,SDL_Rect * = NULL); //applies new surface
	virtual SDL_Surface * load_image(string); //takes in image of sprite
	void handle_events(SDL_Event ,vector<Enemy*>,SDL_Surface*, int &, int&, Crosshairs &); //handles when the user clicks since this means they're firing a weapon
	void showExplosion(int,int,SDL_Surface *); //shows the explosion for the particular weapon
	int getXpos(); // returns x coordinate 
	int getYpos(); // returns y coordinate
	int getSize(); 
	int getCurrentClipAmmo();// returns number of shots in the clip the user is currently using
	bool addToCurrentAmmo(int); // adds to ammo when user purchases more
	int getCurrentAmmo(); // total number of shots the user has for a weapon overall
	int getMaxClipAmmo(); // max number of shots for the clip of a certain weapon
	string getName();
	int getMaxAmmo(); // max number of shots the user can hold for a particular weapon
	virtual void showDuringGamePlay(int, int, SDL_Surface*)=0;
	void setCurrentClipAmmo(int); // sets current clip ammo to input
	virtual void setCurrentAmmo(int); // sets overall total current ammo to input

protected:
	
	string name;
	SDL_Surface * explosionImage; //the image shown when the fire
	int clipsize; // number of shots per clip for a weapon
	int ammoPrice; // price to buy ammo
	int damage; // how much damamge it does when fired at something
	int fireRate; // how quickly weapon can fire
	int explosionSize; // how big the explosion is every time the weapon is fired
	int maxAmmo; // the max number of total shots the user is allowed to hold for a weapon
	int reloadTime; // how long it takes to reload the weapon
	int currentAmmo; // current total ammo the user has for the weapon
	int currentClipAmmo; // current ammo in the clip for the weapon
	int maxClipAmmo; // max number of shots for a clip for a particular weapon
	int crosshairsReloadTime; // how long before the crosshair changes back to green
};

#endif
