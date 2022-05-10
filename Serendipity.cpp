#include "Serendipity.h"

const int DBSIZE = 20;

int main()
{
    mainMenu();
    system("pause");
    return 0;
}

void mainMenu()
{
    bookType** library;
    library = new bookType * [DBSIZE];
    for (int i = 0; i < DBSIZE; i++)
    {
        library[i] = nullptr;
    }
    int bookCount = 0; //static variable
    bool fin;
    do
    {
        char choice;
        system("cls");
        cout << " Serendipity Booksellers" << endl;
        cout << setw(7) << left << "Main Menu" << endl << endl;
        cout << "1.  Cashier Module" << endl << "2.  Inventory Database" << endl << "3.  Report Module" << endl << "4.  Exit" << endl << endl;
        cout << "Enter Your Choice: ";
        cin.get(choice);
        if (choice != '1')
        {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        switch (choice)
        {
        case '1':
            cashier(library, bookCount);
            fin = FALSE;
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        case '2':
            invMenu(library, bookCount);
            fin = FALSE;
            break;
        case '3':
            reports(library, bookCount);
            fin = FALSE;
            break;
        case '4':
            fin = TRUE;
            break;
        default: cout << "Please enter a number in the range 1-4" << endl;
            system("pause");
            break;
        }
    } while (!fin);
}

void cashier(bookType** arr, int& bookCount)
{
    bool repeat;
    do
    {
        int qty;
        bool accept = FALSE;
        char purch;
        char redo;
        //cin.clear();
        //cin.ignore(200,'\n');
        system("cls");
        cout << "Serendipity Book Sellers" << endl << " Cashier Module" << endl;
        int purIndex = lookUpBook(arr, bookCount);
        if (purIndex == -1)
        {
            break;
        }
        cout << "Is this the book you would like to purchase? <Y/N>: ";
        cin >> purch;
        if (toupper(purch) == 'Y')
        {
            bool qtyaccept = FALSE;
            while (qtyaccept == FALSE)
            {
                cout << "How many would you like? : ";
                cin >> qty;
                if (qty <= arr[purIndex]->getQty())
                {
                    qtyaccept = TRUE;
                    for (int i = 0; i < qty; i++)
                    {
                        arr[purIndex]->decrementqty();
                    }
                }
                else
                {
                    cout << "Try a lower number." << endl;
                }
            }
            accept = TRUE;
        }
        else
        {
            cout << "Thank you for visiting. Have a nice day.";
            break;
        }

        system("cls");
        cout << "Serendipity Book Sellers" << endl << endl;
        cout << "Date: " << arr[purIndex]->getDateAdded() << endl << endl;
        cout << left << setw(4) << "Qty" << setw(14) << "ISBN" << setw(73) << "Title" << setw(8) << "Price" << right << setw(15) << "Total" << endl;
        cout << "_______________________________________________________________________________________________________________" << endl << endl;
        cout << left << setw(4) << qty << setw(14) << arr[purIndex]->getISBN() << setw(70) << arr[purIndex]->getTitle() << setw(2) << "$" << right << setw(5) << arr[purIndex]->getRetail() << setw(9) << "$" << fixed << setprecision(2) << setw(6) << arr[purIndex]->getRetail() * qty << endl << endl << endl << endl;
        cout << left << setw(10) << "  Subtotal" << right << setw(49) << "$" << setw(6) << arr[purIndex]->getRetail() * qty << endl;
        cout << left << setw(10) << "  Tax" << right << setw(49) << "$" << setw(6) << arr[purIndex]->getRetail() * qty * 0.06 << endl;
        cout << left << setw(10) << "  Total" << right << setw(49) << "$" << setw(6) << arr[purIndex]->getRetail() * qty + arr[purIndex]->getRetail() * qty * 0.06 << endl << endl;
        cout << "Thank You for Shopping at Serendipity!" << endl;
        do
        {

            cout << "Is there another transaction to be processed? (Y or N)";
            cin >> redo;
            if (toupper(redo) == 'Y')
            {
                repeat = true;
            }
            //cin.clear();
            //cin.ignore(10000, '\n');
            else if (toupper(redo) == 'N')
            {
                repeat = false;
            }
            else
            {
                redo = 'A';
            }
        } while (redo == 'A');
    } while (repeat);
    system("pause");
}

void invMenu(bookType** arr, int& bookCount)
{
    char choice;
    bool acceptChoice;	do
    {
        system("cls");
        cout << " Serendipity Booksellers" << endl;
        cout << "   Inventory Database" << endl;
        cout << "\t\t\t Current Books: " << bookCount << endl;
        cout << "1. Look Up a Book" << endl << "2. Add a Book" << endl << "3. Edit a Book's Record" << endl << "4. Delete a Book" << endl << "5. Return to the Main Menu" << endl << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');
        switch (choice)
        {
        case '1':
            lookUpBook(arr, bookCount);
            acceptChoice = false;
            system("pause");
            break;
        case '2':
            addBook(arr, bookCount);
            acceptChoice = false;
            system("pause");
            break;
        case '3':
            editBook(arr, bookCount);
            acceptChoice = false;
            system("pause");
            break;
        case '4':
            deleteBook(arr, bookCount);
            acceptChoice = false;
            system("pause");
            break;
        case '5':
            system("pause");
            acceptChoice = true;
            break;
        default: cout << "\nPlease enter a number in the range 1 - 5" << endl;
            acceptChoice = false;
            system("pause");
            break;
        }
    } while (acceptChoice == false);
}

void bookInfo(bookType* book)
{
    system("cls");
    cout << " Serendipity Booksellers" << endl;
    cout << left << setw(5) << "Book Information" << endl;
    //cout << "IBSN: " << book->getISBN() << endl << "Title: " << book->getTitle() << endl << "Author: " << book->getAuthor() << endl << "Publisher: " << book->getPub() << endl << "Date Added: " << book->getDateAdded() << endl << "Quantity-On Hand: " << book->getQty() << endl << fixed << setprecision(2) <<
      //  "Wholesale Cost: " << book->getWholesale() << endl << "Retail Price: " << book->getRetail() << endl;
    cout << *book;
}

void reports(bookType** arr, int& bookCount)
{
    char choice;
    bool acceptChoice;
    do
    {
        system("cls");
        cout << " Serendipity Booksellers" << endl;
        cout << left << setw(9) << "Reports" << endl;
        cout << "1. Inventory Listing" << endl << "2. Inventory Wholesale Value" << endl << "3. Inventory Retail Value" << endl << "4. Listing by Quantity" << endl << "5. Listing by Cost" << endl << "6. Listing by Age" << endl << "7. Return to Main Menu" << endl << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(10000, '\n');
        switch (choice)
        {
        case '1': repListing(arr, bookCount);
            acceptChoice = FALSE;
            break;
        case '2': repWholeSale(arr, bookCount);
            acceptChoice = FALSE;
            break;
        case '3': repRetail(arr, bookCount);
            acceptChoice = FALSE;
            break;
        case '4': repQty(arr, bookCount);
            acceptChoice = FALSE;
            break;
        case '5': repCost();
            acceptChoice = FALSE;
            break;
        case '6':
            repAge();
            acceptChoice = FALSE;
            break;
        case '7':
            acceptChoice = TRUE;
            break;
        default: cout << "Please enter a number in the range 1 - 7" << endl;
            system("pause");
            break;
        }
    } while (!acceptChoice);
}

int lookUpBook(bookType** arr, int& bookCount)
{
    string search;
    char accept;
    if (bookCount == 0)
    {
        cout << "There are no books" << endl;
        return -1;
    }
    cout << "Book Look Up" << endl << "Search: ";
    cin.ignore();
    getline(cin, search);
    for (int i = 0; i < bookCount; i++)
    {
        //bookType* book = nullptr;
        //book = arr[i];
        if (arr[i]->getTitle().find(search) != std::string::npos || arr[i]->getISBN().find(search) != std::string::npos)
        {
            cout << "Result: " << arr[i]->getTitle() << endl;
            cout << "View this book record? (Y/N): ";
            cin >> accept;
            if (toupper(accept) == 'Y')
            {
                bookInfo(arr[i]);
                return i;
                break;
            }
        }
        else if (i == bookCount - 1)
        {
            cout << "No matches found" << endl;
            return -1;
        }
    }
}

void addBook(bookType** arr, int& bookCount)
{
    bool finFunc = false;
    do
    {
        bookType* book = nullptr;
        book = new bookType;
        string t = "EMPTY";
        string i = "EMPTY";
        string a = "EMPTY";
        string* p = new string("EMPTY");
        string d = "EMPTY";
        int q = 0;
        double w = 0.00;
        double r = 0.00;
        char choice;
        bool finBook = false;
        do
        {
            system("cls");
            if (bookCount < 20)
            {
                cout << "Add Book:" << endl;
                cout << "current book count :" << bookCount << endl;
                cout << "<1> Enter Title: " << t << endl;
                cout << "<2> Enter ISBN: " << i << endl;
                cout << "<3> Enter Author:" << a << endl;
                cout << "<4> Enter Publisher: " << *p << endl;
                cout << "<5> Enter Date: " << d << endl;
                cout << "<6> Enter Quantity:" << q << endl;
                cout << "<7> Enter Wholesale:" << w << endl;
                cout << "<8> Enter Retail:" << r << endl;
                cout << "<9> Save Book to Database" << endl;
                cout << "<0> Return to Inventory Menu" << endl;
                cout << "Choice <0-9>: ";
                cin >> choice;
                switch (choice)
                {
                case '1': cout << "Enter Title: "; cin.ignore(); getline(cin, t);
                    break;
                case '2': cout << "Enter ISBN: "; cin.ignore(); getline(cin, i);
                    break;
                case '3': cout << "Enter Author: "; cin.ignore(); getline(cin, a);
                    break;
                case '4': cout << "Enter Publisher: "; cin.ignore(); getline(cin, *p);
                    break;
                case '5': cout << "Enter Date: ";  cin.ignore(); getline(cin, d);
                    break;
                case '6': cout << "Enter Quantity: "; cin >> q;
                    break;
                case '7': cout << "Enter Wholesale: "; cin >> w;
                    break;
                case '8': cout << "Enter Retail: "; cin >> r;
                    break;
                case '9':
                    arr[bookCount] = book;
                    bookType::setTitle(arr, t, bookCount);
                    bookType::setISBN(arr, i, bookCount);
                    bookType::setAuthor(arr, a, bookCount);
                    bookType::setPub(arr, p, bookCount);
                    bookType::setDateAdded(arr, d, bookCount);
                    bookType::setQty(arr, q, bookCount);
                    bookType::setWholesale(arr, w, bookCount);
                    bookType::setRetail(arr, r, bookCount);
                    bookCount++;
                    finBook = true;
                    break;
                case '0': finBook = true;
                    finFunc = true;
                    break;
                default: cout << "Invalid Input" << endl;
                    break;
                }
            }
            else
            {
                cout << "There are already the max amount of books" << endl;
                finBook = true;
                finFunc = true;
            }
        } while (!finBook);
    } while (!finFunc);
}


void editBook(bookType** arr, int& bookCount)
{
    system("cls");
    cout << "Edit Book" << endl;
    char choice;
    int bookIndex = lookUpBook(arr, bookCount);
    bookType* book = nullptr;
    book = new bookType;
    book = arr[bookIndex];
    string t = book->getTitle();
    string i = book->getISBN();
    string a = book->getAuthor();
    string* p = new string(book->getPub());
    string d = book->getDateAdded();
    int q = book->getQty();
    double w = book->getWholesale();
    double r = book->getRetail();
    char save;
    bool fin = false;
    do
    {
        system("cls");
        cout << "Edit Book:" << endl;
        cout << "current book count :" << bookCount << endl;
        cout << "<1> Edit Title: " << t << endl;
        cout << "<2> Edit ISBN: " << i << endl;
        cout << "<3> Edit Author:" << a << endl;
        cout << "<4> Edit Publisher:" << *p << endl;
        cout << "<5> Edit Date: " << d << endl;
        cout << "<6> Edit Quantity:" << q << endl;
        cout << "<7> Edit Wholesale:" << setprecision(2) << w << endl;
        cout << "<8> Edit Retail:" << r << endl;
        cout << "<9> Return to Inventory Menu" << endl;
        cout << "Choice<1-9>: ";
        cin >> choice;
        switch (choice)
        {
        case '1': cout << "Enter Title: "; cin.ignore(); getline(cin, t);
            break;
        case '2': cout << "Enter ISBN: "; cin.ignore(); getline(cin, i);
            break;
        case '3': cout << "Enter Author: "; cin.ignore(); getline(cin, a);
            break;
        case '4': cout << "Enter Publisher: "; cin.ignore(); getline(cin, *p);
            break;
        case '5': cout << "Enter Date: ";  cin.ignore(); getline(cin, d);
            break;
        case '6': cout << "Enter Quantity: "; cin >> q;
            break;
        case '7': cout << "Enter Wholesale: $"; cin >> w;
            break;
        case '8': cout << "Enter Retail: $"; cin >> r;
            break;
        case '9': cout << "Do you want to save changes? <Y/N>: ";
            cin >> save;
            if (toupper(save) == 'Y')
            {
                bookType::setISBN(arr, i, bookIndex);
                bookType::setTitle(arr, t, bookIndex);
                bookType::setAuthor(arr, a, bookIndex);
                bookType::setPub(arr, p, bookIndex);
                bookType::setDateAdded(arr, d, bookIndex);
                bookType::setQty(arr, q, bookIndex);
                bookType::setWholesale(arr, w, bookIndex);
                bookType::setRetail(arr, r, bookIndex);
                //arr[bookIndex] = book;
                cout << "Changes have been saved";
            }
            else
            {
                cout << "Changes have been discarded";
            }
            delete book;
            fin = true;	break;
        default: cout << "Not a valid input";
            break;
        }
    } while (!fin);
}

void deleteBook(bookType** arr, int& bookCount)
{
    char del;
    char repeat;
    bool fin;
    bookType* bookLast = nullptr;
    bookLast = new bookType;
    string* p = new string(bookLast->getPub());
    do
    {
        system("cls");
        cout << "Delete Book" << endl;
        int indexDelete = lookUpBook(arr, bookCount);
        cout << "Is this the book you want to DELETE? <Y/N>: ";
        cin >> del;
        if (toupper(del) == 'Y')
        {
            bookLast = arr[bookCount - 1];

            bookType::setISBN(arr, bookLast->getISBN(), indexDelete);
            bookType::setTitle(arr, bookLast->getTitle(), indexDelete);
            bookType::setAuthor(arr, bookLast->getAuthor(), indexDelete);
            bookType::setPub(arr, p, indexDelete);
            bookType::setDateAdded(arr, bookLast->getDateAdded(), indexDelete);
            bookType::setQty(arr, bookLast->getQty(), indexDelete);
            bookType::setWholesale(arr, bookLast->getWholesale(), indexDelete);
            bookType::setRetail(arr, bookLast->getRetail(), indexDelete);

            delete arr[bookCount - 1];
            cout << "Book Deleted" << endl;
            bookCount--;

        }
        else
        {
            cout << "Delete canceled" << endl;
            fin = true;
        }
        cout << "Delete Another? <Y/N>: ";
        cin >> repeat;
        if (toupper(repeat) == 'N')
        {
            fin = true;
        }
        else
        {
            fin = false;
        }
    } while (!fin);
    delete p;
}

void repListing(bookType** arr, int& bookCount)
{
    int num = bookCount;
    int loop;
    if (num % 10 == 0)
    {
        loop = bookCount / 10;
    }
    else
    {
        loop = bookCount / 10 + 1;
    }
    for (int i = 0; i < loop; i++)
    {
        system("cls");
        for (int c = 0; c < 123; c++)
        {
            cout << "*";
        }
        cout << endl << left << setw(49) << "* " << "SERENDIPITY BOOKSELLERS" << setw(47) << "" << "   *" << endl;
        cout << setw(54) << "* " << "REPORT LISTING" << setw(52) << "" << "  *" << endl;
        cout << "* DATE: 05/06/2020" << right << setw(10) << "PAGE: " << i + 1 << " of 2" << setw(20) << "DATABASE SIZE:  " << DBSIZE << "  CURRENT BOOK COUNT:  " << bookCount << setw(42) << "*" << endl;
        cout << left << "* " << setw(28) << "Title" << setw(14) << "ISBN" << setw(15) << "AUTHOR" << setw(15) << "PUBLISHER" << setw(11) << "DATE ADDED" << setw(8) << "QTY O/H" << setw(16) << "WHOLESALE COST" << setw(12) << "RETAIL PRICE" << " *\n";
        cout << "* " << "--------------------------- " << "------------- " << "-------------- " << "-------------- " << "---------- " << "------- " << "--------------- " << "------------ *" << endl;
        
        if (num >= 10)
        {
            for (int z = i * 10; z < i * 10 + 10; z++)
            {
                cout << left << "* " << setw(28) << arr[z]->getTitle().substr(0, 27) << setw(14) << arr[z]->getISBN() << setw(15) << arr[z]->getAuthor().substr(0, 14) << setw(15) << arr[z]->getPub().substr(0, 14) << setw(11) << arr[z]->getDateAdded() << right << setw(7) << arr[z]->getQty() << setw(16) << fixed << setprecision(2) << arr[z]->getWholesale() << setw(13) << arr[z]->getRetail() << " *" << endl;
                cout << left << setw(121) << "*" << " *" << endl;
            }
        }
        else
        {
            for (int z = i * 10; z < i * 10 + num; z++)
            {
                cout << left << "* " << setw(28) << arr[z]->getTitle().substr(0, 27) << setw(14) << arr[z]->getISBN() << setw(15) << arr[z]->getAuthor().substr(0, 14) << setw(15) << arr[z]->getPub().substr(0, 14) << setw(11) << arr[z]->getDateAdded() << right << setw(7) << arr[z]->getQty() << setw(16) << fixed << setprecision(1) << arr[z]->getWholesale() << setw(13) << arr[z]->getRetail() << " *" << endl;
                cout << left << setw(121) << "*" << " *" << endl;
            }
        }
        num -= 10;
        system("pause");
    }
}

void repWholeSale(bookType** arr, int& bookCount)
{
    int num = bookCount;
    int loop;
    double total = 0.0;
    if (num % 10 == 0)
    {
        loop = bookCount / 10;
    }
    else
    {
        loop = bookCount / 10 + 1;
    } 
    for (int i = 0; i < loop; i++)
    {
        system("cls");
        for (int c = 0; c < 122; c++)
        {
            cout << "*";
        }
        cout << endl << left << setw(49) << "* " << "SERENDIPITY BOOKSELLERS" << setw(47) << "" << "  *" << endl;
        cout << setw(48) << "* " << "REPORT WHOLESALE LISTING" << setw(47) << "" << "  *" << endl;
        cout << "* DATE: 04/27/2020" << right << setw(10) << "PAGE: " << i + 1 << " of 2" << setw(20) << "DATABASE SIZE:  " << DBSIZE << "  CURRENT BOOK COUNT:  " << bookCount << setw(41) << "*" << endl;
        cout << left << "* " << setw(45) << "Title" << setw(5) << "" << setw(16) << "ISBN" << setw(10) << "" << setw(8) << "QTY O/H" << setw(12) << "" << setw(16) << "WHOLESALE COST" << setw(6) << "" << " *" << endl;
        cout << "* --------------------------------------------- " << "    ------------- " << "            ------- " << "            --------------         *" << endl;
        if (num >= 10)
        {
            for (int z = i * 10; z < i * 10 + 10; z++)
            {
                cout << left << "* " << setw(45) << arr[z]->getTitle().substr(0, 45) << setw(5) << "" << setw(14) << arr[z]->getISBN() << setw(10) << "" << right << setw(9) << arr[z]->getQty() << setw(10) << "" << setw(17) << fixed << setprecision(2) << arr[z]->getWholesale() << setw(10) << "*" << endl;
                cout << left << setw(121) << "*" << "*" << endl;
                total += arr[z]->getWholesale();
            }
        }
        else
        {
            for (int z = i * 10; z < i * 10 + num; z++)
            {
                cout << left << "* " << setw(45) << arr[z]->getTitle().substr(0, 45) << setw(5) << "" << setw(14) << arr[z]->getISBN() << setw(10) << "" << right << setw(7) << arr[z]->getQty() << setw(10) << "" << setw(17) << fixed << setprecision(2) << arr[z]->getWholesale() << setw(10) << "*" << endl;
                cout << left << setw(121) << "*" << "*" << endl;
                total += arr[z]->getWholesale();
            }
        }
        if (i == loop - 1)
        {
            cout << "* Total: " << total << endl;
        }
        num -= 10;
        system("pause");
    }
}

void repRetail(bookType** arr, int& bookCount)
{
    int num = bookCount;
    int loop;
    double total = 0.0;
    if (num % 10 == 0)
    {
        loop = bookCount / 10;
    }
    else
    {
        loop = bookCount / 10 + 1;
    }
    for (int i = 0; i < loop; i++)
    {
        system("cls");
        for (int c = 0; c < 120; c++)
        {
            cout << "*";
        }
        cout << endl << left << setw(49) << "* " << "SERENDIPITY BOOKSELLERS" << setw(47) << "" << "*" << endl;
        cout << setw(51) << "* " << "REPORT RETAIL LISTING" << setw(47) << "" << "*" << endl;
        cout << "* DATE: 04/27/2020 " << right << setw(10) << "PAGE: " << i + 1 << " of " << loop << setw(20) << "DATABASE SIZE:  " << DBSIZE << "  CURRENT BOOK COUNT:  " << bookCount << setw(38) << "*" << endl;
        cout << left << "* " << setw(45) << "Title" << setw(5) << "" << setw(14) << "ISBN" << setw(10) << "" << setw(8) << "QTY O/H" << setw(15) << "" << setw(16) << "RETAIL COST" << setw(3) << "" << " *" << endl;
        cout << "* --------------------------------------------- " << "    ------------- " << "          ------- " << "               ------------        *" << endl;
        if (num >= 10)
        {
            for (int z = i * 10; z < i * 10 + 10; z++)
            {
                cout << left << "* " << setw(45) << arr[z]->getTitle().substr(0, 45) << setw(5) << "" << setw(14) << arr[z]->getISBN() << setw(10) << "" << right << setw(7) << arr[z]->getQty() << setw(10) << "" << setw(17) << fixed << setprecision(2) << arr[z]->getRetail() << setw(10) << "*" << endl;
                cout << left << setw(119) << "*" << "*" << endl;
                total += arr[z]->getRetail();
            }
        }
        else
        {
            for (int z = i * 10; z < i * 10 + num; z++)
            {
                cout << left << "* " << setw(45) << arr[z]->getTitle().substr(0, 45) << setw(5) << "" << setw(14) << arr[z]->getISBN() << setw(10) << "" << right << setw(7) << arr[z]->getQty() << setw(10) << "" << setw(17) << fixed << setprecision(2) << arr[z]->getRetail() << setw(10) << "*" << endl;
                cout << left << setw(119) << "*" << "*" << endl;
                total += arr[z]->getRetail();
            }
        }
        num -= 10;
        if (i == loop - 1)
        {
            cout << "* Total: " << total << endl;
        }
        system("pause");
    }
}

void repQty(bookType** arr, int& bookCount)
{
    int num = bookCount;
    int loop;
    if (num % 10 == 0)
    {
        loop = bookCount / 10;
    }
    else
    {
        loop = bookCount / 10 + 1;
    }
    selectionSort(arr, bookCount);

    for (int i = 0; i < loop; i++)
    {
        system("cls");
        for (int c = 0; c < 122; c++)
        {
            cout << "*";
        }
        cout << endl << left << setw(49) << "* " << "SERENDIPITY BOOKSELLERS" << setw(47) << "" << "  *" << endl;
        cout << setw(49) << "* " << "REPORT QUANTITY LISTING" << setw(47) << "" << "  *" << endl;
        cout << "* DATE: 04/27/2020" << right << setw(10) << "PAGE: " << i + 1 << " of 2" << setw(20) << "DATABASE SIZE:  " << DBSIZE << "  CURRENT BOOK COUNT:  " << bookCount << setw(41) << "*" << endl;
        cout << left << "* " << setw(45) << "Title" << setw(5) << "" << setw(16) << "ISBN" << setw(10) << "" << setw(8) << "QTY O/H" << setw(12) << "" << setw(16) << "" << setw(6) << "" << " *" << endl;
        cout << "* --------------------------------------------- " << "    ------------- " << "            ------- " << "                                   *" << endl;
        if (num >= 10)
        {
            for (int z = num - 1; z >= num - 10; z--)
            {
                cout << left << "* " << setw(45) << arr[z]->getTitle().substr(0, 45) << setw(5) << "" << setw(16) << arr[z]->getISBN() << setw(10) << "" << right << setw(7) << arr[z]->getQty() << setw(10) << "" << setw(17) << "" << setw(10) << "*" << endl;
                cout << left << setw(121) << "*" << "*" << endl;
            }
        }
        else
        {
            for (int z = num - 1; z >= 0; z--)
            {
                cout << left << "* " << setw(45) << arr[z]->getTitle().substr(0, 45) << setw(5) << "" << setw(16) << arr[z]->getISBN() << setw(10) << "" << right << setw(7) << arr[z]->getQty() << setw(10) << "" << setw(17) << "" << setw(10) << "*" << endl;
                cout << left << setw(121) << "*" << "*" << endl;
            }
        }
        num -= 10;
        system("pause");
    }
}
void repCost()
{
    cout << "You  selected Listing By Cost" << endl;
}

void repAge()
{
    cout << "You  selected  Listing By Age" << endl;
}

void bookType::setTitle(bookType** book, string bookTitle, int index)
{
    book[index]->bookTitle = bookTitle;
}

void bookType::setISBN(bookType** book, string isbnNum, int index)
{
    book[index]->isbn = isbnNum;
}

void bookType::setAuthor(bookType** book, string aut, int index)
{
    book[index]->author = aut;
}

void bookType::setPub(bookType** book, string* pub, int index)
{
    book[index]->publisher = *pub;
}

void bookType::setDateAdded(bookType** book, string d, int index)
{
    book[index]->date = d;
}

void bookType::setQty(bookType** book, int q, int index)
{
    book[index]->qty = q;
}

void bookType::setWholesale(bookType** book, double whole, int index)
{
    book[index]->wholesale = whole;
}

void bookType::setRetail(bookType** book, double ret, int index)
{
    book[index]->retail = ret;
}

string bookType::getTitle()
{
    return bookTitle;
}

string bookType::getISBN()
{
    return isbn;
}

string bookType::getAuthor()
{
    return author;
}

string bookType::getPub()
{
    return publisher;
}

string bookType::getDateAdded()
{
    return date;
}

int bookType::getQty()
{
    return qty;
}

double bookType::getWholesale()
{
    return wholesale;
}

double bookType::getRetail()
{
    return retail;
}

void bookType::decrementqty()
{
    qty -= 1;
}

bool bookType::operator==(const bookType& otherBook) const
{
    return (qty == otherBook.qty );
}//bookTitle == otherBook.bookTitle && isbn == otherBook.isbn && author == otherBook.author && publisher == otherBook.publisher && date == otherBook.date && && wholesale == otherBook.wholesale && retail == otherBook.retail

bool bookType::operator!=(const bookType& otherBook) const
{
    return (qty != otherBook.qty);
}//bookTitle != otherBook.bookTitle && isbn != otherBook.isbn && author != otherBook.author && publisher != otherBook.publisher && date != otherBook.date &&  && wholesale != otherBook.wholesale && retail != otherBook.retail

bool bookType::operator>=(const bookType& otherBook) const
{
    return (qty >= otherBook.qty);
}//bookTitle >= otherBook.bookTitle && isbn >= otherBook.isbn && author >= otherBook.author && publisher >= otherBook.publisher && date >= otherBook.date && && wholesale >= otherBook.wholesale && retail >= otherBook.retail

bool bookType::operator<=(const bookType& otherBook) const
{
    return (qty <= otherBook.qty);
}//bookTitle <= otherBook.bookTitle && isbn <= otherBook.isbn && author <= otherBook.author && publisher <= otherBook.publisher && date <= otherBook.date && && wholesale <= otherBook.wholesale && retail <= otherBook.retail

bool bookType::operator<(const bookType& otherBook) const
{
    return (qty < otherBook.qty);
}//bookTitle < otherBook.bookTitle && isbn < otherBook.isbn && author < otherBook.author && publisher < otherBook.publisher && date < otherBook.date && && wholesale < otherBook.wholesale && retail < otherBook.retail

ostream& operator<< (ostream& osObject, const bookType& book)
{
    osObject << "ISBN: " << book.isbn << endl;
    osObject << "Title: " << book.bookTitle << endl;
    osObject << "Author: " << book.author << endl;
    osObject << "Publisher: " << book.publisher << endl;
    osObject << "Date Added: " << book.date << endl;
    osObject << "Quantity-On Hand: " << book.qty << endl;
    osObject << fixed << setprecision(2) << "Wholesale cost: " << book.wholesale << endl;
    osObject << "Retail Price: " << book.retail << endl;
    return osObject;
    //cout << "IBSN: " << book->getISBN() << endl << "Title: " << book->getTitle() << endl << "Author: " << book->getAuthor() << endl << "Publisher: " << book->getPub() << endl << "Date Added: " << book->getDateAdded() << endl << "Quantity-On Hand: " << book->getQty() << endl << fixed << setprecision(2) <<
  //  "Wholesale Cost: " << book->getWholesale() << endl << "Retail Price: " << book->getRetail() << endl;
}

istream& operator>> (istream& isObject, bookType& book)
{
    string t = "EMPTY";
    string i = "EMPTY";
    string a = "EMPTY";
    string* p = new string("EMPTY");
    string d = "EMPTY";
    int q = 0;
    double w = 0.00;
    double r = 0.00;
    char choice;
    cout << "Add Book:" << endl;
    cout << "current book count :" << endl;//bookCount << endl;
    cout << "<1> Enter Title: " << t << endl;
    cout << "<2> Enter ISBN: " << i << endl;
    cout << "<3> Enter Author:" << a << endl;
    cout << "<4> Enter Publisher: " << *p << endl;
    cout << "<5> Enter Date: " << d << endl;
    cout << "<6> Enter Quantity:" << q << endl;
    cout << "<7> Enter Wholesale:" << w << endl;
    cout << "<8> Enter Retail:" << r << endl;
    cout << "<9> Save Book to Database" << endl;
    cout << "<0> Return to Inventory Menu" << endl;
    isObject >> book.bookTitle;
    isObject >> book.isbn;
    isObject >> book.author;
    isObject >> book.publisher;
    isObject >> book.date;
    isObject >> book.qty;
    isObject >> book.wholesale;
    isObject >> book.retail;
    return isObject;
}