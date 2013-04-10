//Header file for background class which just shows the game's background
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
using namespace std;
class Background
{
	public:
		Background(string);
		void show(SDL_Surface *);
	private:	
		SDL_Surface *image; //the actual image
		//helper functions
		void apply_surface(SDL_Surface*,SDL_Surface*);
		SDL_Surface* load_image(string);
};
#endif
