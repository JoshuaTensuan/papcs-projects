#include <cstdlib>
#include <iostream>
#include <string>

#include "tnode.h"
#include "binary_tree.h"

using namespace std;

int main() {
    binary_tree tree = binary_tree(5);
    // tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(6);
    tree.print();
    tree.deletion(6);
    tree.print();
    tree.insert(8);
    tree.insert(10);
    tree.insert(1);
    tree.print();
    cout << tree.predecessor(7) -> data << endl;
    cout << tree.successor(8) -> data << endl;
}