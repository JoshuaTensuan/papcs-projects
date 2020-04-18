#ifndef CODE_MULTIPLYNODE_H_
#define CODE_MULTIPLYNODE_H_
#include "addnode.h"

class multiplynode : public tnode {
public:
	tnode* left;
	tnode* right;
	multiplynode() {
		left = nullptr;
		right = nullptr;
	}
	multiplynode(tnode* l, tnode* r) {
		left = l;
		right = r;
	}
	~multiplynode() {
		delete left;
		delete right;
	}
	Complex evaluate(Complex x) {
		return left->evaluate(x) * right->evaluate(x);
	}
	tnode* derivative() {
		return new addnode(new multiplynode(left, right->derivative()), new multiplynode(left->derivative(), right));
	}
	tnode* compress() {
		right = right->compress();
		left = left->compress();
		if (left->isnum() && right->isnum()) {
			return new numbernode(left->evaluate(0) * right->evaluate(0));
		}
		if (left->isnum()) {
			if (left->evaluate(0) == 0) {
				return new numbernode(Complex(0, 0));
			}
			if (left->evaluate(0) == 1) {
				return right;
			}
		}
		if (right->isnum()) {
			if (right->evaluate(0) == 0) {
				return new numbernode(Complex(0, 0));
			}
			if (right->evaluate(0) == 1) {
				return left;
			}
		}
		return this;
	}
	string tostring() {
		if (left->isvar() && right->isvar()) {
			return "x ^ 2";
		}
		string ans = "";
		if (left->precedence() < 1) {
			ans += "(" + left->tostring() + ")";
		}
		else {
			ans += left->tostring();
		}
		if ((left->precedence() > 0 && left->precedence() < 3) || (right->precedence() > 0 && right->precedence() < 3) || (left->isnum() && left->precedence() > 0 && right->isnum() && right->precedence() > 0)) {
			ans += " * ";
		}
		if (right->precedence() < 1) {
			return ans + "(" + right->tostring() + ")";
		}
		return ans + right->tostring();
	}
	unsigned int precedence() {
		return 1;
	}
	tnode* chain(tnode* x) {
		return new multiplynode(left->chain(x), right->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif
