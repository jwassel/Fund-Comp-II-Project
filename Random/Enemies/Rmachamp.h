
#ifndef Rmachamp_H
#define Rmachamp_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Rmachamp: public Enemy
{
	public:
		Rmachamp(string,int, int, int , int, int ,int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[3]; //the number of clips in the Rmachamp sprite sheet

};
#endif
