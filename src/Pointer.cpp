#include "Pointer.h"
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
Pointer::Pointer()
{
image=load_image("pointer.png");

SDL_ShowCursor(0);
xposition=0;
yposition=0;
}

SDL_Surface * Pointer::load_image(std::string filename)
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

void Pointer::getMousePosition(){
SDL_GetMouseState(&xposition, &yposition);

}

void Pointer::show(SDL_Surface *screen)
{getMousePosition();
  SDL_Rect shift;
  shift.x = xposition-18;
  shift.y = yposition-18;
  SDL_BlitSurface(image, NULL, screen, &shift);
}


