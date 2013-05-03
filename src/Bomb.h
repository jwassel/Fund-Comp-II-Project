//Header file for the abstract class for our Bombs
#ifndef BOMB_H
#define BOMB_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Enemy.h"
#include "Item.h"
#include "Constants.h"
#include <iostream>
#include <string>
using namespace std;
class Bomb: public Item{
public:
	Bomb(string,int,int,int,int); //constructor
	virtual void setClips()=0; //sets the clip fo the Bomb (how it will look on the store screen)
	virtual void show(SDL_Surface *, vector<Enemy*> enemies, int &score, int &money)=0; //shows the Bomb on the screen
	virtual void showInStore(SDL_Surface*)=0; // function to show bomb in proper place when the store is up
	virtual int getHeight()=0; // returns height
	virtual int getWidth()=0; // returns width
	void setPos(int, int);
	virtual void move()=0;// drops bomb from x position of mouse and y decreases until it hits the ground. this function also determines what enemies are killed by the bomb
	SDL_Surface *load_image(std::string filename); // loads the image of the bomb
	void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip); // applies to the image of the bomb to the screen
	void handle_events(SDL_Event ,vector<Enemy*>,SDL_Surface*,int &, int &); //handles when the user clicks since this means they're firing a Bomb
	int getXpos(); // returns current x pos of bomb
	int getYpos(); // returns current y pos of bomb
	bool shouldShowBomb(); // true if bomb should be shown, false otherwise
	void setShowBomb(bool); // sets value of showBomb
	//virtual void showDuringGamePlay(int, int, SDL_Surface*)=0;

protected:
	
	SDL_Surface * sprite; // the image shown on the store screen
	int damage; // how much damage it does when fired at something
	int mod; // determines what clip of the bomb is shown- just the first if the bomb is falling, the next three if it is exploding
	int xpos; // x coordinate of bomb
	int ypos; // y coordinate of bomb
	int notExploded;
	bool showBomb; // true if the bomb should be shown, false otherwise
	
};

#endif
