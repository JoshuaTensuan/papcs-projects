#ifndef CODE_OPERATORS_SINNODE_H_
#define CODE_OPERATORS_SINNODE_H_
#include <math.h>
#include "multiplynode.h"
#include "numbernode.h"
#include "cosnode.h"

class sinnode : public tnode {
public:
	tnode* down;
	sinnode() {
		down = nullptr;
	}
	sinnode(tnode* d) {
		down = d;
	}
	~sinnode() {
		delete down;
	}
	Complex evaluate(Complex x) {
		return Complex::sin(down->evaluate(x));
	}
	tnode* derivative() {
		return new multiplynode(down->derivative(), new sinnode(new subtractnode(new numbernode(Complex(M_PI / 2, 0)), down)));
	}
	tnode* compress() {
		down = down->compress();
		if (down->isnum()) {
			return new numbernode(Complex::sin(down->evaluate(0)));
		}
		return this;
	}
	string tostring() {
		return "sin(" + down->tostring() + ")";
	}
	unsigned int precedence() {
		return 3;
	}
	tnode* chain(tnode* x) {
		return new sinnode(down->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_OPERATORS_SINNODE_H_ */
