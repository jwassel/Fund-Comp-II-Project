#include "Weapon.h"
#include <string>
#include "Smg.h"

Smg::Smg(string filename, string explosionName, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y, int expsize,int max, int current, int maxclip, int currentclip):Weapon(filename, explosionName,  Price, AmmoPrice, Damage, FireRate,x,y, expsize,max,current,maxclip, currentclip){

setClips();
}

void Smg::fire(){
}

//shows the Weapon on the screen
void Smg::show(SDL_Surface * screen)
{
	apply_surface(xpos, ypos, sprite, screen, &clips);
}

void Smg::showDuringGamePlay(int x,int y, SDL_Surface * screen){

   apply_surface(x,y,sprite,screen,&clips);
}


void Smg::setClips(){
  clips.x = 285;
  clips.y = 88;
  clips.w = 100;
  clips.h = 58;
}

int Smg::getWidth() {
	return clips.w;
}

int Smg::getHeight() {
	return clips.h;
}

int Smg::isClicked(int x, int y) {
	if(x>=xpos && x<=xpos+getWidth() && y>=ypos && y<=ypos+getHeight())
		return 1;
	return 0;
}
