#include "weapon.h"
#include <string>
#include "smg.h"

smg::smg(int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y):weapon(Clipsize, Price, AmmoPrice, Damage, FireRate,x,y){

setClips();
}

void smg::fire(){
}

//shows the weapon on the screen
void smg::show(SDL_Surface * screen)
{
	apply_surface(xpos, ypos, Weapon, screen, &clips);
}

void smg::setClips(){
  clips.x = 285;
  clips.y = 88;
  clips.w = 100;
  clips.h = 58;
}
