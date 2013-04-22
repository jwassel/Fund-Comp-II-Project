#ifndef RPIKACHU_H
#define RPIKACHU_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>

class Rpikachu: public Enemy
{
	public:
		Rpikachu(string,int, int, int, int , int, int ,int, int); //constructor
		 virtual void move(); //move function
		virtual void show(SDL_Surface*,int);
		virtual void setClips();
		void showAttack(SDL_Surface * screen, int count);


	private:
		SDL_Rect clips[11]; //the number of clips in the Rpikachu sprite sheet

};
#endif
