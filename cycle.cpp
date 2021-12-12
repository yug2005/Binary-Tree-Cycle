#include <iostream>
using namespace std;

#include "Node.h"

// Parent Node Implementation : Time Complexity O(n)
bool isCycle(Node *root)
{
    if (!root) return false;
    // if we are in a node with no parent, that must mean we are in the root node
    if (!root->parent)
    {
        // give the root node a temporary parent
        root->parent = new Node; 
        // recursively call the function 
        bool temp = isCycle(root->left) || isCycle(root->right); 
        // deleting all parent pointers before returning
        Node* c = root;
        while (c)
        {
            if (c->left && c->left->parent == c) c = c->left; 
            else if (c->right && c->right->parent == c) c = c->right; 
            else if (c == root) break; 
            else {
                Node* currentParent = c->parent; 
                c = c->parent; 
                currentParent = nullptr; 
                delete currentParent; 
            }
        }
        return temp;
    }
    if (root->left)
    {
        // parent does not exist so initialize to the current node
        if (!root->left->parent) root->left->parent = root; 
        // parent already exists so there is a cycle
        else return true;
    }
    if (root->right)
    {
        // parent does not exist so intialize to the current node
        if (!root->right->parent) root->right->parent = root;
        // parent already exists so there is a cycle
        else return true;
    }
    return isCycle(root->left) || isCycle(root->right);
}

int main()
{
    // creating a test binary tree
    Node *root = new Node(1);
    Node* node1 = root;

    Node* node2 = new Node(2);
    root->left = node2;

    Node* node3 = new Node(3);
    root->right = node3;

    Node* node4 = new Node(4);
    node2->left = node4;

    Node* node5 = new Node(5);
    node2->right = node5;

    Node* node6 = new Node(6);
    node3->right = node6;

    // printing the tree in preorder
    root->printPreOrder(); 

    cout << boolalpha << isCycle(root) << endl;

    // creating a cycle in the binary tree
    node3->left = node5; 

    root->printPreOrder(); 

    cout << boolalpha << isCycle(root) << endl;

    root->printPreOrder(); 

    // changing the binary tree
    node5->right = node2; 
    node5->left = node4; 
    node1->left = node5; 

    cout << boolalpha << isCycle(root) << endl;

    return 0;
}

// Visited Nodes list implementation : Time Complexity O(n^2)
/*
bool isCycle(Node* root){
    if (!root) {return false;}
    // deleting the list of visisted nodes
    if (!root->visitedNodes){
        root->visitedNodes = new Node(root->data);

        bool hasCycle = isCycle(root->left) || isCycle(root->right);

        // deleting the linked list
        while (root->visitedNodes){
            Node* temp = root->visitedNodes;
            root->visitedNodes = root->visitedNodes->right;
            delete temp;
        }

        return hasCycle;
    }
    else {
        if ((root->right && root->right->data == root->visitedNodes->data) ||
        (root->left && root->left->data == root->visitedNodes->data))
            return true;
        Node* c = root->visitedNodes;
        // searching the list for the new
        while (c->right){
            if (c->data == root->data){
                return true;
            }
            c = c->right;
        }
        c->right = new Node(root->data);
        return isCycle(root->left) || isCycle(root->right);
    }
}
*/