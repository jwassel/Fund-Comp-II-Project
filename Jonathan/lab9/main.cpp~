
//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "Enemy.h"
#include "Timer.h"
#include "Sprite.h"
#include "Background.h"
#include "Squirtle.h"
#include "Poliwhirl.h"
#include "Rpidgey.h"
#include "Dome.h"
#include "Weapon.h"
#include "Pistol.h"
#include "Text.h"
#include <string>
#include <vector>
#include <iostream>
//Screen size at bits per pixel
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 1200;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 20;
using namespace std;

//The screen surface
SDL_Surface *screen = NULL;

SDL_Color textColor = { 255, 255, 255 };

//The event structure
SDL_Event event;

vector < Enemy * >enemies;
Squirtle *squirtle;
Poliwhirl *poliwhirl;
Rpidgey *rpidgey;
SDL_Surface *message = NULL;
vector < Weapon * >weapons;
Pistol *pistol;

bool
init ()
{
  //Initialize all SDL subsystems
  if (SDL_Init (SDL_INIT_EVERYTHING) == -1)
    {
      cout << "SDL Initialization failed" << endl;
      return false;
    }

  //Set up the screen
  screen =
    SDL_SetVideoMode (SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

  //If there was an error in setting up the screen
  if (screen == NULL)
    {
      cout << "Screen is null" << endl;
      return false;
    }

  if (TTF_Init () == -1)
    {
      return false;
    }

  //Set the window caption
  SDL_WM_SetCaption ("PokeDome", NULL);

  //If everything initialized fine
  return true;
}

void
clean_up ()
{
  //Free the surface
  //SDL_FreeSurface(background);

  //Quit SDL
  SDL_Quit ();
}

//add all the enemies 
void
load_enemies ()
{
  squirtle = new Squirtle ("squirtlej.png", 1000, 0, 38, 36, -5, 10, 20, 50);
  enemies.push_back (squirtle);
  poliwhirl =
    new Poliwhirl ("poliwhirl.png", 1100, 0, 75, 80, -7, 12, 30, 100);
  enemies.push_back (poliwhirl);
  rpidgey = new Rpidgey ("Rpidgey.png", 0, 200, 37, 30, 5, 0, 5, 10);
  enemies.push_back (rpidgey);
}

void
load_weapons ()
{
  pistol =
    new Pistol ("weapons.png", "explosionsgunshot.PNG", 10, 100, 15, 10, 20,
		0, 0);
  weapons.push_back (pistol);
}

int
main (int argc, char *args[])
{


  //Quit flag
  bool quit = false;

  int count = 0;

  //The frame rate regulator
  Timer fps;



  //Initialize
  if (init () == false)
    {
      return 1;
    }
  Background background ("background.bmp");
  Dome dome ("dome.png", 485, 135, 230, 465, 2000, 2000);
  load_enemies ();
  load_weapons ();
  //While the user hasn't quit
  while (quit == false)
    {
      //Start the frame timer
      fps.start ();

      //show the background
      background.show (screen);
      dome.show (screen);

//move the enemies
      for (int i = 0; i < enemies.size (); i++)
	{
	  enemies[i]->move ();
	  if (enemies[i]->isDead ())
	    continue;
	  if (dome.isCollidingWithEnemy
	      (enemies[i]->getX (), enemies[i]->getY (),
	       enemies[i]->getWidth (), enemies[i]->getHeight (),
	       enemies[i]->getXVel ()))
	    {
	      dome.getAttacked (enemies[i]->attack ());
	      //cout<<"Dome's health: "<<dome.getCurrentHealth()<<endl;
	      if (dome.isDead ())
		{
		  //cout<<"Dome is dead!"<<endl;
		}
	    }
	}

//show the enemies
      for (int j = 0; j < enemies.size (); j++)
	{
	  enemies[j]->show (screen, count);
	}

      //While there's events to handle
      while (SDL_PollEvent (&event))
	{

	  for (int i = 0; i < weapons.size (); i++)
	    {
	      weapons[i]->handle_events (event, enemies, screen);
	    }
	  //If the user has Xed out the window
	  if (event.type == SDL_QUIT)
	    {
	      //Quit the program
	      quit = true;
	    }
	}

      int levelComplete = 0;
      for (int j = 0; j < enemies.size (); j++)
	{
	  if (!enemies[j]->isDead ())
	    {
	      levelComplete = 0;
	      break;
	    }
	  else
	    levelComplete = 1;
	}

      if (levelComplete)
	{
	  SDL_FillRect (screen, &screen->clip_rect,SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));
	  Text levelSuccess ("Level Complete", 2 * SCREEN_WIDTH / 5,2 * SCREEN_HEIGHT / 5, textColor);
	  levelSuccess.show (screen);
	  SDL_Flip (screen);
	  SDL_Delay (2000);
	  quit = true;
	}

      if (dome.isDead ())
	{
	  background.show (screen);
	  for (int j = 0; j < enemies.size (); j++)
	    {
	      enemies[j]->show (screen, count);
	    } SDL_Flip (screen);
	  SDL_Delay (2000);
	  SDL_FillRect (screen, &screen->clip_rect,SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));
	  Text levelFail ("Game Over", 2 * SCREEN_WIDTH / 5, 2 * SCREEN_HEIGHT / 5, textColor);
	  levelFail.show (screen);
	  SDL_Flip (screen);
	  SDL_Delay (2000);
	  quit = true;
	}


      //Update the screen
      if (SDL_Flip (screen) == -1)
	{
	  cout << "Failed updating the screen" << endl;
	  return 1;
	}

      //Cap the frame rate
      if (fps.get_ticks () < 1000 / FRAMES_PER_SECOND)
	{
	  SDL_Delay ((1000 / FRAMES_PER_SECOND) - fps.get_ticks ());
	}
      count++;
    }

  //Clean up
  clean_up ();

  return 0;
}
