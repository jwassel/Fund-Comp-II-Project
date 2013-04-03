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
		void show(SDL_Surface*);
		void setClips();
	private:
		SDL_Surface* sprite;
		SDL_Rect clips[1]; //change this when get new clips
		int xpos;
		int ypos;
		int width;
		int height;
		int maxHealth;
		int currentHealth;
		SDL_Surface* load_image(string);
		void apply_surface(SDL_Surface*,SDL_Surface*,SDL_Rect*);
		
};

#endif
