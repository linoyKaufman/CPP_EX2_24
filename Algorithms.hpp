//206971962 / kaufmanlinoy@gmail.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <iostream>
#include <vector>
#include <stack> 
#include "Graph.hpp"


using namespace std;
namespace ariel{
    class Graph;

    class Algorithms
    {
        public:
        static int isConnected(const Graph &gr);
        static string shortestPath(const Graph &gr,size_t start, size_t end);
        static int isContainsCycle(const Graph &gr);
        static string isBipartite(const Graph &gr);
        static string negativeCycle(const Graph &gr);
    };
}
#endif