#include <iostream>
#include "HugeInt.h"

using namespace std;

int main() {

	HugeInt a;
	a.input();
	HugeInt b;
	b.input();
	HugeInt c;
	c = a - b;
	c.print();
	c = a + b;
	c.print();

	cout << endl << "zero:\t" << c.zero() << endl;
	cout << "a < b:\t" << (a < b) << endl;
	cout << "a > b:\t" << (a > b) << endl;
	cout << "a == b:\t" << (a == b) << endl;
	cout << "a != b:\t" << (a != b) << endl;

	c = a * b;
	c.print();
	return 0;
}