#ifndef SMATRIX_H_
#define SMATRIX_H_

#include "node.h"
#include "dmatrix.h"
class smatrix {
    private:
        node** array_row;
        int max_rows;
        int max_cols;
    public:
        smatrix();
        smatrix(int, int);
        smatrix(const dmatrix &);
        smatrix transpose() const;
        float get(int, int) const;
        int getRows() const;
        int getCols() const;
        node** getArrayPtrRow() const;
        void set(int, int, float);
        smatrix multiply(const smatrix &) const;
        smatrix add(const smatrix &) const;
        void print() const;
        virtual ~smatrix();
};

#endif

