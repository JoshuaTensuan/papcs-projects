#ifndef CODE_OPERATORS_NUMPOWERNODE_H_
#define CODE_OPERATORS_NUMPOWERNODE_H_
#include "lnnode.h"
#include "numbernode.h"

class numpowernode : public tnode {
public:
	tnode* down;
	Complex exponent;
	numpowernode() {
		down = nullptr;
		exponent = 0;
	}
	numpowernode(tnode* d, Complex exp) {
		down = d;
		exponent = exp;
	}
	~numpowernode() {
		delete down;
	}
	Complex evaluate(Complex x) {
		return down->evaluate(x) ^ exponent;
	}
	tnode* derivative() {
		return new multiplynode(down->derivative(), new multiplynode(new numbernode(exponent), new numpowernode(down, exponent - 1)));
	}
	tnode* compress() {
		down = down->compress();
		if (down->isnum()) {
			return new numbernode(down->evaluate(0) ^ exponent);
		}
		if (exponent == 0) {
			return new numbernode(Complex(1, 0));
		}
		if (exponent == 1) {
			return down;
		}
		return this;
	}
	string tostring() {
		string ans = "";
		if (down->precedence() == 3) {
			ans += down->tostring();
		}
		else {
			ans += "(" + down->tostring() + ")";
		}
		ans += "^";
		if (std::abs(exponent.b) < 0.00001 || exponent == Complex(0 ,1) || exponent == Complex(0, -1)) {
			return ans + exponent.tostring();
		}
		return ans + "(" + exponent.tostring() + ")";
	}
	unsigned int precedence() {
		return 2;
	}
	tnode* chain(tnode* x) {
		return new numpowernode(down->chain(x), exponent);
	}
	bool isnum() {
		return false;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_OPERATORS_NUMPOWERNODE_H_ */
