#include "weapon.h"
#include <string>
#include "lmg.h"

lmg::lmg(int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y):weapon(Clipsize, Price, AmmoPrice, Damage, FireRate,x,y){

setClips();
}

void lmg::fire(){
}

//shows the weapon on the screen
void lmg::show(SDL_Surface * screen)
{
	apply_surface(xpos, ypos, Weapon, screen, &clips);
}

void lmg::setClips(){
  clips.x = 270;
  clips.y = 170;
  clips.w = 125;
  clips.h = 57;
}
