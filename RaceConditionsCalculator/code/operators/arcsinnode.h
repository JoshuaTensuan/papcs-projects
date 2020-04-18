#ifndef CODE_OPERATORS_ARCSINNODE_H_
#define CODE_OPERATORS_ARCSINNODE_H_
#include "powernode.h"
#include "numpowernode.h"

class arcsinnode: public tnode {
public:
	tnode* down;
	arcsinnode() {
		down = nullptr;
	}
	arcsinnode(tnode* d) {
		down = d;
	}
	~arcsinnode() {
		delete down;
	}
	Complex evaluate(Complex x) {
		return Complex::arcsin(down->evaluate(x));
	}
	tnode* derivative() {
		return new dividenode(down->derivative(), new numpowernode(new subtractnode(new numbernode(1), new numpowernode(down, 2)), 0.5));
	}
	tnode* compress() {
		down = down->compress();
		if (down->isnum()) {
			return new numbernode(Complex::arcsin(down->evaluate(0)));
		}
		return this;
	}
	string tostring() {
		return "arcsin(" + down->tostring() + ")";
	}
	unsigned int precedence() {
		return 3;
	}
	tnode* chain(tnode* x) {
		return new arcsinnode(down->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_OPERATORS_ARCSINNODE_H_ */
