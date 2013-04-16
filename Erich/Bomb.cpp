
//implementation of the abstract Bomb class

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Bomb.h"
#include <iostream>
#include <vector>
using namespace std;
Bomb::Bomb(string filename, int Price, int x, int y){
	
price = Price;
xpos = x;
ypos = y;

sprite = load_image(filename.c_str());

}
void Bomb::setPos(int x, int y){
xpos=x;
ypos=y;
}

void Bomb::handle_events(SDL_Event event,vector<Enemy*> enemies, SDL_Surface * screen, int &score, int &money)
{

//The mouse offsets
  int x = 0, y = 0;
int enemyX = 0;
int enemyY = 0;
int enemyWidth = 0;
int enemyHeight = 0;
  //If a mouse button was pressed
  if (event.type == SDL_MOUSEBUTTONDOWN)
    {
      //If the left mouse button was pressed
      if (event.button.button == SDL_BUTTON_LEFT)
	{
	
	  //Get the mouse offsets
	  x = event.button.x;
	  y = event.button.y;
	  
	for(int i=0;i<enemies.size();i++)
	{
	enemyX = enemies[i]->getX();
	enemyY = enemies[i]->getY();
	enemyWidth = enemies[i]->getWidth();
	enemyHeight = enemies[i]->getHeight();
	if ((x > enemyX) && (x < enemyX + enemyWidth) && (y > enemyY)
	      && (y < enemyY + enemyHeight))
	    {
		enemies[i]->getAttacked(damage,score,money);
	    	score+=HIT_BONUS;
	    	money+=HIT_BONUS;
	    	}

	}

	}
    }
}


void Bomb::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip){ //applies new surface
    

//Holds offsets
    SDL_Rect shift;

    //Get offsets
    shift.x = x;
    shift.y = y;

    //Blit
    SDL_BlitSurface(source, clip, destination, &shift);

}

SDL_Surface * Bomb::load_image(std::string filename)
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

int Bomb::getXpos() {
	return xpos;
}

int Bomb::getYpos() {
	return ypos;
}

