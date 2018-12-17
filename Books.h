//
// Created by krystian on 17.12.18.
//

#ifndef MAP_BOOKS_H
#define MAP_BOOKS_H

#include <string>
#include <iostream>

using namespace std;

class Books {
private:
	bool inLibrary = true, outLibrary = false;
public:
	string author;
	string category;
	unsigned int howManyPages;
	bool status;

	Books() { }

	Books(string a, string c, unsigned int p, bool s): author(a), category(c), howManyPages(p), status(s) {}

	void lendBook() {
		if (status == inLibrary)
			status = outLibrary;
		else
			cout << "Book currently out of library!" << endl;
	}

	void returnBook() {
		if (status == outLibrary)
			status = inLibrary;
		else
			cout << "Book already in the library!" << endl;
	}

	friend ostream & operator<<(ostream& out, const Books& book) {
		out << "Author: " << book.author << "\tCategory: " << book.category << "\tPages: " << book.howManyPages
		<< "\tStatus: " << (book.status ? "available" : "not available");
		return out;
	}
};

#endif //MAP_BOOKS_H
