#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <queue>
#include <deque>
#include<algorithm>

struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

//creating struct for book and user

class User{
    public:
    int id;
    string name;
    Node *next;
    
    //default constructor
    User(){
        this->id=0;
        this->name="";
        this->next=NULL;
    }
    //parameterized constructor
    User(int id ,string name,Node *next){
        this->id=id;
        this->name=name;
        this->next=next;
    }
    void add_userbook(int book_id){
            Node *newnode=new Node(book_id);
            newnode->next=next;
            next=newnode;
        }
};
struct AVLUserNode {
    User user;
    AVLUserNode *left;
    AVLUserNode *right;
    int height;
    
    AVLUserNode(User user){
        this->user=user;
        this->left=NULL;
        this->right=NULL;
        this->height=1;
    }
};
AVLUserNode *userglobalroot=nullptr;
class AVLUserTree{
    private:
    //AVLNode* root;
        int height(AVLUserNode* node){
            return node ? node->height : 0;
        }
        int balancefactor(AVLUserNode *node){
            return node ? height(node->left)-height(node->right) : 0;
        }

        void updateheight(AVLUserNode* node){
            node->height=1+max(height(node->left),height(node->right));
        }
        AVLUserNode * lrotate(AVLUserNode* node){
            AVLUserNode *node_1=node->right;
            AVLUserNode *node_2=node_1->left;
            node_1->left=node;
            node->right=node_2;
            updateheight(node);
            updateheight(node_1);
            return node_1;
        }
        AVLUserNode * rrotate(AVLUserNode* node){
            AVLUserNode *node_1=node->left;
            AVLUserNode *node_2=node_1->right;
            node_1->right=node;
            node->left=node_2;
            updateheight(node);
            updateheight(node_1);
            return node_1;
        }
        AVLUserNode* balance(AVLUserNode* node){
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
        AVLUserNode* insert(AVLUserNode *node,User user){
            //cout<<node<<" "<<book.title<<endl;
            if(node==NULL)
                return new AVLUserNode(user);

            if(user.id < node->user.id){
                 node->left=insert(node->left,user);
            }
            else if(user.id > node->user.id){
                 node->right=insert(node->right,user);
            }
            else 
                return node;
            return balance(node);
        }
        

        AVLUserNode* findmin(AVLUserNode *node){
            return node->left ? findmin(node->left) : node;
        }
        AVLUserNode * removemin(AVLUserNode *node){
            if(node->left==NULL)
                return node->right;
            node->left=removemin(node->left);
            return balance(node);
        }
        AVLUserNode *remove(AVLUserNode *node,int id){
            if(node==NULL)
                return NULL;
            if(node->user.id > id){
                node->left=remove(node->left,id);
            }
            if(node->user.id < id){
                node->right=remove(node->right,id);
            }
            if(node->user.id == id){
                AVLUserNode *left=node->left;
                AVLUserNode *right=node->right;
                delete node;
                if(right==NULL)
                    return left;
                AVLUserNode *min=findmin(right);
                min->left=left;
                min->right=removemin(right);
                return balance(min);
            }
            return balance(node);
        }
        AVLUserNode* search(AVLUserNode *node,int id){
            if(node==NULL){
                cout<<node->user.id<<endl;
                return NULL;
            }
                
            if(node->user.id > id){
                return search(node->left,id);
            }
            if(node->user.id < id){
                return search(node->right,id);
            }
            if(node->user.id == id)
            {
                return node;
            }
            return NULL;
        }
        
        // void inorder(AVLUserNode * node){
        //     while(node!=NULL){
        //         inorder(node->left);
        //         cout<<"id"<<node->user.id<<"\n"<<"name"<<node->user.name<<"\n"<<"\n"<<endl;
        //         inorder(node->right);
        //     }
        // }
    public:
    AVLUserTree(){}
    AVLUserNode *root=nullptr;
    AVLUserTree(AVLUserNode *root){
        this->root=NULL;
    }
    void insert(User user){
        root=insert(root,user);
    }
    void remove(int id){
        root=remove(root,id);
    }
    User *search(int id){
        AVLUserNode *node=search(root,id);
       return node ? &node->user : NULL;
    }
    void addlinkedlist(int user_id,int book_id){
            User *user=search(user_id);
            if(user){
                user->add_userbook(book_id);
            }
            else{
                cout<<"User not found"<<endl;
            }
        }
    // void listAllUsers(){
    //     inorder(root);
    // }
};