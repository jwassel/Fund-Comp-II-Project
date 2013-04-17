
#ifndef MACHAMP_H
#define MACHAMP_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Machamp: public Enemy
{
	public:
		Squirtle(string,int, int, int , int, int ,int, int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[3]; //the number of clips in the squirtle sprite sheet

};
#endif
