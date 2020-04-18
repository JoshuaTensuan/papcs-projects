#ifndef PARSER_H_
#define PARSER_H_

#include "tnode.h"

#include <string>

class parser {
    public:
        std::string post_order;
        std::string input;
        void to_str(tnode*);
        parser();
        parser(std::string);
        tnode* create_tree(std::string);
        bool isOperator(char);
        std::string getPostFix(std::string);
        char hasHigherPrecedence(char, char);
        int precedence(char);
        std::string removeWhiteSpace(std::string);
        void print2DUtil(tnode*, int);
        void print2D(tnode*);
        bool solve(std::string);
        
};

#endif