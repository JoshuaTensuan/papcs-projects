#ifndef TNODE_H_
#define TNODE_H_


class tnode {
    public:
        tnode(int d, tnode *l, tnode *r);
        tnode(int d);
        tnode* left;
        tnode* right;
        ~tnode();
        int data;
        // tnode* insert(tnode* node, int key);
};

#endif