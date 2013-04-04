#include "weapon.h"
#include <string>
#include "gatling.h"

gatling::gatling(int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y):weapon(Clipsize, Price, AmmoPrice, Damage, FireRate,x,y){

setClips();
}

void gatling::fire(){
}

//shows the weapon on the screen
void gatling::show(SDL_Surface * screen)
{
	apply_surface(xpos, ypos, Weapon, screen, &clips);
}

void gatling::setClips(){
  clips.x = 0;
  clips.y = 185;
  clips.w = 103;
  clips.h = 42;
}
