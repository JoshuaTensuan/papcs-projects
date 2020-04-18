#ifndef CODE_DIVIDENODE_H_
#define CODE_DIVIDENODE_H_
#include "multiplynode.h"
#include "subtractnode.h"
#include "numpowernode.h"

class dividenode : public tnode{
public:
	tnode* left;
	tnode* right;
	dividenode() {
		left = nullptr;
		right = nullptr;
	}
	dividenode(tnode* l, tnode* r) {
		left = l;
		right = r;
	}
	~dividenode() {
		delete left;
		delete right;
	}
	Complex evaluate(Complex x) {
		return left->evaluate(x) / right->evaluate(x);
	}
	tnode* derivative() {
		return new dividenode(new subtractnode(new multiplynode(left->derivative(), right), new multiplynode(left, right->derivative())), new numpowernode(right, Complex(2)));
	}
	tnode* compress() {
		left = left->compress();
		right = right->compress();
		if (left->isnum() && right->isnum()) {
			return new numbernode(left->evaluate(0) / right->evaluate(0));
		}
		if (left->isnum() && left->evaluate(0) == 0) {
			return new numbernode(Complex(0, 0));
		}
		if (right->isnum() && right->evaluate(0) == 1) {
			return left;
		}
		return this;
	}
	string tostring() {
		string ans = "";
		if (left->precedence() < 1) {
			ans += "(" + left->tostring() + ")";
		}
		else {
			ans += left->tostring();
		}
		ans += " / ";
		if (right->precedence() < 2) {
			return ans + "(" + right->tostring() + ")";
		}
		return ans + right->tostring();
	}
	unsigned int precedence() {
		return 1;
	}
	tnode* chain(tnode* x) {
		return new dividenode(left->chain(x), right->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_DIVIDENODE_H_ */
