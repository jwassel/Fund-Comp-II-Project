#include "Weapon.h"
#include <string>
#include "Gatling.h"

Gatling::Gatling(string filename, string explosionName, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y, int expsize,int max, int current, int maxclip, int currentclip):Weapon(filename,explosionName, Price, AmmoPrice, Damage, FireRate,x,y, expsize,max,current,maxclip, currentclip){

setClips();
}

void Gatling::fire(){
}


//shows the Weapon on the screen
void Gatling::showInStore(SDL_Surface *screen)
{

	apply_surface(xInStore, yInStore, sprite, screen, &clips);
}

void Gatling::showDuringGamePlay(int x,int y, SDL_Surface * screen){

   apply_surface(x,y,sprite,screen,&clips);
}

void Gatling::setClips(){
  clips.x = 0;
  clips.y = 185;
  clips.w = 103;
  clips.h = 42;
}

int Gatling::getWidth() {
	return clips.w;
}

int Gatling::getHeight() {
	return clips.h;
}
int Gatling::isClicked(int x, int y)
{
	if(x>=xInStore && x<=xInStore+getWidth() && y>=yInStore && y<=yInStore+getHeight())
		return 1;

	return 0;
}
