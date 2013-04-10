/* Header file for Dome class*/
#ifndef DOME_H
#define DOME_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
using namespace std;
class Dome
{
	public:
		Dome(string,int,int,int,int,int,int);
		void show(SDL_Surface*); //shows diff clip on screen depending on its current health
		void setClips(); //sets three clips on sprite sheet
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		void getAttacked(int); //reduces its health
		int getCurrentHealth();
		int isDead();
		int isCollidingWithEnemy(int, int, int, int, int); //returns true if is colliding with the enemy's parameters which are passed in
	private:
		SDL_Surface* sprite;
		SDL_Rect clips[3]; //change this when get new clips
		int xpos;
		int ypos;
		int width;
		int height;
		int maxHealth;
		int currentHealth;
		//helper functions
		SDL_Surface* load_image(string);
		void apply_surface(SDL_Surface*,SDL_Surface*,SDL_Rect*);
		
};

#endif
