    // 206971962 / kaufmanlinoy@gmail.com
    #include "Graph.hpp"
    #include <iostream>
    #include <vector>
    #include <Algorithms.cpp>
    #include "Algorithms.hpp"
  

    namespace ariel {
    
    Graph::Graph() {}
    Graph::~Graph() {}
    void Graph::cleanGraph(){
        this->getMatrix();
    }

  
    //chek if the mat is valid (square matrix)
    bool Graph::isvalid(const std::vector<std::vector<int>>& mat)
    {
        if(mat.empty()){
    
            return false;
        }
        else{
            size_t size = mat.size(); // mat.size = num of rows
            for (const auto& row : mat) { // row is a const reference
                    if (row.size() != size) { // if the row size is not the same as the size of rows
                        return false;
                    }
                }
        }
        return true;
    }
    //send invalid the matrix and if true, load else, throw invalid gragh
    void Graph::loadGraph(const vector<vector<int> > &mat)
    {
        if(isvalid(mat)){
            this->Matrix = mat;
        }
        else{
            throw std::invalid_argument("invalid Matrix");
        }
    }
    //print num of vertices and edges
    void Graph::printGraph() const
    {
        int numVertices = Matrix.size();
        int numEdges = 0;
        for (const auto& row : Matrix)
        {
            for (int edge : row)
            {
                if (edge != 0)
                {
                    numEdges++;
                }
            }
        }
        cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << endl;
    }
    std::vector<std::size_t> Graph::getNeighbors(std::size_t node) const {
        std::vector<std::size_t> neighbors;
        const std::vector<int>& row = Matrix[node]; // Access the row corresponding to the node

        // Iterate over the row to find the neighbors (non-zero entries)
        for (std::size_t i = 0; i < row.size(); ++i) {
            if (row[i] != 0) {
                neighbors.push_back(i); // Add the index to the neighbors vector
            }
        }

        return neighbors;
    }
    //if the matrix are the same size
    bool isSameSize (const vector<vector<int>>& mat1, const vector<vector<int>>& mat2){
        if (mat1.size() != mat2.size())
        {
            return false;
        }
        for (size_t i = 0; i < mat1.size(); i++)
        {
            if(mat1[i].size() != mat2[i].size())
            {
                return false;
            }
        }
        return true;
    }
    
    Graph Graph::operator+() const {
    return *this;
    }
  
    Graph operator+(const Graph& g1, const Graph& g2) {
        if (!isSameSize(g1.getMatrix(), g2.getMatrix())) {
        throw std::invalid_argument("the matrices are not equal in size");
    }

        Graph g3;
        size_t n = g1.size();
        vector<vector<int>> helpGraph(n, vector<int>(n, 0));

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                helpGraph[i][j] = g1.getMatrix()[i][j] + g2.getMatrix()[i][j];
            }
        }

        g3.loadGraph(helpGraph);
        return g3;
    }
    Graph operator-(const Graph& g1, const Graph& g2) {
        if (!isSameSize(g1.getMatrix(), g2.getMatrix())) {
        throw std::invalid_argument("the matrices are not equal in size");
    }

        Graph g3;
        size_t n = g1.size();
        vector<vector<int>> helpGraph(n, vector<int>(n, 0));

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                helpGraph[i][j] = g1.getMatrix()[i][j] - g2.getMatrix()[i][j];
            }
        }

        g3.loadGraph(helpGraph);
        return g3;
    }

    Graph& Graph :: operator+=(const Graph& g1){
        if (!isSameSize(g1.getMatrix() , this->getMatrix())){
        throw std::invalid_argument("the matrices are not equal in size");
    

        Graph g3;
        size_t n = g1.size();
        vector<vector<int>> helpGraph(n, vector<int>(n, 0));

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                helpGraph[i][j] = g1.getMatrix()[i][j] + this->getMatrix()[i][j];
            }
        }

        g3.loadGraph(helpGraph);
        return g3;
    }
        
    }
    Graph& Graph :: operator-=(const Graph& g1){
        if (!isSameSize(g1.getMatrix() , this->getMatrix())){
        throw std::invalid_argument("the matrices are not equal in size");
    

        Graph g3;
        size_t n = g1.size();
        vector<vector<int>> helpGraph(n, vector<int>(n, 0));

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                helpGraph[i][j] = g1.getMatrix()[i][j] - this->getMatrix()[i][j];
            }
        }

        g3.loadGraph(helpGraph);
        return g3;
    }  
 }

    bool Graph::operator==(Graph& g1) {
    if (!isSameSize(g1.getMatrix() , this->getMatrix())){
        return false;
    size_t  n = g1.getMatrix().size();
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if(g1.getMatrix()[i][j] !=this->getMatrix()[i][j]){
                return false;
            }
        }
    }
    return true;

}
}
bool Graph::isContaine(Graph& g1){
    
    if (g1.getMatrix().size()> this->getMatrix().size()){
        return false;  //g1 is bigger
    }
    for (size_t i = 0; i < this->getMatrix().size(); i++)
    {
        for (size_t j = 0; i < this->getMatrix().size(); j++)
        {
            if(g1.getMatrix()[i][j]>=1 && g1.getMatrix()[i][j]>this->getMatrix()[i][j]){
                return false;
            }
        }
    }
    return true;
    
}
//if this>g1
bool Graph::operator>(Graph& g1) {
    
    if(g1.isContaine(*this)&& !isSameSize(g1.getMatrix(), this->getMatrix())){
        return true;
    }
    if(this->isContaine(g1)&& !isSameSize(g1.getMatrix(), this->getMatrix())){
        return false;
    }
    else if (this->getEdges() > g1.getEdges()){
        return true;
    }
    else if(this->size()> g1.size()){
        return true;
    }
    
return false;

}
//if this<g1
bool Graph::operator<(Graph& g1) {
 return !(*this > g1);
}
bool Graph::operator <= (Graph& g1){
    return (*this < g1) || (g1.operator==(*this));
}
bool Graph::operator >= (Graph& g1){
    return (*this > g1) || (g1.operator==(*this));
}
bool Graph::operator!= (Graph& g1){
    if( g1.operator==(*this)){
        return true;
    }
    return false;
}
void Graph::operator++(){
    size_t size = this->getMatrix().size();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            this->getMatrix()[i][j]=this->getMatrix()[i][j]+1;
        }
        
    }
    
}
void Graph::operator--(){
    size_t size = this->getMatrix().size();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            this->getMatrix()[i][j]=this->getMatrix()[i][j]-1;
        }
        
    }
    
}
    
}