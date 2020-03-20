#include <iostream>
#include <queue>


using namespace std;

enum COLOR {RED, BLACK};

class Node 
{

public:
    int val;
    COLOR color;
    Node *left, *right, *parent;
    
    Node(int val)   :   val(val)
    {
        parent = left = right = NULL;
        color = RED;
    }
    
    Node *uncle() 
    {
        if(parent == NULL or parent->parent == NULL)
            return NULL;
        
        if(parent->isOnLeaf())
            return parent->parent->right;
        else
            return parent->parent->left;
    }
    
    bool isOnLeaf() {   return this == parent->left;   }
    
    Node *sibling()
    {
        if(parent == NULL)
            return NULL;
        
        if(isOnLeaf())
            return parent->right;
        
        return parent->left;
    }
    
    void moveDown(Node *nParent) 
    {
        if(parent != NULL) {
            if(parent != NULL) {
                parent->left = nParent;
            } else {
                parent->right = nParent;
            }
        }
        nParent->parent = parent;
        parent = nParent;
    }
    
    bool hasRedChild() 
    {
        return  (left != NULL and left->color == RED) or 
                (right != NULL and right->color == RED);
    }
};


class RBTree 
{
    Node *root;
    
    void leftRotate(Node *x) 
    {
        Node *nParent = x->right;
        
        if(x == root)
            root = nParent;
        
        x->moveDown(nParent);
        x->right = nParent->left;
        
        if(nParent->left != NULL)
            nParent->left->parent = x;
        
        nParent->left = x;
    }
    
    void rightRotate(Node *x)
    {
        Node *nParent = x->left;
        
        if(x == root)
            root = nParent;
        
        x->moveDown(nParent);
        x->left = nParent->right;
        
        if(nParent->right != NULL)
            nParent->right->parent = x;
        
        nParent->right = x;
    }

    void swapColors(Node *x1, Node *x2) 
    {
        COLOR temp;
        
        temp = x1->color;
        x1->color = x2->color;
        x2->color = temp;
    }
    
    void swapValues(Node *u, Node *v) 
    {
        int temp;
        temp = u->val;
        u->val = v->val;
        v->val = temp;
    }
    
    void fixRedRed(Node *x) 
    {
        if(x == root)
        {
            x->color = BLACK;
            return;
        }
        
        Node *parent = x->parent, *grandparent = parent->parent,
                       *uncle = x->uncle();
                       
        if(parent->color != BLACK) {
            if(uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                fixRedRed(grandparent);
            } else {
                if(parent->isOnLeaf()) {
                    if(x->isOnLeaf()) {
                        swapColors(parent, grandparent);
                    } else {
                        leftRotate(grandparent);
                        swapColors(x, grandparent);
                    }
                } else {
                    if(x->isOnLeaf()) {
                        rightRotate(grandparent);
                        swapColors(x, grandparent);
                    } else {
                        swapColors(parent, grandparent);
                    }
                    leftRotate(grandparent);
                }
            }
        }
    }
    
    Node *successor(Node *x)
    {
        Node *temp = x;
        
        while(temp->left != NULL)
            temp = temp->left;
        
        return temp;
    }
    
    Node *BSTreplace(Node *x)
    {
        if(x->left != NULL and x->right != NULL)
            return successor(x->right);
        
        if(x->left == NULL and x->right == NULL)
            return NULL;
        
        if(x->left != NULL)
            return x->left;
        else 
            return x->right;
    }
};