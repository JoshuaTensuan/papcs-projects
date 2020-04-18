#include "linkedlist.h"
#include <cstdlib>
#include <iostream>
using namespace std;

linkedlist::linkedlist() {
    head = NULL;
}

linkedlist::~linkedlist() {
    while(head != NULL) {
        node *p = head -> next;
        free(head);
        head = p;
    }
}

void linkedlist::push(char c) {
    node *n = new node;
    n->data = c;
    n->next = head;
    head = n;
}

char linkedlist::pop() {
    char c = head -> data;
    node *p = head;
    head = head -> next;
    // head = (*head).next;
    free(p);
    return c;
}

char linkedlist::peek() {
    return head->data;
}

char linkedlist::get(int index) {
    node *p = head;
    for(int i = 0; i < index; i++) {
        p = p -> next;
    }
    return p -> data;
}

int linkedlist::size() {
    int size = 0;
    if(head == NULL) {
        return size;
    }
    node *p = head;
    while(p != NULL) {
        p = p -> next;
        size++;
    }
    return size;
}

bool linkedlist::isPalindrome(int j) {
    bool palindrome = false;
    int len = size();
    if(len-j > 3) {
        if((len-j) % 2 == 0) {
            for(int i = 0; i < ((len - j)/2)-1; i++) {
                if(get(i + j) != get(len-i-1)) {
                    return false;
                } else {
                    palindrome = true;
                }
            } 
        } else {
            for(int i = 0; i <= ((len - j - 1)/2)-1; i++) {
                if(get(i + j) != get(len-i-1)) {
                    return false;
                } else {
                    palindrome = true;
                }
            }
        }
    } else {
        if(len-j == 1 || len-j == 0) {
            return true;
        }
        if(len-j == 2) {
            return(get(len-1) == get(len - 2));
        }
        if(len-j == 3) {
            return(get(len-1) == get(len-3));
        }
    }
    return palindrome;
}

int linkedlist::maxPalindrome() {
    int max = 0;
    int len = size();
    for(int i = len - 1; i >= 0; i--) {
        // cout << "iteration " << i << endl;
        if(isPalindrome(i)) {
            // cout << "yes" << endl;
            int x = len - i;
            if(x > max) {
                max = x;
            }
        }
    }
    return max;
}
