#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Graph{
    map<int,list<int>> L;

public:
    void addEdge(int,int);
    void adjVertices(int);
    void bfsTraversal(int);
    void dfsTraversal(int);
    void dfsWrapper(int,map<int,bool>&);

};

void Graph::addEdge(int x, int y){
    L[x].push_back(y);
    L[y].push_back(x);
}

void Graph::adjVertices(int src){

    list<int> vertices = L[src];

    for(int i : vertices){
        cout << i << " ";
    }

}

void Graph::bfsTraversal(int src){
    map<int,bool> visited;
    queue<int> Q;

    Q.push(src);
    visited[src] = true;

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();

        cout << node << " ";

        for(int nbr : L[node]){
            if(!visited[nbr]){
                Q.push(nbr);
                visited[nbr] = true;
            }
        }

    }
}

void Graph::dfsWrapper(int src,map<int,bool> &visited){

    cout << src << " ";
    visited[src] = true;

    for(int nbr : L[src]){
        if(!visited[nbr]){
            dfsWrapper(nbr,visited);
        }
    }

}


void Graph::dfsTraversal(int src){
    map<int,bool> visited;

    for(auto i : L){
        int node = i.first;
        visited[node] = false;
    }

    dfsWrapper(src,visited);
}

int main(){

    Graph G;

    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(2,3);
    G.addEdge(1,2);
    G.addEdge(3,4);
    G.addEdge(4,5);

    G.adjVertices(0);
    //G.bfsTraversal(0);
    //G.dfsTraversal(0);

    return 0;
}