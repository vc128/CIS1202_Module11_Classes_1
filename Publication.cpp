//Vivian Chang
// CIS 1202 Section 801
//07-19-24

// Publication.cpp
#include "Publication.h"
#include <iostream>
#include <string>
using namespace std;

inline const char* ToString(PublicationType v)
{
    switch (v)
    {
    case BOOK:   return "Book";
    case MAGAZINE:   return "Magazine";
    case NEWSPAPER: return "Newspaper";
    case AUDIO: return "Audio";
    case VIDEO: return "Video";
    default:      return "[Unknown PublicationType]";
    }
}

void Publication::storePublication(string itemTitle, string itemPublisher, float itemPrice, int itemYear, PublicationType itemType, int itemStock) {
    title = itemTitle;
    publisher = itemPublisher;
    price = itemPrice;
    year = itemYear;
    type = itemType;
    stock = itemStock;
}

void Publication::displayInfo() {
    cout << "Title: " << title << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Price: $" << price << endl;
    cout << "Year: " << year << endl;
    cout << "Type: " << ToString(type) << endl;
    cout << "Stock: " << stock << endl;
}

void Publication::checkOut() {
    if (stock > 0) {
        --stock;
    }
    else {
        cout << "Out of stock!" << endl;
    }
}

void Publication::checkIn() {
    ++stock;
}

string Publication::getTitle() {
    return title;
}

int Publication::getStock() {
    return stock;
}
