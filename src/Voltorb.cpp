#include "Bomb.h"
#include <string>
#include "Voltorb.h"
#include <cmath>
#include <iostream>
using namespace std;
Voltorb::Voltorb(string filename, int Price, int Damage, int x, int y):Bomb(filename, Price, Damage, x, y){
mod=1;
notExploded = 1;
//because the first three images are voltorb moving, not exploding. mod will be changed to four when it hits the ground in the move function
setClips();
}

int Voltorb::isClicked(int x, int y)
{
	if(x>=xInStore && x<=xInStore+getWidth() && y>=yInStore && y<=yInStore+getHeight())
		return 1;
	return 0;
}
void Voltorb::move()
{
 if(ypos<GROUND-getHeight())
	ypos+=BOMB_VELOCITY;
 else
 mod=0;
}

void Voltorb::showInStore(SDL_Surface*screen)
{
	apply_surface(xInStore,yInStore,sprite,screen,&clips[1]);
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



void Voltorb::show(SDL_Surface *screen, vector<Enemy*> enemies, int &score, int &money)
{

if(showBomb)
{
int enemyX = 0;
int enemyY = 0;
int enemyWidth = 0;
int enemyHeight = 0;

if (notExploded){
	 if(ypos>=GROUND-getHeight())
 	mod=4;
 	
 	if (mod==4){
	apply_surface(xpos,ypos,sprite,screen,&clips[1]);
	apply_surface(xpos,ypos,sprite,screen,&clips[2]);
	apply_surface(xpos,ypos,sprite,screen,&clips[3]);
	notExploded=0;
	showBomb = false;
		for(int i=0;i<enemies.size();i++)
	{
	enemyX = enemies[i]->getX();
	enemyY = enemies[i]->getY();
	enemyWidth = enemies[i]->getWidth();
	enemyHeight = enemies[i]->getHeight();
	if (abs(xpos - (enemyX+enemyWidth/2)) < VOLTORB_RANGE && abs(ypos - (enemyY+enemyHeight/2)) < ELECTRODE_RANGE)
	    {
		if(enemies[i]->isDead()==false)
		{
		enemies[i]->getAttacked(damage,score,money);
	    	score+=HIT_BONUS;
	    	money+=HIT_BONUS;
		}
	    	}
	}}
	else if (mod==1)
	apply_surface(xpos,ypos,sprite,screen,&clips[0]);
	
	}
}
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

