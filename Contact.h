#pragma once
#include <iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class Contact
{
	int id = 0;
	string firstName = {};
	string secondName = {};
	string address = {};
	string email = {};
	string phoneNumber{};
public:
	Contact();
	~Contact();
	Contact(int _id, const string& fName, const string& sName, const string& _address, const string& _email, const string& pNumber);
	Contact(const Contact& obj);
	Contact(Contact&& obj);
	int getId()const;
	string getFirstName()const;
	string getSecondName()const;
	string getAddress()const;
	string getEmail()const;
	string getPhoneNumber()const;
	void setId(int _id);
	void setFirstName(const string& fName);
	void setSecondName(const string& sName);
	void setAddress(const string& _address);
	void setEmail(const string& _email);
	void setPhoneNumber(const string& pNumber);
	void print()const;
	Contact& operator=(const Contact& obj);
	Contact& operator=(Contact&& obj);
	void save(fstream& fs)const;
	void load(fstream& fs);
};

