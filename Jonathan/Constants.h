#ifndef CONSTANTS_H
#define CONSTANTS_H
const int GROUND = 550;
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 1200;
const int SCREEN_BPP = 32;
//points awarded to player's score and money
const int LEVEL_BONUS = 100;
const int HIT_BONUS = 10;
const int KILL_BONUS = 25;
//dome coordinates
const int MIDDLE_DOME = 305; //where on the screen the upper half of the dome is
const int DOME_BASE_X_BEG = 460; //the x position of the golden dome
const int DOME_BASE_W=225;
const int DOME_BASE_X_END = DOME_BASE_X_BEG + DOME_BASE_W; //The x position plus width of golden dome
const int DOME_HEAD_X_BEG = DOME_BASE_X_BEG + 60;
const int DOME_HEAD_W=115;
const int DOME_HEAD_X_END = DOME_HEAD_X_BEG + DOME_HEAD_W;
const int DOME_HEIGHT=455;
//how far back the enemies will bounce if they hit the dome
const int BOUNCE=20;

//what the health will appear as on teh screen
const int HEALTH_DIVISION_FACTOR = 100;
const int INITIAL_MONEY = 100;

//Pistol information
const int PISTOL_PRICE = 100;
const int PISTOL_AMMO_PRICE = 10;
const int PISTOL_DAMAGE = 15;
const int PISTOL_X = 100;
const int PISTOL_Y = 60;
const int PISTOL_EXP_SIZE = 8;
const int PISTOL_MAX_AMMO = 200;

//Plasma Cannon information
const int PLASMA_CANNON_PRICE = 1000;
const int PLASMA_CANNON_AMMO_PRICE = 100;
const int PLASMA_CANNON_DAMAGE = 100;
const int PLASMA_CANNON_X = 100;
const int PLASMA_CANNON_Y = 450;
const int PLASMA_CANNON_EXP_SIZE = 40;
const int PLASMA_CANNON_MAX_AMMO = 200;

//Gatling information
const int GATLING_PRICE = 400;
const int GATLING_AMMO_PRICE = 30;
const int GATLING_DAMAGE = 8;
const int GATLING_X = 100;
const int GATLING_Y = 250;
const int GATLING_EXP_SIZE = 30;
const int GATLING_MAX_AMMO = 200;

//SMG information
const int SMG_PRICE = 500;
const int SMG_AMMO_PRICE = 35;
const int SMG_DAMAGE = 15;
const int SMG_X = 100;
const int SMG_Y = 150;
const int SMG_EXP_SIZE = 20;
const int SMG_MAX_AMMO = 200;


//lMG information
const int LMG_PRICE = 700;
const int LMG_AMMO_PRICE = 40;
const int LMG_DAMAGE = 25;
const int LMG_X = 100;
const int LMG_Y = 350;
const int LMG_EXP_SIZE = 26;
const int LMG_MAX_AMMO = 200;

//The frame rate
const int FRAMES_PER_SECOND = 20;

#endif
