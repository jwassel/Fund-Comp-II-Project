#include "weapon.h"
#include <string>
#include "pistol.h"

pistol::pistol(int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y):weapon(Clipsize, Price, AmmoPrice, Damage, FireRate,x,y){

setClips();
}

void pistol::fire(){
}

//shows the weapon on the screen
void pistol::show(SDL_Surface * screen)
{
	apply_surface(xpos, ypos, Weapon, screen, &clips);
}

void pistol::setClips(){
  clips.x = 162;
  clips.y = 38;
  clips.w = 68;
  clips.h = 39;
}
