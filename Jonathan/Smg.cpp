#include "Weapon.h"
#include <string>
#include "Smg.h"

Smg::Smg(string filename, string explosionName,string Name, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y, int expsize,int max, int current, int maxclip, int currentclip):Weapon(filename, explosionName, Name, Price, AmmoPrice, Damage, FireRate,x,y, expsize,max,current,maxclip, currentclip){

setClips();
}

void Smg::fire(){
}


//shows the Weapon on the screen
void Smg::showInStore(SDL_Surface * screen)
{
	apply_surface(xInStore, yInStore, sprite, screen, &clips);
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
int Smg::isClicked(int x, int y)
{
	if(x>=xInStore && x<=xInStore+getWidth() && y>=yInStore && y<=yInStore+getHeight())
		return 1;

	return 0;
}
