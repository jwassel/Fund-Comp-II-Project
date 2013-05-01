#include "Weapon.h"
#include <string>
#include "Lmg.h"

Lmg::Lmg(string filename, string explosionName,string Name,int Price, int AmmoPrice, int Damage, int FireRate, int x, int y, int expsize,int max, int currentAmmo, int maxclip, int currentclip):Weapon(filename, explosionName, Name,Price, AmmoPrice, Damage, FireRate,x,y,expsize,max,currentAmmo,maxclip, currentclip){

setClips();
}

void Lmg::fire(){
}


//shows the Weapon on the screen
void Lmg::showInStore(SDL_Surface * screen)
{
	apply_surface(xInStore, yInStore, sprite, screen, &clips);
}

void Lmg::showDuringGamePlay(int x,int y, SDL_Surface * screen){

   apply_surface(x,y,sprite,screen,&clips);
}


void Lmg::setClips(){
  clips.x = 270;
  clips.y = 170;
  clips.w = 125;
  clips.h = 57;
}

int Lmg::getWidth(){
	return clips.w;
}

int Lmg::getHeight() {
	return clips.h;
}
int Lmg::isClicked(int x, int y)
{
	if(x>=xInStore && x<=xInStore+getWidth() && y>=yInStore && y<=yInStore+getHeight())
		return 1;

	return 0;
}
