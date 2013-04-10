#include "Weapon.h"
#include <string>
#include "Pistol.h"

Pistol::Pistol(string filename, string explosionName, int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y):Weapon(filename,explosionName,Clipsize, Price, AmmoPrice, Damage, FireRate,x,y){

setClips();
}

void Pistol::fire(){

}

void Pistol::setClips(){
  clips.x = 162;
  clips.y = 38;
  clips.w = 68;
  clips.h = 39;
}

void Pistol::show(SDL_Surface *screen)
{
	apply_surface(xpos,ypos,sprite,screen,&clips);
}

int Pistol::getWidth() {
	return clips.w;
}
int Pistol::getHeight() {
	return clips.h;
}

int Pistol::isClicked(int x, int y)
{
	if(x>=xpos && x<=xpos+getWidth() && y>=ypos && y<=ypos+getHeight())
		return 1;

	return 0;
}
