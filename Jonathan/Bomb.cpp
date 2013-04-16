
//implementation of the abstract Bomb class

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Bomb.h"
#include "Item.h"
#include <iostream>
#include <vector>
using namespace std;
Bomb::Bomb(string filename, int Price, int Damage, int x, int y):Item(x,y,Price,filename){
	
damage = Damage;
xpos = x;
ypos = y;
//sprite = load_image(filename.c_str());

}
void Bomb::setPos(int x, int y){
xpos=x;
ypos=y;
}

void Bomb::handle_events(SDL_Event event,vector<Enemy*> enemies, SDL_Surface * screen, int &score, int &money)
{

//The mouse offsets
  int x = 0, y = 0;
int enemyX = 0;
int enemyY = 0;
int enemyWidth = 0;
int enemyHeight = 0;
  //If a mouse button was pressed
  if (event.type == SDL_MOUSEBUTTONDOWN)
    {
      //If the left mouse button was pressed
      if (event.button.button == SDL_BUTTON_LEFT)
	{
	
	  //Get the mouse offsets
	  x = event.button.x;
	  y = event.button.y;
	  
	for(int i=0;i<enemies.size();i++)
	{
	enemyX = enemies[i]->getX();
	enemyY = enemies[i]->getY();
	enemyWidth = enemies[i]->getWidth();
	enemyHeight = enemies[i]->getHeight();
	if ((x > enemyX) && (x < enemyX + enemyWidth) && (y > enemyY)
	      && (y < enemyY + enemyHeight))
	    {
		enemies[i]->getAttacked(damage,score,money);
	    	score+=HIT_BONUS;
	    	money+=HIT_BONUS;
	    	}

	}

	}
    }
}


int Bomb::getXpos() {
	return xpos;
}

int Bomb::getYpos() {
	return ypos;
}

