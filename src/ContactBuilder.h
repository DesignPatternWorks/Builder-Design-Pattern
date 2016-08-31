/*
 * ContactBuilder.h
 *
 *      Author: pedro geadas
 */

#ifndef CONTACTBUILDER_H_
#define CONTACTBUILDER_H_

#include <iostream>
#include "Contact.cpp"
using namespace std;

// "Abstract Builder"
class ContactBuilder {
public:

	Contact* getContact() {
		return contact;
	}

	void createNewContact() {
		contact = new Contact();
	}

	virtual void buildLineOne(const string&) = 0;
	virtual void buildLineTwo(const string&) = 0;
	virtual void buildLineThree(const string&) = 0;
	virtual void buildLineFour(const string&) = 0;
	virtual ~ContactBuilder(void) {
		if (contact)
			delete contact;
	}

protected:
	Contact* contact;
};

#endif /* CONTACTBUILDER_H_ */
