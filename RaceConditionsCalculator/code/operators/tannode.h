#ifndef CODE_OPERATORS_TANNODE_H_
#define CODE_OPERATORS_TANNODE_H_
#include "cosnode.h"

class tannode : public tnode {
public:
	tnode* down;
	tannode() {
		down = nullptr;
	}
	tannode(tnode* d) {
		down = d;
	}
	~tannode() {
		delete down;
	}
	Complex evaluate(Complex x) {
		return Complex::tan(down->evaluate(x));
	}
	tnode* derivative() {
		return new dividenode(down->derivative(), new numpowernode(new cosnode(down), Complex(2, 0)));
	}
	tnode* compress() {
		down = down->compress();
		if (down->isnum()) {
			return new numbernode(Complex::tan(down->evaluate(0)));
		}
		return this;
	}
	string tostring() {
		return "tan(" + down->tostring() + ")";
	}
	unsigned int precedence() {
		return 3;
	}
	tnode* chain(tnode* x) {
		return new tannode(down->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_OPERATORS_TANNODE_H_ */
