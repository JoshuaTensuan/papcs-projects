#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "node.h"

class linkedlist {
    private:
        node *head;
    public:
        linkedlist();
        virtual ~linkedlist();
        // linkedlist(linkedlist); // copy
        char get(int n);
        int size();
        void push(char);
        char pop(); //pops front one off, returns front char
        char peek(); // returns thing at node
        bool isPalindrome(int);
        int maxPalindrome();
};



#endif