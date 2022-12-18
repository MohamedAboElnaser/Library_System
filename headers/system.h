#ifndef SYSTEM
#define SYSTEM
#include "../headers/database.h"
#include <iostream>
#include <vector>
using namespace std;
class System {
private:
	DataBase liberary_DB;
		      // idx      id   name
	vector<pair<int,pair<int,string>>> books_index ;  //instead of sorting all library database just sort indexes
	int len=0  ; // for indxing in books_index vector      
	int books_number;
	int users_number;
	void menu();
	int  choice();
	void add_book();
	void search_book_by_prefix();
	void print_who_borrowed_book_by_name();
	void print_library_by_id();
	void print_library_by_name();
	void add_user();
	void user_borrow_book();
	void user_return_book();
	void print_users();
	void print_books();
	bool has_prefix(std::string prefix, std::string name);
	static bool ID(pair<int,pair<int,string>>& p1, pair<int,pair<int,string>>& p2);
	static bool Name(pair<int,pair<int,string>>& p1, pair<int,pair<int,string>>& p2);
	void collect_these_data(std::string &u_name, std::string &b_name, bool &book_exist, bool &user_exist, int &u_index, int &b_index);
	int number_of_users();
	int number_of_books();

public:
	void run();
	System();
	
};


#endif