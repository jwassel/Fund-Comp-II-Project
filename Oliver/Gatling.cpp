#include "Weapon.h"
#include <string>
#include "Gatling.h"

Gatling::Gatling(string filename, string explosionName, int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y):Weapon(filename,explosionName,Clipsize, Price, AmmoPrice, Damage, FireRate,x,y){

setClips();
}

void Gatling::fire(){
}

//shows the Weapon on the screen
void Gatling::show(SDL_Surface *screen)
{
	//Weapon or sprite?? Pistol uses sprite
	apply_surface(xpos, ypos, sprite, screen, &clips);
}

void Gatling::setClips(){
  clips.x = 0;
  clips.y = 185;
  clips.w = 103;
  clips.h = 42;
}
