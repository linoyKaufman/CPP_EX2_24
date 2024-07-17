// 206971962 / kaufmanlinoy@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <utility>
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
        void Graph::cleanGraph();
        std::vector<std::pair<size_t , std::pair<size_t , int>>> getEdges() const;
        std::vector<std::size_t> getNeighbors(std::size_t node) const ;
        
        
        friend Graph operator+(const Graph& g1,const Graph& g2);
        friend Graph operator-(const Graph& g1,const Graph& g2);
        Graph& Graph :: operator+=(const Graph& g1);
        Graph& Graph :: operator-=(const Graph& g1);
        bool Graph::operator==( Graph& g) ;
        bool Graph::operator>(Graph& g1) ;
        bool Graph::isContaine(Graph& g1);
        bool Graph::operator<(Graph& g1);
        bool Graph::operator<= (Graph& g1);
        bool Graph::operator >= (Graph& g1);
        bool Graph::operator!= (Graph& g1);
        void Graph::operator++();
        void Graph::operator--();
        void Graph::operator*(int);
        Graph Graph::operator*(Graph& g1);

        
        
         Graph Graph::operator+() const ;

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