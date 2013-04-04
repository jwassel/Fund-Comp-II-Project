#ifndef PLASMACANNON_H
#define PLASMACANNON_H
#include "weapon.h"
#include <string>


class plasmaCannon: public weapon
{
	public:
		plasmaCannon(int, int, int, int, int, int, int); //constructor
		virtual void fire(); //moves the enemy; diff for every enemy so virtual
		virtual void setClips();
		virtual void show(SDL_Surface *); //shows the enemy on the screen

	private:
		SDL_Rect clips; //the number of clips in the squirtle sprite sheet

};
#endif
