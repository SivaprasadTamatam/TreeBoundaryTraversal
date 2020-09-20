//
//  main.cpp
//  Tree Boundary Traversal
//
//  Created by Sivaprasad Tamatam on 20/09/20.
//

#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    
    Node(int v):val(v),left(NULL), right(NULL){}
};

void PrintLeaves(Node* r){
    if( r != NULL){
        PrintLeaves(r->left);
        if( r->left == NULL && r->right == NULL)
            cout<<r->val<<"     ";
        PrintLeaves(r->right);
    }
}

void PrintBoundaryLeft(Node* r){
    if( r != NULL){
        if( r->left){
            cout<<r->val<<"     ";
            PrintBoundaryLeft(r->left);
        } else if(r->right){
            cout<<r->val<<"     ";
            PrintBoundaryLeft(r->right);
        }
    }
}

void PrintBoundaryRight(Node* r){
    if( r ){
        if( r->right){
            PrintBoundaryRight(r->right);
            cout<<r->val<<"     ";
        } else if(r->left){
            PrintBoundaryRight(r->left);
            cout<<r->val<<"     ";
        }
    }
}

int main(int argc, const char * argv[]) {
    Node* r = new Node(20);
    r->left = new Node(8);
    r->left->left = new Node(4);
    r->left->right = new Node(12);
    r->left->right->left = new Node(10);
    r->left->right->right = new Node(14);
    
    
    r->right = new Node(22);
    
    r->right->right = new Node(25);
    
    cout<<r->val<<"     ";
    
    PrintBoundaryLeft( r->left );
    PrintLeaves(r->left);
    PrintLeaves(r->right);
    PrintBoundaryRight(r->right);
    
    
    return 0;
}
