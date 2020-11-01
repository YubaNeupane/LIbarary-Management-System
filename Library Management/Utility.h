#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "LibarayDatabase.h"
#include "Member.h"
#include <iomanip>
#include "Librarian.h"

using namespace std;

class Utility
{
private:
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    bool isFullScreen = false;

    void displayTitle(string title);
    void displayMainMenuOptions();
 
    void changeColor(int val);

    void changePassword(Member member);
    void changePassword(Librarian libaraian);

    LibarayDatabase* dataBase;
    Member *member;
    Librarian* libaraian;

public:
    Utility(LibarayDatabase* db) {
        dataBase = db;

    }
    int displayMainMenu();
    template <class T>
    void displayAccountInfo(T *account);

    void changeFontSize(int size=24);
    void toggleFullScreen();
    void displaySettingMenu();

    bool displayMemberLoginScreen();
    void displayMemberMenu();

    void displayLibrarianMenu();
    bool displayLibrarianLoginScreen();

    void addMembers();
    void viewMembers();

    void viewBookList(bool show=true);
    void addBook();

    void borrowBook();

    void listBorrowedBooks();


};

template<class T>
inline void Utility::displayAccountInfo(T *account)
{
    while (true) {
        displayTitle("ACCOUNT INFO");

        changeColor(2);
        cout << account->getName().firstName << " " << account->getName().lastName << endl;
        cout << account->getAddress().streetAdress << endl;
        cout << account->getAddress().city << " " << account->getAddress().state << " " << account->getAddress().zipCode << endl;
        cout << account->getPhoneNumber() << endl;

        changeColor(1);
        cout << "\nID: ";
        changeColor(2);
        cout << account->getId() << endl;

        changeColor(1);
       // cout << fixed << right << setw(20) << "1. " << "Change Passsword" << endl;
        cout << fixed << right << setw(20) << "1. " << "Go Back" << endl;

        int userChoice;
       
        changeColor(5);
        cout << fixed << setw(10) << "Choice: ";
        changeColor(10);
        cin >> userChoice;
        if (userChoice == 1) {
            break;
        }


        /*if (userChoice < 0 || userChoice > 2) {
            cout << "Invalid Option.....Try Again!" << endl;
            Sleep(1500);
        }
        else {
            switch (userChoice) {
                case 1:
                    changePassword(*account);
                    return;
                    break;
                case 2:
                    return;
                    break;
                default:
                    break;
            }
        }*/
    }
   


}
