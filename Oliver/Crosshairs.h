#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

#ifndef CROSSHAIRS_H
#define CROSSHAIRS_H
using namespace std;

class Crosshairs {
public:
Crosshairs();
void show(SDL_Surface*);
SDL_Surface * load_image(string);
void getMousePosition();
void setImage(string);
void setCrosshairsGreen(bool);
bool isTheCrosshairsGreen();

private:
SDL_Surface *image;
int xposition;
int yposition;
bool isCrosshairsGreen;

};
#endif
