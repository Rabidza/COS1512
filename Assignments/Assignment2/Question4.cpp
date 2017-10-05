#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAX_NUM_BOOKS = 100; //This is the max amount of different books my bookstore can have duplicate copies are kept in the storeroom
const double DISCOUNT = 0.15; //Discount Percentage
const int QUALIFYINGAMOUNT = 20; //Amount of stock needed to qualify for the discount.

class Book
{
public:
    Book();
    //Initializes a book to an empty string for the title and author, zero for the price and stock

    ~Book();
    //Destructor

    Book(string bookTitle, string bookAuthor, double bookPrice, int Bookstock);
    //Initializes the book and sets the title, author, price and stock to
    //bookTitle, bookAuthor, bookPrice, BookStock.

    void setTitle(string bookTitle);
    //Postcondition: Sets the title of the book to bookTitle.

    void setAuthor(string bookAuthor);
    //Postcondition: Sets the author of the book to bookAuthor

    void setPrice(double bookPrice);
    //Postcondition: Sets the price of the book to bookPrice

    void setStock(int bookStock);
    //Postcondition: Sets the stock of the book to bookStock

    string getTitle();
    //returns the title of the book.

    string getAuthor();
    //returns the author of the book.

    double getPrice();
    //Returns the price of the book

    int getStock();
    //Returns the amount of books in stock.

    friend bool operator >(const Book& book, int amount);
    //Overloads the > operator to check whether the amount of stock of the book is more than an integer value specified

    friend bool operator ==(const Book& book1, const Book& book2);
    //Overloads the == operator so it can be used to check whether the title
    //of two books are the same.
    //returns true if the title of the two books are the same,
    //otherwise returns false.

    friend istream& operator >>(istream& ins, Book& theObject);
    //Overloads the >> operator so it can be used to input values of type Book.
    //Precondition: If ins is a file input stream, then ins has already
    //been connected to a file.

    friend ostream& operator <<(ostream& outs, const Book& theObject);
    //Overloads the << operator so it can be used to output values of type Book.
    //Precondition: If outs is a file output stream, then outs has already
    //been connected to a file.

private:
    string title, author;
    double price;
    int stock;
};

int main()
{
    Book books[MAX_NUM_BOOKS];
    int storeCount = 0; //number of unique books in store

    //Example information for 2 different kinds of books
    for (int i = 0; i < 2; i++)
    {
        cin >> books[i];
        storeCount += 1;
    }

    cout << "Books qualifying for discount: " << endl;
    //Check, display and apply discount to qualifying books
    for (int i = 0; i < storeCount; i++)
    {
        if (books[i] > QUALIFYINGAMOUNT)
        {

            cout << books[i];
            double currentPrice = books[i].getPrice();
            double newPrice = currentPrice - (currentPrice * DISCOUNT);
            books[i].setPrice(newPrice);
        }
    }

    cout << "After Discount has been applied: " << endl;
    for (int i = 0; i < storeCount; i++)
    {
        cout << books[i];
    }

    return 0;
}

Book::Book() : title(""), author(""), price(0), stock(0)
{
    //Intentionally left empty
}

Book::~Book()
{

}

Book::Book(string bookTitle, string bookAuthor, double bookPrice, int bookStock)
{
    title = bookTitle;
    author = bookAuthor;
    price = bookPrice;
    stock = bookStock;
}
void Book::setTitle(string bookTitle)
{
    title = bookTitle;
}

void Book::setAuthor(string bookAuthor)
{
    author = bookAuthor;
}

void Book::setPrice(double bookPrice)
{
    price = bookPrice;
}

void Book::setStock(int bookStock)
{
    stock = bookStock;
}

string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}

double Book::getPrice()
{
    return price;
}

int Book::getStock()
{
    return stock;
}

bool operator >(const Book& book, int amount)
{
    return book.stock > amount;
}

bool operator ==(const Book& book1, const Book& book2)
{
    return book1.title == book2.title;
}

istream& operator >>(istream& ins, Book& theObject)
{
    cout << "Enter the title of the book: ";
    getline(ins, theObject.title, '\n');
    cout << "Enter the author of the book: ";
    getline(ins, theObject.author, '\n');
    cout << "Enter the price of the book: R";
    cin >> theObject.price;
    cout << "Enter the amount of books bought: ";
    cin >> theObject.stock;
    cin.get();
    cout << endl;
}

ostream& operator <<(ostream& outs, const Book& theObject)
{
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "Title:\t" << theObject.title << endl;
    cout << "Author:\t" << theObject.author<< endl;
    cout << "Price:\tR" << theObject.price<< endl << endl;
}
