#ifndef GATLING_H
#define GATLING_H
#include "Weapon.h"
#include <string>


class Gatling: public Weapon
{
	public:
		Gatling(string, string, string, int, int, int, int, int, int,int,int,int,int,int); //constructor
		virtual void fire(); //moves the enemy; diff for every enemy so virtual
		virtual void setClips();
		virtual void showInStore(SDL_Surface *); //shows the enemy on the screen
		int getWidth();
		int getHeight();
		virtual int isClicked(int, int);
void showDuringGamePlay(int ,int , SDL_Surface * );
	private:
		SDL_Rect clips; //the number of clips in the squirtle sprite sheet

};
#endif
