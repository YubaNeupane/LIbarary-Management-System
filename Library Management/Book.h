#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Book
{
public:
	string author ;
	string title ;
	int pages ;
	string location ;

	Book(string title, string author, int pages, string location) {
		this->title = title;
		this->author = author;
		this->pages = pages;
		this->location = location;
	}

	void printBookInfo() const {
		cout << "Title: " << title << endl;
		cout << "Author: " << title << endl;
		cout << "Description: " << location << endl;
		cout << "Pages: " << pages << endl;
	}
};

