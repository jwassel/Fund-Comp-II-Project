
#ifndef Pidgey_H
#define Pidgey_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Pidgey: public Enemy
{
	public:
		Pidgey(string,int, int, int , int, int ,int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[4]; //the number of clips in the Pidgey sprite sheet

};
#endif
