Authors: Jonathan Cobian, Erich Kerekes, Oliver Lamb, Jason Wassel

Image Sources: Dome illustrations by Sarah Burbank. All other images from http://www.spriters-resource.com/
Thanks to http://lazyfoo.net/SDL_tutorials/index.php for some great basic tutorials

This is our final project repository for Fundamentals of Computing II, Spring 2013. We have titled our game "Pokedome," combining the Pokemon enemies we use, and the dome they attack. 

This program is a game written using c++ and the SDL graphics library. The goal of the game is to shoot all the enemies (the pokemon) before they can attack the golden dome. The pokemon will enter from the sides, and approach the dome. They will do no damage if you shoot (click) on them before they reach the dome. If they reach the dome, they will slowly destroy the dome. If the dome is destroyed you lose!

To run this program, you must have SDL installed, as well as the extensions: SDL_image, SDL_ttf, and SDL_mixer.

When all files and extensions are on your machine correctly, open a terminal window and type "make" to compile the program and "main" to run it. 

Controls: 
To buy a weapon or special item, simply click on it in the store screen. 
To shoot an enemy, click on it during gameplay. Red crosshairs indicates you have hit the enemy. They disappear if you have killed it
To drop an electrode bomb, hit the spacebar
To drop a voltorb bomb, hit the v key.
To save a game file, click save game from the store, and then type the name of the file you want to save it as.
To load a game file, click load saved game from the home menu, then type name of file you want to load.
To change weapons, either use the left and right arrow keys to cycle through, or use the 1-5 keys to select a weapon (1=Pistol, 2=SMG, 3=LMG, 4=Gatling, 5=Plasma Cannon)

Known bugs: user can upload any exisiting file into the game, not just ones that the game created


The final program is being kept up to date in the Master Folder. All other folders are for individuals to work on their own and test things out. These other folders are not very organized.
