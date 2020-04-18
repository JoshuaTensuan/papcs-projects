#ifndef CODE_COMPLEX_H_
#define CODE_COMPLEX_H_
#include <iostream>
#include <string>
#include <cmath>

class Complex {
public:
	double a;
	double b;
	Complex() {
		a = 0;
		b = 0;
	}
	Complex(double r) {
		a = r;
		b = 0;
	}
	Complex(double r, double i) {
		a = r;
		b = i;
	}
	~Complex() {
	}
	string tostring(double in) {
		string ans = std::to_string(in);
		ans = ans.erase(ans.find_last_not_of('0') + 1, std::string::npos);
		if (ans[ans.length() - 1] == '.') {
			return ans.substr(0, ans.length() - 1);
		}
		return ans;
	}
	string tostring() {
		if (std::abs(b) < 0.00001) {
			b = 0;
			if (std::abs(a - M_E) < 0.00001) {
				a = M_E;
				return "e";
			}
			if (std::abs(a - M_PI) < 0.00001) {
				a = M_PI;
				return "pi";
			}
			return tostring(a);
		}
		if (std::abs(a) < 0.00001) {
			a = 0;
			if (std::abs(b - 1) < 0.00001) {
				b = 1;
				return "i";
			}
			if (std::abs(b + 1) < 0.00001) {
				b = -1;
				return "-i";
			}
			return tostring(b) + "i";
		}
		if (std::abs(b - 1) < 0.00001) {
			b = 1;
			return tostring(a) + " + i";
		}
		if (std::abs(b + 1) < 0.00001) {
			b = -1;
			return tostring(a) + " - i";
		}
		if (b > 0) {
			return tostring(a) + " + " + tostring(b) + "i";
		}
		return tostring(a) + " - " + tostring(-b) + "i";
	}
	bool operator==(double other) {
		return std::abs(b) < 0.00001 && std::abs(a - other) < 0.00001;
	}
	bool operator==(Complex other) {
		return std::abs(a - other.a) < 0.00001 && std::abs(b - other.b) < 0.00001;
	}
	Complex operator+(Complex x) {
		return Complex(a + x.a, b + x.b);
	}
	Complex operator+(double x) {
		return Complex(a + x, b);
	}
	Complex operator-(Complex x) {
		return Complex(a - x.a, b - x.b);
	}
	Complex operator-(double x) {
		return Complex(a - x, b);
	}
	Complex operator*(Complex x) {
		return Complex(a * x.a - b * x.b, a * x.b + b * x.a);
	}
	Complex operator*(double x) {
		return Complex(a * x, b * x);
	}
	Complex operator/(Complex x) {
		double k = x.a * x.a + x.b * x.b;
		return Complex((a * x.a + b * x.b) / k, (b * x.a - a * x.b) / k);
	}
	Complex operator/(double x) {
		return Complex(a / x, b / x);
	}
	static Complex exp(Complex x) {
		return Complex(std::cos(x.b), std::sin(x.b)) * std::exp(x.a); //fix
	}
	static Complex ln(Complex x) {
		return Complex(0.5 * log(x.a * x.a + x.b * x.b), atan2(x.b, x.a));
	}
	Complex operator^(Complex x) {
		if (a == 0 && b == 0) {
			if (x.b == 0 && x.a > 0) {
				return 0;
			}
			//error
		}
		return exp(ln(*this) * x);
	}
	Complex operator^(double x) {
		return exp(ln(*this) * x);
	}
	static Complex sin(Complex x) {
		Complex t = exp(x * Complex(0, 1));
		return Complex(0, 0.5) * (Complex(1) / t - t);
	}
	static Complex cos(Complex x) {
		Complex t = exp(Complex(0, 1) * x);
		return Complex(0.5, 0) * (t + Complex(1) / t);
	}
	static Complex tan(Complex x) {
		return sin(x) / cos(x);
	}
	static Complex csc(Complex x) {
		return Complex(1) / sin(x);
	}
	static Complex sec(Complex x) {
		return Complex(1) / cos(x);
	}
	static Complex cot(Complex x) {
		return cos(x) / sin(x);
	}
	static Complex arcsin(Complex x) {
		return Complex(0, -1) * ln(Complex(0, 1) * x + ((Complex(1) - x * x) ^ 0.5));
	}
	static Complex arccos(Complex x) {
		return Complex(0, -1) * ln(x + ((x * x - 1) ^ 0.5));
	}
	static Complex arctan(Complex x) {
		return Complex(0, 0.5) * ln((Complex(1) - Complex(0, 1) * x) / (Complex(1) + Complex(0, 1) * x));
	}
	static Complex arccsc(Complex x) {
		return arcsin(Complex(1) / x);
	}
	static Complex arsec(Complex x){
		return arccos(Complex(1) / x);
	}
	static Complex arccot(Complex x) {
		return arccot(Complex(1) / x);
	}
};

#endif /* CODE_COMPLEX_H_ */
