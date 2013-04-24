
//implementation of the abstract Weapon class

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Weapon.h"
#include "Enemy.h"
#include <iostream>
#include <string>
using namespace std;
Weapon::Weapon(string filename,string explosionName, string Name,int Price, int AmmoPrice, int Damage, int FireRate, int x, int y,int expsize, int max, int current, int maxclip, int currentclip):Item(x,y,Price,filename){

name=Name;
ammoPrice = AmmoPrice;
damage = Damage;
fireRate = fireRate;
explosionSize=expsize;
maxAmmo=max;
currentAmmo=current;
maxClipAmmo=maxclip;
currentClipAmmo=currentclip;
reloadTime=RELOAD_TIME;
crosshairsReloadTime=30;


sprite = load_image(filename.c_str());
explosionImage = load_image(explosionName.c_str());

}

string Weapon::getName(){
return name;
}

bool Weapon::addToCurrentAmmo(int m)
{

	if(currentAmmo+currentClipAmmo==maxAmmo+maxClipAmmo){
		return false;
	}
	if(currentAmmo+currentClipAmmo+m>=maxAmmo+maxClipAmmo) {

		currentAmmo=maxAmmo;
		currentClipAmmo=maxClipAmmo;
	
		return true;
	}
	if(currentAmmo+m<maxAmmo){
			
		currentAmmo+=m;
		return true;	
	}
	if(currentAmmo<maxAmmo){
		
		currentAmmo=maxAmmo;
		return true;
	}
	if(currentClipAmmo<maxClipAmmo){
			currentClipAmmo+=m;
			if(currentClipAmmo>maxClipAmmo){
				currentClipAmmo=maxClipAmmo;
					
			}
	return true;

	}
	if(currentClipAmmo<maxClipAmmo){
		
		currentClipAmmo+=m;
		if(currentClipAmmo>maxClipAmmo){
				currentClipAmmo=maxClipAmmo;
				return true;
		}
	}

}
int Weapon::getCurrentClipAmmo(){
return currentClipAmmo;

}


int Weapon::getCurrentAmmo(){
return currentAmmo;

}


int Weapon::getMaxAmmo(){
return maxAmmo;

}

int Weapon::getMaxClipAmmo()
{
	return maxClipAmmo;
}




void Weapon::showExplosion(int x, int y, SDL_Surface *screen)
{
      apply_surface(x,y,explosionImage,screen,NULL);
}

int Weapon::getSize(){
return explosionSize;
}

void Weapon::handle_events(SDL_Event event,vector<Enemy*> enemies, SDL_Surface * screen, int &score, int &money, Crosshairs &crosshairs)
{
//The mouse offsets
  int x = 0, y = 0;
int enemyX = 0;
int enemyY = 0;
int enemyWidth = 0;
int enemyHeight = 0;
if(currentClipAmmo>0)
  {
  //If a mouse button was pressed
  if (event.type == SDL_MOUSEBUTTONDOWN)
    {
      //If the left mouse button was pressed
      if (event.button.button == SDL_BUTTON_LEFT)
	{
	
	  //Get the mouse offsets
	  x = event.button.x;
	  y = event.button.y;
	  showExplosion(x-getSize()/2,y-getSize()/2,screen);
	  
	  currentClipAmmo--;
	for(int i=0;i<enemies.size();i++)
	{
	enemyX = enemies[i]->getX();
	enemyY = enemies[i]->getY();
	enemyWidth = enemies[i]->getWidth();
	enemyHeight = enemies[i]->getHeight();
	if ((x > enemyX) && (x < enemyX + enemyWidth) && (y > enemyY)
	      && (y < enemyY + enemyHeight))
	    {
		if(enemies[i]->isDead()==false)
		{
		crosshairs.setImage("crosshairs.png");
		crosshairs.setCrosshairsGreen(false);
		enemies[i]->getAttacked(damage,score,money);
		score+=HIT_BONUS;
		money+=HIT_BONUS;
		}
	    }

	}

	}
    }
  }
else{
reloadTime--;
	if(reloadTime<=0){
		if(currentAmmo>=maxClipAmmo)
		{
			currentClipAmmo=maxClipAmmo;
			currentAmmo=currentAmmo-maxClipAmmo;
		}
		else if (currentAmmo>0)
		{
			currentClipAmmo = currentAmmo;
			currentAmmo = 0;
		}
		reloadTime=RELOAD_TIME;
	}
}

if(crosshairs.isTheCrosshairsGreen()==false)
{

	crosshairsReloadTime--;
	//cout<<crosshairsReloadTime<<endl;
	if(crosshairsReloadTime<=0)
	{
		cout<<"got in reload time is 0"<<endl;
		crosshairs.setImage("greenCrosshairs.png");
		crosshairs.setCrosshairsGreen(true);
		crosshairsReloadTime = 30;
	}
}
}


void Weapon::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip){ //applies new surface
    

//Holds offsets
    SDL_Rect shift;

    //Get offsets
    shift.x = x;
    shift.y = y;

    //Blit
    SDL_BlitSurface(source, clip, destination, &shift);

}

SDL_Surface * Weapon::load_image(std::string filename)
{
	//temporary storage for the image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized image that will be used
	SDL_Surface* optimizedImage = NULL;

	//Load the iamge
	loadedImage = IMG_Load(filename.c_str());
	//this is 24 bit so not good idea to use this b/c causes slowdown
	
	//if nothing went wrong in loading the image
	if(loadedImage!=NULL)
	{
		//create an optimized image in the same format as the screen (32 bit)
		optimizedImage = SDL_DisplayFormat(loadedImage);

	//Free the old image
	SDL_FreeSurface(loadedImage);

		if(optimizedImage!=NULL)
		{
			//Map the color key
			Uint32 colorkey = SDL_MapRGB( optimizedImage -> format,0xec,0x26,0x26);

			//Set all pizels of color R 0, G 0xFF, B 0xFF to be transparent
			SDL_SetColorKey(optimizedImage,SDL_SRCCOLORKEY, colorkey);
		}
	}
		return optimizedImage;
}


int Weapon::getXpos() {
	return xInStore;
}

int Weapon::getYpos() {
	return yInStore;
}

