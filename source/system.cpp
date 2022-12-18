#include "../headers/system.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

System::System() {
	users_number = books_number = len=0;
	System::books_index.clear();
}

int System::number_of_users() {
	return liberary_DB.Books_database.size();
}

int System::number_of_books() {
	return liberary_DB.Users_database.size();
}

bool System::has_prefix(std::string prefix, std::string name) {
	if (prefix.size()>name.size()) return false;
	else {
		for (int i = 0; i<prefix.size(); i++)
			if (name[i] != prefix[i]) return false;
	}
	return true;
}

void System::add_book() {
	Book b;
	cout << "Enter:\n";
	cout << "Book Id:";   cin >> b.id;
	cout << "Book Name:";  cin >> b.name;
	cout << "Book quantity:"; cin >> b.quantity;
	System::liberary_DB.Books_database.push_back(b);
	pair<int,pair<int,string>> temp=make_pair(len++,make_pair(b.id,b.name));
	System::books_index.push_back(temp);	 
}

void System::search_book_by_prefix() {
	string prefix;
	cout << "Enter the prifex: ";
	cin >> prefix;
	bool flag = false;
	int siz = System::number_of_books();   //number of the books in the sys

	for (int i = 0; i<siz; i++) {
		if (has_prefix(prefix, liberary_DB.Books_database[i].name)) {
			flag = true;
			cout << liberary_DB.Books_database[i].name << "\t";
		}
		cout<<'\n';
	}
	if (!flag)
		cout << "Sorry,there is not book with that prefix.\n";

}

void System::print_who_borrowed_book_by_name() {
	std::string book_name;
	bool flag = false;            //to check if the sys contain this book or not
	int siz = liberary_DB.Books_database.size();
	int i, j;

	cout << "Enter Book Name: "; cin >> book_name;
	for (i = 0; i<siz; i++) {
		if (liberary_DB.Books_database[i].name == book_name) {
			int number_of_users = liberary_DB.Books_database[i].names_of_book_users.size();
			if (number_of_users)      flag = true;
			auto it = liberary_DB.Books_database[i].names_of_book_users.begin();
			auto en = liberary_DB.Books_database[i].names_of_book_users.end();
			for (it; it != en; it++)
				cout << *it << " ";
			cout << "\n";
			i = siz;//means that i printed all the users of the book and no need to compleat the search

		}
	}
	if (!flag)  cout << "sorry, The book name is not correct.\n";
}

bool System::ID(pair<int,pair<int,string>>& p1, pair<int,pair<int,string>>& p2){
		return (p1.second.first < p2.second.first);
}
bool System::Name(pair<int,pair<int,string>>& p1, pair<int,pair<int,string>>& p2){
		return (p1.second.second < p2.second.second);
}


void System::print_library_by_id() {
	sort(books_index.begin(), books_index.end(),ID );
	print_books();
}

void System::print_library_by_name() {
	sort(books_index.begin(), books_index.end(), Name);
	print_books();
}

void System::print_books() {
	int siz = liberary_DB.Books_database.size();
	 
	for (int i = 0; i<siz; i++) {				     //index
		cout <<"ID: "<< liberary_DB.Books_database[books_index[i].first].id << "\t  ";
		cout <<"Name: "<< liberary_DB.Books_database[books_index[i].first].name << "\t   ";
		cout <<"Quantity: "<< liberary_DB.Books_database[books_index[i].first].quantity << "\t   ";
		cout <<"Borrowed Books: "<<liberary_DB.Books_database[books_index[i].first].borrowed_books << "\n";
	}
}

void System::add_user() {
	User u;
	cout << "UserName: "; cin >> u.name;
	cout << "UserID: ";  cin >> u.id;

	liberary_DB.Users_database.push_back(u);
}

void System::collect_these_data(std::string &u_name, std::string &b_name, bool &the_book_exist, bool &the_user_exist, int &user_indx, int &book_indx) {
	int books_siz = number_of_books();
	int users_siz = number_of_users();

	cout << "Enter User name: "; cin >> u_name;
	cout << "Enter Book name: "; cin >> b_name;



	for (int i = 0; i<books_siz; i++)
		if (liberary_DB.Books_database[i].name == b_name) {
			the_book_exist = true;
			book_indx = i;
			i = books_siz;
		}

	for (int j = 0; j<users_siz; j++)
		if (liberary_DB.Users_database[j].name == u_name)
		{
			the_user_exist = true;
			user_indx = j;
			j = users_siz;
		}
}
					 
void System::user_borrow_book() {
	string u_name, b_name;
	int book_indx, user_indx;
	bool the_user_exist = false, the_book_exist = false;

	collect_these_data( u_name, b_name,  the_book_exist, the_user_exist,  user_indx,  book_indx);

	if (the_book_exist && the_user_exist) {
		if (liberary_DB.Books_database[book_indx].quantity>liberary_DB.Books_database[book_indx].borrowed_books)
		{
			liberary_DB.Books_database[book_indx].names_of_book_users.insert(u_name);
			liberary_DB.Books_database[book_indx].borrowed_books++;
			cout << "User Borrowed the book successfully:)\n";
		}
		else {
			cout << "Sorry,ther is no avilable copies:)\n";
		}
	}
	else {
		cout << "The Username or the book name are wrong:(\n";
	}

}

void System::user_return_book() {
	string u_name, b_name;
	int book_indx, user_indx;
	bool the_user_exist = false, the_book_exist = false;

	collect_these_data( u_name, b_name,  the_book_exist, the_user_exist,  user_indx,  book_indx);
	if (the_book_exist&& the_user_exist) {
		liberary_DB.Books_database[book_indx].borrowed_books--;
		liberary_DB.Books_database[book_indx].names_of_book_users.erase(u_name);

		cout<<"Urer return the book successfully:)\n";

	}
	else {
		cout << "There is a problem with Username or Book Name:(,try again\n";
	}
}

void System::print_users() {
	int siz = number_of_users();
	if (siz)
		cout << "ID   \t|" << "Name\n";
	for (int i = 0; i<liberary_DB.Users_database.size(); i++)
		cout << liberary_DB.Users_database[i].id << "   \t|" << liberary_DB.Users_database[i].name << '\n';
}

void System::menu() {
	cout << "Library Menu:\n";
	cout << "\t1]add_book\n";
	cout << "\t2]search_book_by_prefix\n";
	cout << "\t3]print_who_borrowed_book_by_name\n";
	cout << "\t4]print_liberary_by_id\n";
	cout << "\t5]print_liberary_by_name\n";
	cout << "\t6]add_user\n";
	cout << "\t7]user_borrow_book\n";
	cout << "\t8]user_return_book\n";
	cout << "\t9]print_users\n";
	cout << "\t10]Exit\n";
	cout << "Your Choice: ";
}

int System::choice()
{
	int c = -1;
	while (c == -1) {
		menu();
		cin >> c;
		if (!(c >= 1 && c <= 10)) {
			c = -1;// to keep loop until read valid choice 
			cout << "Wrong anser ,Try again\n";
		}
	}
	return c;
 
}

void System::run() {
	bool flag = true;
	int c;
	while (flag) {
		c = choice();
		switch (c)
		{
			case 1: {
				add_book();
				cout << "Book added successfully:)\n";
				break;
			}
			case 2: {
				search_book_by_prefix();
				break;
			}
			case 3: {
				print_who_borrowed_book_by_name();
				break;
			}
			case 4:
			{
				print_library_by_id();
				break;
			}
			case 5:
			{
				print_library_by_name();
				 break;
			}
			case 6:
			{
				add_user(); 
				cout<<"User addes successfully:)\n";
				 break;
			}
			case 7:
			{
				user_borrow_book(); break;
			}
			case 8: {
				user_return_book();  break;
			}
			case 9:
			{
				print_users(); break;
			}
			case 10: {
				flag = false;
			}
			default:
				break;
		}
		cout << "\t\t==================================\n";
	}
}
