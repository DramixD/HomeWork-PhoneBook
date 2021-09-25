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


void Contact::save(fstream& fs) const
{
	fs.write((char*)&id, sizeof(int));
	int len = firstName.length()+1;
	fs.write((char*)&len, sizeof(int));
	fs.write((char*)firstName.c_str(), sizeof(char) * len);
	len = secondName.length()+1;
	fs.write((char*)&len, sizeof(int));
	fs.write((char*)secondName.c_str(), sizeof(char) * len);
	len = address.length()+1;
	fs.write((char*)&len, sizeof(int));
	fs.write((char*)address.c_str(), sizeof(char) * len);
	len = email.length()+1;
	fs.write((char*)&len, sizeof(int));
	fs.write((char*)email.c_str(), sizeof(char) * len);
	len = phoneNumber.length()+1;
	fs.write((char*)&len, sizeof(int));
	fs.write((char*)phoneNumber.c_str(), sizeof(char) * len);
}


void Contact::load(fstream& fs)
{
	fs.read((char*)&id, sizeof(int));

	int len;
	fs.read((char*)&len, sizeof(int));
	char* tmp = new char[len];
	fs.read(tmp, sizeof(char) * len);
	firstName = tmp;
	delete[] tmp;

	fs.read((char*)&len, sizeof(int));
	tmp = new char[len];
	fs.read(tmp, sizeof(char) * len);
	secondName = tmp;
	delete[]tmp;

	fs.read((char*)&len, sizeof(int));
	tmp = new char[len];
	fs.read(tmp, sizeof(char) * len);
	address = tmp;
	delete[]tmp;

	fs.read((char*)&len, sizeof(int));
	tmp = new char[len];
	fs.read(tmp, sizeof(char) * len);
	email = tmp;
	delete[] tmp;

	fs.read((char*)&len, sizeof(int));
	tmp = new char[len];
	fs.read(tmp, sizeof(char) * len);
	phoneNumber = tmp;
	delete[] tmp;
}
