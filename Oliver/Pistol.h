#ifndef PISTOL_H
#define PISTOL_H
#include "Weapon.h"
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Pistol:public Weapon
{
	public:
		Pistol(string,string,int, int,int,int,int,int,int);//constructor
		virtual void setClips();
		virtual void fire();
		virtual void show(SDL_Surface *); //shows the weapon on the screen

	private:
		SDL_Rect clips;
};
#endif
