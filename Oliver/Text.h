#ifndef TEXT_H
#define TEXT_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
using namespace std;
class Text
{
	public:
		Text(string,int,int,SDL_Color, int);
		void apply_surface(int, int, SDL_Surface *,SDL_Surface *); //applies new surface
		void show(SDL_Surface*);
		int getTextXpos();
		int getTextYpos();
		int getWidth();
		int getHeight();
		int isClicked(int, int); //returns 1 if clicked
		void setText(string);
		void setY(int);
		void setSize(int);
		void setX(int);
	private:
		SDL_Surface* message;
		string words;
		int xpos;
		int ypos;
		int width;
		int height;
		int size;
		SDL_Color color;
		TTF_Font *font;
};

#endif
