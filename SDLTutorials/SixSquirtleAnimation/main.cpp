/*Author Jason Wassel
This program was written after reading SDL tutorials located at lazyfoo.net
The character images used in this program came from spriters-resource.com, and the background came from sweetclipart.com

This program does a couple things. It loads images and puts them on surfaces. It is event driven to exit, by clicking the window's 'x' button. It taken in an image, and sets the background to be transparent (if the background is of color EC2626, as I defined.) It takes images off a sprite sheet, and then animates these images to move back and forth across the screen. Lastly It displays text.
*/

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>


//Screen size at bits per pixel
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *spritesheet = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *venusaurspritesheet = NULL;
SDL_Surface *message = NULL;

//The event structure-used to wait for event
SDL_Event event;

//Text Font
TTF_Font *font = NULL;

//The color of the font - white
SDL_Color textColor = { 255, 255, 255 };

//The portions of the sprite map to be blitted-two squirtles, one venusaur
SDL_Rect sprites[6];
SDL_Rect venusaur[1];

//loads images onto the surface
SDL_Surface *
load_image (std::string filename)
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

//comes from sprite sheet of venusaurs
void
apply_surface_venusaur (int x, int y, SDL_Surface * source,
			SDL_Surface * destination, SDL_Rect * venusaur = NULL)
{
  //Holds offsets
  SDL_Rect offset;

  //Get offsets
  offset.x = x;
  offset.y = y;

  //Blit
  SDL_BlitSurface (source, venusaur, destination, &offset);
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
  if (TTF_Init () == -1)
    {
      return false;
    }
  //Set the window caption
  SDL_WM_SetCaption ("Work for lab 8", NULL);
  //If everything initialized fine
  return true;
}



bool
load_files ()
{
  //Load the sprite maps and background
  spritesheet = load_image ("squirtlej.png");
  background = load_image ("background.bmp");
  venusaurspritesheet = load_image ("venusaur.png");
//Open the font
  font = TTF_OpenFont ("Arial.ttf", 40);

//If there was an problem loading the sprite map
  if (spritesheet == NULL)
    {
      return false;
    }

  if (font == NULL)
    {
      return false;
    }

  if (background == NULL)
    {
      return false;
    }

  if (venusaurspritesheet == NULL)
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
  SDL_FreeSurface (venusaurspritesheet);
  SDL_FreeSurface (message);
  //Quit SDL
  //Close the font that was used
  TTF_CloseFont (font);

  //Quit SDL_ttf
  TTF_Quit ();
  SDL_Quit ();
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

  //Clip range for the squirtle sprites
  sprites[0].x = 0;
  sprites[0].y = 108;
  sprites[0].w = 38;
  sprites[0].h = 36;

  //Clip range for the top right
  sprites[1].x = 38;
  sprites[1].y = 108;
  sprites[1].w = 38;
  sprites[1].h = 36;

  sprites[2].x = 76;
  sprites[2].y = 108;
  sprites[2].w = 38;
  sprites[2].h = 36;

  sprites[3].x = 107;
  sprites[3].y = 108;
  sprites[3].w = 38;
  sprites[3].h = 36;

  sprites[4].x = 145;
  sprites[4].y = 108;
  sprites[4].w = 38;
  sprites[4].h = 36;

  sprites[5].x = 183;
  sprites[5].y = 108;
  sprites[5].w = 38;
  sprites[5].h = 36;


  venusaur[0].x = 1200;
  venusaur[0].y = 207;
  venusaur[0].w = 180;
  venusaur[0].h = 170;

//position of the squirtle
  int xpos = 1200;
  int ypos = 300;
//count keeps track of position
//dir keeps track of direction
  int count = 0;
  int dir = -1;
  int pixPerSec = 10;
  //Update the screen
  if (SDL_Flip (screen) == -1)
    {
      return 1;
    }
  message = TTF_RenderText_Solid (font, "Squirtle can't move through Venusaur", textColor);
  if (message == NULL)
    {
      return 1;
    }
  //While the user hasn't quit
  while (quit == false && xpos < 1203)
    {
      apply_surface_background (0, 0, background, screen);
      apply_surface_background (150, 150, message, screen);

      apply_surface_venusaur (100, 300, venusaurspritesheet, screen,
			      &venusaur[0]);
      apply_surface_squirtle (xpos, ypos, spritesheet, screen,
			      &sprites[count % 6]);

      //While there's events to handle
      while (SDL_PollEvent (&event))
	{
	  if (event.type == SDL_KEYDOWN)
	    {
	      switch (event.key.keysym.sym)
		{

		case SDLK_LEFT:
		  dir = -1;
		  break;
		case SDLK_RIGHT:
		  dir = 1;
		  break;
		}
	    }

	  //If the user has Xed out the window
	  else if (event.type == SDL_QUIT)
	    {
	      //Quit the program
	      quit = true;
	    }
	}			//Update the screen
      if (SDL_Flip (screen) == -1)
	{
	  return 1;
	}

//updates position and turns squirtle around if necessary
      if (xpos < 280)
	dir *= -1;

      xpos += (dir) * pixPerSec;
      count++;
      SDL_Delay (30);
    }

  //Free the images and quit SDL
  clean_up ();

  return 0;
}
