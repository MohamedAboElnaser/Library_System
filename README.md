# Description 
this project is implementation of [these](https://drive.google.com/drive/folders/1da0eFTms_1pLt35O0JCYx1zZjO1x4ObT?usp=sharing) requirements

- It is a simple console Library System that contains 10 main options :
   
   - [Add Book](#add-book)
   - [Search Book By Prefix](#search-book-by-prefix)
   - [Print Who Borrowed Book By Name](#print-who-borrowed-book-by-name)
   - [Pring Library By ID](#print-library-by-id)
   - [Pring Library By Name](#print-library-by-name)
   - [Add User](#add-user)
   - [User Borrow Book](#user-borrow)
   - [User Return Book](#use-return-book)
   - [Print Users](#print-the-users)
   - Exit

<hr>

- the system consist of main class ***System*** that consist of 

    - object of ***Database*** Class as a member variable
    - vector of pair that map between the book index in database and its data
    - The main needed member functions

<hr>

# ***Classes***

## DataBase Class
- consists of 
  1. Vector of User Class
  2. Vector of Book Class
   
## User Class
 - It contains all The user data
    - ID
    - Name

## Book Class
- It contains The data of each book in the system
  - ID
  - Name
  - Quantity
  - Number of Borrowed Copies
  - Set of Users Who borrowed the book

# ***Functions***

## Add Book
- Ask the admin to enter book Data and save it in the Database
<hr>

## Search Book By Prefix

- Take a prefix form the user search books database if it contains book with this prefix
<hr>

## Print Who Borrowed Book By Name
- take book name search the database for that book and print all the users who borrowed that book.

<hr>

## Print Library By ID
- these function sort the database of the books in ascending order according to Ids
<hr>

## Print Library By Name
- these function sort the database of the books in ascending order according to Names

<hr>

## Add User
- Insert User to Users Database in the system

<hr>

## User Borrow Book
- add these user to the set of that book and decrease the available copies
<hr>

## Use Return Book 
  - Remove the user name from the set of users of that book and encrease tha available copies by one.

<hr>

## Print The Users
- Show all the Users recorded in the Database system 


# How to Compile
- go to the directory of source 
- type this command in the CLI    
  -       g++ *.cpp -o Library_System 