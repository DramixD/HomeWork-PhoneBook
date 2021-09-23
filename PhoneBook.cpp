#include "PhoneBook.h"

PhoneBook::PhoneBook() = default;

PhoneBook::~PhoneBook()
{
    delete[]book;
}

PhoneBook::PhoneBook(const PhoneBook& obj)
{
    if (obj.size) {
        size = obj.size;
        book = new Contact[size];
        for (int i = 0; i < size; ++i)
            book[i] = obj.book[i];
    }
}

PhoneBook::PhoneBook(PhoneBook&& obj)
{
    if (obj.size) {
        swap(size, obj.size);
        swap(book, obj.book);
    }
}

void PhoneBook::addContact(const Contact& _contact)
{
    Contact* tmp = new Contact[size + 1];
    for (int i = 0; i < size; ++i)
        tmp[i] = book[i];
    tmp[size] = _contact;
    delete[]book;
    book = tmp;
    ++size;
}

void PhoneBook::delContact(int index)
{
    Contact* tmp = new Contact[size - 1];
    for (int i = 0; i < index; ++i)
        tmp[i] = book[i];
    for (int i = index; i < size - 1; ++i)
        tmp[i] = book[i + 1];
    delete[]book;
    book = tmp;
    --size;
}

void PhoneBook::print() const
{
    for (int i = 0; i < size; ++i)
    {
        cout << i << ".\n";
        book[i].print();
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
}

void PhoneBook::save(fstream& fs) const
{
}

void PhoneBook::load(fstream& fs)
{
}

PhoneBook& PhoneBook::operator=(const PhoneBook& obj)
{
    // TODO: insert return statement here
}

PhoneBook& PhoneBook::operator=(PhoneBook&& obj)
{
    // TODO: insert return statement here
}
