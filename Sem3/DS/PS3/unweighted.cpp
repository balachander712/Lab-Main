#include <iostream>
#include <list>

class Graph{

public:
    int vertices;
    std :: list<int> *L;
    Graph(int);
    void addEdge(int,int);
    void printGraph();
};

Graph::Graph(int vertices){
    this->vertices = vertices;
    L = new std:: list<int>[vertices];
}

void Graph::addEdge(int x, int y){
    L[x].push_back(y);
    L[y].push_back(x);
}

void Graph:: printGraph(){
    for(int i = 0; i < vertices; i++){
        std :: cout << "Vertex " << i << "-->"; 
        for( auto itr : L[i]){
            std :: cout << itr << ",";
        }
        std :: cout << std :: endl;
    }

   // std :: cout << std :: endl;
} 

int main(){

    Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,3);
    graph.addEdge(3,4);
    graph.addEdge(0,4);
    graph.printGraph();

    return 0;
}