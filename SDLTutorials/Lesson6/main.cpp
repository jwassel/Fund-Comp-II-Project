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
SDL_Surface *squirtles = NULL;
SDL_Surface *screen = NULL;

//The event structure that will be used
SDL_Event event;

//The portions of the sprite map to be blitted
SDL_Rect clip [4];

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

//places surface destination on the source at position x,y. if clip is null then puts entire image, otherwise
//it expects a sdl_rect which is rectangle of the image that it is clipping out
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
	//Make a temporary rectanagle to hold the offsets
	SDL_Rect offset;
	
	//Give the offsets to the rectangle
	offset.x = x;
	offset.y = y;

	//Blit the surface
	SDL_BlitSurface(source,clip,destination, &offset);
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
	squirtles = load_image("squirtles.png");
	if(background == NULL || squirtles == NULL)
	{
		return false;
	}

	return true;
}

void clean_up()
{
	SDL_FreeSurface(background);
	SDL_FreeSurface(squirtles);
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
	
	//grabs clips of the sprite
	clip[0].x = 0;
	clip[0].y = 0;
	clip[0].w = 50;
	clip[0].h = 50;

	clip[1].x = 50;
	clip[1].y = 0;
	clip[1].w = 50;
	clip[1].h = 50;

	clip[2].x = 100;
	clip[2].y = 0;
	clip[2].w = 50;
	clip[2].h = 50;


	clip[3].x = 150;
	clip[3].y = 0;
	clip[3].w = 50;
	clip[3].h = 50;
	
	//applies each individual clip
	apply_surface(300,300,squirtles,screen,&clip[0]);
	apply_surface(400,300,squirtles,screen,&clip[1]);
	apply_surface(300,400,squirtles,screen,&clip[2]);
	apply_surface(400,400,squirtles,screen,&clip[3]);


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
