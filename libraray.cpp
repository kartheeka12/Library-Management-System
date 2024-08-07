#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <queue>
#include<algorithm>
#include "AVLTree.cpp"
//#include "header.h"

class library{
    private:
        unordered_map<int,string> users;
        unordered_map<int,queue<int> > waitigList;
        unordered_map<int,queue<int> > books_issued;
        unordered_map<int , string> issued_date;
        
        public:
        library(){}
        AVLTree bookTree;

    
    void issue_book(int student_id, int book_id){
        time_t now=time(0);
        char *dt=ctime(&now);
        books_issued[student_id].push(book_id);
        issued_date.insert({book_id,dt});
        
    }
    bool has_book(queue <int>& q,int book_id){
        queue <int> temp=q;
        while(!temp.empty()){
            if(temp.front()==book_id){
                return true;
            }
            temp.pop();
        }
        return false;
    }
    void remove_from_queue(queue <int> &q,int book_id){
        queue <int> dup;
        while(!q.empty()){
            if(q.front()!=book_id){
                dup.push(q.front());
            }
            q.pop();
        }
        q=dup;
    }
    void return_book(int student_id, int book_id){
        
        if( !books_issued[student_id].empty() ){
            auto it=books_issued.find(student_id);
            if(it!=books_issued.end()){
                bool found=has_book(it->second,book_id);
                if(found){
                    remove_from_queue(it->second,book_id);
                }
            }
        }
        auto it_1=issued_date.find(book_id);
        if(it_1!=issued_date.end()){
            issued_date.erase(it_1);
        }
    }
    void display_books_issued(int student_id){
        auto it=books_issued.find(student_id);
        if(it!=books_issued.end()){
            cout<<"Books issued to student : "<<student_id<<": ";
            while(!it->second.empty()){
                cout<<it->second.front()<<" ";
                it->second.pop();
            }
            cout<<endl;
        }else{
            cout<<"No books issued to student "<<student_id<<endl;
        }

    }


        void addBook(int id,string title,string author,int count){
            cout<<"add book "<<title<<endl;
            bookTree.insert(Book(id,title,author,count));
            cout<<"Book added: "<<id<<endl;
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
            bookTree.remove(id);
            cout<<"Book removed: "<<id<<endl;
            
        }
        void searchBook(int id){
            cout<<"Searching books"<<endl;
            Book* book=bookTree.search(id);
            if(book!=NULL){
                cout<<"book found :ID : "<<id<<endl;
            }
            else{
                cout<<"Book not found"<<endl;
            }
        }
        void registerUser(int id,string name){
            users.insert({id,name});
            cout<<"User registered: "<<name<<endl;
        }
        void borrowBook(int userId,int bookId){
            if(users.find(userId)==users.end()){
                cout<<"User not found"<<endl;
                return;
            }
            Book * book=bookTree.search(bookId);
            //cout<<book->count<<endl;
            if(book==nullptr){
                  cout<<"Book not found"<<endl;
                  return;
            }
            else if(book->count > 0){
                    book->count--;
                    cout<<"book borrowed by user "<<userId<<endl;
                    
                    issue_book(userId,  bookId);
                    return;
                
            }
            else{
                    cout<<"Book is already borrowed .Adding to waiting list"<<endl;
                waitigList[bookId].push(userId); 
                return;

                }
             return;  
        }

        bool check_borrow(int userId,int bookId){
            if( !books_issued[userId].empty() ){
            auto it=books_issued.find(userId);
            if(it!=books_issued.end()){
                bool found=has_book(it->second,bookId);
                if(found){
                    return true;
                }
            }
        }
        return false;
        }


        void returnBook(int userId, int bookId){
            if(users.find(userId)==users.end()){
                cout<<"User not found"<<endl;
                return;
            }
            Book * book=bookTree.search(bookId);
            if(book){
                if(check_borrow( userId, bookId)){
                    return_book(userId, bookId);
                    book->count++;
                    if(waitigList[bookId].empty()!=false){
                        int user_waiting=waitigList[bookId].front();
                        waitigList[bookId].pop();
                        borrowBook( user_waiting,bookId);
                    }
                }
                else{
                    cout<<"Book is not borrowed"<<endl;
                }
                cout<<"Book :"<<bookId<<"is returned by user id:"<<userId<<endl;
            }
            else{
                cout<<"Book not found"<<endl;
            }
        }
        void listAllBooks(){
            cout<<"list of all books"<<endl;
            bookTree.listAllBooks();
        }
        void listAllUsers(){
            cout<<"List of all users"<<endl;  
            for(auto x:users){
                cout<<"User id :"<<x.first<<" User name :"<<x.second<<endl;
            }
        }
};