# Graphs

Throughout this project our team implemented the graph data structure consisting of series of points that share relation to one another, represented by edges. We also implemented many functions utilizing the properties of graphs that explored through this project.

## Prerequisites

In order to run the Markov Clustering algorithm, the Eigen 3 Library, in which version 3.3.7 is the latest stable version. This can be downloaded from [Eigen Main Page](http://eigen.tuxfamily.org/index.php?title=Main_Page). This is the only necessary library that must be downloaded in order to run our code.

## Data

Data used can be found in the data folder
All the data we used were various types of graphs such as directed and weighted, undirected and unweighted, etc. We imported all our data from [SNAP Database](https://snap.stanford.edu/data/). The methods that we have written interepret interesting properties of graphs such as being cyclic or not, clustering using multiple methods, indegree and outdegree, and max flow. 

## Code

Our code is made up of various hpp files:

#### [edge.hpp]
  * Makes a single edge object that contains source, destination, and weight info with a comparator that allows for minheaps based on edge weight to be created in analyser methods

#### [node.hpp]
  * Most basic object for each point in the graph containing the number of the node
  
#### [point.hpp]
  * Object representing each point of the graph that creates a node as well as retrieves it and its weight
  
#### [graph.hpp]
  * Object that creates and prints a collection of the points in the graph interrelated by edges as well as retrieves its properties
  
#### [analyser.hpp]
  * Contains all but one of the analysis funtions that can be run on the graphs, which writes the results to text files 
  
#### [mcl.hpp]
  * Contains our Markov Clustering Algorithm
  
#### [main.hpp]
  * Contains the method to create and import graphs as well as run funtions on those graphs


## Results

Results of the main method can be found in the results folder
