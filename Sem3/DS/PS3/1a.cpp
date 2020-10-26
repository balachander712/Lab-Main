#include <iostream>
#include <unordered_map>
#include<list>
#include <string>

using namespace std;


class Graph{
    unordered_map<string,list<pair<string,int>>> L;

public:
    void addEdge(string x, string y, bool isBir,int wt);
    void printGraph();
    void shortestPath(string);
};

void Graph::addEdge(string x, string y, bool isBir,int wt){
    L[x].push_back(make_pair(y,wt));
    if(isBir){
        L[y].push_back(make_pair(x,wt));
    }
}

void Graph::printGraph(){
    for(auto p : L){
        string city = p.first;
        list<pair<string,int>> nbrs = p.second;

        cout << city << "-->";
        for(auto nbr : nbrs){
            cout << nbr.first << "," << nbr.second << " ";
        }

        cout << endl;
    }
}

void Graph::shortestPath(string src){
    
    //Dijikstra algorithm

    unordered_map<string,int> dist;
     
}

int main(){

    Graph G;
    G.addEdge("A","B",true,20);
    G.addEdge("B","D",true,40);
    G.addEdge("A","C",true,10);
    G.addEdge("C","D",true,40);
    G.addEdge("A","D",false,50);
    //G.addEdge("A","B",true,20);
    G.printGraph(); 

    return 0;

}