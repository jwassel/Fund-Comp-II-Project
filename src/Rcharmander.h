
#ifndef RCHARMANDER_H
#define RCHARMANDER_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Rcharmander: public Enemy
{
	public:
		Rcharmander(string,int, int, int , int, int ,int, int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[4]; //the number of clips in the Rcharmander sprite sheet

};
#endif
