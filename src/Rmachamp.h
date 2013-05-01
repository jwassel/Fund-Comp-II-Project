
#ifndef RMACHAMP_H
#define RMACHAMP_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Rmachamp: public Enemy
{
	public:
		Rmachamp(string,int, int, int , int, int ,int, int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[3]; //the number of clips in the squirtle sprite sheet

};
#endif
