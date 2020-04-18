Implementation of binary search tree project


tnode.h and tnode.cpp contain the code for the tree node struct.
The implementation of the binary tree is in binary_tree.h.

Search, max, min, predecessor, successor, insert, delete, and print were implemented in the binary tree class

1. Search method - takes in an integer value and returns a pointer to the tree node with that integer value
- tnode* search(int);

2. Max method - takes in no parameters and returns the integer max value
- int max();

3. Min method - takes in no parameters and returns the integer min value
- int min();

4. Predecessor method - takes in a key integer value and returns a pointer to the predecessor tree node
- tnode* predecessor(int);

5. Successor method - takes in a key integer value and returns a pointer to the successor tree node
- tnode* successor(int);

6. Insert method - takes in an integer value and inserts a node with that integer value to the binary tree
- void insert(int);

7. Delete (deletion) method - takes in an integer value deletes the node with that integer value in the binary tree
- void deletion(int);

8. Print method - takes in no parameters and prints the binary tree horizontally
- void print();
