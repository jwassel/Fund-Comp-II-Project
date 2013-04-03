
//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Enemy.h"
#include "Timer.h"
#include "Sprite.h"
#include "Background.h"
#include "Squirtle.h"
#include <string>
#include <vector>
#include <iostream>
//Screen size at bits per pixel
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 20;
using namespace std;

//The screen surface
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

vector<Enemy*> enemies;
Squirtle* sq;

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
    SDL_WM_SetCaption( "Move Squirtle", NULL );

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
void load_enemies()
{
    sq = new Squirtle("squirtlej.png",1200,300,38,36,-5,0);
    enemies.push_back(sq);
    sq = new Squirtle("squirtlej.png",1200,400,38,36,-5,0);
    enemies.push_back(sq);
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
    Background background("background.bmp");
    load_enemies();
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

	//show the background
	background.show(screen);

	//move the enemies
	for(int i=0;i<enemies.size();i++)
	{
	 enemies[i]->move();
	}




	//show the enemies
	for(int j=0;j<enemies.size();j++)
	{
	 enemies[j]->show(screen,count);
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



