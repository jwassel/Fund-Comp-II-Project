/* Jonathan Cobian, Erich Kerekes, Oliver Lamb, Jason Wassel
This file implements the Dome.h file.
*/

#include "Dome.h"

using namespace std;

//constructor
Dome::Dome(string imageName)
{

}

//if the dome has gotten hit, subtract from the currentHealth
void Dome::getHit(int damage)
{
	currentHealth -= damage;
}

//show the Dome collapse if the currentHealth <= 0
void Dome::collapse()
{

}

//display the Dome sturdier
void Dome::rebuild(int value)
{
	// must make the Dome look sturdier

	//change the health
	currentHealth += value;
}

//when the user buys to increase the maxHealth
void Dome::fortify(int value)
{
	maxHealth += value;
}

//gets the current haelth
int Dome::getCurrentHealth()
{
	return currentHealth;
}

//the left of the image
int Dome::getXPos()
{
	return xPos;
}

//the top of the image
int Dome::getYpos()
{
	return yPos;
)
