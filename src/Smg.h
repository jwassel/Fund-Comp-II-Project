#ifndef SMG_H
#define SMG_H
#include "Weapon.h"
#include <string>


class Smg: public Weapon
{
	public:
		Smg(string, string, string,int, int, int, int, int, int,int,int,int,int,int); //constructor
		virtual void fire(); //moves the enemy; diff for every enemy so virtual
		virtual void setClips();
		virtual void showInStore(SDL_Surface *); //shows the enemy on the screen
		int getWidth();
		int getHeight();
		int isClicked(int, int);
void showDuringGamePlay(int ,int , SDL_Surface * );
	private:
		SDL_Rect clips; //the number of clips in the squirtle sprite sheet

};
#endif
