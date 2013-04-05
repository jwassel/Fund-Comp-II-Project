#include "Weapon.h"
#include <string>
#include "Pistol.h"

Pistol::Pistol(string filename,int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y):Weapon(filename,Clipsize, Price, AmmoPrice, Damage, FireRate,x,y){

setClips();
}

void Pistol::fire(){

}

void Pistol::setClips(){
  clips[0].x = 162;
  clips[0].y = 38;
  clips[0].w = 68;
  clips[0].h = 39;
}
