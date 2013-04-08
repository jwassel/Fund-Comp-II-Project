#include "Weapon.h"
#include <string>
#include "Gatling.h"

Gatling::Gatling(string filename,string explosionName,int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y):Weapon(Clipsize, Price, AmmoPrice, Damage, FireRate,x,y){

setClips();
}

void Gatling::fire(){
}

//shows the weapon on the screen
void Gatling::show(SDL_Surface * screen)
{

}

void Gatling::setClips(){
  clips.x = 0;
  clips.y = 185;
  clips.w = 103;
  clips.h = 42;
}
