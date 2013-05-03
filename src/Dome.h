/* Header file for Dome class*/
#ifndef DOME_H
#define DOME_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Constants.h"
using namespace std;
class Dome
{
	public:
		Dome(string,int,int,int,int,int,int);
		void show(SDL_Surface*); // shows diff clip on screen depending on its current health
		void setClips(); // sets three clips on sprite sheet
		int getX(); // returns x of dome
		int getY(); // returns y of dome
		int getWidth(); // returns width of dome
		int getHeight(); // returns height of dome
		void getAttacked(int); // reduces its health
		int getCurrentHealth(); // returns current health of dome
		void setHealth(int); // sets health of dome to input
		int isDead(); // returns 1 if dead, 0 otherwise
		int isCollidingWithEnemy(int, int, int, int, int); //returns true if is colliding with the enemy's parameters which are passed in
		bool addToCurrentHealth(int); // adds to current health of dome when a user purchases more
	private:
		SDL_Surface* sprite;
		SDL_Rect clips[3]; // change this when get new clips
		int xpos; // x coordinate of dome
		int ypos; // y coordinate of dome
		int width; // width of dome
		int height; // height of dome
		int maxHealth; // max health is usually set to 500 at beginning
		int currentHealth; // keeps track of health as dome is attacked and user purchases more
		//helper functions
		SDL_Surface* load_image(string); // standard load image function
		void apply_surface(SDL_Surface*,SDL_Surface*,SDL_Rect*); // standard function to apply image to screen
		
};

#endif
