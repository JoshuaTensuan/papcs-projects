#ifndef CODE_LNNODE_H_
#define CODE_LNNODE_H_
#include "dividenode.h"
#include "tnode.h"

class lnnode : public tnode {
public:
	tnode* down;
	lnnode() {
		down = nullptr;
	}
	lnnode(tnode* d) {
		down = d;
	}
	~lnnode() {
		delete down;
	}
	Complex evaluate(Complex x) {
		return Complex::ln(down->evaluate(x));
	}
	tnode* derivative() {
		return new dividenode(down->derivative(), down);
	}
	tnode* compress() {
		down = down->compress();
		if (down->isnum()) {
			return new numbernode(Complex::ln(down->evaluate(0)));
		}
		return this;
	}
	string tostring() {
		return "ln(" + down->tostring() + ")";
	}
	unsigned int precedence() {
		return 3;
	}
	tnode* chain(tnode* x) {
		return new lnnode(down->chain(x));
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_LNNODE_H_ */
