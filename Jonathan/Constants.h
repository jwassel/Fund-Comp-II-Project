#ifndef CONSTANTS_H
#define CONSTANTS_H
const int GROUND = 550;
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 1200;
const int SCREEN_BPP = 32;
//points awarded to player's score and money
const int LEVEL_BONUS = 25;
const int HIT_BONUS = 5;
const int KILL_BONUS = 15;
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
const int INITIAL_MONEY = 50;

//Pistol information
const int PISTOL_PRICE = 5;
const int PISTOL_AMMO_PRICE = 2;
const int PISTOL_DAMAGE = 10;
const int PISTOL_X = 100;
const int PISTOL_Y = 60;
const int PISTOL_EXP_SIZE = 8;
const int PISTOL_MAX_AMMO = 150;
const int PISTOL_MAX_CLIP_AMMO= 20;

//Plasma Cannon information
const int PLASMA_CANNON_PRICE = 60;
const int PLASMA_CANNON_AMMO_PRICE = 7;
const int PLASMA_CANNON_DAMAGE = 100;
const int PLASMA_CANNON_X = 100;
const int PLASMA_CANNON_Y = 450;


const int PLASMA_CANNON_EXP_SIZE = 40;
const int PLASMA_CANNON_MAX_AMMO = 100;
const int PLASMA_CANNON_MAX_CLIP_AMMO= 10;

//Gatling information
const int GATLING_PRICE = 25;
const int GATLING_AMMO_PRICE = 5;
const int GATLING_DAMAGE = 30;
const int GATLING_X = 100;
const int GATLING_Y = 350;
const int GATLING_EXP_SIZE = 30;
const int GATLING_MAX_AMMO = 300;
const int GATLING_MAX_CLIP_AMMO= 100;

//SMG information
const int SMG_PRICE = 10;
const int SMG_AMMO_PRICE = 4;
const int SMG_DAMAGE = 15;
const int SMG_X = 100;
const int SMG_Y = 150;
const int SMG_EXP_SIZE = 20;
const int SMG_MAX_AMMO = 200;
const int SMG_MAX_CLIP_AMMO= 40;

//lMG information
const int LMG_PRICE = 20;
const int LMG_AMMO_PRICE = 3;
const int LMG_DAMAGE = 20;
const int LMG_X = 100;
const int LMG_Y = 250;
const int LMG_EXP_SIZE = 26;
const int LMG_MAX_AMMO = 400;
const int LMG_MAX_CLIP_AMMO= 50;

//The frame rate
const int FRAMES_PER_SECOND = 20;
const int DELAY_BETWEEN_LEVELS = 3000;
const int RELOAD_TIME=30;


//Bomb info
const int BOMB_VELOCITY = 7;
const int ELECTRODE_X = 1000;
const int ELECTRODE_Y = 190;
const int VOLTORB_X = 1000;
const int VOLTORB_Y = 170;
const int VOLTORB_PRICE = 2;
const int VOLTORB_DAMAGE = 50;
const int VOLTORB_RANGE = 50;
const int ELECTRODE_PRICE = 4;
const int ELECTRODE_DAMAGE = 100;
const int ELECTRODE_RANGE = 100;

//Health info
const int STARTING_HEALTH = 5000;
const int HEALTH_X = 1000;
const int HEALTH_Y = 240;
const int HEALTH_PRICE = 100;
const int HEALTH_ADDED = 250;

//text info
const int OTHER_TEXT_X = 1000;
const int OTHER_TEXT_Y = 100;
const int MONEY_TEXT_X = 900;
const int MONEY_TEXT_Y = 0;
const int DOME_HEALTH_TEXT_X = 900;
const int DOME_HEALTH_TEXT_Y = 40;
const int HEADER_TEXT_SIZE = 20;
const int BIGGER_HEADER_TEXT_SIZE = 30;
const int STORE_HEADER_TEXT_SIZE = 30;
const int PRICE_TEXT_SIZE = 15;
const int GUNS_TEXT_X = 100;
const int GUNS_TEXT_Y = 10;

#endif
