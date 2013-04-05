#include "Weapon.h"
#include <string>
#include "Lmg.h"

Lmg::Lmg(string filename, string explosionName, int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y):Weapon(filename, explosionName,Clipsize, Price, AmmoPrice, Damage, FireRate,x,y){

setClips();
}

void Lmg::fire(){
}

//shows the Weapon on the screen
void Lmg::show(SDL_Surface * screen)
{
	apply_surface(xpos, ypos, sprite, screen, &clips);
}

void Lmg::setClips(){
  clips.x = 270;
  clips.y = 170;
  clips.w = 125;
  clips.h = 57;
}
