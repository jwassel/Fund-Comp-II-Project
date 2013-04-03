/*Author Jason Wassel
This program was written after reading SDL tutorials located at lazyfoo.net
The character images used in this program came from spriters-resource.com, and the background came from sweetclipart.com

To compile this program, type make on the terminal line.

To use this program, use the up and down arrows to move up and down, and the left and right arrows to change direction

This program does a couple things. It loads images and puts them on surfaces. It is event driven to exit, by clicking the window's 'x' button. It taken in an image, and sets the background to be transparent (if the background is of color EC2626, as I defined.) It takes images off a sprite sheet, and then animates these images to move back and forth across the screen. Lastly It displays text.

The text extension is not located on our laptops, so the text has been commented out
*/

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
//#include "SDL/SDL_ttf.h"
#include <string>
using namespace std;
#include <iostream>

//Screen size at bits per pixel
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *spritesheet = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *explosionsheet=NULL;
SDL_Surface *gunshot=NULL;


//SDL_Surface *message = NULL;

//The event structure-used to wait for event
SDL_Event event;

//Text Font
//TTF_Font *font = NULL;

//The color of the font - white
//SDL_Color textColor = { 255, 255, 255 };

//The portions of the sprite map to be blitted-two squirtles, one venusaur
SDL_Rect sprites[6];

//loads images onto the surface
SDL_Surface *
load_image (string filename)
{
  //The image that's loaded
  SDL_Surface *loadedImage = NULL;

  //The optimized surface that will be used
  SDL_Surface *optimizedImage = NULL;

  //Load the image
  loadedImage = IMG_Load (filename.c_str ());

  //If the image loaded
  if (loadedImage != NULL)
    {
      //Create an optimized surface
      optimizedImage = SDL_DisplayFormat (loadedImage);

      //Free the old surface
      SDL_FreeSurface (loadedImage);

      //If the surface was optimized
      if (optimizedImage != NULL)
	{
	  //Color key surface-Color key is a red color
	  SDL_SetColorKey (optimizedImage, SDL_SRCCOLORKEY,
			   SDL_MapRGB (optimizedImage->format, 0xEC, 0x26,
				       0x26));
	}
    }

  //Return the optimized surface
  return optimizedImage;
}

//applies an image that will be in the background, does not come from sprite sheet
void
apply_surface_background (int x, int y, SDL_Surface * source,
			  SDL_Surface * destination)
{
  //Temporary rectangle to hold the offsets
  SDL_Rect offset;

  //Get the offsets
  offset.x = x;
  offset.y = y;

  //Blit the surface
  SDL_BlitSurface (source, NULL, destination, &offset);
}


//comes from sprite sheet of squirtles
void
apply_surface_squirtle (int x, int y, SDL_Surface * source,
			SDL_Surface * destination, SDL_Rect * sprites = NULL)
{
  //Holds offsets
  SDL_Rect offset;

  //Get offsets
  offset.x = x;
  offset.y = y;

  //Blit
  SDL_BlitSurface (source, sprites, destination, &offset);
}

bool
init ()
{
  //Initialize all SDL subsystems
  if (SDL_Init (SDL_INIT_EVERYTHING) == -1)
    {

      return false;
    }

  //Set up the screen
  screen =
    SDL_SetVideoMode (SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

  //If there was an error in setting up the screen
  if (screen == NULL)
    {
      return false;
    }
  //Initialize SDL_ttf
  /* if (TTF_Init () == -1)
     {
     return false;
     } */
  //Set the window caption
  SDL_WM_SetCaption ("Work for lab 9", NULL);
  //If everything initialized fine
  return true;
}


bool
load_files ()
{
  //Load the sprite maps and background
  spritesheet = load_image ("squirtlej.png");
  background = load_image ("background.bmp");
  explosionsheet=load_image("explosions.PNG");
  gunshot=load_image("explosionsgunshot.PNG");
  // Wartortlesheet=load_image("wartortle.png");
//Open the font
  /* font = TTF_OpenFont ("Arial.ttf", 40);
   */
//If there was an problem loading the sprite map
  if (spritesheet == NULL)
    {

      return false;
    }
/*
  if (font == NULL)
    {
      return false;
    }
*/
  if (background == NULL)
    {
      return false;
    }

  if (explosionsheet == NULL)
    {
      return false;
    }
 if (gunshot == NULL)
    {
      return false;
    }


  //If eveything loaded fine
  return true;
}

void
clean_up ()
{
  //Free the sprite map
  SDL_FreeSurface (spritesheet);
  SDL_FreeSurface (background);
SDL_FreeSurface(explosionsheet);
SDL_FreeSurface(gunshot);
  /* SDL_FreeSurface (message);

     //Close the font that was used
     TTF_CloseFont (font);

     //Quit SDL_ttf
     TTF_Quit (); */
  SDL_Quit ();
}



/////////////////////////////////////////////


//The Enemy
class Enemy
{
public:
  //Initialize the variables
  Enemy (int x, int y, int w, int h);

  //Handles events and set the Enemy's sprite region
  void handle_events ();

  //Shows the Enemy on the screen
  void show (int);
  int isClicked ();

  void set_clips ();
  void Clicked ();
  void updateX (int);
  //The attributes of the Enemy
private:

  int isDead;
int xpos;
int ypos;
int width;
int height;

};
Enemy::Enemy (int x, int y, int w, int h)
{
  //Set the button's attributes
  set_clips ();
  xpos = x;
  ypos = y;
  width = w;
  height = h;
  isDead = 0;
  

}

void
Enemy::Clicked ()
{
  isDead = 1;

}

int
Enemy::isClicked ()
{
  if (isDead == 0)
    return 0;
  else
    return 1;
}

void
Enemy::handle_events ()
{
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
apply_surface_background(x,y,gunshot,screen);
	  //If the mouse is over the button
	  if ((x > xpos) && (x < xpos + width) && (y > ypos)
	      && (y < ypos + height))
	    {
	     
	      Clicked ();
apply_surface_background(xpos+(width/4),ypos+(height/4),explosionsheet,screen);
	    }
	}
    }

}

void
Enemy::show (int count)
{
  //Show the button
  apply_surface_squirtle (xpos, ypos, spritesheet, screen,
			  &sprites[count % 6]);
}



void
Enemy::set_clips ()
{
  //Clip range for the squirtle sprites
  sprites[0].x = 0;
  sprites[0].y = 108;
  sprites[0].w = 38;
  sprites[0].h = 36;

  sprites[1].x = 38;
  sprites[1].y = 108;
  sprites[1].w = 38;
  sprites[1].h = 36;

  sprites[2].x = 76;
  sprites[2].y = 108;
  sprites[2].w = 40;
  sprites[2].h = 36;

  sprites[3].x = 115;
  sprites[3].y = 108;
  sprites[3].w = 39;
  sprites[3].h = 38;

  sprites[4].x = 155;
  sprites[4].y = 108;
  sprites[4].w = 37;
  sprites[4].h = 36;

  sprites[5].x = 192;
  sprites[5].y = 108;
  sprites[5].w = 39;
  sprites[5].h = 36;


}

void
Enemy::updateX (int Xpos)
{
  xpos += Xpos;
}

int
main (int argc, char *args[])
{


//Quit flag
  bool quit = false;

  //Initialize
  if (init () == false)
    {
      return 1;
    }

  //Load the files
  if (load_files () == false)
    {
      return 1;
    }

//position of the squirtle
  int Xpos = 500;
  int ypos = 0;

  Enemy myEnemy (Xpos, ypos, 38, 36);


//count keeps track of position
//dir keeps track of direction
  int count = 0;
  int dir = -1;
  int pixPerSec = 2;
  //Update the screen
  if (SDL_Flip (screen) == -1)
    {
      return 1;
    }
  /* message = TTF_RenderText_Solid (font, "Squirtle can't move through Venusaur", textColor);
     if (message == NULL)
     {
     return 1;
     } */
  //While the user hasn't quit
  while (quit == false && Xpos < 1201 && Xpos > 0)
    {
      apply_surface_background (0, 0, background, screen);
      //apply_surface_background (150, 150, message, screen);



      //If there's events to handle
      while (SDL_PollEvent (&event))
	{
	  myEnemy.handle_events ();


	  //If the user has Xed out the window
	  if (event.type == SDL_QUIT)
	    {
	      //Quit the program
	      quit = true;
	    }
	}


//Show the Enemy If not clicked on
      if (!myEnemy.isClicked ()){
	myEnemy.show (count);}

      Xpos += dir * pixPerSec;
      myEnemy.updateX (dir * pixPerSec);

      count++;
//Update the screen
      if (SDL_Flip (screen) == -1)
	{
	  return 1;
	}
      SDL_Delay (50);


    }

  //Free the images and quit SDL
  clean_up ();

  return 0;
}
