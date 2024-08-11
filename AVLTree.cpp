#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <queue>
#include <deque>
#include<algorithm>
// #include "header.h"

//creating struct for book and user
class Book{
    public:
    int id;
    string title;
    string author;
    int count;
    //default constructor
    Book(){
        this->id=0;
        this->title="";
        this->author="";
        this->count=0;
    }
    //parameterized constructor
    Book(int id ,string title, string author,int count){
        this->id=id;
        this->title=title;
        this->author=author;
        this->count=count;
    }
};
struct AVLNode {
    Book book;
    AVLNode *left;
    AVLNode *right;
    int height;
    
    AVLNode(Book book){
        this->book=book;
        this->left=NULL;
        this->right=NULL;
        this->height=1;
    }
};

AVLNode *globalroot=nullptr;
class AVLTree{
    private:
    //AVLNode* root;
        int height(AVLNode* node){
            return node ? node->height : 0;
        }
        int balancefactor(AVLNode *node){
            return node ? height(node->left)-height(node->right) : 0;
        }

        void updateheight(AVLNode* node){
            node->height=1+max(height(node->left),height(node->right));
        }
        AVLNode * lrotate(AVLNode* node){
            AVLNode *node_1=node->right;
            AVLNode *node_2=node_1->left;
            node_1->left=node;
            node->right=node_2;
            updateheight(node);
            updateheight(node_1);
            return node_1;
        }
        AVLNode * rrotate(AVLNode* node){
            AVLNode *node_1=node->left;
            AVLNode *node_2=node_1->right;
            node_1->right=node;
            node->left=node_2;
            updateheight(node);
            updateheight(node_1);
            return node_1;
        }
        AVLNode* balance(AVLNode* node){
            updateheight(node);
            if(balancefactor(node)>1){
                if(balancefactor(node->left)<0){
                    node->left=lrotate(node->left);
                }
                return rrotate(node);
            }
            if(balancefactor(node)<-1){
                if(balancefactor(node->left)>0){
                    node->right=lrotate(node->right);
                }
                return lrotate(node);
            }
            return node;
        }
        AVLNode* insert(AVLNode *node,Book book){
            //cout<<node<<" "<<book.title<<endl;
            if(node==NULL)
                return new AVLNode(book);

            if(book.id < node->book.id){
                 node->left=insert(node->left,book);
            }
            else if(book.id > node->book.id){
                 node->right=insert(node->right,book);
            }
            else 
                return node;
            return balance(node);
        }
        AVLNode* findmin(AVLNode *node){
            return node->left ? findmin(node->left) : node;
        }
        AVLNode * removemin(AVLNode *node){
            if(node->left==NULL)
                return node->right;
            node->left=removemin(node->left);
            return balance(node);
        }
        AVLNode *remove(AVLNode *node,int id){
            if(node==NULL)
                return NULL;
            if(node->book.id > id){
                remove(node->left,id);
            }
            if(node->book.id < id){
                remove(node->right,id);
            }
            if(node->book.id == id){
                AVLNode *left=node->left;
                AVLNode *right=node->right;
                delete node;
                if(right==NULL)
                    return left;
                AVLNode *min=findmin(right);
                min->left=left;
                min->right=removemin(right);
                return balance(min);
            }
            return balance(node);
        }
        AVLNode* search(AVLNode *node,int id){
            if(node==NULL){
                cout<<"AVL null"<<endl;
                return NULL;
            }
                
            if(node->book.id > id){
                return search(node->left,id);
            }
            if(node->book.id < id){
                return search(node->right,id);
            }
            if(node->book.id == id)
            {
                //cout<<"found avltree"<<endl;
                return node;
            }
            return NULL;
        }
        void inorder(AVLNode * node){
            while(node!=NULL){
                inorder(node->left);
                cout<<"id"<<node->book.id<<"\n"<<"title"<<node->book.title<<"\n"<<"author"<<node->book.author<<"\n"<<endl;
                inorder(node->right);
            }
        }
    public:
    AVLTree(){}
    AVLNode *root=NULL;
    AVLTree(AVLNode *root){
        root=NULL;
    }
    void insert_book(Book book){
        root=insert(root,book);
    }
    void remove(int id){
        root=remove(root,id);
    }
    Book *search(int id){
        cout<<"avl"<<endl;
        AVLNode *node=search(root,id);
        
       return node ? &node->book : NULL;
    }
    
};