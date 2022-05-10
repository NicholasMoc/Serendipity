// ------------------------------------------------------------------------------------------
// File name: sernedipity.cpp
// Project name : Serendipity
// -------------------------------------------------------------------------------------------
// Name : Nicholas Moc Email: nmoc0@ivc.edu
// Course-Section : CS1B # 16755
//
// Creation Date : 1/21/2020
// Date of Last Modificaiton : 2/26/2020
// -------------------------------------------------------------------------------------------
// Purpose : to create a menu and cashier
// -------------------------------------------------------------------------------------------
// Algorithm:
//	Step 1: go to main menu
//	Step 2: User chooses option
//  Step 3: Function correctly
// -------------------------------------------------------------------------------------------

#include "selectionSort.h"
#include <iomanip>
#include <windows.h>
#include <string>
#include <cctype>

using namespace std;

class bookType
{
    friend ostream& operator<< (ostream&, const bookType&);
    friend istream& operator>> (istream&, bookType&);
private:
    string bookTitle;
    string isbn;
    string author;
    string publisher;
    string date;
    int qty;
    double wholesale;
    double retail;
    static int bookCount;
public:
    static void setTitle(bookType**, string, int);
    static void setISBN(bookType**, string, int);
    static void setAuthor(bookType**, string, int);
    static void setPub(bookType**, string*, int);
    static void setDateAdded(bookType**, string, int);
    static void setQty(bookType**, int, int);
    static void setWholesale(bookType**, double, int);
    static void setRetail(bookType**, double, int);
    string getTitle();
    string getISBN();
    string getAuthor();
    string getPub();
    string getDateAdded();
    int getQty();
    double getWholesale();
    double getRetail();
    void decrementqty();
    bool operator<(const bookType& otherBook) const;
    bool operator<=(const bookType& otherBook) const;
    bool operator>=(const bookType& otherBook) const;
    bool operator==(const bookType& otherBook) const;
    bool operator!=(const bookType& otherBook) const;
};
    void mainMenu();
    void cashier(bookType**, int&);
    void invMenu(bookType**, int&);
    void reports(bookType**, int&);
    void bookInfo(bookType*);
    int lookUpBook(bookType**, int&);
    void addBook(bookType**, int&);
    void editBook(bookType**, int&);
    void deleteBook(bookType**, int&);
    void repListing(bookType**, int&);
    void repWholeSale(bookType**, int&);
    void repRetail(bookType**, int&);
    void repQty(bookType**, int&);
    void repCost();
    void repAge();
/*struct bookType
{
    string bookTitle;
    string isbn;
    string author;
    string publisher;
    string date;
    int qty;
    double wholesale;
    double retail;
};*/


