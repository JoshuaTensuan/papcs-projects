#include "node.h"
#include <climits>

using namespace std;

node::node(int d, node *l, node *r, node *p) {
    left = l;
    right = r;
    data = d;
    parent = p;
    black = false;
};

node::node(int d) {
    data = d;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    black = true;
};

node::node(int d, node *l, node *r, node* p, bool b) {
    left = l;
    right = r;
    data = d;
    parent = p;
    black = b;
}

node::~node() {
    if(left != nullptr) {
        delete(left);
    }
    if(right != nullptr) {
        delete(right);
    }
};

