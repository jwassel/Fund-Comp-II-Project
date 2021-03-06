
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Text.h"
#include <iostream>
using namespace std;
Text::Text(string line,int x,int y,SDL_Color c, int s){
words=line;
xpos=x;
ypos=y;
color=c;
size = s;
font = NULL;
font = TTF_OpenFont ("Advert.ttf", size);
TTF_SizeText(font,line.c_str(),&width,&height);


message = TTF_RenderText_Solid (font, words.c_str(), color);

}

void Text::setX(int newX)
{
	xpos = newX;
}
void Text::setSize(int newSize)
{
	size = newSize;
	font = TTF_OpenFont ("Advert.ttf", size);
	TTF_SizeText(font,words.c_str(),&width,&height);
}
void Text::setY(int newY)
{
	ypos = newY;
}
void Text::setText(string newText)
{

	TTF_SizeText(font,newText.c_str(),&width,&height);
	words = newText;
	message = TTF_RenderText_Solid (font, words.c_str(), color);
}
		   
void Text::apply_surface(int x, int y, SDL_Surface *source,SDL_Surface *screen)

{
  //Holds offsets
  SDL_Rect offset;

  //Get offsets
  offset.x = x;
  offset.y = y;

  //Blit
  SDL_BlitSurface (source, NULL, screen, &offset);
}

void Text::show(SDL_Surface*screen){
	apply_surface(xpos, ypos, message, screen );
}

int Text::getTextXpos() {
	return xpos;
}

int Text::getTextYpos() {
	return ypos;
}

int Text::getWidth() {
	return width;
}

int Text::getHeight() {
	return height;
}

//returns 1 if clicked and 0 if not clicked
int Text::isClicked(int x, int y) {
	if(x >= getTextXpos() && y >= getTextYpos() && x <= (getTextXpos() + getWidth()) && y <= (getTextYpos() + getHeight())) return 1;
	return 0;
}
