#ifndef SPRITE_H
#define SPRITE_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
class Sprite
{
	public:
		Sprite(string);
	private:
		SDL_Surface *surface;
};

#endif
