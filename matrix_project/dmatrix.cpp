#include "dmatrix.h"
#include <iostream>

using namespace std;


int dmatrix::getRows() const{
    return rows;
}

float** dmatrix::getArr() const {
    return arr;
}

int dmatrix::getCols() const {
    return cols;
}

int dmatrix::getSize() const {
    return rows * cols;
}

float dmatrix::get(int i, int j) const {
    if(i >= 0 && i < rows && j >= 0 && j < cols) {
        return  arr[i][j];
    } else {
        cout << "Get() method was out of bounds" << endl;
        return 0;
    }
}

void dmatrix::set(int i, int j, float value) {
    if(i  >= 0 && i < rows && j >= 0 && j < cols) {
        arr[i][j] = value;
    } else {
        cout << "Out of bounds error." << endl; 
    }
}
dmatrix::dmatrix() {
    rows = 0;
    cols = 0;
}

dmatrix::dmatrix(int row, int col) {
    arr = new float*[row];
    for(int i = 0; i < row; i++) {
        arr[i] = new float[col];
    }
    rows = row;
    cols = col;
}

dmatrix dmatrix::multiply(const dmatrix &b) {
    if(getCols() != b.getRows()) {
        cout << "Not possible multiplication." << endl;
        dmatrix a = dmatrix(getRows(), getCols());
        return a;
    }
    dmatrix* ret = new dmatrix(getRows(), b.getCols());
    for(int i = 0; i < getRows(); i++) {
        for(int j = 0; j < b.getCols(); j++) {
            float value = 0;
            for(int k = 0; k < b.getRows(); k++) {
                value += get(i, k) * b.get(k, j);
            }
            ret -> set(i, j, value);
        }
    }
    return *ret;
}

dmatrix::dmatrix(const dmatrix &original) {
    rows= original.getRows();
    cols = original.getCols();
    arr = new float*[rows];
    for(int i = 0; i < rows; i++) {
        arr[i] = new float[cols];
    }
    float** ptr = original.getArr();
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            arr[row][col] = ptr[row][col];
        }
    }
}

void dmatrix::print() const {
    for(int x = 0; x < rows; x++) {
        for(int y = 0; y < cols; y++) {
            cout << get(x, y) << " ";
        }
        cout << endl;
    }
}

dmatrix::~dmatrix() {
    delete[] arr;
}