//Header file for the abstract class for our Bombs
#ifndef BOMB_H
#define BOMB_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Enemy.h"
#include "Constants.h"
#include <iostream>
#include <string>
using namespace std;
class Bomb{
public:
	Bomb(string,int,int,int); //constructor
	virtual void setClips()=0; //sets the clip fo the Bomb (how it will look on the store screen)
	virtual void show(SDL_Surface *, vector<Enemy*> enemies, int &score, int &money)=0; //shows the Bomb on the screen
	virtual int getHeight()=0;
	virtual int getWidth()=0;
	void setPos(int, int);
	virtual int move()=0;
	void apply_surface(int, int, SDL_Surface *,SDL_Surface *,SDL_Rect * = NULL); //applies new surface
	SDL_Surface * load_image(string); //takes in image of sprite
	void handle_events(SDL_Event ,vector<Enemy*>,SDL_Surface*,int &, int &); //handles when the user clicks since this means they're firing a Bomb
	int getXpos();
	int getYpos();
	//virtual void showDuringGamePlay(int, int, SDL_Surface*)=0;

protected:
	
	SDL_Surface * sprite; //the image shown on the store screen
	int price; //price to buy the bomb
	int damage; //how much damage it does when fired at something

        int xpos;
	int ypos;
	int mod;
	
};

#endif
