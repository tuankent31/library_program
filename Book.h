#ifndef BOOK_H // 
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    bool isBorrowed;

public:
    Book(int id, std::string title, std::string author, bool isBorrowed = false);



    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool getStatus() const;
    std::string getStatusString() const;

    void borrowBook();
    void returnBook();

    void display() const;

    std::string toFileString() const;
};

#endif 
