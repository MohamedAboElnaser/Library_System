#ifndef BOOK_USER
#define BOOK_USER
#include <iostream>
#include <set>

class Book{
private:
    int id;
    std::string name;
    int quantity;
    int borrowed_books;
    std::set<std::string>names_of_book_users;
public:
    Book(int id,std::string name,int quantity);
    Book();
    friend class System;
    
};

class User{
private:
    int id;
    std::string name;

public:
    User(int id,std::string name);
    User();
    friend class System;
};

#endif