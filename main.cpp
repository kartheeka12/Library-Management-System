#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <queue>
#include <algorithm>
#include "libraray.cpp"



int main() {
    library l;

    //        l.addBook(1,"hi","hlow",10);
    // l.addBook(2,"hello","hlow_2",10);
    //   l.searchBook(1);
    // l.searchBook(4);
    //     l.registerUser(1,"user1");
    //  l.registerUser(2,"user2");
    //   l.borrowBook(4,1);
    //  l.removeBook(1);
    //  l.borrowBook(1,4);
    // l.borrowBook(1,1);
    // l.borrowBook(1,2);
    // l.returnBook(1,1);
    // l.listAllUsers();
    cout<<endl;
    cout<<"   *****  PRESS NUMBER ACOORDING TO YOUR REQUIREMENTS   *****"<<endl;
    cout<<endl;
    cout<<"          ENTER 1 TO REGISTER USER "<<endl;
    cout<<"          ENTER 2 TO  ADD BOOK"<<endl;
    cout<<"          ENTER 3 TO REMOVE BOOK "<<endl;
    cout<<"          ENTER 4 TO SEARCH BOOK "<<endl;
    cout<<"          ENTER 5 TO BORROW BOOK "<<endl;
    cout<<"          ENTER 6 TO RETURN BOOK "<<endl;
    cout<<"          ENTER 7 TO LIST ALL USERS "<<endl;
    cout<<"          ENTER 8 TO LIST ALL BOOKS "<<endl;
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
        //cin>>title;
        getline(cin,title);
        string author;
        cout<<"Enter book author : ";
        //cin>>author;
        getline(cin,author);
        int copies;
        cout<<"Enter number of copies : ";
        cin>>copies;
        //cout<<"book added id : "<<id<<endl;
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
    }
    case 5:{
        int id, userId;
        cout<<"Enter book id : ";
        cin>>id;
        cout<<"Enter user id : ";
        cin>>userId;
        l.borrowBook(id,userId);
        break;
    }
    case 6:{
        int id, userId;
        cout<<"Enter book id : ";
        cin>>id;
        cout<<"Enter user id : ";
        cin>>userId;
        l.returnBook(id,userId);
        break;
    }
    case 7:{
        l.listAllUsers();
        break;
    }
    case 8:{
        l.listAllBooks();
        break;
    }
    default:
        break;
    }
     }
