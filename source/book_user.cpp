#include "../headers/book_user.h"

Book::Book(int id, std::string name, int quantity) :id(id), name(name), quantity(quantity), borrowed_books(0) {
}

Book::Book() {
	id = 0;
	name = "";
	quantity = borrowed_books = 0;
}

User::User() {
	id = 0;
	name = "";
}
User::User(int id, std::string name) :id(id), name(name) {

}