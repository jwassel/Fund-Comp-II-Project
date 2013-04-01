
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
//Screen size at bits per pixel
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 20;


//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
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
    SDL_FreeSurface(background);

    //Quit SDL
    SDL_Quit();
}

//add all the enemies 
void load_enemies(vector<Enemy*> &enemies)
{
   Squirtle squirtle1("squirtle.bmp",1200,300,-5,0);
    enemies[0] = &squirtle1;
}

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

 

    //The frame rate regulator
    Timer fps;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    Background background("background.bmp");
    vector<Enemy*> enemies;
    load_enemies(enemies);
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
	 enemies[j]->show(screen);
	}


        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    //Clean up
    clean_up();

    return 0;
}



