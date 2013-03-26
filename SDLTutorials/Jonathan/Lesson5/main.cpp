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
SDL_Surface *squirtle = NULL;
SDL_Surface *screen = NULL;

//The event structure that will be used
SDL_Event event;


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

		if(optimizedImage!=NULL)
		{
			//Map the color key
			Uint32 colorkey = SDL_MapRGB( optimizedImage -> format,0,0xFF,0xFF);

			//Set all pizels of color R 0, G 0xFF, B 0xFF to be transparent
			SDL_SetColorKey(optimizedImage,SDL_SRCCOLORKEY, colorkey);
		}
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

bool init()
{
	//Initialize all SDL subsystems
	if( SDL_Init( SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	//Set up screen
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);

	if(screen == NULL)
	{
		return 1;
	}

	//Set the window caption
	SDL_WM_SetCaption("Event test", NULL);

	return true;
}

bool load_files()
{

	//Load the images
	background = load_image("background.bmp");
	squirtle = load_image("squirtle.bmp");
	if(background == NULL || squirtle == NULL)
	{
		return false;
	}

	return true;
}

void clean_up()
{
	SDL_FreeSurface(background);
	SDL_FreeSurface(squirtle);
	SDL_Quit();
}

int main( int argc, char* args[])
{


	bool quit = false;

	if(init()==false)
	{
		return 1;
	}

	//Load files 
	if( load_files() == false)
	{
		return 1;
	}

	//Apply surface to screen
	apply_surface(0,0,background,screen);
	apply_surface(600,500,squirtle,screen);


	//Update the screen
	if( SDL_Flip(screen)==-1)
	{
		return 1;
	}

	while( quit == false)
	{
		while( SDL_PollEvent( &event) )
		{
			if(event.type == SDL_QUIT)
			{
			quit = true;		
			}
		}
	}


	clean_up();

	return 0;

	
}
