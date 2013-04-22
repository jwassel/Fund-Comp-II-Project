#include "Bomb.h"
#include <string>
#include "Electrode.h"
#include <cmath>

Electrode::Electrode(string filename, int Price, int Damage, int x, int y):Bomb(filename, Price, Damage, x, y){
mod = 1;
notExploded = 1;
//because the first three images are Electrode moving, not exploding. mod will be changed to four when it hits the ground in the move function
setClips();
}

void Electrode::move()
{
 if(ypos<GROUND-getHeight())
	ypos+=BOMB_VELOCITY;

	
}

int Electrode::isClicked(int x, int y)
{
	if(x>=xInStore && x<=xInStore+getWidth() && y>=yInStore && y<=yInStore+getHeight())
		return 1;
	return 0;
}

void Electrode::showInStore( SDL_Surface* screen)
{
	apply_surface(xInStore,yInStore,sprite,screen,&clips[0]);
}

	
void Electrode::setClips(){

  clips[0].x = 553;
  clips[0].y = 26;
  clips[0].w = 56;
  clips[0].h = 54;
  
  clips[1].x = 687;
  clips[1].y = 26;
  clips[1].w = 56;
  clips[1].h = 54;
  
  clips[2].x = 755;
  clips[2].y = 26;
  clips[2].w = 56;
  clips[2].h = 54;
  
  //explosion
  clips[3].x = 235;
  clips[3].y = 156;
  clips[3].w = 88;
  clips[3].h = 74;
  
}



void Electrode::show(SDL_Surface *screen, vector<Enemy*> enemies, int &score, int &money)
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
	if (abs(xpos - (enemyX+enemyWidth/2)) < ELECTRODE_RANGE && abs(ypos - (enemyY+enemyHeight/2)) < ELECTRODE_RANGE)
	    {
		if(enemies[i]->isDead()==false)
		{
		enemies[i]->getAttacked(damage,score,money);
	    	score+=HIT_BONUS;
	    	money+=HIT_BONUS;
		}
	    	}
	}}
	else
	apply_surface(xpos,ypos,sprite,screen,&clips[0]);
	mod=1;
	}
}
}

void Electrode::showDuringGamePlay(int x,int y, SDL_Surface * screen){

   //apply_surface(x,y,sprite,screen,&clips);
}

int Electrode::getWidth() {
	return clips[0].w;
}
int Electrode::getHeight() {
	return clips[0].h;
}

