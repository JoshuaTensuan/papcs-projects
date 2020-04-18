#ifndef CODE_OPERATORS_ARCCOSNODE_H_
#define CODE_OPERATORS_ARCCOSNODE_H_
#include "powernode.h"
#include "numbernode.h"

class arccosnode: public tnode {
public:
	tnode* down;
	arccosnode() {
		down = nullptr;
	}
	arccosnode(tnode* d) {
		down = d;
	}
	~arccosnode() {
		delete down;
	}
	Complex evaluate(Complex x) {
		return Complex::arccos(down->evaluate(x));
	}
	tnode* derivative() {
		return new dividenode(new multiplynode(new numbernode(-1), down->derivative()), new powernode(new subtractnode(new numbernode(1), new powernode(down, new numbernode(2))), new numbernode(0.5)));
	}
	tnode* compress() {
		down = down->compress();
		if (down->isnum()) {
			return new numbernode(Complex::arccos(down->evaluate(0)));
		}
		return this;
	}
	string tostring() {
		return "arccos(" + down->tostring() + ")";
	}
	unsigned int precedence() {
		return 3;
	}
	tnode* chain(tnode* x) {
		return new arccosnode(down->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_OPERATORS_ARCCOSNODE_H_ */
