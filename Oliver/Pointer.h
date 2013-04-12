#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

#ifndef POINTER_H
#define POINTER_H
using namespace std;

class Pointer {
public:
Pointer();
void show(SDL_Surface*);
SDL_Surface * load_image(string);
void getMousePosition();

private:
SDL_Surface *image;
int xposition;
int yposition;

};
#endif
