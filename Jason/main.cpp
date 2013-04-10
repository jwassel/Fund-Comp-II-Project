/*
Main file for our PokeDome SDL video game!
CSE 20212 Spring 2013 Final Project
Group Members: Jonathan Cobian, Erich Kerekes, Oliver Lamb, Jason Wassel
*/
//The headers and includes for all our classes
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
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
#include "Gatling.h"
#include "Smg.h"
#include "Lmg.h"
#include "PlasmaCannon.h"
#include "Text.h"
#include "Crosshairs.h"
#include <boost/lexical_cast.hpp>
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
SDL_Surface *cursor=NULL;

SDL_Color colorWhite = { 255, 255, 255 };
SDL_Color colorBlack = {0,0,0};
//The event structure
SDL_Event event;

//the different enemies the game can have
vector < Enemy * >enemies; //vector to store the enemies in a given level
Squirtle *squirtle;
Poliwhirl *poliwhirl;
Rpidgey *rpidgey;

SDL_Surface *message = NULL;

//vector that stores the user's current weapons
vector < Weapon * >weapons;
//stores all the weapons the user can buy (NOTE need to change to be of some base class cause the store must also show 
vector < Weapon * >store;
//all the possible weapons
Pistol *pistol;
PlasmaCannon* plasmaCannon;
Gatling* gatling;
Smg* smg;
Lmg* lmg;

//Music
Mix_Music *music;


//user can only use one weapon at a time
int currentWeaponIndex = 0;

//the current level and the maximum # of levels programmed by us
int currentLevel = 1;
int maxLevel = 2;

//SDL initializing material
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

if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) { return false; }
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

//quits SDL
void
clean_up ()
{
  //ADD STUFF FREEING SURFACES

  //Quit SDL
  SDL_Quit ();
}

//add all the enemies for the given level 
void
load_enemies ()
{
  if(currentLevel==1)
  {

   squirtle = new Squirtle ("squirtlej.png", 1000, 0, 38, 36, -5, 10, 20, 50);
   poliwhirl = new Poliwhirl ("poliwhirl.png", 1100, 0, 75, 80, -7, 12, 30, 100);  
   rpidgey = new Rpidgey ("Rpidgey.png", 0, 200, 37, 30, 5, 0, 5, 10);
  enemies.push_back (squirtle);
  enemies.push_back (poliwhirl);
  enemies.push_back (rpidgey);
  }
  else if(currentLevel==2)
  {
	enemies.clear();
       squirtle = new Squirtle ("squirtlej.png", 1000, 0, 38, 36, -10, 20, 20, 50);
      poliwhirl = new Poliwhirl ("poliwhirl.png", 1100, 0, 75, 80, -14, 24, 30, 100);  
      rpidgey = new Rpidgey ("Rpidgey.png", 0, 200, 37, 30, 10, 0, 5, 10);
        enemies.push_back (squirtle);
  	enemies.push_back (poliwhirl);
  	enemies.push_back (rpidgey);
       squirtle = new Squirtle ("squirtlej.png", 1000, -100, 38, 36, -10, 20, 20, 50);
      poliwhirl = new Poliwhirl ("poliwhirl.png", 1100, -100, 75, 80, -14, 24, 30, 100);  
      rpidgey = new Rpidgey ("Rpidgey.png", 0, 300, 37, 30, 10, 0, 5, 10);
    enemies.push_back (squirtle);
  	enemies.push_back (poliwhirl);
  	enemies.push_back (rpidgey);
	
  }
}

//loads all the items to the store
void load_store()
{    // Clipsize, Price, AmmoPrice, Damage, FireRate, x on screen, y on screen

    plasmaCannon = new PlasmaCannon("weapons.png", "explosionplasma.PNG", 25,1000,100,100,1,100,450,40);
    store.push_back(plasmaCannon);
    pistol = new Pistol("weapons.png", "explosionpistol.png", 12,100,10,15,5,100,60,8);
    store.push_back(pistol);
    gatling = new Gatling("weapons.png", "explosiongatling.png", 60,400,30,8,30,100,250,30);
    store.push_back(gatling);
    smg = new Smg("weapons.png", "explosionsmg.PNG", 40,500,35,15,20,100,150,20);
    store.push_back(smg);
    lmg = new Lmg("weapons.png", "explosionlmg.PNG", 100,700,40,25,18,100,350,26);
    store.push_back(lmg);
}

//takes user's click when on the store screen and updates their inventory
bool purchaseFromStore(int x, int y, Text &continueToGame, Text&messageToUser)
{

	if(continueToGame.isClicked(x,y)) {
		return true;
	}
	
	if(pistol->isClicked(x,y))
	{
		messageToUser.setText("Succesfully Added Pistol");
		messageToUser.show(screen);
		SDL_Flip(screen);
		weapons.push_back (pistol);
	}

	if(gatling->isClicked(x,y))
	{
		messageToUser.setText("Succesfully Added Gatling");
		messageToUser.show(screen);
		SDL_Flip(screen);
		weapons.push_back(gatling);

	}

	if(lmg->isClicked(x,y))
	{
		messageToUser.setText("Succesfully Added LMG");
		messageToUser.show(screen);
		SDL_Flip(screen);
		weapons.push_back(lmg);

	}

	if(smg->isClicked(x,y))
	{
		messageToUser.setText("Succesfully Added SMG");
		messageToUser.show(screen);
		SDL_Flip(screen);
		weapons.push_back(smg);

	}

	if(plasmaCannon->isClicked(x,y))
	{
		messageToUser.setText("Succesfully Added Plasma Cannon");
		messageToUser.show(screen);
		SDL_Flip(screen);
		weapons.push_back(plasmaCannon);
	}
	return false;	
}

//goes to the store screen and displays it
int goToStore(Text &continueToGame, Text &gunsMessage, Text &storeHeader)
{  
  SDL_ShowCursor(1);
	SDL_FillRect (screen, &screen->clip_rect,
			SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));
	//store screen
	for(int j=0;j<store.size();j++)
	{
		store[j]->show(screen); //x, y, surface
	}
	continueToGame.show(screen);
	gunsMessage.show(screen);
	storeHeader.show(screen);
	SDL_Flip(screen);

     Text messageToUser("Succesfully Added",continueToGame.getTextXpos()+continueToGame.getWidth()+50,continueToGame.getTextYpos(),colorWhite,20);
   bool continueButton = false;
   while(continueButton == false)
   {
	

	while (SDL_PollEvent (&event)) {
		//If a mouse button was pressed
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			//If the left mouse button was pressed
			if (event.button.button == SDL_BUTTON_LEFT)
			{
	  			//Get the mouse offsets
	  			int x = event.button.x;
	  			int y = event.button.y;
			SDL_FillRect (screen, &screen->clip_rect,
							SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));
					//store screen
					for(int j=0;j<store.size();j++)
					{
						store[j]->show(screen); //x, y, surface
					}
					continueToGame.show(screen);
					gunsMessage.show(screen);
					storeHeader.show(screen);
					SDL_Flip(screen);
				continueButton = purchaseFromStore(x,y,continueToGame,messageToUser);
				if(weapons.size()==0)
					continueButton = false;
			}
		}

		//If the user has Xed out the window
		  if (event.type == SDL_QUIT)
		    {
		      //Quit the program
		      return 0;
		    }

	}
   }
 SDL_ShowCursor(0);
	return 1;
}




//the main function
int
main (int argc, char *args[])
{
//score for the game, increases through the while loop, also will increase based on enemies killed
int score=0;

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

music = Mix_LoadMUS( "beat.wav" );
if( music == NULL )
    {
        return false;    
    }
Mix_PlayMusic( music, -1 );

/*HOME SCREEN*/
  Background background ("background.bmp");
  Background statsborder("border.png");
  background.show(screen);
  
  Text pokeDome("POKEDOME",2*SCREEN_WIDTH/5, SCREEN_HEIGHT/5,colorBlack,50);
  pokeDome.show(screen);
  Text playButton("Play",SCREEN_WIDTH/2,3*SCREEN_HEIGHT/5,colorBlack,30);
  playButton.show(screen);
  SDL_Flip(screen);

  bool play = false;
	//while they have not hit the play button
	while(play==false)
	{
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				//If the left mouse button was pressed
				if (event.button.button == SDL_BUTTON_LEFT)
				{
		  			//Get the mouse offsets
		  			int x = event.button.x;
		  			int y = event.button.y;
					if(playButton.isClicked(x,y))
						play = true;
			
				}
			}

		//If the user has Xed out the window
			  if (event.type == SDL_QUIT)
			    {
			      //Quit the program
			      return 0;
			    }

		}
	}


  load_store();
  Text continueToGame ("Continue to Game", 2 * SCREEN_WIDTH / 5, 8 * SCREEN_HEIGHT / 9, colorWhite, 30);
   Text gunsMessage("Guns",100,10,colorWhite,20);
	Text storeHeader("Select your items", 2*SCREEN_WIDTH/5, 0,colorWhite,40);
     Dome dome ("dome.png", 485, 135, 230, 465, 10000, 10000);
bool gameIsOver= false;

Text scoretext("Score: ",20,20,colorWhite,30);
Text actualscoretext( boost::lexical_cast<string>( score ),110,20,colorWhite,30);
Text weaponname("Weapon: " ,350,20,colorWhite,30);
Text domename ("Dome Health: ",1000,10,colorWhite,20);
Text domehealth(boost::lexical_cast<string>(dome.getCurrentHealth()),1050,30,colorWhite,30);

 Crosshairs crosshairs;
//while they have not beat the game or have not died 
while(gameIsOver==false)
{

  /*ITEM SELECTION*/
   int continued = goToStore(continueToGame,gunsMessage,storeHeader);
	//continue will be 0 if they hit the X on the window while at the store
   if(!continued)
	{
		clean_up();
		return 0;
	}


/* START GAMEPLAY */

  /*LOAD  ENEMIES*/
  load_enemies (); //loads enemies for current level
  quit = false;



  //While the user hasn't quit
  while (quit == false)
    {


   //Start the frame timer
      fps.start ();
      //show the background and dome

      background.show (screen);
	statsborder.show(screen);
      dome.show (screen);

	scoretext.show(screen);
	actualscoretext.setText(boost::lexical_cast<string>(score));
	actualscoretext.show(screen);
	weaponname.show(screen);
	weapons[currentWeaponIndex]->showDuringGamePlay(500,20,screen);
	domename.show(screen);
	//divide health by 100 so it is easier for the user to read
	domehealth.setText(boost::lexical_cast<string>(dome.getCurrentHealth()/100));
	domehealth.show(screen);
//move the enemies
      for (int i = 0; i < enemies.size (); i++)
	{
	  enemies[i]->move ();
	  if (enemies[i]->isDead ())
	    continue;
	//if the enemy is colliding with the dome then attack the dome with the enemy's power
	  if (dome.isCollidingWithEnemy
	      (enemies[i]->getX (), enemies[i]->getY (),
	       enemies[i]->getWidth (), enemies[i]->getHeight (),
	       enemies[i]->getXVel ()))
	    {
	      dome.getAttacked (enemies[i]->attack ());

		//if the dome's health is <=0
	      if (dome.isDead ())
		{
			//freeze the screen for a bit, don't show the dome, then show  game over screen and exit the game
			 background.show (screen);
			  for (int j = 0; j < enemies.size (); j++)
			    {
			      enemies[j]->show (screen, count);
			    } SDL_Flip (screen);
			  SDL_Delay (2000);
			  SDL_FillRect (screen, &screen->clip_rect,
			  				SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));
			  Text levelFail ("Game Over", 2 * SCREEN_WIDTH / 5,
					  2 * SCREEN_HEIGHT / 5, colorWhite,40);
			  levelFail.show (screen);
			  SDL_Flip (screen);
			  SDL_Delay (2000);
			  quit = true;
			  gameIsOver = true;
			  break;
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



		//switch weapons if they hit the left or right arrow keys
	       if(event.type == SDL_KEYDOWN)
		{
			if(event.key.keysym.sym == SDLK_LEFT)
			{
				if(currentWeaponIndex==0) currentWeaponIndex = weapons.size()-1;
				else currentWeaponIndex--;
			}
			else if( event.key.keysym.sym == SDLK_RIGHT)
			{
				if(currentWeaponIndex==weapons.size()-1) currentWeaponIndex = 0;
				else currentWeaponIndex++;
			}
		}
	      weapons[currentWeaponIndex]->handle_events (event, enemies, screen);
	    
	  //If the user has Xed out the window
	  if (event.type == SDL_QUIT)
	    {
	      //Quit the program
	      quit = true;
		gameIsOver = true;
		break;
	    }
	}

	//if all the enemies are dead then the level has been completed
      int levelComplete = 1;
      for (int j = 0; j < enemies.size (); j++)
	{
	  if (!enemies[j]->isDead ())
	    {
	      levelComplete = 0;
	      break;
	    }
	}

	//show level completed screen
      if (levelComplete)
	{
	  SDL_FillRect (screen, &screen->clip_rect,
			SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));
	  Text levelSuccess ("Level Complete", 2 * SCREEN_WIDTH / 5,
			     2 * SCREEN_HEIGHT / 5, colorWhite, 40);
	  levelSuccess.show (screen);
	  SDL_Flip (screen);
	  SDL_Delay (2000);
	  quit = true;
	  currentLevel++;
		//if there are no more levels, show they have beat the game and exit
          if(currentLevel>maxLevel)
	  {
		gameIsOver = true;
 		SDL_FillRect (screen, &screen->clip_rect,
			SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));
		Text gameWon("You have beaten the game!",2 * SCREEN_WIDTH / 5,2 * SCREEN_HEIGHT / 5, colorWhite, 40);
		gameWon.show(screen);
		SDL_Flip(screen);
		SDL_Delay(2000);
		break;
			
	  }
	}

crosshairs.show(screen);
//awards score for the player lasting longer
score++;


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

} //ends gameIsOver while loop

  //Clean up
  clean_up ();

  return 0;
}
