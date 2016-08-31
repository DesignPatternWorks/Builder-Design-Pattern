/*
 * Director.cpp
 *
 *      Author: pedro geadas
 */

#include <cstdlib>
#include <string.h>
#include <iostream>
#include "ContactBuilder.cpp"

using namespace std;

class Director {
public:

	void setContactBuilder(ContactBuilder* contactBuilder) {
		this->contactBuilder = contactBuilder;
	}

	Contact* getContact() {
		return contactBuilder->getContact();
	}

	void constructContact(const string& line1, const string& line2,
			const string& line3, const string& line4) {
		this->contactBuilder->createNewContact();
		this->contactBuilder->buildLineOne(line1);
		this->contactBuilder->buildLineTwo(line2);
		this->contactBuilder->buildLineThree(line3);
		this->contactBuilder->buildLineFour(line4);

	}

private:
	ContactBuilder* contactBuilder;
};

