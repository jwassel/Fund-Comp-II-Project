
#ifndef RMOLTRES_H
#define RMOLTRES_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Rmoltres: public Enemy
{
	public:
		Rmoltres(string,int, int, int , int,int, int ,int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[8]; //the number of clips in the Moltres sprite sheet

};
#endif
