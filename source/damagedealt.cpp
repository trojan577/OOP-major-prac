#include "damagedealt.h"

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
