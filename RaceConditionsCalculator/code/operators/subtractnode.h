#ifndef CODE_SUBTRACTNODE_H_
#define CODE_SUBTRACTNODE_H_
#include "addnode.h"
#include "multiplynode.h"

class subtractnode: public tnode {
public:
	tnode* left;
	tnode* right;
	subtractnode() {
		left = nullptr;
		right = nullptr;
	}
	subtractnode(tnode* l, tnode* r) {
		left = l;
		right = r;
	}
	~subtractnode() {
		delete left;
		delete right;
	}
	Complex evaluate(Complex x) {
		return left->evaluate(x) - right->evaluate(x);
	}
	tnode* derivative() {
		return new subtractnode(left->derivative(), right->derivative());
	}
	tnode* compress() {
		left = left->compress();
		right = right->compress();
		if (left->isnum() && right->isnum()) {
			return new numbernode(left->evaluate(0) - right->evaluate(0));
		}
		if (left->isnum() && left->evaluate(0) == 0) {
			return new multiplynode(new numbernode(Complex(-1, 0)), right);
		}
		if (right->isnum() && right->evaluate(0) == 0) {
			return left;
		}
		return this;
	}
	string tostring() {
		string ans = left->tostring() + " - ";
		if (right->precedence() == 0) {
			return ans + "(" + right->tostring() + ")";
		}
		return ans + right->tostring();
	}
	unsigned int precedence() {
		return 0;
	}
	tnode* chain(tnode* x) {
		return new subtractnode(left->chain(x), right->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_SUBTRACTNODE_H_ */
