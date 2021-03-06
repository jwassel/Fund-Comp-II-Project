
#ifndef MAROWAK_H
#define MAROWAK_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Marowak: public Enemy
{
	public:
		Marowak(string,int, int, int , int, int, int ,int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[3]; //the number of clips in the Marowak sprite sheet

};
#endif
