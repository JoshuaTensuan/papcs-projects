#include <cstdlib>
#include <iostream>
#include <string>

#include "tnode.h"
#include "parser.h"

using namespace std;

int main() {
    parser a = parser();
    string ui;
    cout << "Enter: ";
    getline(cin, ui);
    while(ui.compare("exit") != 0) {
        string ans;
        for(int i = 0; i < ui.length(); ++i) {
            ui[i] = toupper(ui[i]);
        }
        if(a.solve(ui)) {
            ans = "true";
        } else {
            ans = "false";
        }
        cout << "Output: " << ans << endl;
        cout << "Enter: ";
        getline(cin, ui);
    }
}