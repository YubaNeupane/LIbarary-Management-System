#include "Utility.h"
#include <iomanip>

void Utility::displayTitle(string title)
{
    system("cls");
	//changeFontSize(100);
    changeColor(4);


    cout << fixed << right << setw(16) << "" << title << endl;
    cout << "------------------------------------------------------" << endl;
}

void Utility::displayMainMenuOptions()
{
    changeColor(1);
    cout << fixed << right << setw(20) << "1. " << "Login As Members" << endl;
    cout << fixed << right << setw(20) << "2. " << "Login As Librarian" << endl;
    cout << fixed << right << setw(20) << "3. " << "Setting" << endl;
    cout << fixed << right << setw(20) << "4. " << "Exit\n" << endl;
}

void Utility::changeColor(int val)
{
    SetConsoleTextAttribute(screen, val);
}

void Utility::changePassword(Member m)
{

}

void Utility::changePassword(Librarian lib)
{
    while (true) {
        string newPassword;

        displayTitle("CHANGE PASSWORD");
        changeColor(1);
        changeColor(1);
        cout << "Enter New Password: ";
        changeColor(5);
        cin >> newPassword;

        if (newPassword != " ") {
            for (int i = 0; i < dataBase->getLibrarians().size(); i++) {
                if (dataBase->getLibrarians()[i].getId() == lib.getId()) {
                    dataBase->getLibrarians()[i].setPassword(newPassword);

                   // cout << dataBase->getLibrarians()[i].getPassword() << endl;
                    Sleep(1500);
                    break;
                }
            }
            break;
        }
        else {
            cout << "Invalid Option.....Try Again!" << endl;
            Sleep(1500);
        }

    }
}

int Utility::displayMainMenu()
{
    while (true) {
        displayTitle("LIBRARY MANAGEMENT SYSTEM");
        displayMainMenuOptions();

        int userChoice;
        changeColor(5);
        cout << fixed << setw(10) << "Choice: ";
        changeColor(10);
        cin >> userChoice;
        if (userChoice <= 0 || userChoice > 4) {
            cout << "Invalid Option.....Try Again!" << endl;
            Sleep(1500);
        }
        else return userChoice;
    }
}

bool Utility::displayMemberLoginScreen() {
    int attempts = 0;
    string password;
    int idNumber;

    while (attempts < 3) {
        displayTitle("MEMBER LOGIN");
        changeColor(1);
        cout << fixed << right << setw(20) << "" << "ID NUMBER: ";
        changeColor(2);
        cin >> idNumber;

        changeColor(1);
        cout << fixed << right << setw(20) << "" << "PASSWORD : ";
        changeColor(2);
        cin >> password;

        for (int i = 0; i < dataBase->getMembers().size(); i++) {
            if (dataBase->getMembers()[i].getPassword() == password && dataBase->getMembers()[i].getId() == idNumber) {
                delete member;
                member = new Member(dataBase->getMembers()[i].getName(), dataBase->getMembers()[i].getAddress(), dataBase->getMembers()[i].getSchool(), dataBase->getMembers()[i].getPhoneNumber(), dataBase->getMembers()[i].getId());
                return true;
            }
        }
        cout << "Incorrect Login!...Try Again!" << " Attemps: " << attempts+1 << endl;
        Sleep(1000);

        attempts += 1;
    }

    return false;
}

void Utility::displaySettingMenu()
{
    while (true) {
        displayTitle("SETTINGS");
        changeColor(1);
        cout << fixed << right << setw(20) << "1. " << "Toggle FullScreen: ";
        changeColor(2);
        cout << (isFullScreen == true ? "True" : "False") << endl;
        changeColor(1);
        cout << fixed << right << setw(20) << "2. " << "Back to Main Menu\n" << endl;

        int userChoice;
        changeColor(5);
        cout << fixed << setw(10) << "Choice: ";
        changeColor(10);
        cin >> userChoice;
        if (userChoice <= 0 || userChoice > 2) {
            cout << "Invalid Option.....Try Again!" << endl;
            Sleep(1500);
        }
        else {
            switch (userChoice)
            {
            case 1:
                toggleFullScreen();
                break;
            case 2:
                return;
                break;
            default:
                break;
            }
        }
    }
}

void Utility::changeFontSize(int size)
{
	COORD fsize = { SHORT(size),SHORT(size) };
	CONSOLE_FONT_INFOEX Font = { sizeof(Font) };
	::GetCurrentConsoleFontEx(screen, FALSE, &Font);
	Font.dwFontSize = fsize;
	SetCurrentConsoleFontEx(screen, 0, &Font);
}

void Utility::toggleFullScreen()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);

    if (isFullScreen) {
        changeFontSize(50);
        isFullScreen = false;
        RECT r;
        HWND console = GetConsoleWindow();
        GetWindowRect(console, &r);
        MoveWindow(console, r.left, r.top, 1300, 600, TRUE);
    }
    else {
        isFullScreen = true;
       
        changeFontSize(100);
    }

    Sleep(500);
    return;
}

void Utility::displayMemberMenu()
{
    while (true) {

        displayTitle("MEMBERS MENU");
        changeColor(1);

        cout << fixed << right << setw(20) << "1. " << "View books" << endl;
        cout << fixed << right << setw(20) << "2. " << "Borrowed Books" << endl;
        cout << fixed << right << setw(20) << "3. " << "List Borrowed Books" << endl;
        cout << fixed << right << setw(20) << "4. " << "Account Info" << endl;
        cout << fixed << right << setw(20) << "5. " << "Sign Out\n" << endl;

        int userChoice;
        changeColor(5);
        cout << fixed << setw(10) << "Choice: ";
        changeColor(10);
        cin >> userChoice;

        if (userChoice <= 0 || userChoice > 5) {
            cout << "Invalid Option.....Try Again!" << endl;
            Sleep(1500);
        }
        else {
            switch (userChoice)
            {
            case 1:
                viewBookList();
                break;
            case 2:
                borrowBook();
                break;
            case 3:
                listBorrowedBooks();
                break;
            case 4:
                displayAccountInfo(member);               
                break;
            case 5:
                return;
                break;
            default:
                break;
            }
        }

    }
}

bool Utility::displayLibrarianLoginScreen() {

    int attempts = 0;
    string password;
    int idNumber;

    while (attempts < 3) {
        displayTitle("LIBRARIAN LOGIN");
        changeColor(1);
        cout << fixed << right << setw(20) << "" << "ID NUMBER: ";
        changeColor(2);
        cin >> idNumber;

        changeColor(1);
        cout << fixed << right << setw(20) << "" << "PASSWORD : ";
        changeColor(2);
        cin >> password;

        for (int i = 0; i < dataBase->getLibrarians().size(); i++) {
            if (dataBase->getLibrarians()[i].getPassword() == password && dataBase->getLibrarians()[i].getId() == idNumber) {
                delete libaraian;
                libaraian = new Librarian(dataBase->getLibrarians()[i].getName(), dataBase->getLibrarians()[i].getAddress(), dataBase->getLibrarians()[i].getSchool(), dataBase->getLibrarians()[i].getPhoneNumber(), dataBase->getLibrarians()[i].getId());
                return true;
            }
        }
        cout << "Incorrect Login!...Try Again!" << " Attemps: " << attempts + 1 << endl;
        Sleep(1000);

        attempts += 1;
    }

    return false;

}

void Utility::addMembers()
{
    displayTitle("ADD MEMBERS");
   
    //:Member(string firstName, string lastName, string phoneNumber, string streetAdress, string city, string state, string zipCode, string school) : Person(firstName, lastName, phoneNumber, streetAdress, city, state, zipCode, school) {}
    string firstName, lastName, phoneNumber, streetAddress, city, state, zipCode, school, password;
    int id;
    
    changeColor(5);
    cout << "First Name: ";
    changeColor(10);
    cin >> firstName;

    changeColor(5);
    cout << "Last Name: ";
    changeColor(10);
    cin >> lastName;

    changeColor(5);
    cout << "Phone Number: ";
    changeColor(10);
    cin >> phoneNumber;

    changeColor(5);
    cout << "\nStreet Address: ";
    changeColor(10);
    cin >> streetAddress;
    cin.ignore();

    changeColor(5);
    cout << "City: ";
    changeColor(10);
    cin >> city;
    cin.ignore();

    changeColor(5);
    cout << "State: ";
    changeColor(10);
    cin >> state;
    cin.ignore();

    changeColor(5);
    cout << "Zip Code: ";
    changeColor(10);
    cin >> zipCode;

    changeColor(5);
    cout << "School: ";
    changeColor(10);
    cin >> school;

    cout << "\n";
    changeColor(5);
    cout << "ID: ";
    changeColor(10);
    cin >> id;
    changeColor(5);
    cout << "Password: ";
    changeColor(10);
    cin >> password;
    
    Member *temp = new Member(firstName, lastName, phoneNumber, streetAddress, city, zipCode, school);
    temp->setId(id);
    temp->setPassword(password);
    dataBase->addMembers(*temp);

}

void Utility::viewMembers()
{
    int endValue= 0;
    displayTitle("VIEW MEMBERS");
    if (dataBase->getMembers().size() > 0) {
        for (int i = 0; i < dataBase->getMembers().size(); i += 1) {
            changeColor(1);
            cout << i + 1 << ": ";
            changeColor(2);
            cout << dataBase->getMembers()[i].getName().firstName << " " << dataBase->getMembers()[i].getName().lastName << endl;
            endValue = endValue + i + 2;
        }
        changeColor(1);
        cout << endValue << ": ";
        changeColor(2);
        cout << " Exit" << endl;
    }
    else {
        cout << "NO MEMBERS!" << endl;
        Sleep(1500);
        return;
    }

    int userChoice;
    changeColor(5);
    cout << fixed << setw(10) << "Choice: ";
    changeColor(10);
    cin >> userChoice;

    if (userChoice == endValue) { return; }

    if (userChoice <= 0 || userChoice > endValue) {
        cout << "Invalid Option.....Try Again!" << endl;
        Sleep(1500);
    }
    else {
        displayAccountInfo(&dataBase->getMembers()[userChoice - 1]);
    }
    

}

void Utility::viewBookList(bool show)
{
    if(show) displayTitle("VIEW BOOKS");

    changeColor(9);
    cout << "#" << setw(8) << " " << "Title" << setw(13) << " " << " Author" << setw(10) << " " << "Pg#" << setw(3) << " " << "Loc" << endl;

    for (int i = 0; i < dataBase->allBooks.size(); i++) {
        changeColor(2);
        cout << left << setw(2) << i << right << "|";

        changeColor(7);
        cout << fixed << right << setw(17) << dataBase->allBooks[i].title;
        changeColor(6);
        cout << setw(1) << " | " << left << setw(18) << dataBase->allBooks[i].author;
        changeColor(7);
        cout << setw(1) << " | " << left << setw(3) << dataBase->allBooks[i].pages;
        changeColor(6);
        cout << setw(1) << " | " << right << setw(4) << dataBase->allBooks[i].location << endl;
    }
    if (show) {
        string userChoice;
        changeColor(5);
        cout << fixed << setw(10) << "Press any key to go back: ";

        changeColor(10);
        cin >> userChoice;
    }


}

void Utility::addBook()
{
    displayTitle("ADD BOOK");

    string author;
    string title;
    int pages;
    string location;

    changeColor(1);
    cout << "Title: ";
    changeColor(2);
    cin.ignore();
    getline(cin, title);

    changeColor(1);
    cout << "Author: ";
    changeColor(2);
    cin.ignore();
    getline(cin, author);

    changeColor(1);
    cout << "Pages: ";
    changeColor(2);
    cin.ignore();
    cin >> pages;

    changeColor(1);
    cout << "Location: ";
    changeColor(2);
    cin.ignore();
    getline(cin, location);

    Book * b = new Book(title, author, pages, location);
    dataBase->allBooks.push_back(*b);

    changeColor(5);
    cout << "\nBOOK ADDED" << endl;
    Sleep(1500);

}

void Utility::borrowBook()
{

    while(true){
        displayTitle("BORROW BOOK");
        viewBookList(false);

        int userChoice;
        changeColor(5);
        cout << fixed << setw(10) << "\nChoice: ";
        changeColor(10);
        cin >> userChoice;
        if (userChoice < 0 || userChoice > dataBase->allBooks.size()) {
            cout << "Invalid Option.....Try Again!" << endl;
            Sleep(1500);
        }
        else {
            bool found = false;
            for (int i = 0; i < member->borrowBook.size(); i++) {
                    if (member->borrowBook[i].title == dataBase->allBooks[userChoice].title) {
                        found = true;
                        break;
                    }
        
            }
            if (!found) {
                Book *temp = new Book(dataBase->allBooks[userChoice].title, dataBase->allBooks[userChoice].author, dataBase->allBooks[userChoice].pages, dataBase->allBooks[userChoice].location);
                member->borrowBook.push_back(*temp);
                cout << "Book Borrowed!" << endl;
                Sleep(1500);
                break;
            }
            else {
                cout << "Book is already borrowed!" << endl;
                Sleep(1500);
            }
        }

    }
    
    
}

void Utility::listBorrowedBooks()
{
    displayTitle("VIEW BOOKS");

    if (member->borrowBook.size() > 0) {
        changeColor(9);
        cout << "#" << setw(8) << " " << "Title" << setw(13) << " " << " Author" << setw(10) << " " << "Pg#" << setw(3) << " " << "Loc" << endl;

        for (int i = 0; i < member->borrowBook.size(); i++) {
            changeColor(2);
            cout << left << setw(2) << i << right << "|";

            changeColor(7);
            cout << fixed << right << setw(17) << member->borrowBook[i].title;
            changeColor(6);
            cout << setw(1) << " | " << left << setw(18) << member->borrowBook[i].author;
            changeColor(7);
            cout << setw(1) << " | " << left << setw(3) << member->borrowBook[i].pages;
            changeColor(6);
            cout << setw(1) << " | " << right << setw(4) << member->borrowBook[i].location << endl;
        }
    }
    else {
        cout << "NONE BOOKS BORROWED!" << endl;
    } 
        
    string userChoice;
    changeColor(5);
    cout << fixed << setw(10) << "Press any key to go back: ";

    changeColor(10);
    cin >> userChoice;
    
}

void Utility::displayLibrarianMenu()
{
    while (true) {
        displayTitle("LIBRARIAN MENU");
        changeColor(1);
        cout << fixed << right << setw(20) << "1. " << "View Books" << endl;
        cout << fixed << right << setw(20) << "2. " << "Add Books" << endl;
        cout << fixed << right << setw(20) << "3. " << "View Members" << endl;
        cout << fixed << right << setw(20) << "4. " << "Add Members" << endl;
        cout << fixed << right << setw(20) << "5. " << "Account Info" << endl;
        cout << fixed << right << setw(20) << "6. " << "Sign Out" << endl;

        int userChoice;
        changeColor(5);
        cout << fixed << setw(10) << "Choice: ";
        changeColor(10);
        cin >> userChoice;

        if (userChoice <= 0 || userChoice > 6) {
            cout << "Invalid Option.....Try Again!" << endl;
            Sleep(1500);
        }
        else {
            switch (userChoice)
            {
            case 1:
                viewBookList();
                break;
            case 2:
                addBook();
                break;
            case 3:
                viewMembers();
                break;
            case 4:
                addMembers();
                return;
                break;
            case 5:
                displayAccountInfo(libaraian);
                break;
            case 6:
                return;
                break;
            default:
                break;
            }
        }

    }
}

