#include <iostream>
#include "character.h"
#include "equipment.h"
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	int tests;
	int failed;
	cout << "This is a tester-helper for headers character.h & equipment.h" << endl;
	cout << "how many tests would you like to run" << endl;
	cin >> tests;

	string name, symbol;
	int damage;
	double miss;

	/* initiate class here and test with random inputs */
	for(unsigned int i = 0; i < tests; ++i)
	{
		Knife testknife(name, symbol, damage, miss);
	}


	/* finished testing */

	cout << "passed: " << tests - failed << " out of " << tests << "tests" << endl;
	return 0;
}