#include <iostream>
#include <fstream>
#include "graph.hpp"
#include "point.hpp"

using namespace std;

void test_edges_dist() {
    // Global Parameters
    int trials = 200;
    int max_d = 29; // total sqrt(delta x squared + delta y squared) based off plot parameters in point.hpp
    int points = 50;


    double arr_edges[max_d + 1];
    for(int j = 0; j < max_d + 1; j++) {
        arr_edges[j] = 0;
    }

    for(int t = 0; t < trials; t++) {
        for(int d = 0; d < max_d + 1; d ++) {
            graph a = graph(d);
            for(int i = 0; i < points; i++) {
                a.add_point();
            } 
            arr_edges[d] += a.get_count_edges() / ((points * (points - 1)) / 2); // should return (points(points - 1))/2 at max d (when unscaled)
            // scaled arr_edges to be proportioned for all # points, can fit on same graph
        } 
        cout << "Trial " << t+1 << " done" << endl;
    }

    ofstream ofs;
    ofs.open("edges" + to_string(points) + ".txt", ofstream::out | ofstream::trunc);
    ofs.close();

    ofs.open("edges" + to_string(points) + ".txt");
    for(int c = 0; c < max_d + 1; c++) {
        cout << c << "::" << arr_edges[c] / (double) trials << " ";
        ofs << c << " " << arr_edges[c] / (double) trials << "\n"; 
    }
    cout << endl;

}

void test_connectedness() {
    // Global Parameters
    int trials = 4; // trials of entire experiment
    int utrials = 60; // trials at each d to get probability of connectedness
    int max_d = 29; // total sqrt(delta x squared + delta y squared) based off plot parameters in point.hpp
    int points = 50;


    double arr[max_d + 1];
    for(int j = 0; j < max_d + 1; j++) {
        arr[j] = 0;
    }

    double conn = 0;
    graph a = graph(10);
    for(int t = 0; t < trials; t++) {
        for(int d = 0; d < max_d + 1; d ++) {
            conn = 0;
            for(int h = 0; h < utrials; h++) {
                graph a = graph(d);
                for(int i = 0; i < points; i++) {
                    a.add_point();
                } 
                if(a.check_connectedness()) {
                    conn++;
                } 
            } 
            arr[d] += conn / (double) utrials; // add probability
        }
        cout << "Trial " << t+1 << " done" << endl;
    }

    ofstream ofs;
    ofs.open("connected" + to_string(points) + ".txt", ofstream::out | ofstream::trunc);
    ofs.close();

    ofs.open("connected" + to_string(points) + ".txt");
    for(int c = 0; c < max_d + 1; c++) {
        cout << c << "::" << arr[c] / (double) trials << " ";
        ofs << c << " " << arr[c] / (double) trials << "\n"; 
    }
    cout << endl;

}

int main() { 
    test_connectedness();
    // test_edges_dist();
}