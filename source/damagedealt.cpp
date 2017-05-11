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

Damage::Damage (int a, int b int c){
	damagemin = a; 											// sets up variables for the calculations in the class above
	damagemax = b;
	hitchance = c;
}

int main() {
	//if weapon that is selected is dagger {
	Damage dagger (2,5,75); 								// these later on can be coded to fetch values from some sort of storage (min damage, max damage, chanceof success)

	cout << "damage" << dagger.damagegiven() << endl; 		// as a test prints out the damage that would be dealt
	if (dagger.accuracy() = 1){ 							// as a test prints out whether the dagger swipe hit
		cout << "It hit" << endl; 
	else {
		cout << "The shot missed" << endl;
		}
	}
	//}




};