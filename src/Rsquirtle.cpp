
#include "Rsquirtle.h"
#include "Sprite.h"
#include "Enemy.h"
#include "SDL/SDL.h"
#include <string>
Rsquirtle::Rsquirtle(string filename, int x, int y, int w, int h, int xV,
		   int yV, int p, int hea):Enemy(filename, x, y, w, h, xV,
						 yV, p, hea)
{
    setClips();
}

void Rsquirtle::move()
{
    if (ypos + height < GROUND)
	ypos += yVel;
    else if (isBouncer) {
	if (xpos >= DOME_BASE_X_END)
	    xpos += xVel;
	else
	    xpos += BOUNCE;
    } 
    else
	xpos += xVel;

    if (xpos > 0 && xpos < SCREEN_WIDTH) {
	hasEntered = 1;
    }
}

//shows the enemy on the screen
void Rsquirtle::show(SDL_Surface * screen, int count)
{
    if (!isDead())
	apply_surface(xpos, ypos, sprite, screen, &clips[count % 6]);
}

void Rsquirtle::setClips()
{
    //Clip range for the squirtle clips
    clips[0].x = 345-0-38;
    clips[0].y = 108;
    clips[0].w = 38;
    clips[0].h = 36;

    clips[1].x = 345-38-38;
    clips[1].y = 108;
    clips[1].w = 38;
    clips[1].h = 36;

    clips[2].x = 345-76-40;
    clips[2].y = 108;
    clips[2].w = 40;
    clips[2].h = 36;

    clips[3].x = 345-115-39;
    clips[3].y = 108;
    clips[3].w = 39;
    clips[3].h = 38;

    clips[4].x = 345-155-37;
    clips[4].y = 108;
    clips[4].w = 37;
    clips[4].h = 36;

    clips[5].x = 345-192-39;
    clips[5].y = 108;
    clips[5].w = 39;
    clips[5].h = 36;

}
