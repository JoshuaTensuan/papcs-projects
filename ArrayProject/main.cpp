//Joshua Tensuan

#include <iostream>
#include <cstdlib>
#include "array.h"
#include <string>
using namespace std;
void test() {
    // Testing with array of integers
    array<int> a =  array<int>(5);
    cout << ("Default array: ") << endl;
    for(int i = 0; i < 5; i++) {
        // Initialize array
        cout << (a.get(i)) << endl;
    }
    cout << endl;
    cout << ("--------------------------------------") << endl;
    cout << ("a.get(3) value: ") << endl;
    cout << (a.get(3)) << endl;
    cout << endl;
    cout << ("Setting the value at index 3 to 8") << endl;
    a.set(3, 8);
    cout << ("New a.get(3) value: ") << endl;
    cout << (a.get(3)) << endl << endl;
    cout << ("New Array: ") << endl;
        for(int i = 0; i < 5; i++) {
        cout << (a.get(i)) << endl;
    }
    a.~array(); // destruct

    cout << "---------------------------------" << endl << endl << endl << "String testing" << endl;

    // Testing with array of strings
    array<string> b = array<string>(5);
    cout << ("Default Array: ") << endl;
    for(int i = 0; i < 5; i++) {
        cout << (b.get(i)) << endl;
    }
    cout << endl;
    cout << ("--------------------------------------") << endl;
    cout << ("b.get(3) value: ") << endl;
    cout << (b.get(3)) << endl;
    cout << endl;
    cout << ("Setting the value at index 3 to food") << endl;
    b.set(3, "food");
    cout << ("New a.get(3) value: ") << endl;
    cout << (b.get(3)) << endl;
    cout << ("---------------------------------") << endl;
    cout << (" New Array: ") << endl;
    for(int i = 0; i < 5; i++) {
        cout << (b.get(i)) << endl;
    }
    
    b.~array(); // destruct
}
int main() {
    test();

    return 0;
}