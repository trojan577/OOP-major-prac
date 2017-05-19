#include <iostream>
#include "character.h"
#include "equipment.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
	int tests;
	int failed = 0;
	cout << "This is a tester-helper for headers character.h & equipment.h" << endl;
	cout << "how many tests would you like to run" << endl;
	cin >> tests;

	// Seed rand
	srand (time(NULL));

	string name, symbol;

	int damage = 0;
	double miss = 0.0;

	/* initiate class here and test with random inputs */
	for(unsigned int i = 0; i < tests; ++i)
	{
		symbol = rand() % 20;
		Knife testknife(name, symbol, damage, miss);
		if(testknife.getSymbol() != symbol)
			failed++;
	}

	/* finished testing */

	cout << "passed: " << tests - failed << " out of " << tests << " tests" << endl;
	return 0;
}