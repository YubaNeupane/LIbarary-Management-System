#pragma once

#include <vector>
#include "Librarian.h"
#include "Member.h"
#include "Book.h"

using namespace std;

class LibarayDatabase
{
private:
	vector<Librarian> librarians;
	vector<Member> members;
public:
	vector <Book> allBooks;

	LibarayDatabase() {
		Book  *b[10] = {
			new Book("Sons and Lovers","Dante Alighieri",768,"C32"),
			new Book("Gypsy Ballads","Jane Austen",855,"C22"),
			new Book("One Hundred","Samuel Beckett",205,"B123"),
			new Book("Love in","Giovanni Boccaccio",115,"N125"),
			new Book("The Tin Drum","Albert Camus",325,"M23"),
			new Book("Hunger","Paul Celan",105,"D123"),
			new Book("Iliad","Geoffrey Chaucer",125,"F23"),
			new Book("A Doll's House","Anton Chekhov",324,"L11"),
			new Book("Ulysses","Joseph Conrad",110,"E12"),
			new Book("Bader The King","Bader Alanzi",385,"A50")
		};

		for (int i = 0; i < 10; i++) {
			allBooks.push_back(*b[i]);
		}
	};
	~LibarayDatabase() {};


	void addLibrarian(Librarian data);
	void addMembers(Member data);

	vector<Librarian> getLibrarians() { return librarians; }
	vector<Member> getMembers() { return members; }

};