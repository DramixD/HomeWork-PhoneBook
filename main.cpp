#include"PhoneBook.h"


int main() {
	Contact p(12, "str", "last name", "metrolog", "sobaka@mail.ru", "+38099297892222");
	Contact p1(13, "nam", "snam", "Zab", "sobaka@i.ua", "+38099123");
	Contact p2(14, "Den", "Ostr", "Hrest", "ex.ua", "3228");
//	Contact p3(15, "str", "last name", "metrolog", "sobaka@mail.ru", "+38099297892222");
//	Contact p4(16, "str", "last name", "metrolog", "sobaka@mail.ru", "+38099297892222");
	PhoneBook pb;
	pb.addContact(p);
	pb.addContact(p1);
	pb.addContact(p2);
	pb.print();

	fstream fs_out, fs_in;
	fs_out.open("phonebook.txt", ios::out | ios::binary);
	if (fs_out.is_open()) {
		cout << "test1" << endl;
		pb.save(fs_out);
		fs_out.close();
	}


	PhoneBook newPB;
	fs_in.open("phonebook.txt", ios::in | ios::binary);
	if (fs_in.is_open()) {
		cout << "test2" << endl;
		newPB.load(fs_in);
		fs_in.close();
	}

	newPB.print();
}