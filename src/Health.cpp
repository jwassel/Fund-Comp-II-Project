#include "Item.h"
#include "Health.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
Health::Health(string filename, int Price, int x, int y):Item(x,y,Price,filename){
sprite = load_image(filename.c_str());
setClips();
}

int Health::isClicked(int x, int y)
{
	if(x>=xInStore && x<=xInStore+getWidth() && y>=yInStore && y<=yInStore+getHeight())
		return 1;
	return 0;
}


void Health::showInStore(SDL_Surface*screen)
{
	apply_surface(xInStore,yInStore,sprite,screen,&clips[0]);
}
	
void Health::setClips(){

  clips[0].x = 0;
  clips[0].y = 0;
  clips[0].w = 53;
  clips[0].h = 42; 
}


int Health::getWidth() {
	return clips[0].w;
}
int Health::getHeight() {
	return clips[0].h;
}

void Health::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip){ //applies new surface
    

//Holds offsets
    SDL_Rect shift;

    //Get offsets
    shift.x = x;
    shift.y = y;

    //Blit
    SDL_BlitSurface(source, clip, destination, &shift);

}

SDL_Surface * Health::load_image(string filename)
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
