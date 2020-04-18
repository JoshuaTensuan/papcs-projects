#ifndef TNODE_H_
#define TNODE_H_


class tnode {
    public:
        tnode(char d, tnode *l, tnode *r);
        tnode(char d);
        tnode* left;
        tnode* right;
        ~tnode();
        char data;
        unsigned int precedence();
        bool evaluate();
        bool isbool();
};

#endif