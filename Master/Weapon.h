//Header file for the abstract class for our weapons
#ifndef WEAPON_H
#define WEAPON_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Constants.h"
#include "Item.h"
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
	void handle_events(SDL_Event ,vector<Enemy*>,SDL_Surface*, int &, int&); //handles when the user clicks since this means they're firing a weapon
	void showExplosion(int,int,SDL_Surface *); //shows the explosion for the particular weapon
	int getXpos();
	int getYpos();
	int getSize();
	//int getPrice();
	int getCurrentClipAmmo();
	bool addToCurrentAmmo(int);
	int getCurrentAmmo();
	int getMaxClipAmmo();
	string getName();
	int getMaxAmmo();
	virtual void showDuringGamePlay(int, int, SDL_Surface*)=0;

protected:
	
	string name;
	SDL_Surface * explosionImage; //the image shown when the fire
	int clipsize;
	int ammoPrice; //price to buy ammo
	int damage; //how much damamge it does when fired at something
	int fireRate;
	int explosionSize;
	int maxAmmo;
	int reloadTime;
	int currentAmmo;
	int currentClipAmmo;
	int maxClipAmmo;
};

#endif
