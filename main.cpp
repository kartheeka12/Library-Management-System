#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <queue>
#include <algorithm>
#include "libraray.cpp"
//#include "header.h"


int main() {
    library l;
    l.user_root();
    l.book_root() ;
    while(true){
        cout<<endl;
    cout<<"   *****  PRESS NUMBER ACOORDING TO YOUR REQUIREMENTS   *****"<<endl;
    cout<<endl;
    cout<<"          ENTER 1 TO REGISTER USER "<<endl;
    cout<<"          ENTER 2 TO  ADD BOOK"<<endl;
    cout<<"          ENTER 3 TO REMOVE BOOK "<<endl;
    cout<<"          ENTER 4 TO SEARCH BOOK "<<endl;
    cout<<"          ENTER 11 TO SEARCH USER "<<endl;
    cout<<"          ENTER 5 TO BORROW BOOK "<<endl;
    cout<<"          ENTER 6 TO RETURN BOOK "<<endl;
    cout<<"          ENTER 7 TO LIST ALL USERS "<<endl;
    cout<<"          ENTER 8 TO LIST ALL BOOKS "<<endl;
    cout<<"          ENTER 9 TO LIST ALL BORROWED BOOKS "<<endl;
    cout<<"          ENTER 10 TO EXIT "<<endl;
    int x;
    cout<<"Enter your requirment : ";
    cin>>x;
    switch (x)
    {
    case 1: {
        int id;
        cout<<"Enter your uder id : ";
        cin>>id;
        string name;
        cout<<"Enter your name : ";
        cin>>name;
        l.registerUser(id,name);
        break;
    }
        
    case 2:{
        int id;
        cout<<"Enter book id : ";
        cin>>id;
        cin.ignore();
        string title;
        cout<<"Enter book title : ";
        getline(cin,title);
        string author;
        cout<<"Enter book author : ";
        getline(cin,author);
        int copies;
        cout<<"Enter number of copies : ";
        cin>>copies;
        cout<<id<<title<<author<<copies<<endl;
        l.addBook(id,title,author,copies);
        
        break;
    }
    case 3:{
        int id;
        cout<<"Enter book id : ";
        cin>>id;
        l.removeBook(id);
        break;
    }
    case 4:{
        int id;
        cout<<"Enter book id that you want to search : ";
        cin>>id;
        l.searchBook(id);
        break;
    }
    case 5:{
        int id;
        cout<<"Enter user id that you want to search : ";
        cin>>id;
        l.searchUser
        (id);
        break;
    }
    case 6:{
        int bookId, userId;
        cout<<"Enter user id : ";
        cin>>userId;
        cout<<"Enter book id : ";
        cin>>bookId;
        l.borrowBook(userId,bookId);
        break;
    }
    case 7:{
        int userId, bookId;
        cout<<"Enter user id : ";
        cin>>userId;
        cout<<"Enter book id : ";
        cin>>bookId;
        l.returnBook(userId,bookId);
        break;
    }
    case 8:{
        l.listAllUsers();
        break;
    }
    case 9:{
        l.listAllBooks();
        break;
    }
    case 10:{
        l.listAllBorrowedBooks();
        break;
    }
    case 11:
    {
        exit(0);
    }
    default:
        break;
    }
    }   
    
    
}
