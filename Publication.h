//Vivian Chang
// CIS 1202 Section 801
//07-19-24

// Publication.h
#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <string>
using namespace std;

enum PublicationType { BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO };

inline const char* ToString(PublicationType);

class Publication {
    private:
        string title;
        string publisher;
        float price;
        int year;
        PublicationType type;
        int stock;

    public:
        void storePublication(string itemTitle, string itemPublisher, float itemPrice, int itemYear, PublicationType itemType, int itemStock);
        void displayInfo();
        void checkOut();
        void checkIn();
        string getTitle();
        int getStock();
};


#endif