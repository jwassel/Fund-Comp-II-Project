
#ifndef ARTICUNO_H
#define ARTICUNO_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Articuno: public Enemy
{
	public:
		Articuno(string,int, int, int , int,int, int ,int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[7]; //the number of clips in the Articuno sprite sheet

};
#endif
