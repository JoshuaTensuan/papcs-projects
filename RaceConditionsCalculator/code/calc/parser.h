#ifndef CODE_CALC_PARSER_H_
#define CODE_CALC_PARSER_H_
#include "calculator.h"
#include <vector>

struct function {
	bool parenthesis;
	tnode* tree;
	string name;
};
class parser {
public:
	vector<function> functions;
	parser() {
		functions = vector<function>();
	}
	~parser() {
		functions.clear();
	}
	string parse(string in) {
		if (in.length() > 5 && in.substr(0, 5) == "solve") {
			in = in.substr(5, in.length() - 5);
			unsigned int e = in.find('=');
			tnode* root = (new subtractnode(tree(in.substr(0, e)), tree(in.substr(e + 1, in.length() - e - 1))))->compress();
			root = (new subtractnode(new varnode(), new dividenode(root, root->derivative())))->compress();
			Complex ans = Complex(0.34, 0);
			for (unsigned int x = 0; x < 128; x++) {
				ans = root->evaluate(ans);
			}
			return ans.tostring();
		}
		if (in.find('=') == std::string::npos) {
			return tree(in)->compress()->tostring();
		}
		unsigned int e = in.find('=');
		functions.push_back(function());
		functions[functions.size() - 1].parenthesis = false;
		functions[functions.size() - 1].name = "";
		for (unsigned int x = 0; x < e; x++) {
			if (in[x] == '(') {
				functions[functions.size() - 1].parenthesis = true;
				break;
			}
			if (in[x] != ' ') {
				functions[functions.size() - 1].name += in[x];
			}
		}
		functions[functions.size() - 1].tree = tree(in.substr(e + 1, in.length() - e - 1));
		for (unsigned int y = 0; y < functions.size() - 1; y++) {
			if (functions[y].name == functions[functions.size() - 1].name) {
				functions[y] = functions[functions.size() - 1];
				functions.pop_back();
				return "";
			}
		}
		return "";
	}
	tnode* tree(string in) {
		for (int x = 0; x < (int)in.length(); x++) {
			for (unsigned int y = 0; y < functions.size(); y++) {
				if (in.length() - x >= functions[y].name.length() && in.substr(x, functions[y].name.length()) == functions[y].name) {
					tnode* f = functions[y].tree;
					unsigned int z = x + functions[y].name.length();
					for (; z < in.length() && in[z] == '\''; z++, f = f->derivative()->compress());
					if (functions[y].parenthesis) {
						if (in[z] != '(') {
							continue;
						}
						unsigned int m = z;
						z++;
						for (unsigned int par = 1; par != 0; z++) {
							if (in[z] == '(') {
								par++;
								continue;
							}
							if (in[z] == ')') {
								par--;
								continue;
							}
						}
						in = in.substr(0, x) + "(" + f->chain(tree(in.substr(m, z - m)))->compress()->tostring() + ")" + in.substr(z, in.length() - z);
					}
					else {
						in = in.substr(0, x) + "(" + f->tostring() + ")" + in.substr(z, in.length() - z);
					}
					x--;
					break;
				}
			}
		};
		return calculator::infix_to_tree(in);
	}
};

#endif /* CODE_CALC_PARSER_H_ */
