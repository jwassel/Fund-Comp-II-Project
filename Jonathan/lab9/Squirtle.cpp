
#include "Squirtle.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Squirtle::Squirtle(string filename, int x, int y, int xV, int yV):Enemy(string,x,y,xV,yV)
{
}

void Squirtle::move()
{
    //Move the dot left or right
    xpos += xVel;

    //Move the dot up or down
    ypos += yVel;

}


