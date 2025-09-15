#include "Library.h"
#include <fstream>   
#include <sstream>   
#include <limits>    

// cons and des
Library::Library() {
    loadBooks();
    loadMembers();
    std::cout << "Du lieu da duoc tai len tu file.\n";
}

Library::~Library() {
    saveBooks();
    saveMembers();
    std::cout << "Du lieu da duoc luu vao file.\n";
}

void Library::loadBooks() {
    std::ifstream file(booksFile);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string part;
        
        std::getline(ss, part, ',');
        int id = std::stoi(part); 

        std::getline(ss, part, ',');
        std::string title = part;

        std::getline(ss, part, ',');
        std::string author = part;

        std::getline(ss, part, ',');
        bool isBorrowed = (part == "1"); 

        books.emplace_back(id, title, author, isBorrowed);
    }
    file.close(); 
}

void Library::saveBooks() {
    std::ofstream file(booksFile);
    for (const auto& book : books) {
        file << book.toFileString() << std::endl;
    }
    file.close(); 
}

void Library::loadMembers() {
    std::ifstream file(membersFile);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string part;

        std::getline(ss, part, ',');
        int id = std::stoi(part);

        std::getline(ss, part, ',');
        std::string name = part;

        members.emplace_back(id, name);
    }
    file.close();
}

void Library::saveMembers() {
    std::ofstream file(membersFile);
    for (const auto& member : members) {
        file << member.toFileString() << std::endl;
    }
    file.close();
}

int Library::getNextBookId() {
    if (books.empty()) return 1;
    return books.back().getId() + 1;
}

int Library::getNextMemberId() { 
    if (members.empty()) return 1;
    return members.back().getId() + 1;
}


void Library::run() {
    int choice;
    do {
        std::cout << "\n=====================================\n";
        std::cout << "--- HE THONG QUAN LY THU VIEN ---\n";
        std::cout << "=====================================\n";
        std::cout << "1. Hien thi tat ca sach\n";
        std::cout << "2. Them sach moi\n";
        std::cout << "3. Muon sach\n";
        std::cout << "4. Tra sach\n";
        std::cout << "5. Hien thi tat ca thanh vien\n";
        std::cout << "6. Them thanh vien moi\n";
        std::cout << "0. Thoat chuong trinh\n";
        std::cout << "-------------------------------------\n";
        std::cout << "Lua chon cua ban: ";
        
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1; // assign invalid choice
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (choice) {
            case 1: { // display
                std::cout << "\n--- DANH SACH SACH ---\n";
                if (books.empty()) {
                    std::cout << "Thu vien chua co sach nao.\n";
                } else {
                    for (const auto& book : books) {
                        book.display();
                    }
                }
                break;
            }
            case 2: { // add
                std::string title, author;
                std::cout << "Nhap tieu de sach: ";
                std::getline(std::cin, title);
                std::cout << "Nhap tac gia: ";
                std::getline(std::cin, author);

                int newId = getNextBookId();
                books.emplace_back(newId, title, author);
                std::cout << "Them sach thanh cong!\n";
                break;
            }
            case 3: { // borrow
                int bookId;
                std::cout << "Nhap ID sach can muon: ";
                std::cin >> bookId;
                bool found = false;
                for (auto& book : books) {
                    if (book.getId() == bookId) {
                        found = true;
                        if (!book.getStatus()) { 
                            book.borrowBook();
                            std::cout << "Muon sach thanh cong!\n";
                        } else {
                            std::cout << "Sach nay da duoc muon!\n";
                        }
                        break; 
                    }
                }
                if (!found) std::cout << "Khong tim thay sach voi ID nay!\n";
                break;
            }
            case 4: { 
                int bookId;
                std::cout << "Nhap ID sach can tra: ";
                std::cin >> bookId;
                bool found = false;
                for (auto& book : books) {
                    if (book.getId() == bookId) {
                        found = true;
                        if (book.getStatus()) { 
                            book.returnBook();
                            std::cout << "Tra sach thanh cong!\n";
                        } else {
                            std::cout << "Sach nay dang co san trong thu vien, khong can tra!\n";
                        }
                        break;
                    }
                }
                if (!found) std::cout << "Khong tim thay sach voi ID nay!\n";
                break;
            }
            case 5: { 
                std::cout << "\n--- DANH SACH THANH VIEN ---\n";
                 if (members.empty()) {
                    std::cout << "Chua co thanh vien nao.\n";
                } else {
                    for (const auto& member : members) {
                        member.display();
                    }
                }
                break;
            }
            case 6: {
                std::string name;
                std::cout << "Nhap ten thanh vien moi: ";
                std::getline(std::cin, name);

                int newId = getNextMemberId();
                members.emplace_back(newId, name);
                std::cout << "Them thanh vien thanh cong!\n";
                break;
            }
            case 0:
                std::cout << "Thoat chuong trinh...\n";
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
        if (choice != 0) {
            std::cout << "\nNhan Enter de tiep tuc...";
            std::cin.get();
        }

    } while (choice != 0);
}