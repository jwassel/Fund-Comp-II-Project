#ifndef TEXT_H
#define TEXT_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
using namespace std;
class Text
{
	public:
		Text(string,int,int,SDL_Color);
		   void apply_surface(int, int, SDL_Surface *,SDL_Surface *); //applies new surface
void show(SDL_Surface*);
	private:
		SDL_Surface* message;
		string words;
		int xpos;
		int ypos;
		SDL_Color color;
};

#endif
