#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

#ifndef CROSSHAIRS_H
#define CROSSHAIRS_H
using namespace std;

class Crosshairs {
public:
Crosshairs();
void show(SDL_Surface*); // shows crosshair on screen during the game
SDL_Surface * load_image(string); // loads image of crosshair
void getMousePosition(); // returns coordinates of cursor so crosshair can follow it around
void setImage(string); // loads image using load_image
void setCrosshairsGreen(bool); // changes value of isCrosshairsGreen
bool isTheCrosshairsGreen(); // returns value of isCrosshairsGreen

private:
SDL_Surface *image; // image of the crosshair
int xposition; // x position of crosshair mimics x position of mouse
int yposition;// y position of crosshair mimics y position of mouse
bool isCrosshairsGreen; // pretty self explanatory

};
#endif
