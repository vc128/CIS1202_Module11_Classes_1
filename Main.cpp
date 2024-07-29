//Vivian Chang
//CIS 1202 Section 801
//07-19-24

#include <iostream>
#include <fstream>
#include "Publication.h"
using namespace std;

void getPublicationInfo(Publication& pub) {
    string title, publisher;
    double price;
    int year, stock;
    int type;

    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter publisher: ";
    getline(cin, publisher);
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter type (0 for BOOK, 1 for MAGAZINE, 2 for NEWSPAPER, 3 for AUDIO, 4 for VIDEO): ";
    cin >> type;
    cout << "Enter stock: ";
    cin >> stock;

    pub.storePublication(title, publisher, price, year, static_cast<PublicationType>(type), stock);
}

void getPublications(Publication list[], int& count) {
    ifstream infile("publications.txt");
    if (!infile) {
        cerr << "Error opening file." << endl;
        return;
    }

    string title, publisher;
    double price;
    int year, stock, type;
    count = 0;

    while (getline(infile, title)) {
        getline(infile, publisher);
        infile >> price;
        infile >> year;
        infile >> type;
        infile >> stock;
        infile.ignore(); // Ignore the newline character after stock

        list[count].storePublication(title, publisher, price, year, static_cast<PublicationType>(type), stock);
        count++;
    }

    infile.close();
}

void showPublications(Publication list[], int count) {
    for (int i = 0; i < count; i++) {
        list[i].displayInfo();
    }
}

void showTitles(Publication list[], int count) {
    for (int i = 0; i < count; i++) {
        cout << list[i].getTitle() << endl;
    }
}

int findPublication(Publication list[], int count, string title) {
    for (int i = 0; i < count; i++) {
        if (list[i].getTitle() == title) {
            return i;
        }
    }
    return -1; // Sentinel value indicating not found
}

int getMenuChoice() {
    int choice;
    cout << "Menu:\n"
        << "1. Display all publications\n"
        << "2. Display publication titles\n"
        << "3. Find a publication\n"
        << "4. Check out\n"
        << "5. Check in\n"
        << "6. Exit\n"
        << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    Publication list[100];
    int count;

    getPublications(list, count);

    int choice;
    do {
        choice = getMenuChoice();
        cin.ignore(); // To ignore the newline character left in the buffer

        switch (choice) {
        case 1:
            showPublications(list, count);
            break;
        case 2:
            showTitles(list, count);
            break;
        case 3: {
            string title;
            cout << "Enter title to find: ";
            getline(cin, title);
            int index = findPublication(list, count, title);
            if (index != -1) {
                list[index].displayInfo();
            }
            else {
                cout << "Publication not found." << endl;
            }
            break;
        }
        case 4: {
            string title;
            cout << "Enter title to check out: ";
            getline(cin, title);
            int index = findPublication(list, count, title);
            if (index != -1) {
                list[index].checkOut();
            }
            else {
                cout << "Publication not found." << endl;
            }
            break;
        }
        case 5: {
            string title;
            cout << "Enter title to check in: ";
            getline(cin, title);
            int index = findPublication(list, count, title);
            if (index != -1) {
                list[index].checkIn();
            }
            else {
                cout << "Publication not found." << endl;
            }
            break;
        }
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}