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
#include "Rsquirtle.h"
#include "Poliwhirl.h"
#include "Rpoliwhirl.h"
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
#include "Moltres.h"
#include "Rmoltres.h"
#include "Rzapdos.h"
#include "Pikachu.h"
#include "Rpikachu.h"
#include "Item.h"
#include "Health.h"
#include "Ammo.h"
#include <boost/lexical_cast.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>

using namespace std;

//The screen surface
SDL_Surface *screen = NULL;
SDL_Surface *cursor=NULL;

//different colors of text in the game
SDL_Color colorWhite = { 255, 255, 255 };
SDL_Color colorBlack = {0,0,0};
SDL_Color colorRed = {220,20,20};

//The event structure, handles mouse clicks and key presses etc
SDL_Event event;

//the different enemies the game can have
vector < Enemy * >enemies; //vector to store the enemies in a given level
Squirtle *squirtle;
Rsquirtle *rsquirtle;
Rpoliwhirl *rpoliwhirl;
Poliwhirl *poliwhirl;
Rpidgey *rpidgey;
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
Voltorb *storeVoltorb;
Electrode *storeElectrode;
Voltorb *voltorb;
Electrode *electrode;
Rmoltres *rmoltres;
Moltres *moltres;
Pikachu *pikachu;
Rpikachu *rpikachu;

//vector that stores the user's current weapons
vector < Weapon * >weapons;
//vector that stores the users voltorbs and electrodes
vector < Voltorb * > voltorbs;
vector < Electrode * > electrodes;

//vector that stores everything that can be bought in the store
vector < Item * >store;



//all the possible weapons
Pistol *pistol;
PlasmaCannon* plasmaCannon;
Gatling* gatling;
Smg* smg;
Lmg* lmg;
//the possible ammos
Ammo *pistolAmmo;
Ammo *smgAmmo;
Ammo *lmgAmmo;
Ammo *gatlingAmmo;
Ammo *plasmaCannonAmmo;

//health declared
Health* health;

//Music
Mix_Music *music;

//vector of teh differnet names of the backgrounds so that it progresses through day/ngiht over time
vector<string> backgrounds;
int currentBackground = 1; //start at 1, not 0 eventhough 0 is first b/c first time switch, first set background to current, then add 1

//will be true when they buy the gun. so that they don't buy multiple
bool addedPistol=false,addedSmg=false,addedLmg=false,addedGatling=false,addedPlasma=false;
int pistolIndex,smgIndex,lmgIndex,gatlingIndex,plasmaIndex; //variables of what index in weapons vector that gun is for the user.
int weaponsBought = 0;
//user can only use one weapon at a time
int currentWeaponIndex = 0;
int currentVoltorbIndex = 0;
int currentElectrodeIndex = 0;
//the current level and the maximum # of levels programmed by us
int currentLevel = 1;
int score=0;
//int maxLevel = 10;
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

//Takes in a random number from load enemies, this number will determine which pokemon is spawned. will add that pokemon to enemies vector
void addpokemon(int key){
	switch (key){
	case 1:
		squirtle =new Squirtle ("squirtlej.png", rand()%1500+900, 0, SQUIRTLE_HEIGHT, SQUIRTLE_WIDTH, -(rand()%5+5),Y_VELOCITY_DESCENT, SQUIRTLE_POWER, SQUIRTLE_HEALTH);
		enemies.push_back (squirtle);
	break;
	case 2:
		charmander =new Charmander ("charmander.png", rand()%1500+900, 0, CHARMANDER_HEIGHT,CHARMANDER_WIDTH, -(rand()%5+5), Y_VELOCITY_DESCENT, CHARMANDER_POWER, CHARMANDER_HEALTH);
		enemies.push_back (charmander);
	break;
	case 3:
		rcharmander =new Rcharmander ("Rcharmander.png", 300-(rand()%1800), 0, CHARMANDER_HEIGHT, CHARMANDER_WIDTH, (rand()%5+5), Y_VELOCITY_DESCENT, CHARMANDER_POWER, CHARMANDER_HEALTH);
		enemies.push_back (rcharmander);
	break;
	

	case 4: rpikachu = new Rpikachu("Rpikachu.png",300-(rand()%1800),0, PIKACHU_HEIGHT, PIKACHU_WIDTH, (rand()%5+5), Y_VELOCITY_DESCENT, PIKACHU_POWER, PIKACHU_HEALTH);
		enemies.push_back (rpikachu);
		break;
	case 5:	pikachu = new Pikachu("pikachu.png",rand()%1500+900,0, PIKACHU_HEIGHT, PIKACHU_WIDTH, -(rand()%5+5), Y_VELOCITY_DESCENT, PIKACHU_POWER, PIKACHU_HEALTH);
		enemies.push_back (pikachu);
	break;
	case 6:
		pidgey =new Pidgey ("pidgey.png", rand()%600+900, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, PIDGEY_HEIGHT, PIDGEY_WIDTH, -(rand()%5+5), 0,PIDGEY_POWER, PIDGEY_HEALTH);
		enemies.push_back (pidgey);
	break;
	case 7:
		rpidgey =new Rpidgey ("Rpidgey.png", 300-(rand()%1800), rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, PIDGEY_HEIGHT, PIDGEY_WIDTH, (rand()%5+5), 0, PIDGEY_POWER, PIDGEY_HEALTH);
		enemies.push_back (rpidgey);
	break;
	case 8:
		poliwhirl =new Poliwhirl ("poliwhirl.png", rand()%1500+900, 0, POLIWHIRL_HEIGHT, POLIWHIRL_WIDTH,-(rand()%8+5), Y_VELOCITY_DESCENT, POLIWHIRL_POWER, POLIWHIRL_HEALTH);
		enemies.push_back (poliwhirl);
	break;
	case 9:
		machamp =new Machamp ("machamp.png", rand()%1500+900, 0, MACHAMP_HEIGHT, MACHAMP_WIDTH, -(rand()%8+5), Y_VELOCITY_DESCENT,MACHAMP_POWER, MACHAMP_HEALTH);
		enemies.push_back(machamp);
	break;
	case 10:
	rmachamp =new Rmachamp ("Rmachamp.png", 300-rand()%2400, 0, MACHAMP_HEIGHT, MACHAMP_WIDTH, (rand()%8+5), Y_VELOCITY_DESCENT,MACHAMP_POWER, MACHAMP_HEALTH);
		enemies.push_back(rmachamp);
	break;
	case 11:
		marowak =new Marowak ("marowak.png", rand()%1500+900, 0, MAROWAK_HEIGHT, MAROWAK_WIDTH, -(rand()%8+5), Y_VELOCITY_DESCENT,MAROWAK_POWER, MAROWAK_HEALTH);
		enemies.push_back(marowak);
	break;
	case 12:
	rmarowak =new Rmarowak ("Rmarowak.png", 300-(rand()%2400), 0, MAROWAK_HEIGHT, MAROWAK_WIDTH, (rand()%8+5), Y_VELOCITY_DESCENT,MAROWAK_POWER, MAROWAK_HEALTH);
		enemies.push_back(rmarowak);
	break;
	case 13:
		rzapdos = new Rzapdos ("Rzapdos.png", 300-(rand()%2400), rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ZAPDOS_HEIGHT, ZAPDOS_WIDTH, (rand()%12+5), 0,ZAPDOS_POWER, ZAPDOS_HEALTH);
		enemies.push_back (rzapdos);
	break;
	case 14:
		zapdos =new Zapdos ("zapdos.png", rand()%1500+900, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ZAPDOS_HEIGHT, ZAPDOS_WIDTH, -(rand()%12+5), 0,ZAPDOS_POWER, ZAPDOS_HEALTH);
		enemies.push_back (zapdos);
	break;
	case 15:
		rarticuno =new Rarticuno ("Rarticuno.png",300-(rand()%2400), rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ARTICUNO_HEIGHT, ARTICUNO_WIDTH, (rand()%12+5),0, ARTICUNO_POWER, ARTICUNO_HEALTH);
		enemies.push_back (rarticuno);
	break;
	case 16:
articuno =new Articuno ("articuno.png", rand()%1500+900, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ARTICUNO_HEIGHT, ARTICUNO_WIDTH,-(rand()%12+5), 0, ARTICUNO_POWER, ARTICUNO_HEALTH);
		enemies.push_back (articuno);
	break;
	case 17:
	rmoltres =new Rmoltres ("Rmoltres.png",300-(rand()%2400), rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ARTICUNO_HEIGHT, ARTICUNO_WIDTH, (rand()%12+5),0, ARTICUNO_POWER, ARTICUNO_HEALTH);
		enemies.push_back (rmoltres);
	break;
	case 18: moltres =new Moltres ("moltres.png",rand()%1500+900, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ARTICUNO_HEIGHT, ARTICUNO_WIDTH, -(rand()%12+5),0, ARTICUNO_POWER, ARTICUNO_HEALTH);
		enemies.push_back (moltres);

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
int numberOfEnemies=rand()%4+1.5*currentLevel;
//adds correct number of enemies
for(int i=0; i<numberOfEnemies;i++)
{

//pokemon key determines what species of pokemon will be created. each time through the for loop, a different one is made. the while loop ensures that a key that we have is to be used
pokemonkey=rand()%(3+currentLevel)+1;

while(pokemonkey>18){
pokemonkey=rand()%(3+currentLevel)+1;
}

//pushes back the proper enemy
addpokemon(pokemonkey);
}


}




//loads all the items to the store
void load_store()
{    



    plasmaCannon = new PlasmaCannon("weapons.png", "explosionplasma.PNG","Plasma Cannon",PLASMA_CANNON_PRICE,PLASMA_CANNON_AMMO_PRICE,PLASMA_CANNON_DAMAGE,5,PLASMA_CANNON_X,PLASMA_CANNON_Y,PLASMA_CANNON_EXP_SIZE,PLASMA_CANNON_MAX_AMMO,PLASMA_CANNON_MAX_AMMO,PLASMA_CANNON_MAX_CLIP_AMMO,PLASMA_CANNON_MAX_CLIP_AMMO);
    store.push_back(plasmaCannon);
    pistol = new Pistol("weapons.png", "explosionpistol.png","Pistol", PISTOL_PRICE,PISTOL_AMMO_PRICE,PISTOL_DAMAGE,5,PISTOL_X,PISTOL_Y,PISTOL_EXP_SIZE,PISTOL_MAX_AMMO,PISTOL_MAX_AMMO,PISTOL_MAX_CLIP_AMMO,PISTOL_MAX_CLIP_AMMO);
    store.push_back(pistol);
    gatling = new Gatling("weapons.png", "explosiongatling.png", "Gatling", GATLING_PRICE,GATLING_AMMO_PRICE,GATLING_DAMAGE,5,GATLING_X,GATLING_Y,GATLING_EXP_SIZE,GATLING_MAX_AMMO,GATLING_MAX_AMMO,GATLING_MAX_CLIP_AMMO,GATLING_MAX_CLIP_AMMO);
    store.push_back(gatling);
    smg = new Smg("weapons.png", "explosionsmg.PNG","SMG",SMG_PRICE,SMG_AMMO_PRICE,SMG_DAMAGE,5,SMG_X,SMG_Y,SMG_EXP_SIZE,SMG_MAX_AMMO,SMG_MAX_AMMO,SMG_MAX_CLIP_AMMO,SMG_MAX_CLIP_AMMO);
    store.push_back(smg);
    lmg = new Lmg("weapons.png", "explosionlmg.PNG","LMG",LMG_PRICE,LMG_AMMO_PRICE,LMG_DAMAGE,5,LMG_X,LMG_Y,LMG_EXP_SIZE,LMG_MAX_AMMO,LMG_MAX_AMMO,LMG_MAX_CLIP_AMMO,LMG_MAX_CLIP_AMMO);
    store.push_back(lmg);

    storeVoltorb = new Voltorb ("bombs.png", VOLTORB_PRICE, VOLTORB_DAMAGE, VOLTORB_X, VOLTORB_Y);
    store.push_back(storeVoltorb);

    storeElectrode = new Electrode("bombs.png",ELECTRODE_PRICE,ELECTRODE_DAMAGE,ELECTRODE_X,ELECTRODE_Y);
    store.push_back(storeElectrode);

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

//shows instructions on screen. returns 1 if user has exited out window, 0 otherwise
int goToInstructions(Text &backButton)
{
	int spacing = 25;
	 SDL_FillRect (screen, &screen->clip_rect,
	SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));
	backButton.show(screen);
	Text actualInstructions("Instructions",SCREEN_WIDTH/2-100,0,colorWhite,30);
	actualInstructions.show(screen);
	actualInstructions.setSize(20);
	actualInstructions.setX(350);

	actualInstructions.setText("Goal: Protect the Golden Dome by shooting the Pokemon");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight()+spacing);
	actualInstructions.show(screen);
	
	actualInstructions.setText("Before each level, you can go to the store to buy items");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight()+spacing);
	actualInstructions.show(screen);

	actualInstructions.setText("You can buy guns,ammo,health,and bombs at the store");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight()+spacing);
	actualInstructions.show(screen);

	actualInstructions.setText("To switch amongst your guns, either use the arrow keys or press 1-5");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight()+spacing);
	actualInstructions.show(screen);

	actualInstructions.setText("1 = Pistol, 2 = SMG, 3 = LMG, 4 = Gatling, 5 = Plasma Cannon");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight()+spacing);
	actualInstructions.show(screen);

	actualInstructions.setText("To reload when your clip is empty, shake the mouse quickly");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight()+spacing);
	actualInstructions.show(screen);

	actualInstructions.setText("To drop a voltorb, hit the 'v' key");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight()+spacing);
	actualInstructions.show(screen);

	actualInstructions.setText("To drop an electrode, hit the spacebar");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight()+spacing);
	actualInstructions.show(screen);

	actualInstructions.setText("Once the Dome's Health is 0, you lose");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight()+spacing);
	actualInstructions.show(screen);

	
	actualInstructions.setText("Use the terminal to load or save a level after clicking load or save in game");
	actualInstructions.setY(actualInstructions.getTextYpos()+actualInstructions.getHeight()+spacing);
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
			if(event.type==SDL_QUIT)
			{
				return 1;
			}
		}
	}
	return 0;
}


//takes user's click when on the store screen and updates their inventory
bool purchaseFromStore(int x, int y, Dome &dome,Text &continueToGame, Text&messageToUser,Text &actualMoneyText, Text &actualDomeHealthText,Background &cover,Text&currentAmmoText,Text&maxAmmoText,Text&currentAmmo,Text&maxAmmo, Text &currentVoltorbsText,Text&currentVoltorbsNumber,Text &currentElectrodesText,Text&currentElectrodesNumber, Text&saveText, bool &quit, bool &gameIsOver)
{


	cover.show(screen);
	if(continueToGame.isClicked(x,y)) {
		return true;
	}
	
	if(saveText.isClicked(x,y)){
		quit=true;
		gameIsOver=true;

		string	name;	
		cout<<"Enter Name of Savefile"<<endl;	
		cin>>name;
		ofstream myfile;

		myfile.open(name.c_str());

		myfile<</*"Score:"<<*/score<<endl;
		myfile<</*"CurrentLevel:"<<*/currentLevel<<endl;
		myfile<</*"Money:"<<*/money<<endl;


		if(addedPistol)
		{
		myfile<<"1"<<endl;
		myfile<</*"PistolAmmo:"<<*/weapons[pistolIndex]->getCurrentAmmo()<<endl;
		myfile<</*"PistolClipAmmo:"<<*/weapons[pistolIndex]->getCurrentClipAmmo()<<endl;
		}		

		else{
		myfile<<"0"<<endl;
		myfile<<"0"<<endl;
		myfile<<"0"<<endl;
		}
		

		if(addedSmg){
		myfile<<"1"<<endl;
			myfile<</*"SmgAmmo:"<<*/weapons[smgIndex]->getCurrentAmmo()<<endl;
		myfile<</*"SmgClipAmmo:"<<*/weapons[smgIndex]->getCurrentClipAmmo()<<endl;
		}		
		else{
		myfile<<"0"<<endl;
		myfile<<"0"<<endl;
		myfile<<"0"<<endl;
		}
	
		if(addedLmg){
		myfile<<"1"<<endl;
		myfile<</*"LmgAmmo:"<<*/weapons[lmgIndex]->getCurrentAmmo()<<endl;
		myfile<</*"LmgClipAmmo:"<<*/weapons[lmgIndex]->getCurrentClipAmmo()<<endl;
		}
		else{
		myfile<<"0"<<endl;
		myfile<<"0"<<endl;
		myfile<<"0"<<endl;
		}
		if(addedGatling){
		myfile<<"1"<<endl;
			myfile<</*"GatlingAmmo:"<<*/weapons[gatlingIndex]->getCurrentAmmo()<<endl;
		myfile<</*"GatlingClipAmmo:"<<*/weapons[gatlingIndex]->getCurrentClipAmmo()<<endl;
		}
		else{
		myfile<<"0"<<endl;
		myfile<<"0"<<endl;
		myfile<<"0"<<endl;
		}
		if(addedPlasma){
		myfile<<"1"<<endl;
		myfile<</*"PlasmaCannonAmmo:"<<*/weapons[plasmaIndex]->getCurrentAmmo()<<endl;
		myfile<</*"PlasmaCannonClipAmmo:"<<*/weapons[plasmaIndex]->getCurrentClipAmmo()<<endl;		
		}
		else{
		myfile<<"0"<<endl;
		myfile<<"0"<<endl;
		myfile<<"0"<<endl;
		}

		myfile<</*"Voltorbs:"<<*/voltorbs.size()<<endl;
		myfile<</*"Electrodes:"<<*/electrodes.size()<<endl;


		myfile<</*"Health:"<<*/dome.getCurrentHealth()<<endl<<endl;
		
		myfile.close();
		cout<<"Succesfully saved to " << name<<endl;
		return false;
	}


	
	if(storeVoltorb->isClicked(x,y))
	{
		currentVoltorbsText.show(screen);
		if(money>=storeVoltorb->getPrice())
		{
			money-=storeVoltorb->getPrice();
			actualMoneyText.setText(boost::lexical_cast<string>(money));
			messageToUser.setText("Succesfully Added Voltorb");
    			voltorb = new Voltorb ("bombs.png", VOLTORB_PRICE, VOLTORB_DAMAGE, VOLTORB_X, VOLTORB_Y);
			voltorbs.push_back(voltorb);
			currentVoltorbsNumber.setText(boost::lexical_cast<string>(voltorbs.size()));
		}
		else
			messageToUser.setText("Not enough Money!");
		currentVoltorbsNumber.show(screen);
	}
	
	if(storeElectrode->isClicked(x,y))
	{
		currentElectrodesText.show(screen);
		if(money>=storeElectrode->getPrice())
		{
			money-=storeElectrode->getPrice();
			actualMoneyText.setText(boost::lexical_cast<string>(money));
			messageToUser.setText("Succesfully Added Electrode");
    			electrode = new Electrode("bombs.png",ELECTRODE_PRICE,ELECTRODE_DAMAGE,ELECTRODE_X,ELECTRODE_Y);
			electrodes.push_back(electrode);
			currentElectrodesNumber.setText(boost::lexical_cast<string>(electrodes.size()));

		}
		else
			messageToUser.setText("Not enough Money!");

			currentElectrodesNumber.show(screen);
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
				pistolIndex = weaponsBought;
				weaponsBought++;
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
				gatlingIndex = weaponsBought;
				weaponsBought++;
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
				lmgIndex = weaponsBought;
				weaponsBought++;
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
				smgIndex = weaponsBought;
				weaponsBought++;
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
				plasmaIndex = weaponsBought;
				weaponsBought++;
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
		currentAmmoText.show(screen);
		maxAmmoText.show(screen);
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
					currentAmmo.setText(boost::lexical_cast<string>(pistol->getCurrentAmmo()+pistol->getCurrentClipAmmo()));
					currentAmmo.show(screen);
					maxAmmo.show(screen);
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
		currentAmmoText.show(screen);
		maxAmmoText.show(screen);
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
					currentAmmo.setText(boost::lexical_cast<string>(smg->getCurrentAmmo()+smg->getCurrentClipAmmo()));
					currentAmmo.show(screen);
					maxAmmo.show(screen);
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
		currentAmmoText.show(screen);
		maxAmmoText.show(screen);
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
					currentAmmo.setText(boost::lexical_cast<string>(lmg->getCurrentAmmo()+lmg->getCurrentClipAmmo()));
					currentAmmo.show(screen);
					maxAmmo.show(screen);
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
		currentAmmoText.show(screen);
		maxAmmoText.show(screen);
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
					currentAmmo.setText(boost::lexical_cast<string>(gatling->getCurrentAmmo()+gatling->getCurrentClipAmmo()));
					currentAmmo.show(screen);
					maxAmmo.show(screen);
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

		currentAmmoText.show(screen);
		maxAmmoText.show(screen);
		if(addedPlasma)
		{
			
			if(money>=plasmaCannonAmmo->getPrice())
			{
				bool addedAmmo = plasmaCannon->addToCurrentAmmo(PLASMA_CANNON_AMMO_PER_PURCHASE);
				if (addedAmmo)
				{
					money-=plasmaCannonAmmo->getPrice();

					actualMoneyText.setText(boost::lexical_cast<string>(money));
					messageToUser.setText("Succesfully Added Plasma Cannon Ammo");
					currentAmmo.setText(boost::lexical_cast<string>(plasmaCannon->getCurrentAmmo()+plasmaCannon->getCurrentClipAmmo()));
					currentAmmo.show(screen);
					maxAmmo.show(screen);
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

//erases the unused voltorbs and electrodes from the vector so taht the vector doesn't get huge over the course of game
void clear_unused_bombs()
{

	if(voltorbs.size()>0)
	{
	voltorbs.erase(voltorbs.begin(),voltorbs.begin()+currentVoltorbIndex);
	currentVoltorbIndex = 0;
	}
	if(electrodes.size()>0)
	{
	electrodes.erase(electrodes.begin(),electrodes.begin()+currentElectrodeIndex);
	currentElectrodeIndex = 0;
	}
}



//goes to the store screen and displays it
int goToStore(Dome &dome,Text &continueToGame, Text &gunsMessage, Text &priceHeader, Text &ammoHeader,Text &storeHeader, Text &moneyText, Text &actualMoneyText,Text &pistolPriceText,Text &plasmaCannonPriceText,Text &gatlingPriceText,Text &smgPriceText,Text &lmgPriceText, Text &voltorbPriceText, Text &electrodePriceText, Text &specialsText, Text &healthPriceText, Text &domeText, Text&actualDomeHealthText,Text &pistolAmmoPriceText,Text &plasmaCannonAmmoPriceText,Text &gatlingAmmoPriceText,Text &smgAmmoPriceText,Text &currentWeaponAmmoText, Text &currentWeaponMaxAmmoText,Text &lmgAmmoPriceText,Text &pistolText,Text &plasmaCannonText,Text &gatlingText, Text &smgText,Text &lmgText,Text &currentAmmoText,Text&maxAmmoText,
Text &currentVoltorbsText,Text &currentVoltorbsNumber, Text &currentElectrodesText,Text &currentElectrodesNumber, Text &saveText,bool &quit, bool &gameIsOver)
{  
	//deletes from the bombs vector so that they don't get huge throughout the game
	clear_unused_bombs();


//covers up the ammo if the mouse is not over anything
Background cover("Coverup.png");
	//set money text and dome health since money and health could change each time you come to the store
	actualMoneyText.setText(boost::lexical_cast<string>(money));
	actualDomeHealthText.setText(boost::lexical_cast<string>(dome.getCurrentHealth()/HEALTH_DIVISION_FACTOR));

  	SDL_ShowCursor(1);
	SDL_FillRect (screen, &screen->clip_rect,
			SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));

	//show all text and buttons
	continueToGame.show(screen);
	gunsMessage.show(screen);
	priceHeader.show(screen);
	ammoHeader.show(screen);
	storeHeader.show(screen);
	moneyText.show(screen);
	pistolText.show(screen);
	plasmaCannonText.show(screen);
	gatlingText.show(screen);
	smgText.show(screen);
	lmgText.show(screen);

	saveText.show(screen);
	
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
	currentWeaponMaxAmmoText.show(screen);
	currentWeaponAmmoText.show(screen);
	lmgAmmoPriceText.show(screen);
	voltorbPriceText.show(screen);
	electrodePriceText.show(screen);
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
					}
				
				continueButton = purchaseFromStore(x,y,dome,continueToGame,messageToUser,actualMoneyText,actualDomeHealthText,cover,currentAmmoText,maxAmmoText,currentWeaponAmmoText,currentWeaponMaxAmmoText,
currentVoltorbsText,currentVoltorbsNumber,currentElectrodesText,currentElectrodesNumber,saveText, quit, gameIsOver);
				if(gameIsOver==true) return 1;
				if(continueButton&&weapons.size()==0)
				{
					continueButton = false;
					messageToUser.setText("You Need at least 1 gun!");
				}
					//show them all text and buttons again
					continueToGame.show(screen);
					gunsMessage.show(screen);
					priceHeader.show(screen);
					ammoHeader.show(screen);
					storeHeader.show(screen);
					messageToUser.show(screen);
					moneyText.show(screen);
					pistolText.show(screen);
					plasmaCannonText.show(screen);
					gatlingText.show(screen);
					smgText.show(screen);
					lmgText.show(screen);
					saveText.show(screen);
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
					currentWeaponMaxAmmoText.show(screen);
					currentWeaponAmmoText.show(screen);
					lmgAmmoPriceText.show(screen);
					voltorbPriceText.show(screen);
					electrodePriceText.show(screen);
					specialsText.show(screen);
					healthPriceText.show(screen);
					domeText.show(screen);
					actualDomeHealthText.show(screen);
					
					

				
			}
		}
		//if they motion over the ammo or bombs, show on the screen how much ammo/bombs they have
		if(event.type ==SDL_MOUSEMOTION){
			int x = event.button.x;
	  		int y = event.button.y;
			if(pistolAmmo->isClicked(x,y)||pistol->isClicked(x,y))
				{
					currentAmmoText.setText("Current Ammo");
					maxAmmoText.setText("Max Ammo");
					if(addedPistol)
					{      
					currentWeaponMaxAmmoText.setText(boost::lexical_cast<string>(weapons[pistolIndex]->getMaxAmmo() + weapons[pistolIndex]->getMaxClipAmmo()));
					currentWeaponAmmoText.setText(boost::lexical_cast<string>(weapons[pistolIndex]->getCurrentAmmo() + weapons[pistolIndex]->getCurrentClipAmmo()));					
					}
					else
					{
					currentWeaponMaxAmmoText.setText(boost::lexical_cast<string>(pistol->getMaxAmmo() + pistol->getMaxClipAmmo()));
					currentWeaponAmmoText.setText(boost::lexical_cast<string>(pistol->getCurrentAmmo() + pistol->getCurrentClipAmmo()));
					}
					currentAmmoText.show(screen);
					maxAmmoText.show(screen);
					currentWeaponMaxAmmoText.show(screen);
					currentWeaponAmmoText.show(screen);
				}
			else if(plasmaCannonAmmo->isClicked(x,y)||plasmaCannon->isClicked(x,y))
				{
					currentAmmoText.setText("Current Ammo");
					maxAmmoText.setText("Max Ammo"); 					
					if(addedPlasma)
					{      
					currentWeaponMaxAmmoText.setText(boost::lexical_cast<string>(weapons[plasmaIndex]->getMaxAmmo() + weapons[plasmaIndex]->getMaxClipAmmo()));
					currentWeaponAmmoText.setText(boost::lexical_cast<string>(weapons[plasmaIndex]->getCurrentAmmo() + weapons[plasmaIndex]->getCurrentClipAmmo()));					
					}
					else
					{
					currentWeaponMaxAmmoText.setText(boost::lexical_cast<string>(plasmaCannon->getMaxAmmo() + plasmaCannon->getMaxClipAmmo()));
					currentWeaponAmmoText.setText(boost::lexical_cast<string>(plasmaCannon->getCurrentAmmo() + plasmaCannon->getCurrentClipAmmo()));
					}
					currentAmmoText.show(screen);
					maxAmmoText.show(screen);
					currentWeaponMaxAmmoText.show(screen);
					currentWeaponAmmoText.show(screen);
				}
			else if(gatlingAmmo->isClicked(x,y)||gatling->isClicked(x,y))
				{
					currentAmmoText.setText("Current Ammo");
					maxAmmoText.setText("Max Ammo"); 					
					if(addedGatling)
					{      
					currentWeaponMaxAmmoText.setText(boost::lexical_cast<string>(weapons[gatlingIndex]->getMaxAmmo() + weapons[gatlingIndex]->getMaxClipAmmo()));
					currentWeaponAmmoText.setText(boost::lexical_cast<string>(weapons[gatlingIndex]->getCurrentAmmo() + weapons[gatlingIndex]->getCurrentClipAmmo()));					
					}
					else
					{
					currentWeaponMaxAmmoText.setText(boost::lexical_cast<string>(gatling->getMaxAmmo() + gatling->getMaxClipAmmo()));
					currentWeaponAmmoText.setText(boost::lexical_cast<string>(gatling->getCurrentAmmo() + gatling->getCurrentClipAmmo()));
					}
					currentAmmoText.show(screen);
					maxAmmoText.show(screen);
					currentWeaponMaxAmmoText.show(screen);
					currentWeaponAmmoText.show(screen);
				}
			else if(smgAmmo->isClicked(x,y)||smg->isClicked(x,y))
					{
					
					currentAmmoText.setText("Current Ammo");
					maxAmmoText.setText("Max Ammo"); 
					if(addedSmg)
					{      
					currentWeaponMaxAmmoText.setText(boost::lexical_cast<string>(weapons[smgIndex]->getMaxAmmo() + weapons[smgIndex]->getMaxClipAmmo()));
					currentWeaponAmmoText.setText(boost::lexical_cast<string>(weapons[smgIndex]->getCurrentAmmo() + weapons[smgIndex]->getCurrentClipAmmo()));					
					}
					else
					{
					currentWeaponMaxAmmoText.setText(boost::lexical_cast<string>(smg->getMaxAmmo() + smg->getMaxClipAmmo()));
					currentWeaponAmmoText.setText(boost::lexical_cast<string>(smg->getCurrentAmmo() + smg->getCurrentClipAmmo()));
					}
					currentAmmoText.show(screen);
					maxAmmoText.show(screen);
					currentWeaponMaxAmmoText.show(screen);
					currentWeaponAmmoText.show(screen);

					}
			else if(lmgAmmo->isClicked(x,y)||lmg->isClicked(x,y))
				{
					currentAmmoText.setText("Current Ammo");
					maxAmmoText.setText("Max Ammo"); 	
					if(addedLmg)
					{      
					currentWeaponMaxAmmoText.setText(boost::lexical_cast<string>(weapons[lmgIndex]->getMaxAmmo() + weapons[lmgIndex]->getMaxClipAmmo()));
					currentWeaponAmmoText.setText(boost::lexical_cast<string>(weapons[lmgIndex]->getCurrentAmmo() + weapons[lmgIndex]->getCurrentClipAmmo()));					
					}
					else
					{
					currentWeaponMaxAmmoText.setText(boost::lexical_cast<string>(lmg->getMaxAmmo() + lmg->getMaxClipAmmo()));
					currentWeaponAmmoText.setText(boost::lexical_cast<string>(lmg->getCurrentAmmo() + lmg->getCurrentClipAmmo()));
					}
					currentAmmoText.show(screen);
					maxAmmoText.show(screen);
					currentWeaponMaxAmmoText.show(screen);
					currentWeaponAmmoText.show(screen);
					
				}
			else if(storeVoltorb->isClicked(x,y))
			{
					currentVoltorbsText.setText("Current Voltorbs");
					currentVoltorbsNumber.setText(boost::lexical_cast<string>(voltorbs.size()));
					currentVoltorbsText.show(screen);
					currentVoltorbsNumber.show(screen);
			}
			else if(storeElectrode->isClicked(x,y))
			{
					currentElectrodesText.setText("Current Electrodes");
					currentElectrodesNumber.setText(boost::lexical_cast<string>(electrodes.size()));
					currentElectrodesText.show(screen);
					currentElectrodesNumber.show(screen);
			}
			else {
					currentWeaponMaxAmmoText.setText(" ");
					currentWeaponAmmoText.setText(" ");
					currentAmmoText.setText(" ");
					maxAmmoText.setText(" ");
					currentVoltorbsText.setText(" ");
					currentVoltorbsNumber.setText(" ");
					currentElectrodesText.setText(" ");
					currentElectrodesNumber.setText(" ");
					cover.show(screen);
				}

		}
			SDL_Flip(screen);

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


void load_previous_game(Dome &dome){
cout<<"Enter the name of the saved data file:\n";
string input;	
cin>>input;
ifstream infile;
infile.open(input.c_str());
while(!infile.good()){
cout<<"Not a valid game file, try again!"<<endl;
cin>>input;
infile.close();
infile.open(input.c_str());
}

cout<<"File load success. Go back to the game!"<<endl;




int pistoll;
int smgg;
int lmgg;
int gatlingg;
int plasmaa;
int pistolAmmo;
int pistolClipAmmo;
int smgAmmo;
int smgClipAmmo;
int lmgAmmo;
int lmgClipAmmo;
int gatlingAmmo;
int gatlingClipAmmo;
int plasmaCannonAmmo;
int plasmaCannonClipAmmo;
int numVoltorbs;
int numElectrodes;
int domeHealth;




infile>>score;
infile>>currentLevel;
infile>>money;




   


infile>>pistoll;
infile>>pistolAmmo; //
infile>>pistolClipAmmo; //
if(pistoll==1){
addedPistol=true;
pistol = new Pistol("weapons.png", "explosionpistol.png","Pistol", PISTOL_PRICE,PISTOL_AMMO_PRICE,PISTOL_DAMAGE,5,PISTOL_X,PISTOL_Y,PISTOL_EXP_SIZE,PISTOL_MAX_AMMO,PISTOL_MAX_AMMO,PISTOL_MAX_CLIP_AMMO,PISTOL_MAX_CLIP_AMMO);
weapons.push_back(pistol);
pistolIndex=weaponsBought;
weapons[weaponsBought]->setCurrentAmmo(pistolAmmo);
weapons[weaponsBought]->setCurrentClipAmmo(pistolClipAmmo);
weaponsBought++;
}

infile>>smgg;
infile>>smgAmmo;
infile>>smgClipAmmo;//
if(smgg==1){
addedSmg=true;

    smg = new Smg("weapons.png", "explosionsmg.PNG","SMG",SMG_PRICE,SMG_AMMO_PRICE,SMG_DAMAGE,5,SMG_X,SMG_Y,SMG_EXP_SIZE,SMG_MAX_AMMO,SMG_MAX_AMMO,SMG_MAX_CLIP_AMMO,SMG_MAX_CLIP_AMMO);

weapons.push_back(smg);
smgIndex=weaponsBought;
weapons[weaponsBought]->setCurrentAmmo(smgAmmo);
weapons[weaponsBought]->setCurrentClipAmmo(smgClipAmmo);
weaponsBought++;
}


infile>>lmgg;
infile>>lmgAmmo;
infile>>lmgClipAmmo;
if(lmgg==1){
addedLmg=true;
 lmg = new Lmg("weapons.png", "explosionlmg.PNG","LMG",LMG_PRICE,LMG_AMMO_PRICE,LMG_DAMAGE,5,LMG_X,LMG_Y,LMG_EXP_SIZE,LMG_MAX_AMMO,LMG_MAX_AMMO,LMG_MAX_CLIP_AMMO,LMG_MAX_CLIP_AMMO);


weapons.push_back(lmg);
lmgIndex=weaponsBought;
weapons[weaponsBought]->setCurrentAmmo(lmgAmmo);
weapons[weaponsBought]->setCurrentClipAmmo(lmgClipAmmo);
weaponsBought++;
}



infile>>gatlingg;
infile>>gatlingAmmo;
infile>>gatlingClipAmmo;//
if(gatlingg==1){
addedGatling=true;
 gatling = new Gatling("weapons.png", "explosiongatling.png", "Gatling", GATLING_PRICE,GATLING_AMMO_PRICE,GATLING_DAMAGE,5,GATLING_X,GATLING_Y,GATLING_EXP_SIZE,GATLING_MAX_AMMO,GATLING_MAX_AMMO,GATLING_MAX_CLIP_AMMO,GATLING_MAX_CLIP_AMMO);
weapons.push_back(gatling);
gatlingIndex=weaponsBought;
weapons[weaponsBought]->setCurrentAmmo(gatlingAmmo);
weapons[weaponsBought]->setCurrentClipAmmo(gatlingClipAmmo);
weaponsBought++;
}

infile>>plasmaa;
infile>>plasmaCannonAmmo;
infile>>plasmaCannonClipAmmo;//
if(plasmaa==1){
addedPlasma=true;

    plasmaCannon = new PlasmaCannon("weapons.png", "explosionplasma.PNG","Plasma Cannon",PLASMA_CANNON_PRICE,PLASMA_CANNON_AMMO_PRICE,PLASMA_CANNON_DAMAGE,5,PLASMA_CANNON_X,PLASMA_CANNON_Y,PLASMA_CANNON_EXP_SIZE,PLASMA_CANNON_MAX_AMMO,PLASMA_CANNON_MAX_AMMO,PLASMA_CANNON_MAX_CLIP_AMMO,PLASMA_CANNON_MAX_CLIP_AMMO);

    
weapons.push_back(plasmaCannon);
plasmaIndex=weaponsBought;
weapons[weaponsBought]->setCurrentAmmo(plasmaCannonAmmo);
weapons[weaponsBought]->setCurrentClipAmmo(plasmaCannonClipAmmo);
weaponsBought++;
}



infile>>numVoltorbs;
for(int k=0;k<numVoltorbs;k++){

voltorb = new Voltorb ("bombs.png", VOLTORB_PRICE, VOLTORB_DAMAGE, VOLTORB_X, VOLTORB_Y);
    voltorbs.push_back(voltorb);

}
infile>>numElectrodes;
for(int i=0; i<numElectrodes;i++){
 electrode = new Electrode("bombs.png",ELECTRODE_PRICE,ELECTRODE_DAMAGE,ELECTRODE_X,ELECTRODE_Y);
 electrodes.push_back(electrode);

}


infile>>domeHealth;
dome.setHealth(domeHealth);

infile.close();
//removes the file they used to load the game so that they can't reload it later
remove(input.c_str());
}






//loads the vector of backgrounds that transition through the time of day
void load_backgrounds()
{
backgrounds.push_back("background.bmp");
backgrounds.push_back("background4.bmp");
backgrounds.push_back("background3.bmp");
backgrounds.push_back("background2.bmp");
backgrounds.push_back("background5.bmp");
}

//the main function
int main (int argc, char *args[])
{
srand(time(NULL)); //seeds RNG for random levels
load_backgrounds();
//user's score for the game,
score=0;
  //Quit flag
  bool quit = false;

//a count through the entire game play loop
  int count = 0;

  //The frame rate regulator
  Timer fps;


  //Initialize
  if (init () == false)
    {
      return 1;
    }

//plays music throughout the game repeating
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
	Text instructions("Instructions",playButton.getTextXpos()-50,playButton.getTextYpos()+50,colorBlack,30);
	instructions.show(screen);
	Text backButton("Back",SCREEN_WIDTH/2,SCREEN_HEIGHT-50,colorWhite,30);

	Text loadButton("Load Previous Game",50,0,colorWhite,40);
loadButton.show(screen);

 Dome dome ("dome.png", DOME_BASE_X_BEG, SCREEN_HEIGHT-DOME_HEIGHT, DOME_BASE_W, DOME_HEIGHT, STARTING_HEALTH, STARTING_HEALTH);

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
					int quit;
					if(playButton.isClicked(x,y))
						play = true;
					if(instructions.isClicked(x,y))
					{
						quit = goToInstructions(backButton);
						background.show(screen);
						pokeDome.show(screen);
						playButton.show(screen);
						instructions.show(screen);
					
						SDL_Flip(screen);
						if(quit)
							return 0;
					}
					if(loadButton.isClicked(x,y)){
						SDL_EventState(SDL_MOUSEBUTTONDOWN,SDL_IGNORE);
						load_previous_game(dome);
						play=true;
						SDL_EventState(SDL_MOUSEBUTTONDOWN,SDL_ENABLE);
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

//Creates the dome and then all the text and images that will be dispalyed on the store
    
  load_store();
  Text continueToGame ("Continue to Game", 2 * SCREEN_WIDTH / 5, 8 * SCREEN_HEIGHT / 9, colorWhite, BIGGER_HEADER_TEXT_SIZE);
   Text gunsMessage("Guns",GUNS_TEXT_X,GUNS_TEXT_Y,colorWhite,HEADER_TEXT_SIZE);
Text priceHeader("Price ($)",PLASMA_CANNON_X+plasmaCannon->getWidth()-20,10,colorWhite,HEADER_TEXT_SIZE);
	Text ammoHeader("Ammo ($)",priceHeader.getTextXpos()+priceHeader.getWidth()+10,GUNS_TEXT_Y,colorWhite,HEADER_TEXT_SIZE);
	
	Text storeHeader("Select your items", 2*SCREEN_WIDTH/5, 0,colorWhite,STORE_HEADER_TEXT_SIZE);
	Text pistolText("Pistol",PISTOL_X,PISTOL_Y+pistol->getHeight()+5,colorWhite,PRICE_TEXT_SIZE);
Text plasmaCannonText("Plasma Cannon",PLASMA_CANNON_X,PLASMA_CANNON_Y+plasmaCannon->getHeight()+5,colorWhite,PRICE_TEXT_SIZE);
Text gatlingText("Gatling",GATLING_X,GATLING_Y+gatling->getHeight()+5,colorWhite,PRICE_TEXT_SIZE);
Text smgText("SMG",SMG_X,SMG_Y+smg->getHeight()+5,colorWhite,PRICE_TEXT_SIZE);
Text lmgText("LMG",LMG_X,LMG_Y+lmg->getHeight()+5,colorWhite,PRICE_TEXT_SIZE);

	Text pistolPriceText(boost::lexical_cast<string>( PISTOL_PRICE ),PLASMA_CANNON_X+plasmaCannon->getWidth()+20,PISTOL_Y,colorWhite,PRICE_TEXT_SIZE);
	Text plasmaCannonPriceText(boost::lexical_cast<string>( PLASMA_CANNON_PRICE ),PLASMA_CANNON_X+plasmaCannon->getWidth()+20,PLASMA_CANNON_Y,colorWhite,PRICE_TEXT_SIZE);
	Text gatlingPriceText(boost::lexical_cast<string>( GATLING_PRICE ),PLASMA_CANNON_X+plasmaCannon->getWidth()+20,GATLING_Y,colorWhite,PRICE_TEXT_SIZE);
	Text smgPriceText(boost::lexical_cast<string>( SMG_PRICE ),PLASMA_CANNON_X+plasmaCannon->getWidth()+20,SMG_Y,colorWhite,PRICE_TEXT_SIZE);
	Text lmgPriceText(boost::lexical_cast<string>( LMG_PRICE ),PLASMA_CANNON_X+plasmaCannon->getWidth()+20,LMG_Y,colorWhite,PRICE_TEXT_SIZE);
	Text voltorbPriceText("$"+boost::lexical_cast<string>(VOLTORB_PRICE),VOLTORB_X+storeVoltorb->getWidth()+20,VOLTORB_Y,colorWhite,PRICE_TEXT_SIZE);
	Text electrodePriceText("$"+boost::lexical_cast<string>(ELECTRODE_PRICE),ELECTRODE_X+storeElectrode->getWidth()+20,ELECTRODE_Y,colorWhite,PRICE_TEXT_SIZE);	
	Text specialsText("Specials", OTHER_TEXT_X, OTHER_TEXT_Y, colorWhite, HEADER_TEXT_SIZE);
	Text healthPriceText("$" +boost::lexical_cast<string>(HEALTH_PRICE) + " for " + boost::lexical_cast<string>(HEALTH_ADDED/HEALTH_DIVISION_FACTOR) + " health", HEALTH_X + health->getWidth() + 5, HEALTH_Y, colorWhite, PRICE_TEXT_SIZE);
	Text moneyText("Money: $ ",MONEY_TEXT_X,MONEY_TEXT_Y,colorWhite,BIGGER_HEADER_TEXT_SIZE);
	Text actualMoneyText(boost::lexical_cast<string>(money),moneyText.getTextXpos()+moneyText.getWidth(),MONEY_TEXT_Y,colorWhite,BIGGER_HEADER_TEXT_SIZE);
	Text domeText("Dome Health:",DOME_HEALTH_TEXT_X,DOME_HEALTH_TEXT_Y,colorWhite,BIGGER_HEADER_TEXT_SIZE);
	Text actualDomeHealthText(boost::lexical_cast<string>(dome.getCurrentHealth()/HEALTH_DIVISION_FACTOR),domeText.getTextXpos()+domeText.getWidth()+10,DOME_HEALTH_TEXT_Y,colorWhite,BIGGER_HEADER_TEXT_SIZE);

Text pistolAmmoPriceText(boost::lexical_cast<string>( PISTOL_AMMO_PRICE )+ " for " + boost::lexical_cast<string>(PISTOL_AMMO_PER_PURCHASE) + " shots",PISTOL_AMMO_X+pistolAmmo->getWidth()+20,PISTOL_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);
	Text plasmaCannonAmmoPriceText(boost::lexical_cast<string>( PLASMA_CANNON_AMMO_PRICE )+ " for " + boost::lexical_cast<string>(PLASMA_CANNON_AMMO_PER_PURCHASE) + " shots",PLASMA_CANNON_AMMO_X+plasmaCannonAmmo->getWidth()+20,PLASMA_CANNON_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);
	Text gatlingAmmoPriceText(boost::lexical_cast<string>( GATLING_AMMO_PRICE )+ " for " + boost::lexical_cast<string>(GATLING_AMMO_PER_PURCHASE) + " shots",GATLING_AMMO_X+gatlingAmmo->getWidth()+20,GATLING_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);
	Text smgAmmoPriceText(boost::lexical_cast<string>( SMG_AMMO_PRICE ) + " for " + boost::lexical_cast<string>(SMG_AMMO_PER_PURCHASE) + " shots",SMG_AMMO_X+smgAmmo->getWidth()+20,SMG_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);
	Text lmgAmmoPriceText(boost::lexical_cast<string>( LMG_AMMO_PRICE )+ " for " + boost::lexical_cast<string>(LMG_AMMO_PER_PURCHASE) + " shots",LMG_AMMO_X+lmgAmmo->getWidth()+20,LMG_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);
	
	Text saveText("Save Game",550,85,colorWhite,40);
	


	Text currentWeaponAmmoText("",CURRENT_AMMO_X,CURRENT_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);
	Text currentWeaponMaxAmmoText("",MAX_AMMO_X,MAX_AMMO_Y,colorWhite,PRICE_TEXT_SIZE);
	Text currentAmmoText("Current Ammo",CURRENT_AMMO_TEXT_HEADER_X,CURRENT_AMMO_TEXT_HEADER_Y,colorWhite,PRICE_TEXT_SIZE);
	Text maxAmmoText("Max Ammo",MAX_AMMO_TEXT_HEADER_X,MAX_AMMO_TEXT_HEADER_Y,colorWhite,PRICE_TEXT_SIZE);
	Text noVols("You are out of Voltorbs",200,300,colorWhite,70);
	Text noElecs("You are out of Electrodes",200,300,colorWhite,70);
	Text currentVoltorbsText("Current Voltorbs",CURRENT_VOLTORB_TEXT_X,CURRENT_VOLTORB_TEXT_Y,colorWhite,PRICE_TEXT_SIZE);
	Text currentVoltorbsNumber("0",CURRENT_VOLTORB_NUMBER_X,CURRENT_VOLTORB_NUMBER_Y,colorWhite,PRICE_TEXT_SIZE);
	Text currentElectrodesText("Current Electrodes",CURRENT_ELECTRODE_TEXT_X,CURRENT_ELECTRODE_TEXT_Y,colorWhite,PRICE_TEXT_SIZE);
	Text currentElectrodesNumber("0",CURRENT_ELECTRODE_NUMBER_X,CURRENT_ELECTRODE_NUMBER_Y,colorWhite,PRICE_TEXT_SIZE);



//will be true once the user has died or has exited the game

bool gameIsOver= false;



//class that replaces mouse with the crosshairs
 Crosshairs crosshairs;


//while they have not beat the game or have not died 
while(gameIsOver==false)
{

  /*ITEM SELECTION*/
   int continued = goToStore(dome,continueToGame,gunsMessage,priceHeader,ammoHeader,storeHeader,moneyText,actualMoneyText,pistolPriceText,plasmaCannonPriceText,gatlingPriceText,smgPriceText,
lmgPriceText,voltorbPriceText, electrodePriceText, specialsText, healthPriceText,domeText,actualDomeHealthText,pistolAmmoPriceText,plasmaCannonAmmoPriceText,gatlingAmmoPriceText,smgAmmoPriceText,currentWeaponAmmoText, currentWeaponMaxAmmoText,
lmgAmmoPriceText,pistolText,plasmaCannonText,gatlingText,smgText,lmgText,currentAmmoText,maxAmmoText,currentVoltorbsText,currentVoltorbsNumber,
currentElectrodesText,currentElectrodesNumber,saveText, quit, gameIsOver);
	if(gameIsOver)
		break;
	//continue will be 0 if they hit the X on the window while at the store
   if(!continued)
	{
		clean_up();
		return 0;
	}
Text reload("RELOAD!" ,400,300,colorRed, 100);
Text scoretext("Score: ",20,10,colorWhite,30);
Text actualscoretext( boost::lexical_cast<string>( score ),110,10,colorWhite,30);
Text weaponname("Weapon: " ,350,10,colorWhite,30);
Text cliptext("Clip: ", 750,10,colorWhite,30);
Text cliptotal(boost::lexical_cast<string>( weapons[0]->getCurrentClipAmmo() ),850,10,colorWhite,30);
Text totaltext("Total: ", 750,40,colorWhite,30);
Text total(boost::lexical_cast<string>( weapons[0]->getCurrentAmmo() ),850,40,colorWhite,30);
Text domename ("Dome Health: ",1000,10,colorWhite,20);
Text domehealth(boost::lexical_cast<string>(dome.getCurrentHealth()),1050,30,colorWhite,30);
Text leveltext("Level: ",20,40,colorWhite,30); 
Text levelnumber(boost::lexical_cast<string>(currentLevel),110,40,colorWhite,30);
Text weapontitle(weapons[currentWeaponIndex]->getName(),350,40,colorWhite,30);

/* START GAMEPLAY */

  /*LOAD  ENEMIES*/
  load_enemies (); //loads enemies for current level

  //the quit will be true when they ahve completed the level or died
  quit = false;



  //While the user hasn't quit or died
  while (quit == false)
    {


   //Start the frame timer
      fps.start ();
      //show the content on the gameplay screen
	domehealth.setText(boost::lexical_cast<string>(dome.getCurrentHealth()/HEALTH_DIVISION_FACTOR));
weapontitle.setText(weapons[currentWeaponIndex]->getName());
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
	weapontitle.show(screen);
	
weapons[currentWeaponIndex]->showDuringGamePlay(575,25,screen);

//shows the reload text if they ran out of ammo
if(weapons[currentWeaponIndex]->getCurrentClipAmmo()==0 && count%6>2) //so that the reload flashes
reload.show(screen);

//shows any voltorbs if they should be shown (if clikced a v)
for(int i=0;i<currentVoltorbIndex;i++)
{
	if(voltorbs[i]->shouldShowBomb())
	{
		voltorbs[i]->move();
		voltorbs[i]->show(screen,enemies,score,money);
	}
}
//same for electrodes
for(int i=0;i<currentElectrodeIndex;i++)
{
	if(electrodes[i]->shouldShowBomb())
	{
		electrodes[i]->move();
		electrodes[i]->show(screen,enemies,score,money);
	}
}
//move all of the enemies
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
			  Text gameOver ("Game Over", 2 * SCREEN_WIDTH / 5,
					  2 * SCREEN_HEIGHT / 5, colorWhite,40);
			  gameOver.show (screen);
		  Text finalLevel ("Final Level = " + boost::lexical_cast<string>(currentLevel), gameOver.getTextXpos(),
					  gameOver.getTextYpos()+50, colorWhite,40);
			  Text finalScore("Final Score = " + boost::lexical_cast<string>(score),finalLevel.getTextXpos(),finalLevel.getTextYpos()+50,colorWhite,40);
			  finalLevel.show(screen);
			  finalScore.show(screen);
			  SDL_Flip (screen);
			  SDL_Delay (5000);
			  quit = true;
			  gameIsOver = true; //game ends if the dome dies
			  break;
		}
	    }
	}
	if(gameIsOver==true)
		break;

//show the enemies  
      for (int j = 0; j < enemies.size (); j++)
	{
	  enemies[j]->show (screen, count);
	}
	

      //While there's events to handle
      while (SDL_PollEvent (&event))
	{
		
	       if(event.type == SDL_KEYDOWN)
		{
			//drop a voltorb
			if(event.key.keysym.sym == SDLK_v){
				if(currentVoltorbIndex<voltorbs.size())
				{
					SDL_EventState(SDL_KEYDOWN,SDL_IGNORE);
					voltorbs[currentVoltorbIndex]->setShowBomb(true);
					int xmouse, ymouse;
					SDL_GetMouseState(&xmouse, &ymouse);
					voltorbs[currentVoltorbIndex]->setPos(xmouse, BOMB_STARTING_POINT);
					currentVoltorbIndex++;
					SDL_EventState(SDL_KEYDOWN,SDL_ENABLE);
				}
			
				else
				noVols.show(screen); //shows text taht says no more voltorbs
			}
	
			//drop an electrode
			if(event.key.keysym.sym == SDLK_SPACE){
				if(currentElectrodeIndex<electrodes.size())
				{
					SDL_EventState(SDL_KEYDOWN,SDL_IGNORE);
					electrodes[currentElectrodeIndex]->setShowBomb(true);
					int xmouse, ymouse;
					SDL_GetMouseState(&xmouse, &ymouse);
					electrodes[currentElectrodeIndex]->setPos(xmouse,  BOMB_STARTING_POINT);
					currentElectrodeIndex++;
					SDL_EventState(SDL_KEYDOWN,SDL_ENABLE);
				}
			
				else
				noElecs.show(screen); //shows text that says no more electrodes
			}
			

			
			//switches to the previous weapon they own
			if(event.key.keysym.sym == SDLK_LEFT)
			{
				if(currentWeaponIndex==0) currentWeaponIndex = weapons.size()-1;
				else currentWeaponIndex--;
			}
			else if( event.key.keysym.sym == SDLK_RIGHT) //switches to next weapon they own
			{
				if(currentWeaponIndex==weapons.size()-1) currentWeaponIndex = 0;
				else currentWeaponIndex++;
			}
			else if( event.key.keysym.sym == SDLK_1) //switches to next weapon they own
			{
				if(addedPistol) currentWeaponIndex = pistolIndex;
			}
			else if( event.key.keysym.sym == SDLK_2) //switches to next weapon they own
			{
				if(addedSmg) currentWeaponIndex = smgIndex;
			}
			else if( event.key.keysym.sym == SDLK_3) //switches to next weapon they own
			{
				if(addedLmg) currentWeaponIndex = lmgIndex;
			}
			else if( event.key.keysym.sym == SDLK_4) //switches to next weapon they own
			{
				if(addedGatling) currentWeaponIndex = gatlingIndex;
			}
			else if( event.key.keysym.sym == SDLK_5) //switches to next weapon they own
			{
				if(addedPlasma) currentWeaponIndex = plasmaIndex;
			}
			
		}
			
		//checks any mouse clicks and kills enemies and updates scroe and money if is collision
	      weapons[currentWeaponIndex]->handle_events (event, enemies, screen,score,money,crosshairs);
	      
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
		if(currentLevel%2 == 1)
		{
			background.setImage(backgrounds[currentBackground]);
			currentBackground++;
			if(currentBackground>=5)
				currentBackground = 0;
		}
		//if there are no more levels, show they have beat the game and exit
		//commented out b/c we're playing with unlimited levels
		 /*   if(currentLevel>maxLevel)
		{
			gameIsOver = true;
	 		SDL_FillRect (screen, &screen->clip_rect,
				SDL_MapRGB (screen->format, 0x00, 0x00, 0x00));
			Text gameWon("You have beaten the game!",2 * SCREEN_WIDTH / 5,2 * SCREEN_HEIGHT / 5, colorWhite, 40);
			gameWon.show(screen);
			SDL_Flip(screen);
			SDL_Delay(2000);
			break;
			
		  }*/
	}

//shows the crosshairs on the screen
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
