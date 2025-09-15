#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    const std::string booksFile = "books.txt";
    const std::string membersFile = "members.txt";

    void loadBooks();
    void saveBooks();
    void loadMembers();
    void saveMembers();
    int getNextBookId();
    int getNextMemberId();

public:
    Library();  
    ~Library(); 

    void run(); 
};

#endif
