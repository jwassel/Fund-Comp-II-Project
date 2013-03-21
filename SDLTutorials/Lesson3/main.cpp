#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
using namespace std;

//The attributes of the screen
const int SCREEN_WIDTH = 1204;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The surfaces that will be used
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;



SDL_Surface *load_image(string filename)
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
	}
		return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
	//Make a temporary rectanagle to hold the offsets
	SDL_Rect offset;
	
	//Give the offsets to the rectangle
	offset.x = x;
	offset.y = y;

	//Blit the surface
	SDL_BlitSurface(source,NULL,destination, &offset);
}

int main( int argc, char* args[])
{
	//Initialize all SDL subsystems (video, audio, timers, etc)
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		//exit the program if if can't intialize
		return 1;
	}

	//Set up screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);

	if(screen == NULL)
	{
		return 1;
	}

	//Set the window caption
	SDL_WM_SetCaption("Hello World", NULL);

	//Load the images
	background = load_image("background.bmp");
	apply_surface(0,0,background,screen);	


	//Update the screen
	if( SDL_Flip(screen)==-1)
	{
		return 1;
	}

	SDL_Delay(2000);

	//free the surfaces
	SDL_FreeSurface(background);

	//Quit SDL
	SDL_Quit();

	return 0;

	
}
