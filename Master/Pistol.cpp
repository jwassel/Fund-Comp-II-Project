#include "Weapon.h"
#include <string>
#include "Pistol.h"

Pistol::Pistol(string filename, string explosionName, int Price, int AmmoPrice, int Damage, int FireRate, int x, int y, int expsize,int max, int current, int maxclip, int currentclip):Weapon(filename,explosionName, Price, AmmoPrice, Damage, FireRate,x,y,expsize,max,current,maxclip, currentclip){

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



void Pistol::showInStore(SDL_Surface *screen)
{
	apply_surface(xInStore,yInStore,sprite,screen,&clips);
}

void Pistol::showDuringGamePlay(int x,int y, SDL_Surface * screen){

   apply_surface(x,y,sprite,screen,&clips);
}


int Pistol::getWidth() {
	return clips.w;
}
int Pistol::getHeight() {
	return clips.h;
}
int Pistol::isClicked(int x, int y)
{
	if(x>=xInStore && x<=xInStore+getWidth() && y>=yInStore && y<=yInStore+getHeight())
		return 1;

	return 0;
}
