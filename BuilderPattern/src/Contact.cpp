/*
 * Contact.cpp
 *
 *      Author: pedro geadas
 */
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

class Contact {
public:

	void setStreet(const string& street) {
		this->street = new string(street);
	}
	void setCountry(const string& country) {
		this->country = new string(country);
	}
	void setNumber(const string& number) {
		this->number = new string(number);
	}
	void setCity(const string& city) {
		this->city = new string(city);
	}
	void setRegion(const string& region) {
		this->region = new string(region);
	}
	void setZipCode(const string& zipCode) {
		this->zipcode = new string(zipCode);
	}
	void setPhone(const string& phone) {
		this->phone = new string(phone);
	}
	void print_contact() const {
		cout << "Street: " << *this->street << "\nNumber: " << *this->number
				<< "\nCity: " << *this->city << "\nCountry: " << *this->country
				<< "\nZipCode: " << *this->zipcode << "\nPhone: "
				<< *this->phone << "\nRegion: " << *this->region << endl
				<< endl;
	}

private:
	string* street;
	string* country;
	string* number;
	string* city;
	string* region;
	string* zipcode;
	string* phone;
};
