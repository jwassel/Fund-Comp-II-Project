#ifndef PISTOL_H
#define PISTOL_H
#include "Weapon.h"
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Pistol:public Weapon
{
	public:
		Pistol(string,int, int,int,int,int,int,int);//constructor
		void setClips();
		void fire();

	private:
		SDL_Rect clips[1];
};
#endif
