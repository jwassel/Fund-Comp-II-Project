//Header file for the abstract class for our Bombs
#ifndef AMMO_H
#define AMMO_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Item.h"
#include "Constants.h"
#include <iostream>
#include <string>
using namespace std;
class Ammo: public Item{
public:
	Ammo(string,int,int,int,int); //constructor
	void setClips(); //sets the clip fo the Bomb (how it will look on the store screen)
	virtual void showInStore(SDL_Surface*);
	virtual int isClicked(int,int);
	int getHeight();
	int getWidth();
	void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
	SDL_Surface * load_image(string);

protected:
	
	int xpos;
	int ypos;
	SDL_Rect clips[5];
	int numberOnSheet;
	
};

#endif
