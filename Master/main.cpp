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
#include "Constants.h"
#include "Crosshairs.h"
#include "Voltorb.h"
#include "Bomb.h"
#include "Electrode.h"
#include "Articuno.h"
#include "Rarticuno.h"
#include "Charmander.h"
#include "Rcharmander.h"
#include "Machamp.h"
#include "Rmachamp.h"
#include "Rmarowak.h"
#include "Marowak.h"
#include "Pidgey.h"
#include "Zapdos.h"
#include "Rzapdos.h"
#include "Item.h"
#include "Health.h"
#include "Ammo.h"
#include <boost/lexical_cast.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

//The screen surface
SDL_Surface *screen = NULL;
SDL_Surface *cursor=NULL;

SDL_Color colorWhite = { 255, 255, 255 };
SDL_Color colorBlack = {0,0,0};
SDL_Color colorRed = {220,20,20};
//The event structure
SDL_Event event;

//the different enemies the game can have
vector < Enemy * >enemies; //vector to store the enemies in a given level
Squirtle *squirtle;
Poliwhirl *poliwhirl;
Rpidgey *rpidgey;
Voltorb *voltorb;
Electrode *electrode;
Articuno *articuno;
Rarticuno *rarticuno;
Rcharmander *rcharmander;
Charmander *charmander;
Marowak *marowak;
Rmarowak *rmarowak;
Machamp *machamp;
Rmachamp *rmachamp;
Pidgey *pidgey;
Zapdos *zapdos;
Rzapdos *rzapdos;


SDL_Surface *message = NULL;

//vector that stores the user's current weapons
vector < Weapon * >weapons;

vector < Item * >store;
vector < Bomb * > bombs;

//all the possible weapons
Pistol *pistol;
PlasmaCannon* plasmaCannon;
Gatling* gatling;
Smg* smg;
Lmg* lmg;

Ammo *pistolAmmo;
Ammo *smgAmmo;
Ammo *lmgAmmo;
Ammo *gatlingAmmo;
Ammo *plasmaCannonAmmo;

//health declared
Health* health;

//Music
Mix_Music *music;

//will be true when they buy the gun. so that they don't buy multiple
bool addedPistol=false,addedSmg=false,addedLmg=false,addedGatling=false,addedPlasma=false;

//user can only use one weapon at a time
int currentWeaponIndex = 0;

//the current level and the maximum # of levels programmed by us
int currentLevel = 1;
int maxLevel = 10;
int money = INITIAL_MONEY;

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

//Takes in a random number from load enemies, this number will determine which pokemon is spawned
void addpokemon(int key){
	switch (key){
	case 1:
		squirtle =new Squirtle ("squirtlej.png", rand()%1500+900, 0, SQUIRTLE_HEIGHT, SQUIRTLE_WIDTH, -(rand()%5+3),Y_VELOCITY_DESCENT, SQUIRTLE_POWER, SQUIRTLE_HEALTH);
		enemies.push_back (squirtle);
	break;
	case 2:
		charmander =new Charmander ("charmander.png", rand()%1500+900, 0, CHARMANDER_HEIGHT,CHARMANDER_WIDTH, -(rand()%5+3), Y_VELOCITY_DESCENT, CHARMANDER_POWER, CHARMANDER_HEALTH);
		enemies.push_back (charmander);
	break;
	case 3:
		rcharmander =new Rcharmander ("Rcharmander.png", -(rand()%2400), 0, CHARMANDER_HEIGHT, CHARMANDER_WIDTH, (rand()%5+3), Y_VELOCITY_DESCENT, CHARMANDER_POWER, CHARMANDER_HEALTH);
		enemies.push_back (rcharmander);
	break;
	case 4:
		pidgey =new Pidgey ("pidgey.png", rand()%600+900, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, PIDGEY_HEIGHT, PIDGEY_WIDTH, -(rand()%5+3), 0,PIDGEY_POWER, PIDGEY_HEALTH);
		enemies.push_back (pidgey);
	break;
	case 5:
		rpidgey =new Rpidgey ("Rpidgey.png", -(rand()%2400), rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, PIDGEY_HEIGHT, PIDGEY_WIDTH, (rand()%5+3), Y_VELOCITY_DESCENT, PIDGEY_POWER, PIDGEY_HEALTH);
		enemies.push_back (rpidgey);
	break;
	case 6:
		poliwhirl =new Poliwhirl ("poliwhirl.png", rand()%1500+900, 0, POLIWHIRL_HEIGHT, POLIWHIRL_WIDTH,-(rand()%8+5), Y_VELOCITY_DESCENT, POLIWHIRL_POWER, POLIWHIRL_HEALTH);
		enemies.push_back (poliwhirl);
	break;
	case 7:
		machamp =new Machamp ("machamp.png", rand()%1500+900, 0, MACHAMP_HEIGHT, MACHAMP_WIDTH, -(rand()%8+5), Y_VELOCITY_DESCENT,MACHAMP_POWER, MACHAMP_HEALTH);
		enemies.push_back(machamp);
	break;
	case 8:
	rmachamp =new Rmachamp ("Rmachamp.png", -rand()%2400, 0, MACHAMP_HEIGHT, MACHAMP_WIDTH, (rand()%8+5), Y_VELOCITY_DESCENT,MACHAMP_POWER, MACHAMP_HEALTH);
		enemies.push_back(rmachamp);
	break;
	case 9:
		marowak =new Marowak ("marowak.png", rand()%1500+900, 0, MAROWAK_HEIGHT, MAROWAK_WIDTH, -(rand()%8+5), Y_VELOCITY_DESCENT,MAROWAK_POWER, MAROWAK_HEALTH);
		enemies.push_back(marowak);
	break;
	case 10:
	rmarowak =new Rmarowak ("Rmarowak.png", -(rand()%2400), 0, MAROWAK_HEIGHT, MAROWAK_WIDTH, (rand()%8+5), Y_VELOCITY_DESCENT,MAROWAK_POWER, MAROWAK_HEALTH);
		enemies.push_back(rmarowak);
	break;
	case 11:
		rzapdos = new Rzapdos ("Rzapdos.png", -(rand()%2400), rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ZAPDOS_HEIGHT, ZAPDOS_WIDTH, (rand()%12+5), 0,ZAPDOS_POWER, ZAPDOS_HEALTH);
		enemies.push_back (rzapdos);
	break;
	case 12:
		zapdos =new Zapdos ("zapdos.png", rand()%1500+900, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ZAPDOS_HEIGHT, ZAPDOS_WIDTH, -(rand()%12+5), 0,ZAPDOS_POWER, ZAPDOS_HEALTH);
		enemies.push_back (zapdos);
	break;
	case 13:
		rarticuno =new Rarticuno ("Rarticuno.png",-(rand()%2400), rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ARTICUNO_HEIGHT, ARTICUNO_WIDTH, (rand()%12+5),0, ARTICUNO_POWER, ARTICUNO_HEALTH);
		enemies.push_back (rarticuno);
	break;
		case 14:articuno =new Articuno ("articuno.png", rand()%1500+900, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ARTICUNO_HEIGHT, ARTICUNO_WIDTH,-(rand()%12+5), 0, ARTICUNO_POWER, ARTICUNO_HEALTH);
		enemies.push_back (articuno);
	break;
	default:
	break;
}
}


//add all the enemies for the given level 
void load_enemies ()
{
//gets rid of any remaining enemies from the previous loop.
   enemies.clear();

int pokemonkey;
//numberOfEnemies Randomly determines how many enemies will spawn each round. goes up as levels go up
int numberOfEnemies=rand()%4+2*currentLevel;
//adds correct number of enemies
for(int i=0; i<numberOfEnemies;i++)
{

//pokemon key determines what species of pokemon will be created. each time through the for loop, a different one is made. the while loop ensures that a key that we have is to be used
pokemonkey=rand()%(3+currentLevel)+1;
while(pokemonkey>13){
pokemonkey=rand()%(3+currentLevel)+1;
}

//pushes back the proper enemy
addpokemon(pokemonkey);
}
	rmachamp =new Rmachamp ("Rmachamp.png", -rand()%2400, 0, MACHAMP_HEIGHT, MACHAMP_WIDTH, (rand()%8+5), Y_VELOCITY_DESCENT,MACHAMP_POWER, MACHAMP_HEALTH);
		enemies.push_back(rmachamp);

}




//loads all the items to the store
void load_store()
{    



    plasmaCannon = new PlasmaCannon("weapons.png", "explosionplasma.PNG",PLASMA_CANNON_PRICE,PLASMA_CANNON_AMMO_PRICE,PLASMA_CANNON_DAMAGE,5,PLASMA_CANNON_X,PLASMA_CANNON_Y,PLASMA_CANNON_EXP_SIZE,PLASMA_CANNON_MAX_AMMO,PLASMA_CANNON_MAX_AMMO,PLASMA_CANNON_MAX_CLIP_AMMO,PLASMA_CANNON_MAX_CLIP_AMMO);
    store.push_back(plasmaCannon);
    pistol = new Pistol("weapons.png", "explosionpistol.png", PISTOL_PRICE,PISTOL_AMMO_PRICE,PISTOL_DAMAGE,5,PISTOL_X,PISTOL_Y,PISTOL_EXP_SIZE,PISTOL_MAX_AMMO,PISTOL_MAX_AMMO,PISTOL_MAX_CLIP_AMMO,PISTOL_MAX_CLIP_AMMO);
    store.push_back(pistol);
    gatling = new Gatling("weapons.png", "explosiongatling.png",  GATLING_PRICE,GATLING_AMMO_PRICE,GATLING_DAMAGE,5,GATLING_X,GATLING_Y,GATLING_EXP_SIZE,GATLING_MAX_AMMO,GATLING_MAX_AMMO,GATLING_MAX_CLIP_AMMO,GATLING_MAX_CLIP_AMMO);
    store.push_back(gatling);
    smg = new Smg("weapons.png", "explosionsmg.PNG",SMG_PRICE,SMG_AMMO_PRICE,SMG_DAMAGE,5,SMG_X,SMG_Y,SMG_EXP_SIZE,SMG_MAX_AMMO,SMG_MAX_AMMO,SMG_MAX_CLIP_AMMO,SMG_MAX_CLIP_AMMO);
    store.push_back(smg);
    lmg = new Lmg("weapons.png", "explosionlmg.PNG",LMG_PRICE,LMG_AMMO_PRICE,LMG_DAMAGE,5,LMG_X,LMG_Y,LMG_EXP_SIZE,LMG_MAX_AMMO,LMG_MAX_AMMO,LMG_MAX_CLIP_AMMO,LMG_MAX_CLIP_AMMO);
    store.push_back(lmg);

    voltorb = new Voltorb ("bombs.png", VOLTORB_PRICE, VOLTORB_DAMAGE, VOLTORB_X, VOLTORB_Y);
    store.push_back(voltorb);

    health = new Health ("redCross.png", HEALTH_PRICE, HEALTH_X, HEALTH_Y);
    store.push_back(health);

    pistolAmmo = new Ammo("ammoScreenshot.png", PISTOL_AMMO_PRICE, PISTOL_AMMO_X, PISTOL_AMMO_Y, 0);
    store.push_back(pistolAmmo);

    smgAmmo = new Ammo("ammoScreenshot.png", SMG_AMMO_PRICE, SMG_AMMO_X, SMG_AMMO_Y, 1);
    store.push_back(smgAmmo);

    lmgAmmo = new Ammo("ammoScreenshot.png", LMG_AMMO_PRICE, LMG_AMMO_X, LMG_AMMO_Y, 2);
    store.push_back(lmgAmmo);

    gatlingAmmo = new Ammo("ammoScreenshot.png", GATLING_AMMO_PRICE, GATLING_AMMO_X, GATLING_AMMO_Y, 3);
    store.push_back(gatlingAmmo);

    plasmaCannonAmmo = new Ammo("ammoScreenshot.png", PLASMA_CANNON_AMMO_PRICE, PLASMA_CANNON_AMMO_X, PLASMA_CANNON_AMMO_Y, 4);
    store.push_back(plasmaCannonAmmo);


}

void goToInstructions(Text &backButton)
{

	 SDL_FillRect (screen, &screen->clip_rect,
	SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));
	backButton.show(screen);
	Text actualInstructions("PokeDome",SCREEN_WIDTH/2-100,0,colorWhite,30);
	actualInstructions.show(screen);
	actualInstructions.setSize(20);
	actualInstructions.setX(50);

	actualInstructions.setText("Goal: Protect the Golden Dome by shooting the Pokemon");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight()+20);
	actualInstructions.show(screen);
	
	actualInstructions.setText("Before each level, you can go to the store to buy items");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight());
	actualInstructions.show(screen);

	actualInstructions.setText("Buy Weapons and Ammo at the store, click to shoot");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight());
	actualInstructions.show(screen);

	actualInstructions.setText("To switch amongst your weapons, use the arrow keys");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight());
	actualInstructions.show(screen);

	actualInstructions.setText("Buy Health for the Dome at the store");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight());
	actualInstructions.show(screen);

	actualInstructions.setText("Once the Dome's Health is 0, you lose");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight());
	actualInstructions.show(screen);

	actualInstructions.setText("To reload when your clip is empty, shake the mouse quickly");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight());
	actualInstructions.show(screen);

	SDL_Flip(screen);
	bool goBack = false;
	while(goBack==false)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
		  			//Get the mouse offsets
		  			int x = event.button.x;
		  			int y = event.button.y;
					if(backButton.isClicked(x,y))
					{
						goBack = true;
						break;
					}
				}
			}
		}
	}
}


//takes user's click when on the store screen and updates their inventory
bool purchaseFromStore(int x, int y, Dome &dome,Text &continueToGame, Text&messageToUser,Text &actualMoneyText, Text &actualDomeHealthText)
{

	if(continueToGame.isClicked(x,y)) {
		return true;
	}
	
	if(voltorb->isClicked(x,y))
	{
		if(money>=voltorb->getPrice())
		{
			money-=voltorb->getPrice();
			actualMoneyText.setText(boost::lexical_cast<string>(money));
			messageToUser.setText("Succesfully Added Voltorb");
			bombs.push_back(voltorb);
		}
		else
			messageToUser.setText("Not enough Money!");
	}
	if(pistol->isClicked(x,y))
	{
		if(addedPistol==false)
		{
			if(money>=pistol->getPrice())
			{
				money-=pistol->getPrice();
				actualMoneyText.setText(boost::lexical_cast<string>(money));
				messageToUser.setText("Succesfully Added Pistol");
				weapons.push_back (pistol);
				addedPistol=true;
			}
			else
				messageToUser.setText("Not enough Money!");
		}
		else
			messageToUser.setText("You already own a pistol!");


	}
	
	if(gatling->isClicked(x,y))
	{
		if(addedGatling==false)
		{
			if(money>=gatling->getPrice())
			{
				money-=gatling->getPrice();
				actualMoneyText.setText(boost::lexical_cast<string>(money));
				messageToUser.setText("Succesfully Added Gatling");
				weapons.push_back (gatling);
				addedGatling=true;
			}
			else
				messageToUser.setText("Not enough Money!");
		}
		else
			messageToUser.setText("You already own a gatling!");

	}

	if(lmg->isClicked(x,y))
	{
		if(addedLmg==false)
		{
			if(money>=lmg->getPrice())
			{
				money-=lmg->getPrice();
				actualMoneyText.setText(boost::lexical_cast<string>(money));
				messageToUser.setText("Succesfully Added LMG");
				weapons.push_back (lmg);
				addedLmg=true;
			}
			else
				messageToUser.setText("Not enough Money!");
		}
		else
			messageToUser.setText("You already own an LMG!");

	}

	if(smg->isClicked(x,y))
	{
		if(addedSmg==false)
		{
			if(money>=smg->getPrice())
			{
				money-=smg->getPrice();
				actualMoneyText.setText(boost::lexical_cast<string>(money));
				messageToUser.setText("Succesfully Added SMG");
				weapons.push_back (smg);
				addedSmg=true;
			}
			else
				messageToUser.setText("Not enough Money!");
			}
		else
			messageToUser.setText("You already own an SMG!");	

	}

	if(plasmaCannon->isClicked(x,y))
	{
		if(addedPlasma==false)
		{
			if(money>=plasmaCannon->getPrice())
			{
				money-=plasmaCannon->getPrice();
				actualMoneyText.setText(boost::lexical_cast<string>(money));
				messageToUser.setText("Succesfully Added Plasma Cannon");
				weapons.push_back (plasmaCannon);
				addedPlasma = true;
			}
			else
				messageToUser.setText("Not enough Money!");
		}
		else
			messageToUser.setText("You already own a Plasma Cannon!");
	}
	if(health->isClicked(x,y))
	{
		if(money>=health->getPrice())
		{
			
			bool addedHealth = dome.addToCurrentHealth(HEALTH_ADDED);
			if(addedHealth)
			{
			money-=health->getPrice();
			actualMoneyText.setText(boost::lexical_cast<string>(money));
			actualDomeHealthText.setText(boost::lexical_cast<string>(dome.getCurrentHealth()/HEALTH_DIVISION_FACTOR));
			 messageToUser.setText("Succesfully Added Health");
			}
			else messageToUser.setText("Health is already full!");		
		}
		else
			messageToUser.setText("Not enough Money!");
	}
	if(pistolAmmo->isClicked(x,y))
	{
		if(addedPistol)
		{
			if(money>=pistolAmmo->getPrice())
			{
			
				bool addedAmmo = pistol->addToCurrentAmmo(PISTOL_AMMO_PER_PURCHASE);
				if (addedAmmo)
				{
					money-=pistolAmmo->getPrice();
					actualMoneyText.setText(boost::lexical_cast<string>(money));
					messageToUser.setText("Succesfully Added Pistol Ammo");
				}
				else messageToUser.setText("Pistol has full ammo!");
			}
			else
				messageToUser.setText("Not enough Money!");
		}
		else
			messageToUser.setText("You don't own a pistol!");
	}
	if(smgAmmo->isClicked(x,y))
	{
		if(addedSmg)
		{
			if(money>=smgAmmo->getPrice())
			{
			
				bool addedAmmo = smg->addToCurrentAmmo(SMG_AMMO_PER_PURCHASE);
				if (addedAmmo)
				{
					money-=smgAmmo->getPrice();
					actualMoneyText.setText(boost::lexical_cast<string>(money));
					messageToUser.setText("Succesfully Added Smg Ammo");
				}
				else messageToUser.setText("Smg has full ammo!");
			}
			else
				messageToUser.setText("Not enough Money!");
		}
		else
			messageToUser.setText("You don't own a Smg!");
	}
	if(lmgAmmo->isClicked(x,y))
	{
		if(addedLmg)
		{
			if(money>=lmgAmmo->getPrice())
			{
			
				bool addedAmmo = lmg->addToCurrentAmmo(LMG_AMMO_PER_PURCHASE);
				if (addedAmmo)
				{
					money-=lmgAmmo->getPrice();
					actualMoneyText.setText(boost::lexical_cast<string>(money));
					messageToUser.setText("Succesfully Added Lmg Ammo");
				}
				else messageToUser.setText("Lmg has full ammo!");
			}
			else
				messageToUser.setText("Not enough Money!");
		}
		else
			messageToUser.setText("You don't own a Lmg!");
	}
	if(gatlingAmmo->isClicked(x,y))
	{
		if(addedGatling)
		{
			if(money>=gatlingAmmo->getPrice())
			{
			
				bool addedAmmo = gatling->addToCurrentAmmo(GATLING_AMMO_PER_PURCHASE);
				if (addedAmmo)
				{
					money-=gatlingAmmo->getPrice();
					actualMoneyText.setText(boost::lexical_cast<string>(money));
					messageToUser.setText("Succesfully Added Gatling Ammo");
				}
				else messageToUser.setText("Gatling has full ammo!");
			}
			else
				messageToUser.setText("Not enough Money!");
		}
		else
			messageToUser.setText("You don't own a Gatling!");
	}
	if(plasmaCannonAmmo->isClicked(x,y))
	{
		if(addedPlasma)
		{
			if(money>=plasmaCannonAmmo->getPrice())
			{
			
				bool addedAmmo = plasmaCannon->addToCurrentAmmo(PLASMA_CANNON_AMMO_PER_PURCHASE);
				if (addedAmmo)
				{
					money-=gatlingAmmo->getPrice();
					actualMoneyText.setText(boost::lexical_cast<string>(money));
					messageToUser.setText("Succesfully Added Plasma Cannon Ammo");
				}
				else messageToUser.setText("Plasma Cannon has full ammo!");
			}
			else
				messageToUser.setText("Not enough Money!");
		}
		else
			messageToUser.setText("You don't own a Plasma Cannon!");
	}
	return false;	
}

//goes to the store screen and displays it
int goToStore(Dome &dome,Text &continueToGame, Text &gunsMessage, Text &priceHeader, Text &storeHeader, Text &moneyText, Text &actualMoneyText,Text &pistolPriceText,Text &plasmaCannonPriceText,Text &gatlingPriceText,Text &smgPriceText,Text &lmgPriceText, Text &voltorbPriceText, Text &specialsText, Text &healthPriceText, Text &domeText, Text&actualDomeHealthText,Text &pistolAmmoPriceText,Text &plasmaCannonAmmoPriceText,Text &gatlingAmmoPriceText,Text &smgAmmoPriceText,Text &lmgAmmoPriceText)
{  
	//set money text and dome health since money and health could change each time you come to the store
	actualMoneyText.setText(boost::lexical_cast<string>(money));
	actualDomeHealthText.setText(boost::lexical_cast<string>(dome.getCurrentHealth()/HEALTH_DIVISION_FACTOR));

  	SDL_ShowCursor(1);
	SDL_FillRect (screen, &screen->clip_rect,
			SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));

	
	continueToGame.show(screen);
	gunsMessage.show(screen);
	priceHeader.show(screen);
	storeHeader.show(screen);
	moneyText.show(screen);
	actualMoneyText.show(screen);
	pistolPriceText.show(screen);
	plasmaCannonPriceText.show(screen);
	gatlingPriceText.show(screen);
	smgPriceText.show(screen);
	lmgPriceText.show(screen);
	pistolAmmoPriceText.show(screen);
	plasmaCannonAmmoPriceText.show(screen);
	gatlingAmmoPriceText.show(screen);
	smgAmmoPriceText.show(screen);
	lmgAmmoPriceText.show(screen);
	voltorbPriceText.show(screen);
	specialsText.show(screen);
	healthPriceText.show(screen);
	domeText.show(screen);
	actualDomeHealthText.show(screen);
	//store screen

	for(int j=0;j<store.size();j++)
	{	
		store[j]->showInStore(screen); //x, y, surface
	}

	SDL_Flip(screen);

     Text messageToUser("",continueToGame.getTextXpos()+continueToGame.getWidth()+50,continueToGame.getTextYpos(),colorWhite,20);
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
						store[j]->showInStore(screen); //x, y, surface
					}/*
					for(int j=0;j<storeBombs.size();j++)
					{	
						storeBombs[j]->showInStore(screen); //x, y, surface
					}*/
				continueButton = purchaseFromStore(x,y,dome,continueToGame,messageToUser,actualMoneyText,actualDomeHealthText);
				if(continueButton&&weapons.size()==0)
				{
					continueButton = false;
					messageToUser.setText("You Need at least 1 weapon!");
				}
				
					continueToGame.show(screen);
					gunsMessage.show(screen);
					priceHeader.show(screen);
					storeHeader.show(screen);
					messageToUser.show(screen);
					moneyText.show(screen);
					actualMoneyText.show(screen);
					pistolPriceText.show(screen);
					plasmaCannonPriceText.show(screen);
					gatlingPriceText.show(screen);
					smgPriceText.show(screen);
					lmgPriceText.show(screen);
					pistolAmmoPriceText.show(screen);
					plasmaCannonAmmoPriceText.show(screen);
					gatlingAmmoPriceText.show(screen);
					smgAmmoPriceText.show(screen);
					lmgAmmoPriceText.show(screen);
					voltorbPriceText.show(screen);
					specialsText.show(screen);
					healthPriceText.show(screen);
					domeText.show(screen);
					actualDomeHealthText.show(screen);
					SDL_Flip(screen);

				
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
int main (int argc, char *args[])
{
srand(time(NULL));
//user's score for the game,
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

music = Mix_LoadMUS( "Pokemon Theme Song Instrumental.wav" );
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
	Text instructions("Instructions",playButton.getTextXpos(),playButton.getTextYpos()+50,colorBlack,30);
	instructions.show(screen);
	Text backButton("Back",SCREEN_WIDTH/2,SCREEN_HEIGHT-50,colorWhite,30);
  SDL_Flip(screen);
  bool play = false;
  bool goBack = false;
	//while they have not hit the play button
	int c = 0;
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
					if(instructions.isClicked(x,y))
					{
						goToInstructions(backButton);
						background.show(screen);
						pokeDome.show(screen);
						playButton.show(screen);
						instructions.show(screen);
						SDL_Flip(screen);
						
					}
			
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

     Dome dome ("dome.png", DOME_BASE_X_BEG, SCREEN_HEIGHT-DOME_HEIGHT, DOME_BASE_W, DOME_HEIGHT, STARTING_HEALTH, STARTING_HEALTH);
  load_store();
  Text continueToGame ("Continue to Game", 2 * SCREEN_WIDTH / 5, 8 * SCREEN_HEIGHT / 9, colorWhite, BIGGER_HEADER_TEXT_SIZE);
   Text gunsMessage("Guns",GUNS_TEXT_X,GUNS_TEXT_Y,colorWhite,HEADER_TEXT_SIZE);
	Text priceHeader("Price ($)",gunsMessage.getTextXpos()+gunsMessage.getWidth()+30,10,colorWhite,HEADER_TEXT_SIZE);
	Text storeHeader("Select your items", 2*SCREEN_WIDTH/5, 0,colorWhite,STORE_HEADER_TEXT_SIZE);
	Text pistolPriceText(boost::lexical_cast<string>( PISTOL_PRICE ),PISTOL_X+pistol->getWidth()+20,PISTOL_Y,colorWhite,PRICE_TEXT_SIZE);
	Text plasmaCannonPriceText(boost::lexical_cast<string>( PLASMA_CANNON_PRICE ),PLASMA_CANNON_X+plasmaCannon->getWidth()+20,PLASMA_CANNON_Y,colorWhite,PRICE_TEXT_SIZE);
	Text gatlingPriceText(boost::lexical_cast<string>( GATLING_PRICE ),GATLING_X+gatling->getWidth()+20,GATLING_Y,colorWhite,PRICE_TEXT_SIZE);
	Text smgPriceText(boost::lexical_cast<string>( SMG_PRICE ),SMG_X+smg->getWidth()+20,SMG_Y,colorWhite,PRICE_TEXT_SIZE);
	Text lmgPriceText(boost::lexical_cast<string>( LMG_PRICE ),LMG_X+lmg->getWidth()+20,LMG_Y,colorWhite,PRICE_TEXT_SIZE);
	Text voltorbPriceText(boost::lexical_cast<string>(VOLTORB_PRICE),VOLTORB_X+voltorb->getWidth()+20,VOLTORB_Y,colorWhite,PRICE_TEXT_SIZE);
	Text specialsText("Specials", OTHER_TEXT_X, OTHER_TEXT_Y, colorWhite, HEADER_TEXT_SIZE);
	Text healthPriceText(boost::lexical_cast<string>(HEALTH_PRICE), HEALTH_X + health->getWidth() + 20, HEALTH_Y, colorWhite, PRICE_TEXT_SIZE);
	Text moneyText("Money: $ ",MONEY_TEXT_X,MONEY_TEXT_Y,colorWhite,BIGGER_HEADER_TEXT_SIZE);
	Text actualMoneyText(boost::lexical_cast<string>(money),moneyText.getTextXpos()+moneyText.getWidth(),MONEY_TEXT_Y,colorWhite,BIGGER_HEADER_TEXT_SIZE);
	Text domeText("Dome Health:",DOME_HEALTH_TEXT_X,DOME_HEALTH_TEXT_Y,colorWhite,BIGGER_HEADER_TEXT_SIZE);
	Text actualDomeHealthText(boost::lexical_cast<string>(dome.getCurrentHealth()/HEALTH_DIVISION_FACTOR),domeText.getTextXpos()+domeText.getWidth()+10,DOME_HEALTH_TEXT_Y,colorWhite,BIGGER_HEADER_TEXT_SIZE);

Text pistolAmmoPriceText(boost::lexical_cast<string>( PISTOL_AMMO_PRICE ),PISTOL_AMMO_X+pistolAmmo->getWidth()+20,PISTOL_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);
	Text plasmaCannonAmmoPriceText(boost::lexical_cast<string>( PLASMA_CANNON_AMMO_PRICE ),PLASMA_CANNON_AMMO_X+plasmaCannonAmmo->getWidth()+20,PLASMA_CANNON_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);
	Text gatlingAmmoPriceText(boost::lexical_cast<string>( GATLING_AMMO_PRICE ),GATLING_AMMO_X+gatlingAmmo->getWidth()+20,GATLING_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);
	Text smgAmmoPriceText(boost::lexical_cast<string>( SMG_AMMO_PRICE ),SMG_AMMO_X+smgAmmo->getWidth()+20,SMG_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);
	Text lmgAmmoPriceText(boost::lexical_cast<string>( LMG_AMMO_PRICE ),LMG_AMMO_X+lmgAmmo->getWidth()+20,LMG_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);

bool gameIsOver= false;








//class that replaces mouse with the crosshairs
 Crosshairs crosshairs;


//while they have not beat the game or have not died 
while(gameIsOver==false)
{

  /*ITEM SELECTION*/
   int continued = goToStore(dome,continueToGame,gunsMessage,priceHeader,storeHeader,moneyText,actualMoneyText,pistolPriceText,plasmaCannonPriceText,gatlingPriceText,smgPriceText,
lmgPriceText,voltorbPriceText, specialsText, healthPriceText,domeText,actualDomeHealthText,pistolAmmoPriceText,plasmaCannonAmmoPriceText,gatlingAmmoPriceText,smgAmmoPriceText,
lmgAmmoPriceText);
	//continue will be 0 if they hit the X on the window while at the store
   if(!continued)
	{
		clean_up();
		return 0;
	}
Text reload("RELOAD!" ,400,300,colorRed, 100);
Text scoretext("Score: ",20,10,colorWhite,30);
Text actualscoretext( boost::lexical_cast<string>( score ),110,10,colorWhite,30);
Text weaponname("Weapon: " ,350,20,colorWhite,30);
Text cliptext("Clip: ", 750,10,colorWhite,30);
Text cliptotal(boost::lexical_cast<string>( weapons[0]->getCurrentClipAmmo() ),850,10,colorWhite,30);
Text totaltext("Total: ", 750,40,colorWhite,30);
Text total(boost::lexical_cast<string>( weapons[0]->getCurrentAmmo() ),850,40,colorWhite,30);
Text domename ("Dome Health: ",1000,10,colorWhite,20);
Text domehealth(boost::lexical_cast<string>(dome.getCurrentHealth()),1050,30,colorWhite,30);
Text leveltext("Level: ",20,40,colorWhite,30); 
Text levelnumber(boost::lexical_cast<string>(currentLevel),110,40,colorWhite,30);
/* START GAMEPLAY */

  /*LOAD  ENEMIES*/
  load_enemies (); //loads enemies for current level
  quit = false;

int dropbomb=0;

  //While the user hasn't quit
  while (quit == false)
    {


   //Start the frame timer
      fps.start ();
      //show the background and dome
	//divide health by 100 so it is easier for the user to read
	domehealth.setText(boost::lexical_cast<string>(dome.getCurrentHealth()/HEALTH_DIVISION_FACTOR));

cliptotal.setText(boost::lexical_cast<string>( weapons[currentWeaponIndex]->getCurrentClipAmmo()));
actualscoretext.setText(boost::lexical_cast<string>(score));
total.setText(boost::lexical_cast<string>( weapons[currentWeaponIndex]->getCurrentAmmo()) );

	
      background.show (screen);
	statsborder.show(screen);

      dome.show (screen);
	cliptext.show(screen);
	scoretext.show(screen);
	actualscoretext.show(screen);
	weaponname.show(screen);
	domename.show(screen);
	domehealth.show(screen);
	total.show(screen);
	cliptotal.show(screen);
	totaltext.show(screen);
	leveltext.show(screen);
	levelnumber.show(screen);

weapons[currentWeaponIndex]->showDuringGamePlay(500,20,screen);
if(weapons[currentWeaponIndex]->getCurrentClipAmmo()==0 && count%6>2) //so that the reload flashes
reload.show(screen);

if (dropbomb){
	voltorb->show(screen,enemies,score,money);
	if (voltorb->move())
	dropbomb=0;
}
//move the enemies
      for (int i = 0; i < enemies.size (); i++)
	{
	  enemies[i]->move ();
	  if (enemies[i]->isDead ())
	    continue;
	//if the enemy is colliding with the dome then attack the dome with the enemy's power
	  if (dome.isCollidingWithEnemy(enemies[i]->getX (), enemies[i]->getY (),enemies[i]->getWidth (), enemies[i]->getHeight (),enemies[i]->getXVel()))
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
			if(event.key.keysym.sym == SDLK_SPACE){
			dropbomb++;
			int xmouse, ymouse;
			SDL_GetMouseState(&xmouse, &ymouse);
			voltorb->setPos(xmouse, ymouse);
			}

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
		
	      weapons[currentWeaponIndex]->handle_events (event, enemies, screen,score,money);
	      
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
		//ignores mouse clicks after all enemies have been destroyed to avoid automatically going to the next level
		SDL_EventState(SDL_MOUSEBUTTONDOWN,SDL_IGNORE);
	 	score+=LEVEL_BONUS;
		money+=LEVEL_BONUS;
	  	SDL_FillRect (screen, &screen->clip_rect,SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));
	  	Text levelSuccess ("Level Complete", 2 * SCREEN_WIDTH / 5, 2 * SCREEN_HEIGHT / 5, colorWhite, 40);
	  	levelSuccess.show (screen);
	  	SDL_Flip (screen);
	  	SDL_Delay (DELAY_BETWEEN_LEVELS);
	  	//after the delay enable mouse clicking
	  	SDL_EventState(SDL_MOUSEBUTTONDOWN,SDL_ENABLE);
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
