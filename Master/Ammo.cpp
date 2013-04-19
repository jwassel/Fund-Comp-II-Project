#include "Item.h"
#include "Ammo.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
Ammo::Ammo(string filename, int Price, int x, int y, int n):Item(x,y,Price,filename){
sprite = load_image(filename.c_str());
setClips();
numberOnSheet = n;
}

int Ammo::isClicked(int x, int y)
{
	if(x>=xInStore && x<=xInStore+getWidth() && y>=yInStore && y<=yInStore+getHeight())
		return 1;
	return 0;
}


void Ammo::showInStore(SDL_Surface*screen)
{
	apply_surface(xInStore,yInStore,sprite,screen,&clips[numberOnSheet]);
}
	
void Ammo::setClips(){

	clips[0].x = 4;
	clips[0].y = 11;
	clips[0].w = 40;
	clips[0].h = 24;

	clips[1].x = 101;
	clips[1].y = 16;
	clips[1].w = 39;
	clips[1].h = 33;

	clips[2].x = 210;
	clips[2].y = 6;
	clips[2].w = 38;
	clips[2].h = 31;

	clips[3].x = 334;
	clips[3].y = 8;
	clips[3].w = 35;
	clips[3].h = 27;

	clips[4].x = 512;
	clips[4].y = 2;
	clips[4].w = 31;
	clips[4].h = 36;
}


int Ammo::getWidth() {
	return clips[0].w;
}
int Ammo::getHeight() {
	return clips[0].h;
}

void Ammo::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip){ //applies new surface
    

//Holds offsets
    SDL_Rect shift;

    //Get offsets
    shift.x = x;
    shift.y = y;

    //Blit
    SDL_BlitSurface(source, clip, destination, &shift);

}

SDL_Surface * Ammo::load_image(string filename)
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
