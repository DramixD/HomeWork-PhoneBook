#pragma once
#include"Contact.h"


class PhoneBook
{
	int size = 0;
	Contact* book = nullptr;
public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(const PhoneBook& obj);
	PhoneBook(PhoneBook&& obj);
	void addContact(const Contact& _contact);
	void delContact(int index);
	void print()const;
	void save(fstream& fs)const;
	void load(fstream& fs);
	PhoneBook& operator=(const PhoneBook& obj);
	PhoneBook& operator=(PhoneBook&& obj);
};

