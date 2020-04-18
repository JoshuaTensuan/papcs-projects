#ifndef CODE_OPERATORS_VARNODE_H_
#define CODE_OPERATORS_VARNODE_H_
#include "numbernode.h"

class varnode : public tnode {
public:
	varnode() {}
	~varnode() {}
	Complex evaluate(Complex x) {
		return x;
	}
	tnode* derivative() {
		return new numbernode(1);
	}
	unsigned int precedence() {
		return 3;
	}
	tnode* compress() {
		return this;
	}
	string tostring() {
		return "x";
	}
	tnode* chain(tnode* x) {
		return x;
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return true;
	}
};

#endif /* CODE_OPERATORS_VARNODE_H_ */
