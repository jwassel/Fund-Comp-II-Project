#include "Squirtle.h"
#include "SDL/SDL.h"
Squirtle::Squirtle(int x, int y, int h, int p, int xv, int yv, int xlim):Enemy(x,y,h,p,xv,yv)
{
	xLimit = xlim;
}

void Squirtle::move()
{
    //Move the dot left or right
    xpos += xVel;

    //If the dot went too far to the left or right
    if( ( xpos == xLimit ))
    {
        //stop moving
        xVel=0;
    }

    //Move the dot up or down
    ypos += yVel;

    //If the dot went too far up or down
    if( ( ypos < 0 ) || ( ypos > 600 ) )
    {
        //move back
        ypos -= yVel;
    }
}
