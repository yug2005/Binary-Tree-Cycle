# Binary Tree Cycle

This algorithm detects a cycle in a binary tree by adding just one data member to the definition of a tree node. 

The algorithm has a time complexity of **O(n)** and a space complexity of **O(1)**. 

The isCycle(Node* root) function takes in one parameter and it recursively determines whether a given binary tree has a cycle or not. It does by detecting duplicate nodes in the tree when traversing through in pre-order. 

The algorithm works as follows :

When you go into the isCycle function, you first check if the current node is nullptr, if so you return false. 

Then you check whether the current node's parent pointer is nullptr. This will only be the case when the user calls the isCycle function in main. Therefore, this is at the root node of the binary tree. You set the parent of this root node to either the left or the right child node temporarily. 

We can distinguish the time when the user is calling the isCycle() function this way because in the function, you check the parent nodes of the child nodes. If they are empty (nullptr), you assign them to the current node. However, if they are not empty and if they are the current node, it means that a parent pointer already exists and it points to another node. That means there are two parents and therefore there is a cycle. Before returning true however, you delete the root node's parent pointer and reset it to null as it should be. 

Also, there is a corner case you need to check for. If a node's both left and right pointers are pointing to the same node, that is also a cycle and you need to return true. 

**Note** : This algorithm works for nearly all types of insertion into the binary tree. 