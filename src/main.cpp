//============================================================================
// Name        : BuilderPattern.cpp
// Author      : Pedro Geadas
// Date        : October 10, 2011, 11:41 PM
// Version     :
// Copyright   :
// Description : Builder Design Pattern implementation in C++.
//============================================================================

#include <cstdlib>
#include <string.h>
#include <fstream>
#include <iostream>
#include "Director.cpp"

using namespace std;

void chooseRightAdressType(Director* d, char* str, char* str1, char* str3,
		char* str4) {

	ContactBuilder* cb;

	if (strcmp(str3, "United States") == 0) {
		cb = new USAContactBuilder();
		d->setContactBuilder(cb);
		d->constructContact(str, str1, str3, str4);
	}
	if (strcmp(str3, "France") == 0) {
		cb = new FranceContactBuilder();
		d->setContactBuilder(cb);
		d->constructContact(str, str1, str3, str4);
	}
	d->getContact()->print_contact();
}

int main(int argc, char** argv) {

	ifstream arq;
	arq.open("contacts.txt");
	char *str = new char[100];
	char *str1 = new char[100];
	char *str3 = new char[100];
	char *str4 = new char[100];

	Director* d = new Director();
	char *str2 = new char[2];
	int num = 0;
	arq.getline(str2, 2);
	num = atoi(str2); /*number of contacts in the file*/

	if (arq.is_open() && arq.good()) {

		for (int i = 0; i < num; i++) {

			arq.getline(str, 100, '\n'); //number and address
			if (strcmp(str, "") == 0) {
				i--;
				continue;
			}
			arq.getline(str1, 100, '\n'); // region and zip-code
			arq.getline(str3, 100, '\n'); // country
			arq.getline(str4, 100, '\n'); // phone number

			chooseRightAdressType(d, str, str1, str3, str4);
		}
	} else {
		cout << "Something went wrong...";
	}
	arq.close();

	return 0;
}

