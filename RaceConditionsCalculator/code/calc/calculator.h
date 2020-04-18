#ifndef CODE_CALC_CALCULATOR_H_
#define CODE_CALC_CALCULATOR_H_
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <cmath>
#include "stack.h"
#include "../operators/tnode.h"
#include "../operators/addnode.h"
#include "../operators/powernode.h"
#include "../operators/numpowernode.h"
#include "../operators/varnode.h"
#include "../operators/cosnode.h"
#include "../operators/arccosnode.h"
#include "../operators/arcsinnode.h"
#include "../operators/tannode.h"
#include "../operators/arctannode.h"
using namespace std;

class calculator{
public:
	calculator(){
	}
	~calculator(){
	}
	static string evaluate (string input){
		return tree_to_answer(postfix_to_tree(infix_to_postfix(input)));
	}
	static tnode* infix_to_tree(string in) {
		return postfix_to_tree(infix_to_postfix(in));
	}
	static string infix_to_postfix(string in) {
		string good = "";
		for (unsigned int x = 0; x < in.length(); x++) {
			if (in[x] != ' ') {
				good += in[x];
			}
		}
		return recurse(good);
	}
	static string recurse(string in) {
		for (;;) {
			unsigned int par = 1;
			bool leave = false;
			if (in[0] != '(' || in[in.length() - 1] != ')') {
				break;
			}
			for (unsigned int x = 1; x < in.length() - 1; x++) {
				if (in[x] == '(') {
					par++;
				}
				if (in[x] == ')') {
					par--;
				}
				if (par == 0) {
					leave = true;
					break;
				}
			}
			if (leave) {
				break;
			}
			in = in.substr(1, in.length() - 2);
		}
		if (in.length() == 1) {
			if (in[0] == '-') {
				return "-1";
			}
			return in;
		}
		unsigned int par = 0;
		if (in[in.length() - 1] == ')') {
			par++;
		}
		for (unsigned int x = in.length() - 2; x > 0; x--) {
			if (in[x] == ')') {
				par++;
				continue;
			}
			if (in[x] == '(') {
				par--;
				continue;
			}
			if (par == 0) {
				if (in[x] == '+') {
					return recurse(in.substr(0, x)) + " " + recurse(in.substr(x + 1, in.length() - x - 1)) + " +";
				}
				if (in[x] == '-' && (in[x - 1] == 'i' || in[x - 1] == 'I' || in[x - 1] == 'x' || in[x - 1] == ')' || (in[x - 1] >= '0' && in[x - 1] <= '9') || in[x - 1] == 'e' || in[x - 1] == 'E') && (in[x + 1] == '-' || in[x + 1] == 'x' || in[x + 1] == '(' || (in[x + 1] >= '0' && in[x + 1] <= '9') || in[x + 1] == 'e' || in[x + 1] == 'E' || in[x + 1] == 'p' || in[x + 1] == 'P' || in[x + 1] == 'l' || in[x + 1] == 's' || in[x + 1] == 'c' || in[x + 1] == 't' || in[x + 1] == 'a')) {
					return recurse(in.substr(0, x)) + " " + recurse(in.substr(x + 1, in.length() - x - 1)) + " -";
				}
			}
		}
		par = 0;
		if (in[in.length() - 1] == ')') {
			par++;
		}
		for (int x = in.length() - 2; x >= 0; x--) {
			if (par == 0) {
				if (in[x] == '*') {
					return recurse(in.substr(0, x)) + " " + recurse(in.substr(x + 1, in.length() - x - 1)) + " *";
				}
				if ((in[x] == '-' && (in[x + 1] < '0' || in[x + 1] > '9')) || ((in[x] > '9' || in[x] < '0' || in[x + 1] > '9' || in[x + 1] < '0') && (in[x] == ')' || in[x] == 'e' || in[x] == 'E' || in[x] == 'i' || in[x] == 'I' || in[x] == 'x' || (in[x] >= '0' && in[x] <= '9')) && (in[x + 1] == 's' || in[x + 1] == 'c' || in[x + 1] == 't' || in[x + 1] == 'l' || in[x + 1] == 'a' || in[x + 1] == '(' || in[x + 1] == 'P' || in[x + 1] == 'p' || in[x + 1] == 'e' || in[x + 1] == 'E' || in[x + 1] == 'x' || in[x + 1] == 'i' || (in[x + 1] >= '0' && in[x + 1] <= '9')))) {
					return recurse(in.substr(0, x + 1)) + " " + recurse(in.substr(x + 1, in.length() - x - 1)) + " *";
				}
				if (in[x] == '/') {
					return recurse(in.substr(0, x)) + " " + recurse(in.substr(x + 1, in.length() - x - 1)) + " /";
				}
			}
			if (in[x] == ')') {
				par++;
			}
			if (in[x] == '(') {
				par--;
			}
		}
		par = 0;
		if (in[0] == '(') {
			par++;
		}
		for (unsigned int x = 1; x < in.length() - 1; x++) {
			if (in[x] == '(') {
				par++;
				continue;
			}
			if (in[x] == ')') {
				par--;
			}
			if (par == 0) {
				if (in[x] == '^') {
					return recurse(in.substr(0, x)) + " " + recurse(in.substr(x + 1, in.length() - x - 1)) + " ^";
				}
			}
		}
		if (in.length() > 2) {
			if (in[0] == 'l' && in[1] == 'n') {
				return recurse(in.substr(2, in.length() - 2)) + " ln";
			}
		}
		if (in.length() > 3) {
			if (in[0] == 's' && in[1] == 'i' && in[2] == 'n') {
				return recurse(in.substr(3, in.length() - 3)) + " sin";
			}
			if (in[0] == 'c' && in[1] == 'o' && in[2] == 's') {
				return recurse(in.substr(3, in.length() - 3)) + " cos";
			}
			if (in[0] == 't' && in[1] == 'a' && in[2] == 'n') {
				return recurse(in.substr(3, in.length() - 3)) + " tan";
			}
		}
		if (in.length() > 6) {
			if (in[0] == 'a' && in[1] == 'r' && in[2] == 'c') {
				if (in[3] == 's' && in[4] == 'i' && in[5] == 'n') {
					return recurse(in.substr(6, in.length() - 6)) + " arcsin";
				}
				if (in[3] == 'c' && in[4] == 'o' && in[5] == 's') {
					return recurse(in.substr(6, in.length() - 6)) + " arccos";
				}
				if (in[3] == 't' && in[4] == 'a' && in[5] == 'n') {
					return recurse(in.substr(6, in.length() - 6)) + " arctan";
				}
			}
		}
		return in;
	}
	static tnode* postfix_to_tree(string post) {
		stack<tnode*> s = stack<tnode*>();
		unsigned int x = 0;
		for (;x < post.length();) {
			if (post[x] == '+') {
				tnode* n = s.pop();
				s.push(new addnode(s.pop(), n));
				x += 2;
				continue;
			}
			if (post[x] == '-' && (x + 1 >= post.length() || post[x + 1] == ' ')) {
				tnode* n = s.pop();
				s.push(new subtractnode(s.pop(), n));
				x += 2;
				continue;
			}
			if (post[x] == '*') {
				tnode* n = s.pop();
				s.push(new multiplynode(s.pop(), n));
				x += 2;
				continue;
			}
			if (post[x] == '/') {
				tnode* n = s.pop();
				s.push(new dividenode(s.pop(), n));
				x += 2;
				continue;
			}
			if (post[x] == '^') {
				tnode* n = s.pop();
				s.push(new powernode(s.pop(), n));
				x += 2;
				continue;
			}
			if (post[x] == 'x') {
				s.push(new varnode());
				x += 2;
				continue;
			}
			if (post[x] == 'e' || post[x] == 'E') {
				s.push(new numbernode(Complex(M_E, 0)));
				x += 2;
				continue;
			}
			if (post[x] == 'i') {
				s.push(new numbernode(Complex(0, 1)));
				x += 2;
				continue;
			}
			if (post[x] == '-' || (post[x] >= '0' && post[x] <= '9')) {
				double ans;
				if (post[x] == '-') {
					ans = '0' - post[++x];
				}
				else {
					ans = post[x] - '0';
				}
				x++;
				for (;x < post.length() && post[x] >= '0' && post[x] <= '9'; x++) {
					if (ans < 0) {
						ans = ans * 10 - (post[x] - '0');
						continue;
					}
					ans = ans * 10 + (post[x] - '0');
				}
				if (x < post.length() && post[x] == '.') {
					double div = 1;
					x++;
					for (;x < post.length() && post[x] >= '0' && post[x] <= '9'; x++) {
						div = div * 10;
						if (ans < 0) {
							ans -= (post[x] - '0') / div;
							continue;
						}
						ans += (post[x] - '0') / div;
					}
				}
				if (x >= post.length() || post[x] == ' ') {
					s.push(new numbernode(Complex(ans, 0)));
					x++;
					continue;
				}
				if (post[x] == 'i') {
					s.push(new numbernode(Complex(0, ans)));
					x += 2;
					continue;
				}
			}
			if (x + 1 < post.length()) {
				if ((post[x] == 'P' && post[x + 1] == 'I') || (post[x] == 'p' && post[x + 1] == 'i')) {
					s.push(new numbernode(M_PI));
					x += 3;
					continue;
				}
				if (post[x] == 'l' && post[x + 1] == 'n') {
					s.push(new lnnode(s.pop()));
					x += 3;
					continue;
				}
				if (x + 2 < post.length()) {
					if (post[x] == 's' && post[x + 1] == 'i' && post[x + 2] == 'n') {
						s.push(new sinnode(s.pop()));
						x += 4;
						continue;
					}
					if (post[x] == 'c' && post[x + 1] == 'o' && post[x + 2] == 's') {
						s.push(new cosnode(s.pop()));
						x += 4;
						continue;
					}
					if (post[x] == 't' && post[x + 1] == 'a' && post[x + 2] == 'n') {
						s.push(new tannode(s.pop()));
						x += 4;
						continue;
					}
					if (x + 5 < post.length()) {
						if (post[x] == 'a' && post[x + 1] == 'r' && post[x + 2] == 'c') {
							if (post[x + 3] == 's' && post[x + 4] == 'i' && post[x + 5] == 'n') {
								s.push(new arcsinnode(s.pop()));
								x += 7;
								continue;
							}
							if (post[x + 3] == 'c' && post[x + 4] == 'o' && post[x + 5] == 's') {
								s.push(new arccosnode(s.pop()));
								x += 7;
								continue;
							}
							if (post[x + 3] == 't' && post[x + 4] == 'a' && post[x + 5] == 'n') {
								s.push(new arctannode(s.pop()));
								x += 7;
								continue;
							}
						}
					}
				}
			}
		}
		return s.pop()->compress();
	}
	static string tree_to_answer(tnode*);
	static int precedence(char s){ // used for in->post
		if ((s == '+') || (s == '-')){
			return 0;
		}
		if ((s == '*') || (s == '/')){
			return 1;
		}
		if (s == '^'){
			return 2;
		}
		return -1;
	}
};

#endif /* CODE_CALC_CALCULATOR_H_ */
