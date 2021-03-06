#ifndef PISTOL_H
#define PISTOL_H
#include "Weapon.h"
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Pistol:public Weapon
{
	public:
		Pistol(string,string,string,int, int,int,int,int,int,int,int,int,int,int);//constructor
		virtual void setClips();
		virtual void fire();
		virtual void showInStore(SDL_Surface *); //shows the weapon on the screen
		int getWidth();
		int getHeight();
		virtual int isClicked(int,int);
		void showDuringGamePlay(int ,int , SDL_Surface * );
	private:
		SDL_Rect clips;
};
#endif
