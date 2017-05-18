#ifndef DAMAGEDEALT_H
#define DAMAGEDEALT_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class Damage {
	int damagemin, damagemax, hitchance;
		public:
		Damage(int, int, int)
		int damagegiven() {return
			rand() % (damagemax - damagemin) + damagemin;	// using random works out damage dealt based of max and min hit of weapon
		};
		int accuracy() {
			if((rand() % hitchance + 0) <= hitchance){
				return 1;									// using random works out whether the shot made it
			}
		};
};

#endif
