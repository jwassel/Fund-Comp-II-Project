#include "Weapon.h"
#include <string>
#include "PlasmaCannon.h"

PlasmaCannon::PlasmaCannon(string filename, string explosionName, int Clipsize, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y,int expsize):Weapon(filename, explosionName,Clipsize, Price, AmmoPrice, Damage, FireRate,x,y,expsize){

setClips();
}

void PlasmaCannon::fire(){
}

//shows the Weapon on the screen
void PlasmaCannon::show(SDL_Surface * screen)
{
	apply_surface(xpos, ypos, sprite, screen, &clips);
}

void PlasmaCannon::setClips(){
  clips.x = 271;
  clips.y = 311;
  clips.w = 125;
  clips.h = 60;
}
void PlasmaCannon::showDuringGamePlay(int x,int y, SDL_Surface * screen){

   apply_surface(x,y,sprite,screen,&clips);
}


int PlasmaCannon::getWidth() {
	return clips.w;
}
int PlasmaCannon::getHeight() {
	return clips.h;
}

int PlasmaCannon::isClicked(int x, int y)
{
	if(x>=xpos && x<=xpos+getWidth() && y>=ypos && y<=ypos+getHeight())
		return 1;

	return 0;
}
