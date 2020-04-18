#include "dmatrix.h"
#include "smatrix.h"
#include <iostream>

using namespace std;

void dmatrix_test()
{
    dmatrix a = dmatrix(2, 2);
    dmatrix b = dmatrix(2, 2);

    float ar[2][2] = {
        {1, 1},
        {1, 1}};
    float br[2][2] = {
        {3, 0},
        {0, 4}};

    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            a.set(i, j, ar[i][j]);
        }
    }
    for (int i = 0; i < b.getRows(); i++)
    {
        for (int j = 0; j < b.getCols(); j++)
        {
            b.set(i, j, br[i][j]);
        }
    }
    dmatrix c = a.multiply(b);
    c.print();
    a.~dmatrix();
    b.~dmatrix();
    c.~dmatrix();
}

void smatrix_test()
{
    // smatrix *d = new smatrix(2,2);
    smatrix d = smatrix(2,2);
    d.set(0, 1, 8);
    d.set(0, 0, 4);
    
    d.set(1, 1, 1);
    smatrix e = smatrix(2, 3);
    e.set(0, 0, -6);
    e.set(1, 0, 3);
    e.set(1, 1, 11);
    smatrix f = d.multiply(e);
    d.print();
    e.print();
    f.print();
    d.~smatrix();
    e.~smatrix();
    f.~smatrix();
    // cout << "print worked" << endl;
}

void smatrix_convert()
{
    dmatrix a = dmatrix(2, 2);
    dmatrix b = dmatrix(2, 3);

    float ar[2][2] = {
        {1, 5},
        {1, 3}};
    float br[2][3] = {
        {0, 4, 5},
        {2, 0, 0}};

    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            a.set(i, j, ar[i][j]);
        }
    }
    for (int i = 0; i < b.getRows(); i++)
    {
        for (int j = 0; j < b.getCols(); j++)
        {
            b.set(i, j, br[i][j]);
        }
    }
    dmatrix c = a.multiply(b);
    c.print();
    cout << endl;
    smatrix b_conv = smatrix(b);
    b_conv.print();
}
int main(int argc, char *argv[])
{
    // smatrix_convert();
   smatrix_test();
// dmatrix_test();
}