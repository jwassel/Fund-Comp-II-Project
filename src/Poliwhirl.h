
#ifndef POLIWHIRL_H
#define POLIWHIRL_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>
class Poliwhirl: public Enemy
{
	public:
		Poliwhirl(string,int, int, int , int, int ,int,int,int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();

	private:
		SDL_Rect clips[6]; //the number of clips in the squirtle sprite sheet

};
#endif
