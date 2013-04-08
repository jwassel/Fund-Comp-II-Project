
//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Weapon.h"
#include "PlasmaCannon.h"
#include <string>
#include <vector>
#include <iostream>
#include "Timer.h"
#include "Pistol.h"
#include "Gatling.h"
#include "Smg.h"
#include "Lmg.h"

//Screen size at bits per pixel
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 1200;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 20;
using namespace std;

//The screen surface
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

vector<Weapon*> weapons;
PlasmaCannon* plasmaCannon;
Pistol* pistol;
Gatling* gatling;
Smg* smg;
Lmg* lmg;

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
	cout<<"SDL Initialization failed"<<endl;
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
	cout<<"Screen is null"<<endl;
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Welcome to the Shop", NULL );

    //If everything initialized fine
    return true;
}

void clean_up()
{
    //Free the surface
    //SDL_FreeSurface(background);

    //Quit SDL
    SDL_Quit();
}

//add all the enemies 
void load_weapons()
{    // Clipsize, Price, AmmoPrice, Damage, FireRate, x on screen, y on screen
    plasmaCannon = new PlasmaCannon(25,1000,100,100,1,100,450);
    weapons.push_back(plasmaCannon);
    pistol = new Pistol(12,100,10,15,5,100,60);
    weapons.push_back(pistol);
    gatling = new Gatling(60,400,30,8,30,100,250);
    weapons.push_back(gatling);
    smg = new Smg(40,500,35,15,20,100,150);
    weapons.push_back(smg);
    lmg = new Lmg(100,700,40,25,18,100,350);
    weapons.push_back(lmg);
}

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    int count = 0;

    //The frame rate regulator
    Timer fps;

    //Initialize
    if( init() == false )
    {
        return 1;
    }
    load_weapons();
    //While the user hasn't quit
    while( quit == false )
    {
        //Start the frame timer
        fps.start();

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
	
	//show the weapons
	for(int j=0;j<weapons.size();j++)
	{
	 weapons[j]->show(screen);
	}

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
	 cout<<"Failed updating the screen"<<endl;
            return 1;
        }

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
	count++;
    }

    //Clean up
    clean_up();

    return 0;


}



