#ifndef lmg_H
#define lmg_H
#include "weapon.h"
#include <string>


class lmg: public weapon
{
	public:
		lmg(int, int, int, int, int, int, int); //constructor
		virtual void fire(); //moves the enemy; diff for every enemy so virtual
		virtual void setClips();
		virtual void show(SDL_Surface *); //shows the enemy on the screen

	private:
		SDL_Rect clips; //the number of clips in the squirtle sprite sheet

};
#endif
