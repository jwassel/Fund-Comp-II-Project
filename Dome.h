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
		void rebuild(int); //dome will look sturdier once the user buys more health
		void fortify(int); //increase the maxHealth of the Dome after buying
		
	private:
		int currentHealth;
		int maxHealth;
};
