/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The button states in the sprite sheet
const int CLIP_MOUSEOVER = 0;
const int CLIP_MOUSEOUT = 1;
const int CLIP_MOUSEDOWN = 2;
const int CLIP_MOUSEUP = 3;

//The surfaces
SDL_Surface *buttonSheet = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The clip regions of the sprite sheet
SDL_Rect clips[ 4 ];

//The Enemy
class Enemy
{
   public:
    //Initialize the variables
    Enemy( int x, int y, int w, int h );

    //Handles events and set the Enemy's sprite region
    void handle_events();

    //Shows the Enemy on the screen
    void show();  
	int isClicked();

 private:
    //The attributes of the Enemy
    SDL_Rect box;

    //The part of the Enemy sprite sheet that will be shown
    SDL_Rect* clip;

    int isDead;
};

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0xEC, 0x26, 0x26 ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

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
    SDL_WM_SetCaption( "Button Test", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the button sprite sheet
    buttonSheet = load_image( "pidgey.png" );

    //If there was a problem in loading the button sprite sheet
    if( buttonSheet == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surface
    SDL_FreeSurface( buttonSheet );

    //Quit SDL
    SDL_Quit();
}



Enemy::Enemy( int x, int y, int w, int h )
{
    //Set the button's attributes
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
    isDead=0;
    //Set the default sprite
    clip = &clips[ CLIP_MOUSEOUT ];
}

int Enemy::isClicked(){
if (isDead==0)
return 0;
else
return 1;
}

void Enemy::handle_events()
{
    //The mouse offsets
    int x = 0, y = 0;

    //If the mouse moved
    if( event.type == SDL_MOUSEMOTION )
    {
        //Get the mouse offsets
        x = event.motion.x;
        y = event.motion.y;

        //If the mouse is over the Enemy
        if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
        {
            //Set the Enemy sprite
            clip = &clips[ CLIP_MOUSEOVER ];
        }
        //If not
        else
        {
            //Set the Enemy sprite
            clip = &clips[ CLIP_MOUSEOUT ];
        }
    }
    //If a mouse button was pressed
    if( event.type == SDL_MOUSEBUTTONDOWN )
    {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;

            //If the mouse is over the button
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
                //Set the button sprite
                clip = &clips[ CLIP_MOUSEDOWN ];
            }
        }
    }
    //If a mouse button was released
    if( event.type == SDL_MOUSEBUTTONUP )
    {
        //If the left mouse button was released
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;

            //If the mouse is over the button
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
                //Set the button sprite
                clip = &clips[ CLIP_MOUSEUP ];
            }
        }
    }
}

void Enemy::show()
{
    //Show the button
    apply_surface( box.x, box.y, buttonSheet, screen, clip );
}

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }


    //Make the button
    Enemy myEnemy(8, 7, 37, 30 );

    //While the user hasn't quit
    while( quit == false )
    {
        //If there's events to handle
        if( SDL_PollEvent( &event ) )
        {
            //Handle Enemy events
            myEnemy.handle_events();

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        //Show the Enemy If not clicked on
        if(!myEnemy.isClicked())
	myEnemy.show();

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }

    //Clean up
    clean_up();

    return 0;
}
