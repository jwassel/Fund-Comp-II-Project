#ifndef VOLTORB_H
#define VOLTORB_H
#include "Bomb.h"
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Voltorb:public Bomb
{
	public:
		Voltorb(string,int,int,int,int);//constructor
		virtual void setClips(); //sets the clip fo the Bomb (how it will look on the store screen)
		virtual void show(SDL_Surface *, vector<Enemy*> enemies, int &score, int &money); //shows the Bomb on the screen
		virtual void showInStore(SDL_Surface *);
		virtual int getHeight();
		virtual int getWidth();
		virtual int move();
		int getXpos();
		int getYpos();
		int isClicked(int,int);
		virtual void showDuringGamePlay(int, int, SDL_Surface*);
	private:
		SDL_Rect clips[4];
};
#endif
