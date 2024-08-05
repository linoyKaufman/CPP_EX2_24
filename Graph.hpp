// 206971962 / kaufmanlinoy@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <utility>
#include <ostream>
#include <iostream>

using namespace std;
namespace ariel {
    class Graph {
    private:
        bool directed;
        std::vector<std::vector<int>> Matrix;


    public:
  
    Graph() ; 
    ~Graph() ; 
        bool isvalid(const std::vector<std::vector<int>> &mat);
        void loadGraph(const std::vector<std::vector<int>> &matrix);
        void printGraph() const;
        size_t size() const{
            return this->Matrix.size();}
        friend bool isSameSize(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2);
        void cleanGraph();

        std::vector<std::size_t> getNeighbors(std::size_t node) const ;
        friend ostream& operator<< (ostream& o, const Graph& gr);
        
        friend Graph operator+(const Graph& g1,const Graph& g2);
        friend Graph operator-(const Graph& g1,const Graph& g2);
        void operator+=(const Graph& g1);
        void operator-=(const Graph& g1);
        bool operator==( Graph& g) ;
        bool operator>(Graph& g1) ;
        bool isContaine(Graph& g1);
        bool operator<(Graph& g1);
        bool operator<= (Graph& g1);
        bool operator >= (Graph& g1);
        bool operator!= (Graph& g1);
        void operator++();
        void operator--();
        void operator*(int)const;

        int getEdges() const;
        Graph operator*(Graph &g1);
        Graph operator+() const;
        void operator*=(int num);
        void operator/=(int num);

        bool isEdge(size_t from, size_t to) const {
            return Matrix[from][to] != 0;
        }
        std::vector<std::vector<int>> getMatrix() const {
            return Matrix;
        }
    };
    using StartNode = size_t;
}
#endif