#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <string>
using namespace std;

//The attributes of the screen
const int SCREEN_WIDTH = 1204;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The surfaces that will be used
SDL_Surface *background = NULL;
SDL_Surface *message = NULL;
SDL_Surface *screen = NULL;

//The event structure that will be used
SDL_Event event;

//The font that's going to be used
TTF_Font *font = NULL;

//The color of the font
SDL_Color textColor = {255,255,255};

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

	//Initialize SDL_ttf
	if (TTF_Init() == -1 )
	{
		return false;
	}

	//Set the window caption
	SDL_WM_SetCaption("Event test", NULL);

	return true;
}

bool load_files()
{

	//Load the images
	background = load_image("background.bmp");
	//Open the font
	font = TTF_OpenFont("Arial.ttf",28 );

	if(background == NULL)
	{
		return false;
	}

	//If there was an error in loading the font
	if(font == NULL)
	{
		return false;
	}

	return true;
}

void clean_up()
{
	SDL_FreeSurface(background);
	SDL_FreeSurface(message);

	//close the font
	TTF_CloseFont(font);
	
	//quit SDL_ttf
	TTF_Quit();

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


	//Render the text
	SDL_Surface * upMessage = TTF_RenderText_Solid(font, "Up was pressed.",textColor);
	SDL_Surface * downMessage = TTF_RenderText_Solid(font, "Down was pressed.",textColor);
	SDL_Surface * leftMessage = TTF_RenderText_Solid(font, "Left was pressed.",textColor);
	SDL_Surface * rightMessage = TTF_RenderText_Solid(font, "Right was pressed.",textColor);

	//Apply surface to screen
	apply_surface(0,0,background,screen);

	

	//Update the screen
	if( SDL_Flip(screen)==-1)
	{
		return 1;
	}

	while( quit == false)
	{
		if( SDL_PollEvent( &event) )
		{
			if(event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_UP:
						message = upMessage;
					break;
					case SDLK_DOWN:
						message = downMessage;
					break;
					case SDLK_LEFT:
						message = leftMessage;
					break;
					case SDLK_RIGHT:
						message = rightMessage;
					break;
				}
			}
			else
			if(event.type == SDL_QUIT)
			{
			quit = true;		
			}

		}
	}
	if( message!=NULL)
	{
		apply_surface(0,0,background,screen);
		apply_surface((SCREEN_WIDTH - message ->w)/2, (SCREEN_HEIGHT - message ->h)/2,message,screen);

		message = NULL;
	}

	//Update the screen
	if( SDL_Flip(screen)==-1)
	{
		return 1;
	}
	clean_up();

	return 0;

	
}
