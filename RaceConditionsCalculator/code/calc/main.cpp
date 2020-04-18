#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "stack.h"
#include "calculator.h"
#include "../operators/tnode.h"
#include "../operators/powernode.h"
#include "../operators/cosnode.h"
#include "../operators/arcsinnode.h"
#include "../operators/arccosnode.h"
#include "../operators/numpowernode.h"
#include "../operators/varnode.h"
#include "../operators/tannode.h"
#include "../operators/arctannode.h"
#include "parser.h"

using namespace std;

int evaluate(string infix) {
    return 2; // return result of infix string
}

int main() {
    // // main.exe
    // ifstream infile;
    // infile.open("C:/calc/code/raceconditionscalculator/code/parse.txt"); //place of parse.txt file that comes from lua gui (should be able to run c++ exe in lua sim)
    // string parse2;
    // getline(infile, parse2);
    // infile.close();

    // // ifstream objfile;
    // // if(objfile.peek() == ifstream::traits_type::eof()) { // check if object file is empty
    // //     parser solver = parser();
    // //     objfile.close();
    // //     ofstream file_obj;
    // //     file_obj.open("../object.txt");
    // //     file_obj.write((char*)&solver, sizeof(solver)); // store object
    // //     file_obj.close();
    // // }

    // // ifstream readobj;
    // // parser solve_main;
    // // readobj.open("../object.txt", ios::in); 
    // // readobj.read((char*)&solve_main, sizeof(solve_main));
    // // readobj.close();

    // parser solver = parser();
    // // cout << "y2" << endl << "n" << endl;
    // // cout << parse2 << endl;
    // string answer = solver.parse(parse2);
    // // cout << "y3" << endl;


    // ofstream ofs;
    // ofs.open("C:/calc/code/raceconditionscalculator/code/parse.txt", ofstream::out | ofstream::trunc); //place of parse.txt file
    // ofs.close(); //deletes content of parse.txt file




    // // std::cout << "haha" << endl;
    // // cout << parse << endl;
    // // int x = evaluate(parse); 
    // // cout << solver.parse("1+1") << endl;
    // // cout << "y" << endl;
    // ofstream o;
    // o.open("C:/calc/code/raceconditionscalculator/code/trans.txt");
    // o << answer; //this text file wile then be read by the lua sim and get the output
    // o.close();
    // // ofstream ofs3;
    // // ofs.open("../object.txt", std::ofstream::out | std::ofstream::trunc);
    // // ofs.close();

    // // ofstream file_obj;
    // // file_obj.open("../object.txt");
    // // file_obj.write((char*)&solve_main, sizeof(solve_main)); // store object
    // // file_obj.close();

    parser solver = parser();
    string ui;
    cout << "Enter: ";
    std::getline(std::cin, ui);
    while(ui.compare("exit") != 0) {
        string ans = solver.parse(ui);
        cout << "Output: " << ans << endl;
        cout << "Enter: ";
        std::getline(std::cin, ui);
    }

    return 0;
}