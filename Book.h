#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {

    // Defining variable that describe the Book class
private:
    string _title;
    string _author;
    int _pages;
    double _cost;

public:
    Book();
    Book(string title, string author, int page, double cost);

    // GETTERS
    string getTitle();
    string getAuthor();
    int getPage();
    double getCost();

    // SETTERS
    void setTitle(string title);
    void setAuthor(string author);
    void setPage(int page);
    void setCost(double cost);
};

#endif