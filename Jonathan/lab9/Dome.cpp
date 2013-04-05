//Get good image and set clips.
#include "Dome.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include <string>
using namespace std;
Dome::Dome(string filename,int x, int y, int w, int h, int max, int curr)
{
	sprite = load_image(filename.c_str());
	setClips();
	xpos = x;
	ypos = y;
	width = w;
	height = h;
	maxHealth = max;
	currentHealth = curr;
}

void Dome::getAttacked(int power)
{
	currentHealth-=power;
}

void Dome::show(SDL_Surface * screen)
{
	int imageNum=0;

	if(currentHealth>maxHealth/3&& currentHealth<2*maxHealth/3)
		imageNum=1;
	else if(currentHealth<maxHealth/3)
		imageNum=2;

	apply_surface(sprite,screen,&clips[imageNum]);
}

int Dome::isDead()
{
	if(currentHealth<=0)
		return 1;

	return 0;
}

int Dome::getX()
{
	return xpos;
}

int Dome::getY()
{
	return ypos;
}

int Dome::getWidth()
{
	return width;
}

int Dome::getHeight()
{
	return height;
}

void Dome::setClips()
{
  //Clip range for the squirtle clips
  clips[0].x = 300;
  clips[0].y = 55;
  clips[0].w = 230;
  clips[0].h = 465;

clips[1].x = 595;
  clips[1].y = 55;
  clips[1].w = 230;
  clips[1].h = 465;

clips[2].x = 890;
  clips[2].y = 22;
  clips[2].w = 260;
  clips[2].h = 500;

}

int Dome::getCurrentHealth()
{
	return currentHealth;
}

void Dome::apply_surface(SDL_Surface* source, SDL_Surface* destination,SDL_Rect* clip)
{ //applies new surface
    //Holds offsets
    SDL_Rect shift;

    //Get offsets
    shift.x = xpos;
    shift.y = ypos;
    //Blit
    SDL_BlitSurface(source, clip, destination, &shift);
}

SDL_Surface * Dome::load_image(string filename)
{
	//temporary storage for the image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized image that will be used
	SDL_Surface* optimizedImage = NULL;

	//Load the iamge
	loadedImage = IMG_Load(filename.c_str());
	//this is 24 bit so not good idea to use this b/c causes slowdown
	
	//if nothing went wrong in loading the image
	if(loadedImage!=NULL)
	{
		//create an optimized image in the same format as the screen (32 bit)
		optimizedImage = SDL_DisplayFormat(loadedImage);

	//Free the old image
	SDL_FreeSurface(loadedImage);

		if(optimizedImage!=NULL)
		{
			//Map the color key
			Uint32 colorkey = SDL_MapRGB( optimizedImage -> format,0xec,0x26,0x26);

			//Set all pizels of color R 0, G 0xFF, B 0xFF to be transparent
			SDL_SetColorKey(optimizedImage,SDL_SRCCOLORKEY, colorkey);
		}
	}
		return optimizedImage;
}