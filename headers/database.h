#ifndef DATABASE
#define DATABASE
#include "book_user.h"
#include "vector"

class DataBase {
private:
	std::vector<Book> Books_database;
	std::vector<User> Users_database;
public:
	friend class System;

};

#endif