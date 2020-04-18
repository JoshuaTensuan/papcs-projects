#ifndef CODE_OPERATORS_COSNODE_H_
#define CODE_OPERATORS_COSNODE_H_
#include "multiplynode.h"
#include "numbernode.h"
#include "sinnode.h"

class cosnode : public tnode {
public:
	tnode* down;
	cosnode() {
		down = nullptr;
	}
	cosnode(tnode* d) {
		down = d;
	}
	~cosnode() {
		delete down;
	}
	Complex evaluate(Complex x) {
		return Complex::cos(down->evaluate(x));
	}
	tnode* derivative() {
		return new multiplynode(new multiplynode(new numbernode(-1), down->derivative()), new sinnode(down));
	}
	tnode* compress() {
		down = down->compress();
		if (down->isnum()) {
			return new numbernode(Complex::cos(down->evaluate(0)));
		}
		return this;
	}
	string tostring() {
		return "cos(" + down->tostring() + ")";
	}
	unsigned int precedence() {
		return 3;
	}
	tnode* chain(tnode* x) {
		return new cosnode(down->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_OPERATORS_COSNODE_H_ */
