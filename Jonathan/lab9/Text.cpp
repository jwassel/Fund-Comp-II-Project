
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Text.h"
#include <iostream>
using namespace std;
Text::Text(string line,int x,int y,SDL_Color c){
words=line;
xpos=x;
ypos=y;
color=c;
TTF_Font *font = NULL;
font = TTF_OpenFont ("Arial.ttf", 40);
if( font == NULL ) { cout<<"hey2"; }

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
