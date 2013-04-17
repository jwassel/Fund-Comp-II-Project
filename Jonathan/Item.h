#ifndef ITEM_H
#define ITEM_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Constants.h"
#include <string>
using namespace std;
class Item
{
	public:
		Item(int,int,int,string);
		virtual void showInStore(SDL_Surface*)=0;
		virtual int isClicked(int,int) = 0;
		int getPrice();
		 //SDL_Surface* load_image(string);
		//void apply_surface(int, int, SDL_Surface* , SDL_Surface* , SDL_Rect*);

	protected:
		int price;
		SDL_Surface * sprite;
		int xInStore;
		int yInStore;
	
		
};
#endif
