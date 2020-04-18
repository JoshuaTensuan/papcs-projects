#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <utility>
#include <stdio.h>
#include <chrono>
#include <fstream>
#include "daryheap.h"
#include "graph.h"

using namespace std;

void test_dary_heap() {
    daryheap a = daryheap(5);
    a.insert(make_pair(1,0));
    a.insert(make_pair(2,0));
    // a.insert(make_pair(3,0));
    // a.insert(make_pair(4,0));
    // a.insert(make_pair(5,0));
    // a.insert(make_pair(-1,0));
    // a.insert(make_pair(8,0));
    // a.insert(make_pair(6,0));
    cout << a.empty() << endl;
    // a.remove(make_pair(0,3));
    // a.print();
}

void test_graph() {
    // create the graph given in above fugure 
    int V = 9; 
    Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7);   

    cout << "Start shortest path algo" << endl;
    auto start = chrono::high_resolution_clock::now();
    g.shortestPath(0, 3); 
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast <chrono::milliseconds>(stop - start);
    cout << "Done shortest path in " << duration.count() << " milliseconds!" << endl;
}

void test_dijk(int d, int av) { // av is number of trials to run and average
    int V = 1632803; // number of nodes in graph
    // int V = 4847571;
    Graph g(V);

    // insert g data
    cout << "Start loading data" << endl;
    ifstream infile("soc-pokec-relationships.txt");
    // ifstream infile("soc-LiveJournal1.txt");
    int a, b;
    while (infile >> a >> b) {
        g.addEdge(a - 1, b - 1, 1); // data not zero-indexed
        // g.addEdge(a, b, 1); // data not zero-indexed
        // g.addEdge(b, a, 1); // if data is undirected
    }
    cout << "Starting shortest path algo" << endl;
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < av; i++) {
        g.shortestPath(0, d); 
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast <chrono::milliseconds>(stop - start);
    cout << "Done shortest path in average of " << (duration.count()/av) << " milliseconds with d of " << (d) << endl;
}

void bellman_ford(int src) {
    int V = 1632803; // number of nodes in graph
    // int V = 4847571;
    Graph g(V);

    // insert g data
    cout << "Start loading data" << endl;
    ifstream infile("soc-pokec-relationships.txt");
    int a, b;
    while (infile >> a >> b) {
        g.addEdge(a - 1, b - 1, 1); // data not zero-indexed
        // g.addEdge(a, b, 0); // data not zero-indexed
        // g.addEdge(b, a, 1); // if data is undirected
    }

    cout << "Start bellman-ford algo" << endl;
    list<pair<int,int>>* list = g.get_list();
    int dist[V];
    // int pred[V];
    for(int i = 0; i < V; i++) {
        dist[i] = INF;
        // pred[i] = ;
    }
    dist[src] = 0;
    for(int j = 1; j < V; j++) {
        for(int e = 0; e < V; e++) {
            auto it1 = std::next(list -> begin(), e);
            if(dist[e] + 1 < dist[it1 -> first]) {
                dist[it1 -> first] = dist[e] + 1;
            }
        }
    }

    ofstream outfile;
    outfile.open("verify.txt");
    for(int x = 0; x < V; x++) {
        outfile << ("%d \t\t %d\n", x, dist[x]) << endl; 
    }
    cout << "done" << endl;
}


bool verify(Graph g, int V) { // using floyd-warshall's algo
    return true;
}


int main() {
    // test_graph();
    // test_dary_heap();
    // test_dijk(2,5);
    // test_dijk(3, 5); // average 5 runs
    test_dijk(4, 3); // average 5 runs
    // test_dijk(5, 5); // average 5 runs
    // test_dijk(6, 5); // average 5 runs
    // test_dijk(7, 5); // average 5 runs
    // test_dijk(8, 5); // average 5 runs
    // test_dijk(9, 5); // average 5 runs
    // test_dijk(10, 5); // average 5 runs
    // test_dijk(11, 5); // average 5 runs
    // test_dijk(12, 5); // average 5 runs
    // test_dijk(13, 5); // average 5 runs
    // test_dijk(14, 5); // average 5 runs
    // test_dijk(32, 5); // average 5 runs
    // test_dijk(16, 5); // average 5 runs
    // test_dijk(17, 5); // average 5 runs
    // bellman_ford(0);
} 