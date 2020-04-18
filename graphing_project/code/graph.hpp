#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>
#include <iostream>
#include <math.h>

#include "point.hpp"

using namespace std;

class graph {
    public:
        graph(double d) {
            number_nodes = 0;
            nodes = new vector<point>();
            mat = new vector<vector<int>>();
            dist = d;
            count_edges = 0;
            visited = new vector<bool>();
        }
        vector<vector<int>>* get_graph() {
            return mat;
        }

        vector<point>* get_point() {
            return nodes;
        }

        void add_point() {
            nodes -> push_back(point());
            number_nodes++;
            visited -> push_back(false);
            vector<int> x;
            for(int i = 0; i < number_nodes; i++) {
                x.push_back(0);
            }
            mat = new vector<vector<int>>();
            for(int j = 0; j < number_nodes; j++) {
                mat -> push_back(x);
            }
            update_points(dist);
        }

        void add_point(double x, double y) {
            nodes -> push_back(point(x,y));
            ++number_nodes;
            visited -> push_back(false);
            vector<int> vec;
            for(int i = 0; i < number_nodes; i++) {
                vec.push_back(0);
            }
            mat = new vector<vector<int>>();
            for(int j = 0; j < number_nodes; j++) {
                mat -> push_back(vec);
            }
            update_points(dist);
        }

        void add_point(point p) {
            nodes -> push_back(p);
            ++number_nodes;
            visited -> push_back(false);
            vector<int> vec;
            for(int i = 0; i < number_nodes; i++) {
                vec.push_back(0);
            }
            mat = new vector<vector<int>>();
            for(int j = 0; j < number_nodes; j++) {
                mat -> push_back(vec);
            }
            update_points(dist);
        }

        int get_number_nodes() {
            return number_nodes;
        }

        void print() {
            if(number_nodes == 0) {

            } else {
                for(auto i = mat -> begin(); i != mat -> end(); i++) {
                    for(auto j = i -> begin(); j != i -> end(); j++) {
                        cout << *j << " ";
                    }
                    cout << endl;
                }
            }
        }

        void reset_points() {
            for(auto i = mat -> begin(); i != mat -> end(); i++) {
                for(auto j = i -> begin(); j != i -> end(); j++) {
                    *j = 0;
                }
            }
            visited = new vector<bool>();
            count_edges = 0;
        }

        void update_points(double d) {
            count_edges = 0;
            int a = 0;
            int b = 0;
            for(auto i = mat -> begin(); i != mat -> end(); i++) {
                b = 0;
                for(auto j = i -> begin(); j != i -> end(); j++) {
                    if(a != b) {
                        double xa = (nodes -> at(a)).x;
                        double ya = (nodes -> at(a)).y;
                        double xb = (nodes -> at(b)).x;
                        double yb = (nodes -> at(b)).y;
                        if(pow(pow(yb - ya, 2) + pow(xb - xa, 2), 0.5) <= d) {
                            *j = 1;
                            count_edges++;
                        } else {
                            *j = 0;
                        }
                    }
                    ++b;
                }
                ++a;
            }
            count_edges = count_edges / 2.0;
        }

        double get_count_edges() {
            return count_edges;
        }


        void dfs(int s) {
            visited -> at(s) = true;
            vector<int> lis = mat -> at(s);
            int j = 0;
            for(auto i = lis.begin(); i != lis.end(); i++) {
                if(*i == 1) {
                    if(!(visited -> at(j))) {
                        dfs(j);
                    }
                }
                j++;
            }
        }

        bool check_connectedness() {
            for(auto i = visited -> begin(); i != visited -> end(); i++) {
                *i = false;
            }
            dfs(0);
            bool connected = true;
            for(auto j = visited -> begin(); j != visited -> end(); j++) {
                if(!*j) {
                    connected = false;
                }
            }
            return connected;
        }
        

    private:
        vector<vector<int>> *mat;
        vector<point> *nodes;
        vector<bool> *visited;
        int number_nodes; // for quicker reference
        double dist;
        double count_edges;
};

#endif