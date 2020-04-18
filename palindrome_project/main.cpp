#include "linkedlist.h"
#include "linkedlist.cpp"
#include "node.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    linkedlist el;
    string temp = argv[1];
    int size = temp.length();
    for(int i = size - 1; i >= 0; i--) {
        el.push(argv[1][i]);
    }
    cout << el.maxPalindrome() << endl;
}