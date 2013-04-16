
#ifndef Rmarowak_H
#define Rmarowak_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Rmarowak: public Enemy
{
	public:
		Rmarowak(string,int, int, int , int, int ,int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[3]; //the number of clips in the Rmarowak sprite sheet

};
#endif
