#include <iostream>
#include <string>
#include <stack>
#include <limits.h>
#include "tnode.h"
#include "parser.h"

using namespace std; 

parser::parser() {

};

void parser::to_str(tnode* head) {
    if(head -> left != nullptr) {
        to_str(head -> left);
    }
    std::cout << head -> data << " ";
    if(head -> right != nullptr) {
        to_str(head -> right);
    }
};

parser::parser(std::string inp) {
    input = inp;
    for(int i=0; i < input.length(); i++) {
        if(input[i] == ' ') {
            input.erase(i,1);
        }
    }
    while(input.at(0) == '(' && input.at(input.length() - 1) == ')') {
        input = input.substr(1, input.length() - 2);
    }
} 

tnode* parser::create_tree(string postfix) {
    stack<tnode*> st;
    tnode *t = nullptr;
    tnode *t1 = nullptr;
    tnode *t2 = nullptr;
    for (int i=0; i< (postfix).length(); i++) 
        { 
        // If operand, simply push into stack 
        if (!isOperator(postfix[i])) 
        { 
            t = new tnode(postfix[i]); 
            st.push(t); 
        } 
        else // operator 
        { 
            t = new tnode(postfix[i]); 
  
            // Pop two top nodes 
            t1 = st.top(); // Store top 
            st.pop();      // Remove top 
            if(!(st.empty())) {    
                t2 = st.top(); 
                st.pop();
            } 
  
            //  make them children 
            t -> left = t1; 

            if(t2) {
                t -> right = t2;
            } 
  
            // Add this subexpression to stack 
            st.push(t); 
            
        } 
        t1 = nullptr;
        t2 = nullptr;
    } 
    t = st.top();
    st.pop();
    return t;
}

string parser::getPostFix(string input) {
    string infix = input;
    for(int i=0; i < infix.length(); i++) {
        if(infix[i] == ' ') {
            infix.erase(i,1);
        }
    }
    while(infix.at(0) == '(' && infix.at(infix.length() - 1) == ')') {
        infix = infix.substr(1, infix.length() - 2);
    }
    std::stack<char> st; 
    st.push('N'); 
    int l = infix.length(); 
    string ns; 
    for(int i = 0; i < l; i++) { 
        // If the scanned character is an operand, add it to output string. 
        if(infix[i] == '!' && infix[i+1] == '!') {
            i++;
            continue;
        }
        if(!isOperator(infix[i]))  {
            ns+=infix[i]; 
        }
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(infix[i] == '(') {
            st.push('('); 
        }
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(infix[i] == ')') { 
            while(st.top() != 'N' && st.top() != '(') { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            if(st.top() == '(') { 
                char c = st.top(); 
                st.pop(); 
            } 
        } 
         //If an operator is scanned 
        else { 
            while(st.top() != 'N' && precedence(infix[i]) <= precedence(st.top())) { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(infix[i]); 
        } 
    } 
    //Pop all the remaining elements from the stack 
    while(st.top() != 'N') { 
        char c = st.top(); 
        st.pop(); 
        ns += c; 
    } 
      
    return ns;
}

char parser::hasHigherPrecedence(char a, char b) {
    int a_prec = precedence(a);
    int b_prec = precedence(b);
    if(a_prec >= b_prec) {
        return a;
    } else {
        return b;
    }
}

int parser::precedence(char data) {
    switch(data) {
        case '&':  
            return 3;
        case '|':  
            return 3;
            break; 
        case '!':  
            return 4;
        case '>': //implies
            return 2;
        case '^': //xor
            return 3;
        case 'T':
            return -1;
        case 'F':
            return -1;
        default:
            return INT_MIN;
    }
};

bool parser::isOperator(char a) {
    switch(a) {
        case '&':  
            return true;
        case '|':  
            return true;
            break; 
        case '!':  
            return true;
        case '>': //implies
            return true;
        case '^': //xor
            return true;
        case 'T':
            return false;
        case 'F':
            return false;
        case '(':
            return true;
        case ')':
            return true;
        default:
            return false;
    }
}

string parser::removeWhiteSpace(string inp) {
    string out;
    for(int i = 0; i < inp.length(); i++) {
        if(inp[i] != ' ') {
            out += inp[i];
        }
    }
    return out;
}

bool parser::solve(string inp) {
    return create_tree(getPostFix(removeWhiteSpace(inp))) -> evaluate();
}

void parser::print2DUtil(tnode *root, int space)  
{  
    // Base case  
    if (root == NULL)  {
        return;  
    }
    int COUNT = 3; // distance between two levels
    space += COUNT;  
    print2DUtil(root->right, space);  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->data<<"\n";  
    print2DUtil(root->left, space);  
}  
  
void parser::print2D(tnode* root)  
{   
    print2DUtil(root, 0);  
}  
