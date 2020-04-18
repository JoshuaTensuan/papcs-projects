#ifndef CODE_CALC_STACK_H_
#define CODE_CALC_STACK_H_
#include <cstdlib>
using namespace std;

template <class E> struct snode {
	snode* next;
	E data;
	snode() {
		data = 0;
		next = nullptr;
	}
	snode(snode* a) {
		data = 0;
		next = a;
	}
	snode(E d) {
		data = d;
		next = nullptr;
	}
	snode(snode* a, E d) {
		next = a;
		data = d;
	}
};
template<class E> class stack {
public:
	unsigned int length;
	snode<E>* head;
	stack() {
		length = 0;
		head = nullptr;
	}
	~stack() {
		for (; head != nullptr;) {
			snode<E>* t = head->next;
			delete head;
			head = t;
		}
	}
	E peek() {
		return head->data;
	}
	void push(E push) {
		head = new snode<E>(head, push);
		++length;
	}
	E pop() {
		--length;
		snode<E>* t = head;
		E ans = t->data;
		head = head->next;
		delete t;
		return ans;
	}
};



#endif /* CODE_CALC_STACK_H_ */
