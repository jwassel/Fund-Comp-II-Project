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
	void setClips(); //sets the clip for the ammo using the sprite sheet
	virtual void showInStore(SDL_Surface*); // displays the image in the store using apply_surface
	virtual int isClicked(int,int); // 1 if image in store is clicked, 0 otherwise
	int getHeight(); // returns height of image
	int getWidth(); // returns width of image- used in isClicked with height
	void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip); // applies image to the screen
	SDL_Surface * load_image(string); // loads images of ammo

protected:
	
	int xpos; // x position for image in store
	int ypos; // y position for image in store
	SDL_Rect clips[5]; // clips of images
	int numberOnSheet; 
	
};

#endif
