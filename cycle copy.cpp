#include <iostream>
using namespace std;

#include "Node.h"

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

// bool isCycle(Node* root)
// {
//     if (!root) {return false;}
//     if (!root->parent){
//         if (root->left) root->parent = root->left;
//         else if (root->right) root->parent = root->right;
//         else return false;
//     }
//     // if both right and left point to the same node
//     if (root->right && root->left && root->right == root->left){
//         return true;
//     }
//     if (root->left){
//         cout << "checking the left node" << endl;
//         if(!root->left->parent){
//             cout << "initializing parent" << endl;
//             root->left->parent = root;
//         }
//         else if (root->left->parent != root){
//             cout << "parent already exists so there is a cycle" << endl;
//             return true;
//         }
//         else {
//             cout << "the left node already has the correct parent" << endl;
//         }
//     }
//     if (root->right){
//         cout << "checking the right node" << endl;
//         if(!root->right->parent){
//             // parent does not exist
//             cout << "initializing parent" << endl;
//             root->right->parent = root;
//         }
//         else if (root->right->parent != root){
//             cout << "parent already exists so there is a cycle" << endl;
//             return true;
//         }
//         else {
//             cout << "the right node already has the correct parent" << endl;
//         }
//     }
//     return isCycle(root->left) || isCycle(root->right);
// }

bool isCycle(Node *root)
{
    if (!root)
    {
        return false;
    }
    // if we are in a node with no parent, that must mean we are in the root node
    if (!root->parent)
    {
        // give the root node a temporary parent
        if (root->left)
            root->parent = root->left;
        else if (root->right)
            root->parent = root->right;
        else
            return false;
    }
    // if both right and left point to the same node, return true
    if (root->right && root->left && root->right == root->left)
    {
        return true;
    }
    if (root->left)
    {
        if (!root->left->parent)
        {
            // parent does not exist so initialize to the current node
            root->left->parent = root;
        }
        else if (root->left->parent != root)
        {
            // reset the pointer to nullptr in case this is the root
            root->left->parent = nullptr;
            // parent already exists so there is a cycle
            return true;
        }
    }
    if (root->right)
    {
        if (!root->right->parent)
        {
            // parent does not exist so intialize to the current node
            root->right->parent = root;
        }
        else if (root->right->parent != root)
        {
            // reset the pointer to nullptr in case this is the root
            root->right->parent = nullptr;
            // parent already exists so there is a cycle
            return true;
        }
    }
    bool temp = isCycle(root->left) || isCycle(root->right);
    // delete the temporary pointer
    root->parent = nullptr;
    return temp;
}

int main()
{
    Node *root = new Node(3);

    root->left = new Node(1);

    cout << boolalpha << isCycle(root) << endl;

    root->right = new Node(6);
    root->right->left = root->left;

    // root->right->right = new Node(6);
    // root->right->right->right = root->right;

    // root->printVisitedList();

    //cout << boolalpha << isCycle(root) << endl;

    // root->printVisitedList();

    //root->insert(5);

    cout << boolalpha << isCycle(root) << endl;

    // root->printVisitedList();

    Node *newRoot = new Node(4);
    newRoot->right = root;

    cout << boolalpha << isCycle(newRoot) << endl;

    cout << boolalpha << isCycle(newRoot) << endl;

    return 0;
}
