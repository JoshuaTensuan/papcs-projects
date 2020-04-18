#ifndef CODE_OPERATORS_ARCTANNODE_H_
#define CODE_OPERATORS_ARCTANNODE_H_
#include "powernode.h"

class arctannode : public tnode {
public:
	tnode* down;
	arctannode() {
		down = nullptr;
	}
	arctannode(tnode* d) {
		down = d;
	}
	~arctannode() {
		delete down;
	}
	Complex evaluate(Complex x) {
		return Complex::arctan(down->evaluate(x));
	}
	tnode* derivative() {
		return new dividenode(down->derivative(), new addnode(new numbernode(Complex(1, 0)), new numpowernode(down, Complex(2, 0))));
	}
	tnode* compress() {
		down = down->compress();
		if (down->isnum()) {
			return new numbernode(Complex::arctan(down->evaluate(0)));
		}
		return this;
	}
	string tostring() {
		return "arctan(" + down->tostring() + ")";
	}
	unsigned int precedence() {
		return 3;
	}
	tnode* chain(tnode* x) {
		return new arctannode(down->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_OPERATORS_ARCTANNODE_H_ */
