
#ifndef SQUIRTLE_H
#define SQUIRTLE_H
#include "Enemy.h"
#include "Sprite.h"
#include <string>
class Squirtle: public Enemy
{
	public:
		Squirtle(string,int, int, int ,int); //constructor
		 virtual void move(); //move function

};
#endif
