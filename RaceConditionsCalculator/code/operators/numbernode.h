#ifndef CODE_OPERATORS_NUMBERNODE_H_
#define CODE_OPERATORS_NUMBERNODE_H_
#include "tnode.h"
using namespace std;

class numbernode : public tnode {
public:
	Complex number;
	numbernode() {
		number = 0;
	}
	numbernode(double a) {
		number.a = a;
		number.b = 0;
	}
	numbernode(Complex n) {
		number = n;
	}
	~numbernode() {}
	Complex evaluate(Complex x) {
		return number;
	}
	tnode* derivative() {
		return new numbernode();
	}
	string tostring() {
		return number.tostring();
	}
	unsigned int precedence() {
		if (std::abs(number.b) < 0.00001) {
			number.b = 0;
			return 3;
		}
		if (std::abs(number.a) < 0.00001) {
			number.a = 0;
			return 1;
		}
		return 0;
	}
	tnode* compress() {
		return this;
	}
	tnode* chain(tnode* x) {
		return this;
	}
	bool isnum() {
		return true;
	}
	bool isvar() {
		return false;
	}
};

#endif /* CODE_OPERATORS_NUMBERNODE_H_ */
