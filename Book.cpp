#include "Book.h"

Book::Book(int id, std::string title, std::string author, bool isBorrowed) {
    this->id = id;
    this->title = title;
    this->author = author;
    this->isBorrowed = isBorrowed;
}

int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
bool Book::getStatus() const { return isBorrowed; }
std::string Book::getStatusString() const {
    return isBorrowed ? "Da muon" : "Co san";
}

void Book::borrowBook() { isBorrowed = true; }
void Book::returnBook() { isBorrowed = false; }

void Book::display() const {
    std::cout << "ID: " << id << "\t| Tieu de: " << title
              << "\t| Tac gia: " << author
              << "\t| Trang thai: " << getStatusString() << std::endl;
}

std::string Book::toFileString() const {
    return std::to_string(id) + "," + title + "," + author + "," + std::to_string(isBorrowed);
}
