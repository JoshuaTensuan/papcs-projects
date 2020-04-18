Tested knowledge of Red Black Trees by implementation of red black tree in C++.

node.h and node.cpp contain the code for the tree node struct.
The implementation of the red black tree is in red_black_tree.h.

Information about the node struct:
- Same as binary tree node struct but also has an included field of the color 
-- Denoted by bool black where black == true means that node is black and black == false means that node is red

Search, max, min, predecessor, successor, insert, delete, rotate, and print were implemented in the red black tree class

1. Search method - takes in an integer value and returns a pointer to the tree node with that integer value
- node* search(int);

2. Max method - takes in no parameters and returns the integer max value
- int max();

3. Min method - takes in no parameters and returns the integer min value
- int min();

4. Predecessor method - takes in a key integer value and returns a pointer to the predecessor tree node
- node* predecessor(int);

5. Successor method - takes in a key integer value and returns a pointer to the successor tree node
- node* successor(int);

6. Insert method - takes in an integer value and inserts a node with that integer value to the red black tree
- void insert(int);

7. Delete (deletion) method - takes in an integer value deletes the node with that integer value in the red black tree
- void deletion(int);

8. Rotate method - Takes in a node pointer to rotate about and a boolean where if the boolean is true, it rotates left about the node, and if false, it rotates right about the node
- void rotate(node*, bool);

9. Print method - takes in no parameters and prints the red black tree horizontally with the colors (b = black, r = red)
- void print();

