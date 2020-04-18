#ifndef CODE_POWERNODE_H_
#define CODE_POWERNODE_H_
#include "lnnode.h"
#include "tnode.h"

class powernode : public tnode {
public:
	tnode* left;
	tnode* right;
	powernode() {
		left = nullptr;
		right = nullptr;
	}
	powernode(tnode* l, tnode* r) {
		left = l;
		right = r;
	}
	~powernode() {
		delete left;
		delete right;
	}
	Complex evaluate(Complex x) {
		return left->evaluate(x) ^ right->evaluate(x);
	}
	tnode* derivative() {
		return new multiplynode(this, new addnode(new multiplynode(new lnnode(left), right->derivative()), new dividenode(new multiplynode(left->derivative(), right), left)));
	}
	tnode* compress() {
		left = left->compress();
		right = right->compress();
		if (left->isnum() && right->isnum()) {
			return new numbernode(left->evaluate(0) ^ right->evaluate(0));
		}
		if (left->isnum()) {
			if (left->evaluate(0) == 0) {
				return new numbernode(Complex(0, 0));
			}
			if (left->evaluate(0) == 1) {
				return new numbernode(Complex(1, 0));
			}
		}
		if (right->isnum()) {
			if (right->evaluate(0) == 0) {
				return new numbernode(Complex(1, 0));
			}
			if (right->evaluate(0) == 1) {
				return left;
			}
			return new numpowernode(left, right->evaluate(0));
		}
		return this;
	}
	string tostring() {
		string ans = "";
		if (left->precedence() == 3) {
			ans += left->tostring();
		}
		else {
			ans += "(" + left->tostring() + ")";
		}
		ans += "^";
		if (right->precedence() == 3) {
			return ans + right->tostring();
		}
		return ans + "(" + right->tostring() + ")";
	}
	unsigned int precedence() {
		return 2;
	}
	tnode* chain(tnode* x) {
		return new powernode(left->chain(x), right->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_POWERNODE_H_ */
