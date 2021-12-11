#include "Node.h"

// Node* Node::visitedNodes = nullptr;

Node::Node()
{
    left = nullptr;
    right = nullptr;
    parent = nullptr; 
}

Node::Node(int n)
{
    data = n;
    right = nullptr;
    left = nullptr;
    parent = nullptr; 
}

Node::~Node()
{
    ;
}

void Node::insert(int value)
{
    if (value < data)
    {
        if (left == nullptr)
        {
            left = new Node(value);
        }
        else
        {
            left->insert(value);
        }
    }
    else
    {
        if (right == nullptr)
        {
            right = new Node(value);
        }
        else
        {
            right->insert(value);
        }
    }
}

void Node::printInOrder()
{
    if (left != nullptr)
    {
        left->printInOrder();
    }
    cout << data << endl;
    if (right != nullptr)
    {
        right->printInOrder();
    }
}

void Node::printPreOrder()
{
    cout << data << endl;
    if (left != nullptr)
    {
        left->printPreOrder();
    }
    if (right != nullptr)
    {
        right->printPreOrder();
    }
}

void Node::printPostOrder()
{
    if (left != nullptr)
    {
        left->printPostOrder();
    }
    if (right != nullptr)
    {
        right->printPostOrder();
    }
    cout << data << endl;
}

// void Node::printVisitedList()
// {
//     Node *c = visitedNodes;
//     while (c)
//     {
//         cout << visitedNodes->data << " ";
//         c = c->right;
//     }
//     cout << endl;
// }
