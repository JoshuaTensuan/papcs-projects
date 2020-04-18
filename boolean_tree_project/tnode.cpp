#include "tnode.h"
#include <climits>

using namespace std;

tnode::tnode(char d, tnode *l, tnode *r) {
    left = l;
    right = r;
    data = d;
};
tnode::tnode(char d) {
    data = d;
    left = nullptr;
    right = nullptr;
};
tnode::~tnode() {
    if(left != nullptr) {
        delete(left);
    }
    if(right != nullptr) {
        delete(right);
    }
};
bool tnode::evaluate() {
    switch (data) { 
        case '&':  
            return left -> evaluate() && right -> evaluate();
        case '|':  
            return left -> evaluate() || right -> evaluate();
            break; 
        case '!':  
            return !(left -> evaluate());
        case '>':
            return !(left -> evaluate()) || right -> evaluate();
        case '^':
            return (left -> evaluate() || right -> evaluate()) && (!(left -> evaluate()) && right -> evaluate());
        case 'T':
            return true;
        case 'F':
            return false;
        default:
            return false;
    }
};
unsigned int tnode::precedence() {
    switch(data) {
        case '&':  
            return 1;
        case '|':  
            return 1;
            break; 
        case '!':  
            return 0;
        case '>': //implies
            return 2;
        case '^': //xor
            return 1;
        case 'T':
            return -1;
        case 'F':
            return -1;
        default:
            return INT_MIN;
    }
};

bool tnode::isbool() { 
    if(data == 'T' || data == 'F') {
        return true;
    } else {
        return false;
    }
};


