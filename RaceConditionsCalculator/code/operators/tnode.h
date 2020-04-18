#ifndef TNODE_H_
#define TNODE_H_
#include <iostream>
#include <string>
#include "../temps/Complex.h"

class tnode {
  public:
		virtual ~tnode(){}
        virtual Complex evaluate(Complex) = 0;
        virtual tnode* derivative() = 0;
        virtual unsigned int precedence() = 0;
        virtual tnode* compress() = 0;
        virtual string tostring() = 0;
        virtual tnode* chain(tnode*) = 0;
        virtual bool isnum() = 0;
        virtual bool isvar() = 0;
};

#endif
