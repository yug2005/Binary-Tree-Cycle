#include <iostream>
using namespace std; 

class Node {
    public: 
        int data; 
        Node* left; 
        Node* right; 
        Node* parent; 
        //static Node* visitedNodes;
    
        Node(); 
        Node(int n);
        ~Node(); 

        void printVisitedList(); 

        void insert(int value);
        void printInOrder();
        void printPreOrder(); 
        void printPostOrder(); 
};
