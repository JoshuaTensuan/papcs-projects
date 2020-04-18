#ifndef ADDNODE_H_
#define ADDNODE_H_
#include "tnode.h"
#include "numbernode.h"

class addnode : public tnode {
public:
	tnode* left;
	tnode* right;
	addnode() {
		left = nullptr;
		right = nullptr;
	}
	addnode(tnode* l, tnode* r) {
		left = l;
		right = r;
	}
	~addnode() {
		delete left;
		delete right;
	}
	Complex evaluate(Complex x) {
		return left->evaluate(x) + right->evaluate(x);
	}
	tnode* derivative() {
		return new addnode(left->derivative(), right->derivative());
	}
	tnode* compress() {
		left = left->compress();
		right = right->compress();
		if (left->isnum() && right->isnum()) {
			return new numbernode(left->evaluate(0) + right->evaluate(0));
		}
		if (left->isnum() && left->evaluate(0) == 0) {
			return right;
		}
		if (right->isnum() && right->evaluate(0) == 0) {
			return left;
		}
		return this;
	}
	string tostring() {
		return left->tostring() + " + " + right->tostring();
	}
	unsigned int precedence() {
		return 0;
	}
	tnode* chain(tnode* x) {
		return new addnode(left->chain(x), right->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif
