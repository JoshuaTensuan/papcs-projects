#include <iostream>
#include "daryheap.h"
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

typedef pair<int, int> iPair;

using namespace std;

daryheap::daryheap() {
    vec_heap = new vector<pair<int, int>>();
}

daryheap::daryheap(int num) {
    d = num;
    vec_heap = new vector<pair<int,int>>();
}

int daryheap::test() {
    return vec_heap -> at(1).first;
}

iPair daryheap::get_min() {
    return vec_heap -> at(0);
}

bool daryheap::empty() {
    return vec_heap -> size() <= 0;
}

void daryheap::pop() {
    iPair temp = vec_heap -> at(vec_heap -> size() - 1);
    vec_heap -> at(0) = temp;
    // cerr << vec_heap -> size() << endl;
    vec_heap -> resize(vec_heap -> size() - 1);
    sift_down(0, vec_heap -> size() - 2);
}

void daryheap::insert(pair<int, int> add) {
    vec_heap -> push_back(add);
    // cerr << "adding works" << endl;
    sift_up(vec_heap -> size() - 1);
    
    // insert sift up algorithm
}

int daryheap::index_child(int index, int n) { // where n is zero-indexed
    return d * index + (n + 1);
} 

int daryheap::index_parent(int index) {
    if(index == 0) {
        return 0;
    } else {
        return (index - 1) / d;
    } // maybe fix
}

void daryheap::sift_up(int i) {
    int p = index_parent(i);
    if((vec_heap -> at(i)).first < (vec_heap -> at(p)).first) {
        iPair temp = vec_heap -> at(i);
        vec_heap -> at(i) = vec_heap -> at(p);
        vec_heap -> at(p) = temp;
        if(p > 0) {
            sift_up(p);
        }
    }
} // min daryheap sift_up

void daryheap::sift_down(int index, int end) {
    int i = 0;
    if(index_child(index, 0) <= end) {
        while(i < d) {
            if(index_child(index, i) <= end) {
                if((vec_heap -> at(index_child(index, i))).first >= (vec_heap -> at(index)).first) {
                    i++;
                } else {
                    break;
                }
            } else {
                i = -1;
                break;
            }
        }
        if(i != -1) {
            if(vec_heap -> at(index).first > vec_heap -> at(index_child(index, i)).first) {
                iPair temp = vec_heap -> at(index_child(index, i));
                vec_heap -> at(index_child(index, i)) = vec_heap -> at(index);
                vec_heap -> at(index) = temp;
                sift_down(index_child(index, i), end);
            }
        }
    }
} // min daryheap sift_down

void daryheap::remove(int index) {
    iPair temp = vec_heap -> at(vec_heap -> size() - 1);
    vec_heap -> at(index) = temp;
    vec_heap -> resize(vec_heap -> size() - 1);
    sift_down(index, vec_heap -> size() - 1);
}

void daryheap::print() {
    int a = 0;
    int b = 0;
    for(int i = 0; i < vec_heap -> size(); i++){
        iPair x = vec_heap -> at(i);
        cout << x.first << " ";
        b++;
        if(b % (int) pow(d, a) == 0) {
            cout << endl;
            a++;
            b = 0;
        }
    }
    cout << endl;
}

vector<iPair>* daryheap::get_heap() {
    return vec_heap;
}

// int* daryheap::get_arr() {
//     int *a = new int[vec_heap -> size()];
//     for(int i = 0; i < vec_heap -> size(); i++) {
//         a[i] = vec_heap -> at(i);
//     }
//     return a;
// }



