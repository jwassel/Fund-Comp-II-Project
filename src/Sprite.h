//Header file for abstarct Sprite class
#include "SDL/SDL.h"
#include <vector>
#include <string>

#ifndef SPRITE_H
#define SPRITE_H
using namespace std;

class Sprite{
    public:
	Sprite(string, int , int, int, int);
        void apply_surface(int, int, SDL_Surface *,SDL_Surface *,SDL_Rect * = NULL); //applies new surface
	SDL_Surface * load_image(string); //takes in image of sprite
        virtual void move()=0; // handles the movement of the sprite
        virtual void show(SDL_Surface *,int)=0; // updates the frames of the sprite sheet shown based on conditional logic
	virtual void setClips() = 0;

    protected:
       	SDL_Surface * sprite; //the image
	int xpos;
	int ypos;
	int width;
	int height;


};

#endif
