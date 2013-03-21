//implementation of the abstract weapon class

#include "Weapon.h"

Weapon::Weapon(int cs, int p, int ap, int d, int fr, int rr, string ch){
	clipSize=cs;	 
	price=p;
	 ammoPrice=ap;
	 damage=d;
	 fireRate=fr;
	 reloadRate=rr;
}

int clipSize;
	int price;
	int ammoPrice;
	int damage;
	int fireRate;
	int reloadRate;
	SDL_Surface crosshair;

}

