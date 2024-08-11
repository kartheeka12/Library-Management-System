// #ifndef HEADER_H
// #define HEADER_H
#pragma once
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <queue>
#include<algorithm>
#include<string>

class Book{
    public:
    int id;
    string title;
    string author;
    bool issued;
    Book();
    Book(int id,string title,string author,bool issued);
};
struct User{
    int id;
    string name;
    User();
    User(int id,string name);
};
struct AVLNode{
    Book book;
    AVLNode *left;
    AVLNode *right;
    int height;
    AVLNode(Book book);
};
class AVLTree{
    private:
    AVLNode *root;
    int height(AVLNode *node);
    int balancefactor(AVLNode *node);
    void updateheight(AVLNode* node);
    AVLNode * lrotate(AVLNode* node);
    AVLNode * rrotate(AVLNode* node);
    AVLNode* balance(AVLNode* node);
    AVLNode* insert(AVLNode *node,Book book);
    AVLNode* findmin(AVLNode *node);
    AVLNode * removemin(AVLNode *node);
    AVLNode *remove(AVLNode *node,int id);
    AVLNode *search(AVLNode *node,int id);
    void inorder(AVLNode * node);
    public:
    AVLTree();
    AVLTree(AVLNode *root);
    void insert(Book book);
    void remove(int id);
    Book *search(int id);
    void listAllBooks();

};
class library{
    private:  
    unordered_map<int,string> users;
    unordered_map<int,queue<int> > waitigList;
    public:
    library();
    AVLTree bookTree;
    
    void addBook(int id,string title,string author,bool issued);
    void removeBook(int id);
    void searchBook(int id);
    void registerUser(int id,string name);
    void borrowBook(int userId,int bookId);
    void returnBook(int userId, int bookId);
    void listAllUsers();
    void listAllBooks();

};
// class info{
//     private:
//     unordered_map<int,queue<int> > books_issued;
//     unordered_map<int , string> issued_date;
//     public:
//     void issue_book(int student_id, int book_id);
//     bool has_book(queue <int>& q,int book_id);
//     void remove_from_queue(queue <int> &q,int book_id);
//     void return_book(int student_id, int book_id);
//     void display_books_issued(int student_id);
// };