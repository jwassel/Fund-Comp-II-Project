#include "Bomb.h"
#include <string>
#include "Voltorb.h"

Voltorb::Voltorb(string filename, int Price, int Damage, int x, int y):Bomb(filename, Price, Damage, x, y){
mod = 1; 
//because the first three images are voltorb moving, not exploding. mod will be changed to four when it hits the ground in the move function
setClips();
}

int Voltorb::move()
{
 if(ypos<GROUND-getHeight()){
	ypos+=BOMB_VELOCITY;
	return 0;}
 	
 	
 	return 1;
	
}


	
void Voltorb::setClips(){

  clips[0].x = 16;
  clips[0].y = 29;
  clips[0].w = 45;
  clips[0].h = 42;
  
  clips[1].x = 149;
  clips[1].y = 29;
  clips[1].w = 45;
  clips[1].h = 42;
  
  clips[2].x = 215;
  clips[2].y = 29;
  clips[2].w = 45;
  clips[2].h = 42;
  
  //explosion
  clips[3].x = 228;
  clips[3].y = 91;
  clips[3].w = 58;
  clips[3].h = 57;
  
}



void Voltorb::show(SDL_Surface *screen, int count)
{
	 if(ypos>=GROUND-getHeight())
 	mod=4;
 	
 	if (mod==4){
	apply_surface(xpos,ypos,sprite,screen,&clips[count%mod]);
	apply_surface(xpos,ypos,sprite,screen,&clips[(count+1)%mod]);
	apply_surface(xpos,ypos,sprite,screen,&clips[(count+2)%mod]);
	apply_surface(xpos,ypos,sprite,screen,&clips[(count+3)%mod]);
	}
	else
	apply_surface(xpos,ypos,sprite,screen,&clips[count%mod]);
	mod=1;
	
}

void Voltorb::showDuringGamePlay(int x,int y, SDL_Surface * screen){

   //apply_surface(x,y,sprite,screen,&clips);
}

int Voltorb::getWidth() {
	return clips[0].w;
}
int Voltorb::getHeight() {
	return clips[0].h;
}

int Voltorb::isClicked(int x, int y)
{
	if(x>=xpos && x<=xpos+getWidth() && y>=ypos && y<=ypos+getHeight())
		return 1;

	return 0;
}
