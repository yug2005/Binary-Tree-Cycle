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
         
        root->parent = new Node(root->data);
        if (root->left) root->left->parent = root;
        if (root->right) root->right->parent = root;

        bool temp = isCycle(root->left) || isCycle(root->right);

        Node* currParent;
        Node* tptr = root;

        while (tptr) {
            if (tptr->left && tptr->left->parent == tptr) {
                tptr = tptr->left;
            } else if (tptr->right && tptr->right->parent == tptr) {
                tptr = tptr->right;
            } else if (tptr != root) {
                currParent = tptr->parent;
                cout << "tptr: " << tptr->data << endl; 
                tptr->parent = nullptr;
                tptr = currParent;
            } else {
                break;
            }
        }

        delete root->parent;
        return temp;
    }
    if (root->left)
    {
        if (!root->left->parent)
        {
            // parent does not exist so initialize to the current node
            root->left->parent = root;
        }
        else
        {
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
        else
        {
            // parent already exists so there is a cycle
            return true;
        }
    }
    return isCycle(root->left) || isCycle(root->right);
    // reset the parent pointer of the root node to nullptr
}

int main()
{
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

    //root->printPreOrder(); 

    cout << boolalpha << isCycle(root) << endl;

    //root->printPreOrder(); 

    cout << boolalpha << isCycle(root) << endl;

    return 0;
}

