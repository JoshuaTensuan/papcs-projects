#include<bits/stdc++.h> 
using namespace std; 
#include <cstdlib>
#include <utility>
#include <iostream>
#include <stdio.h>
#include "tnode.h"

using namespace std;
  
class binary_tree { 
    tnode* head;
    public: 
        binary_tree();
        binary_tree(int);
        tnode* help_insert(tnode*, int);
        void insert(int);
        void help_print(tnode*, int);
        void print();
        int min();
        int max();
        void deleteNode(tnode*&, int);
        void deletion(int);
        void searchKey(tnode*&, int, tnode*&);
        tnode* search(int);
        void findPreSuc(tnode*, tnode*&, tnode*&, int);
        tnode* predecessor(int);
        tnode* successor(int);
    }; 

binary_tree::binary_tree() {
    head = nullptr;
}

binary_tree::binary_tree(int key) {
    tnode* root = new tnode(key);
    head = root;
}

void binary_tree::findPreSuc(tnode* root, tnode*& pre, tnode*& suc, int key) {
    if (root == NULL) { 
        return ;
    } 
    if (root -> data == key) { 
        if (root -> left != NULL) { 
            tnode* tmp = root->left; 
            while (tmp -> right) {
                tmp = tmp -> right;
            } 
            pre = tmp; 
        } 
        if (root -> right != NULL) { 
            tnode* tmp = root -> right ; 
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

tnode* binary_tree::predecessor(int key) {
    tnode* pre = nullptr;
    tnode* suc = nullptr;
    findPreSuc(head, pre, suc, key);
    return pre;
}

tnode* binary_tree::successor(int key) {
    tnode* pre = nullptr;
    tnode* suc = nullptr;
    findPreSuc(head, pre, suc, key);
    return suc;
}

tnode* binary_tree::help_insert(tnode* node, int key) { 
    if (node == nullptr) {
        return new tnode(key); 
    }
    if (key < node -> data) {
        node -> left  = help_insert(node->left, key); 
    } 
    else if (key > node -> data) {
        node -> right = help_insert(node->right, key);    
    }
    return node; 
} 


void binary_tree::insert(int key) {
    help_insert(head, key);
}

void binary_tree::help_print(tnode *root, int space) { 
    if (root == NULL)  {
        return;  
    }
    int COUNT = 3; 
    space += COUNT;  
    help_print(root -> right, space);  
    cout << endl;  
    for (int i = COUNT; i < space; i++)  
        cout << " ";  
    cout << root -> data <<"\n";  
    help_print(root -> left, space);  
} 

int binary_tree::min() {
    tnode* temp = head;
    while(temp -> left != nullptr) {
        temp = temp -> left;
    }
    return temp -> data;
}

int binary_tree::max() {
    tnode* temp = head;
    while(temp -> right != nullptr) {
        temp = temp -> right;
    }
    return temp -> data;
}

void binary_tree::print() {
    help_print(head, 0);
}

void binary_tree::searchKey(tnode* &curr, int key, tnode* &parent) {
	while (curr != nullptr && curr -> data != key) {
		parent = curr;
		if (key < curr->data) {
			curr = curr->left;
        } else {	
        	curr = curr->right;
        }
	}
}

void binary_tree::deletion(int key) {
    deleteNode(head, key);
}

tnode* binary_tree::search(int key) {
    tnode* temp = head;
    tnode* parent = nullptr;
    searchKey(temp, key, parent);
    return temp;
}

void binary_tree::deleteNode(tnode*& root, int key) {
	tnode* parent = nullptr;
	tnode* curr = root;
	searchKey(curr, key, parent);
	if (curr == nullptr) {
		return;
    }
	if (curr->left == nullptr && curr->right == nullptr) {
		if (curr != root) {
			if (parent->left == curr) {
				parent->left = nullptr;
            } else {
				parent->right = nullptr;
            }
		}
		else {
			root = nullptr;
        }
		free(curr);	
	} 
	else if (curr->left && curr->right) {
        tnode* successor = curr;
        while( successor -> left != nullptr) {
		    successor = successor -> left;
	    }
		int val = successor->data;
		deleteNode(root, successor->data);
		curr->data = val;
	}
	else {
		tnode* child = (curr->left) ? curr->left: curr->right;
		if (curr != root) {
			if (curr == parent->left) {
				parent->left = child;
            } else {
				parent->right = child;
            }
		}
		else {
			root = child;
        }
		free(curr);
	}
}




