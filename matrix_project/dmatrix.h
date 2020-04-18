#include "smatrix.h"

#ifndef DMATRIX_H_
#define DMATRIX_H_


class dmatrix {
    private:
        float** arr;
        int rows;
        int cols;
    public:
        dmatrix();
        dmatrix(int, int);
        dmatrix(const dmatrix &);
        float get(int, int) const;
        int getSize() const;
        int getRows() const;
        int getCols() const;
        void set(int, int, float);
        dmatrix multiply(const dmatrix &);
        void print() const;
        virtual ~dmatrix();
        float** getArr() const;
};



#endif