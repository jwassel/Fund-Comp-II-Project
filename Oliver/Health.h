//Header file for the abstract class for our Bombs
#ifndef HEALTH_H
#define HEALTH_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Item.h"
#include "Constants.h"
#include <iostream>
#include <string>
using namespace std;
class Health: public Item{
public:
	Health(string,int,int,int,int); //constructor
	//can no longer use pure virtual functions
	virtual void setClips(); //sets the clip fo the Bomb (how it will look on the store screen)
	virtual void show(SDL_Surface *, vector<Enemy*> enemies, int &score, int &money)=0; //shows the Bomb on the screen
	virtual void showInStore(SDL_Surface*)=0;
	virtual int getHeight()=0;
	virtual int getWidth()=0;
	void setPos(int, int);
	virtual int move()=0;
	SDL_Surface *load_image(std::string filename);
	void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
	void handle_events(SDL_Event ,vector<Enemy*>,SDL_Surface*,int &, int &); //handles when the user clicks since this means they're firing a Bomb
	int getXpos();
	int getYpos();
	//virtual void showDuringGamePlay(int, int, SDL_Surface*)=0;

protected:
	
	SDL_Surface * sprite; //the image shown on the store screen
	int health; //how much damage it does when fired at something
	int mod;
	int xpos;
	int ypos;
	SDL_Rect clips[1];
	
};

#endif
