#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 
#include <cstdlib>
#include <utility>
#include <iostream>
#include <stdio.h>
#include "daryheap.h"

typedef pair<int, int> iPair; 

using namespace std;
  
class Graph { 
    int V;   
    list< pair<int, int> > *adj; // adjacency list
  
public: 
    Graph(int);
    // add distance w between node u and node v
    void addEdge(int, int, int); 
    // prints shortest path from s 
    void shortestPath(int, int); 
    void shortestPathFrom(int, int, int);
    list <pair<int,int>>* get_list();

}; 


  
Graph::Graph(int V) { 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
void Graph::addEdge(int u, int v, int w) { 
    adj[u].push_back(make_pair(v, w)); 
    // adj[v].push_back(make_pair(u, w)); only if directed
} 

list<pair<int,int>>* Graph::get_list() {
    return adj;
}
  
void Graph::shortestPath(int src, int d) { 
    daryheap pq = daryheap(d);
    vector<int> dist(V, INF); // Create a vector for distances and initialize all distances as infinite (INF) 
    pq.insert(make_pair(0, src)); // Distance to self is 0
    dist[src] = 0; 
    while (!pq.empty()) { 
        // The first vertex in pair is the minimum distance vertex, extract it from priority queue. vertex label is stored in second of pair (it has to be done this way to keep the vertices sorted distance (distance must be first item in pair) 
        int u = pq.get_min().second; 
        pq.pop();  // problem with pop method
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent of u. 
            int v = (i) -> first; 
            int weight = (i) -> second; 
            //  If there is shorter path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 
    // Print shortest distances stored in dist[] 
    ofstream outfile;
    outfile.open("outfile.txt");
    for (int i = 0; i < V; ++i) {
        outfile << ("%d \t\t %d\n", i, dist[i]) << endl; 
    }
} 


void Graph::shortestPathFrom(int src, int ind, int d) {
    daryheap pq = daryheap(d);
    cerr << "before declaration" << endl;
    vector<int> dist(V, INF); // Create a vector for distances and initialize all distances as infinite (INF) 
    cerr << "after declaration of dist" << endl;
    pq.insert(make_pair(0, src)); // Distance to self is 0
    dist[src] = 0; 
    while (!pq.empty()) { 
        // The first vertex in pair is the minimum distance vertex, extract it from priority queue. vertex label is stored in second of pair (it has to be done this way to keep the vertices sorted distance (distance must be first item in pair) 
        int u = pq.get_min().second; 
        pq.pop(); 
  
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) { 
            // Get vertex label and weight of current adjacent of u. 
            int v = (i) -> first; 
            int weight = (i) -> second; 
            //  If there is shorter path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.insert(make_pair(dist[v], v)); 
            } 
        } 
        
    } 
    // Print shortest distances stored in dist[] 
    
    cout << "Shortest distance from Source to node " << ind << " is " << dist[ind] << endl;
} 
