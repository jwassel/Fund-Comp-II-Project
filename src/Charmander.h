
#ifndef CHARMANDER_H
#define CHARMANDER_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Charmander: public Enemy
{
	public:
		Charmander(string,int, int, int , int, int ,int, int,int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[6]; //the number of clips in the Charmander sprite sheet

};
#endif
