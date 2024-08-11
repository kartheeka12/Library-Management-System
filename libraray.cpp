#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <queue>
#include<algorithm>
#include "AVLTree.cpp"
#include "AVLUserTree.cpp"
//#include "header.h"

extern AVLNode* globalroot;
extern AVLUserNode* userglobalroot;
class library{
        
        public:
        library(){ }
        AVLTree bookTree;
        AVLUserTree userTree;
        void initialize(){
            FILE *book_txt=fopen("book_list.txt","a");
            if(book_txt==NULL){
                cout<<"text file is not created"<<endl;
            }
            else{
                fprintf(book_txt,"id : %d , title : %s , author : %s , count : %d \n",123,"Untouchable","Mulk Raj Anand",25);
                fprintf(book_txt,"id : %d , title : %s , author : %s , count : %d \n",125,"Train to pakistan","Khushwant singh",35);
                fprintf(book_txt,"id : %d , title : %s , author : %s , count : %d \n",128,"Godan","Munshi premchand",15);
                fprintf(book_txt,"id : %d , title : %s , author : %s , count : %d \n",130,"The complete adventures of feluda","Satyajit Ray");
            }
            fclose(book_txt);
        }
        void initialize_1(){
            FILE *user_txt=fopen("user_list.txt","a");
            if(user_txt==NULL){
                cout<<"text file is not created"<<endl;
            }
            else{
                fprintf(user_txt,"id : %d , name : %s \n",125453,"Kartheeka");
                fprintf(user_txt,"id : %d , name : %s \n",124555,"Devmani");
                fprintf(user_txt,"id : %d , name : %s \n",123238,"Sathvika");
                fprintf(user_txt,"id : %d , name : %s \n",136570,"Deekshitha");
            }
            fclose(user_txt);
        }
        
AVLNode* book_root() {
    FILE* fp = fopen("book_list.txt", "r");
    if (fp == NULL) {
        cout << "File not found" << endl;
        return nullptr;
    }
    char* tokenn;
    char title[50];
    char author[50];
    int id;
    int count;
    char delim[2]=",";

     char str[150];
    while (fgets(str, sizeof(str), fp) != NULL) {
         tokenn = strtok(str, delim);
        if (tokenn != NULL) {
            tokenn += 5; // Move the pointer to the start of the number
             id = atoi(tokenn);
        }
        tokenn=strtok(NULL, delim);
        if (tokenn != NULL) {
            tokenn += 9; // Move the pointer to the start of the number
             strcpy(title, tokenn);
        }
        tokenn=strtok(NULL, delim);
        if (tokenn != NULL) {
            tokenn += 10; // Move the pointer to the start of the number
             strcpy(author, tokenn);
        }
        tokenn=strtok(NULL, delim);
        if (tokenn != NULL) {
            tokenn += 8; // Move the pointer to the start of the number
             count = atoi(tokenn);
        }
        bookTree.insert_book(Book(id, title, author, count));
    }
    fclose(fp);
    globalroot=bookTree.root;
    return globalroot;
}

AVLUserNode* user_root() {
    FILE* fp = fopen("user_list.txt", "r");
    if (fp == NULL) {
        cout << "File not found" << endl;
        return nullptr;
    }
    char* tokenn;
    int id;
    char name[50];
    char delim[2] = ",";

    char str[150];
    while (fgets(str, sizeof(str), fp) != NULL) {
        tokenn = strtok(str, delim);
        if (tokenn != NULL) {
            tokenn += 5; // Move the pointer to the start of the number
            id = atoi(tokenn);
        }
        tokenn = strtok(NULL, delim);
        if (tokenn != NULL) {
            tokenn += 8; // Move the pointer to the start of the name
            strcpy(name, tokenn);
        }
        
        userTree.insert(User(id, name, NULL));
    }

    fclose(fp);
    userglobalroot = userTree.root;
    return userTree.root;
}

        void addBook(int id,string title,string author,int count){
            cout<<"add book "<<title<<endl;
            bookTree.insert_book(Book(id,title,author,count));
            cout<<"Book added: "<<id<<endl;
            globalroot=bookTree.root;
            FILE *book_txt=fopen("book_list.txt","a");
            if(book_txt==NULL){
                cout<<"text file is not created"<<endl;
            }
            else{
                fprintf(book_txt,"id : %d , title : %s , author : %s , count : %d \n",id,title.c_str(),author.c_str(),count);
            }
            fclose(book_txt);
            
        }
        void removeBook(int id){
            Book *book=bookTree.search(id);
            if(book!=NULL){
                bookTree.remove(id);
            cout<<"Book removed: "<<id<<endl;
            FILE *fptr=fopen("book_list.txt","r");
            if(fptr==NULL){
                cout<<"File not found"<<endl;
            }
            else{
                FILE *fptr2;
                char ch;
                int line;
                int temp=1;
                cout<<"Enter the line number of the book in book_list file to remove fromt text file : "<<endl;
                cin>>line;
                fptr2=fopen("book_list_temp.txt","w");
                ch=fgetc(fptr);
                while(ch != EOF){
                    if(ch == '\n'){
                        temp++;
                    }
                    if(temp != line ){
                        fputc(ch,fptr2);
                    }
                }
                fclose(fptr);
                fclose(fptr2);
                rename("book_list_temp.txt","book_list.txt");
                cout<<"Removed from list of books"<<endl;
            }

            }
            else{
                cout<<"Book not found"<<endl;
            }
            

        }
        void searchBook(int id){
            cout<<"Searching books"<<endl;
            Book* book=bookTree.search(id);
            if(book==NULL){
                cout<<"Book not found"<<endl;
            }
            else{
                 cout<<"book found :ID : "<<id<<endl;
            }
        }
        void registerUser(int id,string name){
            cout<<"User registered: "<<name<<endl;
            userTree.insert(User(id, name, NULL));
            FILE *user_txt=fopen("user_list.txt","a");
            if(user_txt==NULL){
                cout<<"text file is not created"<<endl;
            }
            else{
                fprintf(user_txt,"id : %d , name : %s  \n",id,name.c_str());
            }
            fclose(user_txt);
        }

        bool searchUser(int id) {
        cout << "Searching Users" << endl;
        User* user = userTree.search(id); // Ensure this uses userglobalroot internally if needed
        if (user == NULL) {
        cout << "User not found" << endl;
        return false;
        } 
        else {
        cout << "User found: ID: " << id << endl;
        return true;
        }
}

    void borrowBook(int userId, int bookId) {
        //cout<<userglobalroot->user.id<<endl;
    User* user = userTree.search(userId); // Ensure this uses userglobalroot internally if needed
        if (user == NULL) {
        cout << "User not found" << endl;
        return ;
        }
    
    Book* book = bookTree.search(bookId);
    if (book == NULL) {
        cout << "Book not found" << endl;
        return;
    } 
    else if(!check_borrow( userId, bookId)) {
        cout << "Book id : "<<bookId<<" borrowed by user : " << userId << endl;
        userTree.addlinkedlist(userId, bookId);
        FILE *fp = fopen("books_borrowed.txt", "a");
        if (fp == NULL) {
            cout << "Books_issued text file is not created" << endl;
        } else {
            fprintf(fp, "User id: %d, Book id: %d\n", userId, bookId);
        }
        fclose(fp);
        return;
    }
    else{
        cout<<"Book id : "<<bookId<<" is already borrowed by this user."<<endl;
    }
}

         bool check_borrow(int userId,int bookId){
                User* user=userTree.search(userId);
                if(user!=NULL)
                {
                    Node *node=user->next;
                    while(node!=NULL){
                        if(node->data==bookId)
                            return true;
                        node=node->next;
                    }
                    return false;
                }
        return false;
        }


        void returnBook(int userId, int bookId){

            User * user=userTree.search(userId);
            if(user==nullptr){
                  cout<<"User not found"<<endl;
                  return;
            }
            Book * book=bookTree.search(bookId);
            if(book==NULL){
                cout<<"Book not found"<<endl;
                return;
            }
            else if(!check_borrow( userId, bookId)){
                
                    FILE *fptr=fopen("books_borrowed.txt","r");
                    if(fptr==NULL){
                        cout<<"Book borrowed file not found"<<endl;
                    }
                    else{
                        FILE *fptr2;
                        char ch;
                        int line;
                        int temp=1;
                        cout<<"Enter the line number of the book in books_borrowed file to remove fromt text file : "<<endl;
                        cin>>line;
                        fptr2=fopen("book_list_temp.txt","w");
                        ch=fgetc(fptr);
                        while(ch != EOF){
                            if(ch == '\n'){
                                temp++;
                            }
                            if(temp != line ){
                                fputc(ch,fptr2);
                            }
                        }
                        fclose(fptr);
                        fclose(fptr2);
                         rename("book_list_temp.txt","books_borrowed.txt");
                        cout<<"Book :"<<bookId<<"is returned by user id:"<<userId<<endl;
                        cout<<"Removed from list of borrowed books"<<endl;
                return;
            }
                   
                
            }
            else{
                cout<<"book is not borrowed by this user"<<endl;
             }
           
        }
        void listAllBooks(){
            cout<<"list of all books"<<endl;
             FILE *file = fopen("book_list.txt", "r");
            if(file!=NULL){
                char ch;
                ch=fgetc(file);
                while(ch != EOF){
                    cout<<ch;
                    ch=fgetc(file);
                }
            }
            else{
                cout<<"File not found"<<endl;
            }
        }
        void listAllUsers(){
            cout<<"List of all users"<<endl;  
            FILE *file = fopen("user_list.txt", "r");
            if(file!=NULL){
                char ch;
                ch=fgetc(file);
                while(ch != EOF){
                    cout<<ch;
                    ch=fgetc(file);
                }
            }
            else{
                cout<<"File not found"<<endl;
            }
        }
        void listAllBorrowedBooks(){
            cout<<"List of Borrowed books"<<endl;  
            FILE *file = fopen("books_borrowed.txt", "r");
            if(file!=NULL){
                char ch;
                ch=fgetc(file);
                while(ch != EOF){
                    cout<<ch;
                    ch=fgetc(file);
                }
            }
            else{
                cout<<"File not found"<<endl;
            }
        }
};