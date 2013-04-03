
//implementation of the abstract enemy class

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Enemy.h"
#include "Sprite.h"
#include "Background.h"
Enemy::Enemy(string filename, int x,int y, int w, int h, int xv, int yv,int hea):Sprite(filename,x,y,w,h)
{
	xVel = xv;
	yVel = yv;
	health=hea;		
}

int Enemy::getX()
{
	return xpos;
}

void
Enemy::handle_events (SDL_Surface *screen)
{

	Background gunshot("explosionsgunshot.png");
Background explosion("explosions.png");SDL_Event event;
  //The mouse offsets
  int x = 0, y = 0;

  //If a mouse button was pressed
  if (event.type == SDL_MOUSEBUTTONDOWN)
    {
      //If the left mouse button was pressed
      if (event.button.button == SDL_BUTTON_LEFT)
	{
	  //Get the mouse offsets
	  x = event.button.x;
	  y = event.button.y;
gunshot.show(screen);
	  //If the mouse is over the button
	  if ((x > xpos) && (x < xpos + width) && (y > ypos)
	      && (y < ypos + height))
	    {
	 
explosion.show(screen);
	    }
	}
    }
}
