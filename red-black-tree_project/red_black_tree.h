#include <bits/stdc++.h> 
#include <cstdlib>
#include <utility>
#include <iostream>
#include <stdio.h>
#include "node.h"

  
class red_black_tree { 
    node* head;
    public: 
        red_black_tree();
        red_black_tree(int);
        void insert(int);
        void insertfix(node*);
        void help_print(node*, int);
        void print();
        int min();
        int max();
        void delfix(node*);
        void deletion(int);
        void searchKey(node*&, int, node*&);
        node* search(int);
        void findPreSuc(node*, node*&, node*&, int);
        node* predecessor(int);
        node* successor(int);
        void rotate(node*, bool left);
    }; 

red_black_tree::red_black_tree() {
    head = nullptr;
}

red_black_tree::red_black_tree(int key) {
    node *root = new node(key, nullptr, nullptr, nullptr, true);
    head = root;
}

int red_black_tree::min() {
    node* temp = head;
    while (temp -> left) {
        temp = temp -> left;
    }
    return temp -> data;
}

int red_black_tree::max() {
    node* temp = head;
    while (temp -> right) {
        temp = temp -> right;
    }
    return temp -> data;
}

void red_black_tree::rotate(node* s, bool left) { // parameter of true rotate rotates rbt left about s
    if (left) {
        if (s -> right != nullptr) {
            node* c2 = s -> right;
            if (c2 -> left != nullptr) {
                s -> right = c2 -> left;
                c2 -> left -> parent = s;
            } else {
                s -> right = nullptr;
            }
            if (s -> parent != nullptr) {
                c2 -> parent = s -> parent;
                if (s == s -> parent -> right) {
                    s -> parent -> right = c2;
                } else {
                    s -> parent -> left = c2;
                }
            } else {
                head = c2;
            } 
            c2 -> left = s;
            s -> parent = c2;
        }
    } else {
        if (s -> left != nullptr) {
            node* c1 = s -> left;
            if (c1 -> right != nullptr) {
                s -> left = c1 -> right;
                c1 -> right -> parent = s;
            } else {
                s -> left = nullptr;
            }
            if (s -> parent != nullptr) {
                c1 -> parent = s -> parent;
                if (s == s -> parent -> right) {
                    s -> parent -> right = c1;
                } else {
                    s -> parent -> left = c1;
                }
            } else {
                head = c1;
            }
            c1 -> right = s;
            s -> parent = c1;
        }
    }
}


void red_black_tree::findPreSuc(node* root, node*& pre, node*& suc, int key) {
    if (root == nullptr) { 
        return ;
    } 
    if (root -> data == key) { 
        if (root -> left != nullptr) { 
            node* tmp = root -> left; 
            while (tmp -> right) {
                tmp = tmp -> right;
            } 
            pre = tmp; 
        } 
        if (root -> right != nullptr) { 
            node* tmp = root -> right ; 
            while (tmp -> left) {
                tmp = tmp -> left;
            } 
            suc = tmp; 
        } 
        return ; 
    } 
    if (root -> data > key) { 
        suc = root; 
        findPreSuc(root -> left, pre, suc, key) ; 
    } 
    else { 
        pre = root; 
        findPreSuc(root -> right, pre, suc, key) ; 
    } 
}

node* red_black_tree::predecessor(int key) {
    node* pre = nullptr;
    node* suc = nullptr;
    findPreSuc(head, pre, suc, key);
    return pre;
}

node* red_black_tree::successor(int key) {
    node* pre = nullptr;
    node* suc = nullptr;
    findPreSuc(head, pre, suc, key);
    return suc;
}

void red_black_tree::insert(int key) {  
    node *p,*q;
    node *t = new node(key, nullptr, nullptr, nullptr, false);
    p = head;
    q = nullptr;
    if (head == nullptr) {
        head = t;
    } else {
        while (p != nullptr) {
            q = p;
            if (p -> data < t -> data) {
                p = p -> right;
            } else {
                p = p -> left;
            }
        }
        t -> parent=q;
        if (q -> data < t -> data) {
            q -> right=t;
        } else {
            q -> left=t;
        }
     }
     insertfix(t);
}

void red_black_tree::insertfix(node* s) {
    if (head != s) {
        node* u;
        while (s -> parent != nullptr && !(s -> parent -> black)) { // true color = black
           node *g = s-> parent -> parent;
           if (g -> left != s -> parent) {
                if (g -> left == nullptr) {
                    if (s -> parent -> left == s) {
                        s = s -> parent;
                        rotate(s, false);
                    }
                    s -> parent -> black = true;
                    g -> black = false;
                    rotate(g, true);
                } else {
                    u = g -> left;
                    if (u -> black == false) {
                        s -> parent -> black = true;
                        u -> black = true;
                        g -> black = false;
                        s = g;
                    }
                }
           } else {
                if (g -> right == nullptr) {
                    if (s -> parent -> right == s) {
                        s = s -> parent;
                        rotate(s, true); // true rotate rotates left
                    }
                    s -> parent -> black = true;
                    g -> black = false;
                    rotate(g, false);
                } else {
                    u = g -> right;
                    if (!(u -> black)) {
                        s -> parent -> black = true;
                        u -> black = true;
                        g -> black= false;
                        s = g;
                    }
                }
           }
           head -> black = true;
        }
    }
}

void red_black_tree::searchKey(node* &curr, int key, node* &parent) {
	while (curr != nullptr && curr -> data != key) {
		parent = curr;
		if (key < curr -> data) {
			curr = curr -> left;
        } else {	
        	curr = curr -> right;
        }
	}
}

node* red_black_tree::search(int key) {
    node* temp = head;
    node* parent = nullptr;
    searchKey(temp, key, parent);
    return temp;
}

void red_black_tree::deletion(int key) {
    if (head == nullptr) {
        std::cout << "Empty Tree" << std::endl;
        return ;
    }
    node *p = search(key);
    node *y = nullptr;
    node *q = nullptr;

    if (p == nullptr) {
        std::cout << "Element Not Found." << std::endl;
        return ;
    }
    if (p -> left == nullptr || p -> right == nullptr) {
        y=p;
    } else {
        y = successor(p -> data);
    }
    if (y -> left != nullptr) {
        q = y -> left;
    } else {
        if (y -> right != nullptr) {
            q = y -> right;
        } else {
            q = nullptr;
        }
    }
    if (q != nullptr) {
        q -> parent = y -> parent;
    }
    if (y -> parent == nullptr) {
         head=q;
    } else {
        if (y == y -> parent -> left) {
            y -> parent -> left = q;
        } else {
            y->parent->right=q;
        }
    }
    if (y != p) {
        p -> black = y -> black;
        p -> data = y -> data;
    }
    if (y -> black) {
        delfix(q);
    }
}

// finish delfix
void red_black_tree::delfix(node* p) {
    node *s;
    while(p != head && p -> black) {
        if (p -> parent -> left ==p) {
            s = p -> parent -> right;
            if (!(s -> black)) {
                s -> black = true;
                p -> parent -> black = false;
                rotate(p -> parent, true);
                s = p -> parent -> right;
            }
            if (s -> right -> black && s -> left -> black) {
                s -> black = false;
                p = p -> parent;
            } else {
                if (s -> right -> black) {
                    s -> left -> black = true;
                    s -> black = false;
                    rotate(s, false);
                    s = p -> parent -> right;
                }
                s -> black = p -> parent -> black;
                p -> parent -> black = true;
                s -> right -> black = true;
                rotate(p -> parent, true);
                p = head;
            }
        } else {
            s = p -> parent -> left;
                if (!(s -> black)) {
                    s -> black = true;
                    p -> parent -> black = false;
                    rotate(p ->parent, false);
                    s = p -> parent -> left;
                  }
                if (s -> left -> black && s -> right -> black) {
                    s -> black = false;
                    p = p -> parent;
                } else {
                    if (s -> left -> black) {
                        s -> right -> black = true;
                        s -> black = false;
                        rotate(s, true);
                        s = p -> parent -> left;
                    }
                    s -> black = p -> parent -> black;
                    p -> parent -> black = true;
                    s -> left -> black = true;
                    rotate(p -> parent, head);
                    p = head;
                }
            }
       p -> black = true;
       head -> black = true;
    }
}

void red_black_tree::print() {
    help_print(head, 3);
}

void red_black_tree::help_print(node *root, int space) {
    if (root == NULL)  {
        return;  
    }
    int COUNT = 3; 
    space += COUNT;  
    help_print(root -> right, space);  
    std::cout << std::endl;  
    for (int i = COUNT; i < space; i++) {
        std::cout << " ";  
    }
    if (root -> black) {
        std::cout << root -> data << "b" << "\n";  
    } else {
        std::cout << root -> data << "r" << "\n";  
    }
    help_print(root -> left, space);  
}