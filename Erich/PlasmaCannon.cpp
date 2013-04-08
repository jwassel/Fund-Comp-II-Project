#include "weapon.h"
#include <string>
#include "plasmaCannon.h"

plasmaCannon::plasmaCannon(int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y):weapon(Clipsize, Price, AmmoPrice, Damage, FireRate,x,y){

setClips();
}

void plasmaCannon::fire(){
}

//shows the weapon on the screen
void plasmaCannon::show(SDL_Surface * screen)
{
	apply_surface(xpos, ypos, Weapon, screen, &clips);
}

void plasmaCannon::setClips(){
  clips.x = 271;
  clips.y = 311;
  clips.w = 125;
  clips.h = 60;
}
