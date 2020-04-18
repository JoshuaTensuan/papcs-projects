#include "smatrix.h"
#include <iostream>
#include "node.h"

using namespace std;

smatrix::smatrix()
{
}

smatrix::smatrix(int r, int c)
{
    max_rows = r;
    max_cols = c;
    array_row = new node *[max_rows];
    for (int i = 0; i < max_rows; i++)
    {
        array_row[i] = nullptr;
    }
}

smatrix::smatrix(const dmatrix &d)
{
    float **ptr = d.getArr();
    max_rows = d.getRows();
    max_cols = d.getCols();
    array_row = new node *[max_rows];
    for (int x = 0; x < max_rows; x++)
    {
        array_row[x] = nullptr;
    }
    for (int i = 0; i < max_rows; i++)
    {
        for (int j = 0; j < max_cols; j++)
        {
            float val = ptr[i][j];
            if (val != 0)
            {
                node *n = new node();
                n->col = j;
                n->data = val;
                n->next = nullptr;
                if (array_row[i] == nullptr)
                {
                    array_row[i] = n;
                }
                else
                {
                    node *temp = array_row[i];
                    while (temp->next != nullptr)
                    {
                        temp = temp->next;
                    }
                    temp->next = n;
                }
            }
        }
    }
}

void smatrix::set(int r, int c, float value)
{
    if (r < max_rows && c < max_cols)
    {
        node *n = new node();
        n->col = c;
        n->data = value;
        if (array_row[r] == nullptr)
        {
            n->next = nullptr;
            array_row[r] = n;
        }
        else
        {
            if (array_row[r]->next == nullptr)
            {
                if(array_row[r] -> col > c) {
                    node *temp_ptr = array_row[r];
                    n -> next = temp_ptr;
                    array_row[r] = n;
                } else {
                    n -> next = nullptr;
                    array_row[r] -> next = n;
                }
            }
            else
            {

                node *temp_ptr = array_row[r];
                while (!(temp_ptr->next == nullptr) && temp_ptr->next->col < c)
                {
                    temp_ptr = temp_ptr->next;
                }
                node *after_ptr = temp_ptr->next;
                temp_ptr->next = n;
                n->next = after_ptr;
            }
        }
    }
    else
    {
        cout << "YOU'RE BAD" << endl;
    }
}

float smatrix::get(int r, int c) const
{
    node *p = array_row[r];
    while (p != nullptr && p->col < c)
    {
        p = p->next;
    }
    if (p != nullptr && p->col == c)
    {
        return p->data;
    }
    else
    {
        return 0.0;
    }
}

int smatrix::getRows() const
{
    return max_rows;
}

int smatrix::getCols() const
{
    return max_cols;
}

void smatrix::print() const
{
    for (int i = 0; i < max_rows; i++)
    {
        node *ptr = array_row[i];
        for (int j = 0; j < max_cols; j++)
        {
            if (ptr == nullptr)
            {
                cout << " - ";
            }
            else if (ptr->col > j)
            {
                cout << " - ";
            }
            else if (ptr->col == j)
            {
                cout << " " << ptr->data << " ";
                ptr = ptr->next;
            }
            else
            {
                cout << "YOU'RE BAD ";
            }
        }
        cout << endl;
    }
}

smatrix smatrix::add(const smatrix &b) const
{
    smatrix ret = smatrix(max_rows, max_cols);
    for (int i = 0; i < max_rows; i++)
    {
        node *lp = array_row[i];
        node *rp = b.getArrayPtrRow()[i];
        node *psum = nullptr;
        while (lp != nullptr || rp != nullptr)
        {
            float rv = 0;
            unsigned int rc = 0;
            if (lp == nullptr)
            {
                rv = rp->data;
                rc = rp->col;
                rp = rp->next;
            }
            else
            {
                if (rp == nullptr || lp->col < rp->col)
                {
                    rv = lp->data;
                    rc = lp->col;
                    lp = lp->next;
                }
                else
                {
                    if (rp->col < lp->col)
                    {
                        rv = rp->data;
                        rc = rp->col;
                        rp = rp->next;
                    }
                    else
                    {
                        rv = lp->data + rp->data;
                        rc = lp->col;
                        rp = rp->next;
                        lp = lp->next;
                    }
                }
            }

            if (rv != 0)
            {
                node *sum = new node();
                sum->col = rc;
                sum->data = rv;
                sum->next = nullptr;
                if (psum == nullptr)
                {
                    ret.getArrayPtrRow()[i] = sum;
                    psum = sum;
                }
                else
                {
                    psum->next = sum;
                    psum = sum;
                }
            }
        }
    }
    return ret;
}

smatrix smatrix::multiply(const smatrix &b) const
{
    if (max_cols != b.getRows())
    {
        cerr << "Invalid matrix multiplication" << endl;
        return smatrix();
    }
    smatrix *ret = new smatrix(max_rows, b.getCols());

    smatrix b_trans = b.transpose();
    for (int i = 0; i < max_rows; i++)
    {
        node *pmult = nullptr;
        for (int j = 0; j < b.getCols(); j++)
        {
            node *left_p = array_row[i];
            node *right_p = b_trans.getArrayPtrRow()[j];
            float return_val = 0;
            unsigned int return_col = j;
            while (left_p != nullptr && right_p != nullptr)
            {
                if (left_p->col < right_p->col)
                {
                    left_p = left_p->next;
                }
                else
                {
                    if (right_p->col < left_p->col)
                    {
                        right_p = right_p->next;
                    }
                    else
                    {
                        return_val += left_p->data * right_p->data;
                        left_p = left_p->next;
                        right_p = right_p->next;
                    }
                }
            }
            if (return_val != 0)
            {
                node *mult = new node();
                mult->col = return_col;
                mult->data = return_val;
                mult->next = nullptr;
                if (pmult == nullptr)
                {
                    ret->getArrayPtrRow()[i] = mult;
                    pmult = mult;
                }
                else
                {
                    pmult->next = mult;
                    pmult = mult;
                }
            }
        }
    }
    return *ret;
}

smatrix smatrix::transpose() const
{
    smatrix *ret = new smatrix(max_cols, max_rows);
    for (int i = 0; i < max_rows; i++)
    {
        node *temp = array_row[i];
        while (temp != nullptr)
        {
            node *n = new node();
            n->col = i;
            n->data = temp->data;
            if (ret->getArrayPtrRow()[temp->col] == nullptr)
            {
                n->next = nullptr;
                ret->getArrayPtrRow()[temp->col] = n;
            }
            else
            {
                node *temp_ptr = ret->getArrayPtrRow()[temp->col];
                while (temp_ptr->next != nullptr)
                {
                    temp_ptr = temp_ptr->next;
                }
                n->next = nullptr;
                temp_ptr->next = n;
            }
            temp = temp->next;
        }
    }
    return *ret;
}

node **smatrix::getArrayPtrRow() const
{
    return array_row;
}

smatrix::~smatrix()
{
    delete array_row;
}