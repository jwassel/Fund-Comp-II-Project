#ifndef ELECTRODE_H
#define ELECTRODE_H
#include "Bomb.h"
#include <string>
#include "SDL/SDL.h"
#include "Constants.h"
#include "SDL/SDL_image.h"

class Electrode:public Bomb
{
	public:
		Electrode(string,int,int,int,int);//constructor
		virtual void setClips(); //sets the clip fo the Bomb (how it will look on the store screen)
		virtual void show(SDL_Surface *, vector<Enemy*> enemies, int &score, int &money); //shows the Bomb on the screen
		virtual void showInStore(SDL_Surface*);		
		virtual int getHeight();
		virtual int getWidth();
		virtual int isClicked(int,int);
		virtual void move();
		int getXpos();
		int getYpos();
		virtual void showDuringGamePlay(int, int, SDL_Surface*);
	private:
		SDL_Rect clips[4];
};
#endif
