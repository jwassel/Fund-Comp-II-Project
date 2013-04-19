
#ifndef RARTICUNO_H
#define RARTICUNO_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Rarticuno: public Enemy
{
	public:
		Rarticuno(string,int, int, int,int , int, int ,int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();


	private:
		SDL_Rect clips[3]; //the number of clips in the Rarticuno sprite sheet

};
#endif
