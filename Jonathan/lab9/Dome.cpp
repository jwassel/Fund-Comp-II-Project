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

void Dome::show(SDL_Surface * screen)
{
	int imageNum=0;
	if(currentHealth==maxHealth)
		imageNum=0;

	apply_surface(sprite,screen,&clips[imageNum]);
}

void Dome::setClips()
{
  //Clip range for the squirtle clips
  clips[0].x = 250;
  clips[0].y = 70;
  clips[0].w = 65;
  clips[0].h = 85;

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
