#include "SDL/SDL.h"

int main(int argc, char* args[])
{
	//the images
	//a surface is an iamge and these are pointers
	//to them
	SDL_Surface* hello = NULL;
	SDL_Surface* screen = NULL;

	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//Set up the screen
	//640 wide by 480 high window w/ 32 bits per pixel. last argument sets up surface in memory
	screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);

	//Load image
	//takes in a  path to image, returns NULL if error loading the image
	hello = SDL_LoadBMP("hello.bmp");

	//Apply image to screen
	//1st param is source surface, 3rd is destination surface
	SDL_BlitSurface(hello,NULL,screen,NULL);
	
	//Update screen, need to call to see image
	SDL_Flip(screen);

	//Need to pause the window so image doesn't just flash
	SDL_Delay(2000); //in milliseconds

	//Free the loaded image
	SDL_FreeSurface(hello);

	//quits SDL
	SDL_Quit();

	return 0;
}
