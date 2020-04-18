#ifndef DARYHEAP_H_
#define DARYHEAP_H_

#include <string>
#include <vector>
#include <utility>

// iPair ==>  Integer Pair 
// typedef pair<int, int> iPair; 

using namespace std;

class daryheap {
    public:
        vector<pair<int, int>>* get_heap();
        daryheap(int);
        daryheap();
        void insert(pair<int, int>);
        pair<int, int> get_min();
        int index_parent(int);
        int index_child(int, int);
        void sift_up(int);
        void sift_down(int, int);
        // void sift_down();
        void remove(int);
        void print();
        int* get_arr();
        bool empty();
        void pop();
        int test();
    private:
        vector<pair<int, int>> *vec_heap;
        int d;
};

#endif