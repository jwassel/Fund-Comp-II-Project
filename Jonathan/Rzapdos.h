
#ifndef Rzapdos_H
#define Rzapdos_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Rzapdos: public Enemy
{
	public:
		Rzapdos(string,int, int, int , int, int ,int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[3]; //the number of clips in the Rzapdos sprite sheet

};
#endif
