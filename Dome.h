/* Jonathan Cobian, Erich Kerekes, Oliver Lamb, Jason Wassel
This is the class for the Dome (aka the tower).
*/

#include"SDL/SDL.h"
#include<string>

using namespace std;

class Dome {
	public:
		Dome(string);
		void getHit(int); //dome will shake or start to fall apart when it is being attacked
		void collapse(); //dome will collapse when its health reaches 0
		void newCastleImage(int); //dome will look sturdier once the user buys more health
		void increaseMaxHealth(int); //increase the maxHealth of the Dome after buying
		int getCurrentHealth(); //returns the currentHealth
		int getXPos(); //returns the xposition of the image
		int getYPos(); //returns the yposition of the image
		
	private:
		int currentHealth; //will decrease as enemies hit it, can increase through buying health
		int maxHealth; //maximum health that the castle can begin with
		int xPos; //left hand side of image
		int yPos; //top of image
};
