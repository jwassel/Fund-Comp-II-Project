#include "Item.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
Health::Health(string filename, int Price, int Damage, int x, int y):Item(x,y,Price,filename){
mod = 1; 
//because the first three images are Health moving, not exploding. mod will be changed to four when it hits the ground in the move function
setClips();
}

int Health::isClicked(int x, int y)
{
	if(x>=xInStore && x<=xInStore+getWidth() && y>=yInStore && y<=yInStore+getHeight())
		return 1;
	return 0;
}
int Health::move()
{
 if(ypos<GROUND-getHeight()){
	ypos+=BOMB_VELOCITY;
	return 0;}
 	
 	
 	return 1;
	
}

void Health::showInStore(SDL_Surface*screen)
{
	apply_surface(xInStore,yInStore,sprite,screen,&clips[0]);
}
	
void Health::setClips(){

  clips[0].x = 0;
  clips[0].y = 0;
  clips[0].w = 106;
  clips[0].h = 106;
/*  
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
*/  
}



void Health::show(SDL_Surface *screen, vector<Enemy*> enemies, int &score, int &money)
{
int enemyX = 0;
int enemyY = 0;
int enemyWidth = 0;
int enemyHeight = 0;


	 if(ypos>=GROUND-getHeight())
 	mod=4;
 	
 	if (mod==4){
	apply_surface(xpos,ypos,sprite,screen,&clips[1]);
	apply_surface(xpos,ypos,sprite,screen,&clips[2]);
	apply_surface(xpos,ypos,sprite,screen,&clips[3]);
		for(int i=0;i<enemies.size();i++)
	{
	enemyX = enemies[i]->getX();
	enemyY = enemies[i]->getY();
	enemyWidth = enemies[i]->getWidth();
	enemyHeight = enemies[i]->getHeight();
	if (abs(xpos - (enemyX+enemyWidth/2)) < Health_RANGE)
	    {
		enemies[i]->getAttacked(damage,score,money);
	    	score+=HIT_BONUS;
	    	money+=HIT_BONUS;
	    	}
	}}
	else
	apply_surface(xpos,ypos,sprite,screen,&clips[0]);
	mod=1;
	
}

void Health::showDuringGamePlay(int x,int y, SDL_Surface * screen){

   //apply_surface(x,y,sprite,screen,&clips);
}

int Health::getWidth() {
	return clips[0].w;
}
int Health::getHeight() {
	return clips[0].h;
}
