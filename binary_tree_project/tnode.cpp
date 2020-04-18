#include "tnode.h"
#include <climits>

using namespace std;

tnode::tnode(int d, tnode *l, tnode *r) {
    left = l;
    right = r;
    data = d;
};
tnode::tnode(int d) {
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

