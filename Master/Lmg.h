#ifndef LMG_H
#define LMG_H
#include "Weapon.h"
#include <string>


class Lmg: public Weapon
{
	public:
		Lmg(string, string, int, int, int, int, int, int, int); //constructor
		virtual void fire(); //moves the enemy; diff for every enemy so virtual
		virtual void setClips();
		virtual void show(SDL_Surface *); //shows the enemy on the screen
		int getWidth();
		int getHeight();
		int isClicked(int, int);

	private:
		SDL_Rect clips; //the number of clips in the squirtle sprite sheet

};
#endif
