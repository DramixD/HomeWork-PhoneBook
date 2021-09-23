#include "Contact.h"

Contact::Contact() = default;

Contact::~Contact()
{}

Contact::Contact(int _id, const string& fName, const string& sName, const string& _address, const string& _email, const string& pNumber)
{
	id = _id;
	firstName = fName;
	secondName = sName;
	address = _address;
	email = _email;
	phoneNumber = pNumber;
}

Contact::Contact(const Contact& obj)
{
	id = obj.id;
	firstName = obj.firstName;
	secondName = obj.secondName;
	address = obj.address;
	email = obj.email;
	phoneNumber = obj.phoneNumber;
}

Contact::Contact(Contact&& obj)
{
	swap(id, obj.id);
	swap(firstName, obj.firstName);
	swap(secondName, obj.secondName);
	swap(address, obj.address);
	swap(email, obj.email);
	swap(phoneNumber, obj.phoneNumber);
}

int Contact::getId() const
{
	return id;
}

string Contact::getFirstName() const
{
	return firstName;
}

string Contact::getSecondName() const
{
	return secondName;
}

string Contact::getAddress() const
{
	return address;
}

string Contact::getEmail() const
{
	return email;
}

string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

void Contact::setId(int _id)
{
	id = _id;
}

void Contact::setFirstName(const string& fName)
{
	firstName = fName;
}

void Contact::setSecondName(const string& sName)
{
	secondName = sName;
}

void Contact::setAddress(const string& _address)
{
	address = _address;
}

void Contact::setEmail(const string& _email)
{
	email = _email;
}

void Contact::setPhoneNumber(const string& pNumber) {
	phoneNumber = pNumber;
}

void Contact::print() const
{
	cout << setw(15) << "Id:" << id << endl;
	cout << setw(15) << "First name:" << firstName << endl;
	cout << setw(15) << "Second name:" << secondName << endl;
	cout << setw(15) << "Address:" << address << endl;
	cout << setw(15) << "Email:" << email << endl;
	cout << setw(15) << "Phone number:" << phoneNumber << endl;
}

Contact& Contact::operator=(const Contact& obj)
{
	if (this == &obj)
		return *this;
	id = obj.id;
	firstName = obj.firstName;
	secondName = obj.secondName;
	address = obj.address;
	email = obj.email;
	phoneNumber = obj.phoneNumber;
	return *this;
}

Contact& Contact::operator=(Contact&& obj)
{
	if (this == &obj)
		return *this;
	swap(id, obj.id);
	swap(firstName, obj.firstName);
	swap(secondName, obj.secondName);
	swap(address, obj.address);
	swap(email, obj.email);
	swap(phoneNumber, obj.phoneNumber);
	return *this;
}
