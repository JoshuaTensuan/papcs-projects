#ifndef NODE_H_
#define NODE_H_


class node {
    public:
        node(int d, node *l, node *r, node* p, bool b);
        node(int d, node *l, node *r, node* p);
        node(int d);
        node* left;
        node* right;
        node* parent;
        ~node();
        int data;
        bool black; // true = black, red = false
};

#endif