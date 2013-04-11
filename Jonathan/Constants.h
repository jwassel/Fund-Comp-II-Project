#ifndef CONSTANTS_H
#define CONSTANTS_H
const int GROUND = 550;
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 1200;
const int SCREEN_BPP = 32;
//points awarded to player's score
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
#endif
