# LIBRARY - MANAGEMENT - SYSTEM

The Library Management System is  aimed at managing the records of books in a library. It includes functionalities such as adding new books, searching for books, and maintaining the  of books records.

## Features

- Add new books with details like title, author, ID, and count.
- Add new users with details like ID, name.
- Search for books by their ID.
- Delete book by their ID.
- Display book details.
- Display user details.
- Display borrowed books.

## Installation

To get started with the Library Management System, follow these steps:

1. **Clone the repository:**
    ```sh
    git clone https://github.com/your-username/library-management-system.git
    ```

2. **Navigate to the project directory:**
    ```sh
    cd library-management-system
    ```

3. **Compile the project:**
    ```sh
    g++ -o library_management_system main.cpp libraray.cpp -std=c++11
    ```

4. **Run the executable:**
    ```sh
    ./library_management_system
    ```



## Classes and Methods
### Linrary Class
- void initialize(): Initializes the library with some books.
- void initialize_1(): Initializes the library with some users.
- AVLNode* book_root(): Reads books from book_list.txt and builds the AVL tree.
- void addBook(int id, string title, string author, int count): Adds a new book.
- void removeBook(int id): Removes a book by ID.
- void searchBook(int id): Searches for a book by ID.
- void registerUser(int id, string name): Registers a new user.
- void borrowBook(int userId, int bookId): Borrows a book for a user.
- void returnBook(int userId, int bookId): Returns a borrowed book.
- void listAllBooks(): Lists all books.
- void listAllUsers(): Lists all users.
- void listAllBorrowedBooks(): Lists all borrowed books.

### AVLTree Class
- void insert_book(int id, string title, string author, int count): Inserts a new book into the AVL tree.
- void remove(int id): Removes a book from the AVL tree.
- AVLNode* search(int id): Searches for a book in the AVL tree.
  
### AVLUserTree Class
- void insert(int id, string name): Inserts a new user into the AVL tree.
- void remove(int id): Removes a user from the AVL tree.
- User* search(int id): Searches for a user in the AVL tree.

