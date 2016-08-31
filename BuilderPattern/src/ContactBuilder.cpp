/*
 * ContactBuilder.cpp
 *
 *      Author: pedro geadas
 */

#include <iostream>
#include "ContactBuilder.h"
using namespace std;

class USAContactBuilder: public ContactBuilder {
public:

	void buildLineOne(const string& line) {
		int pos = line.find_first_of(" ");
		contact->setNumber(line.substr(0, pos));
		contact->setStreet(line.substr(pos + 1, line.length()));
	}

	void buildLineTwo(const string& line) {
		int pos = line.find_first_of(",");
		int pos2 = line.find_last_of(" ");
		contact->setCity(line.substr(0, pos));
		contact->setZipCode(line.substr(pos2 + 1, line.length()));
		contact->setRegion(line.substr(pos + 2, pos2 - (pos + 2)));
	}

	void buildLineThree(const string& line) {
		contact->setCountry(line);
	}

	void buildLineFour(const string& line) {
		contact->setPhone(line);
	}
};

class FranceContactBuilder: public ContactBuilder {
public:

	void buildLineOne(const string& line) {
		int pos = line.find_first_of(" ");
		contact->setNumber(line.substr(0, pos));
		contact->setStreet(line.substr(pos + 1, line.length()));
	}

	void buildLineTwo(const string& line) {
		int pos = line.find_first_of(" ");
		contact->setZipCode(line.substr(0, pos));
		contact->setCity(line.substr(pos + 1, line.length()));
		contact->setRegion("");
	}

	void buildLineThree(const string& line) {
		contact->setCountry(line);
	}

	void buildLineFour(const string& line) {
		contact->setPhone(line);
	}
};
