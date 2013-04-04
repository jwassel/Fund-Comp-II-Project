
//implementation of the abstract weapon class

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "weapon.h"

weapon::weapon(int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y){

clipsize = Clipsize;
price = Price;
ammoPrice = AmmoPrice;
damage = Damage;
fireRate = fireRate;
xpos = x;
ypos = y;

Weapon = load_image("weapons.png");

}

void weapon::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip){ //applies new surface
    //Holds offsets
    SDL_Rect shift;

    //Get offsets
    shift.x = x;
    shift.y = y;

    //Blit
    SDL_BlitSurface(source, clip, destination, &shift);
}

SDL_Surface * weapon::load_image(std::string filename)
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


