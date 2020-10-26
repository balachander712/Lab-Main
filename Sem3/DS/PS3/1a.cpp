#include <bits/stdc++.h>

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

    for(auto j : L){
        dist[j.first] = INT32_MAX;
    }

    set<pair<int,string>> s;

    dist[src] = 0;
    s.insert(make_pair(0,src));

    while(!s.empty()){

        auto p = *(s.begin());
        string node = p.second;
        int nodeDist = p.first;
        s.erase(s.begin());

        for(auto childPair : L[node]){
            if(nodeDist + childPair.second < dist[childPair.first]){
                string dest = childPair.first;
                auto f = s.find(make_pair(dist[dest],dest));
                if(f != s.end()){
                    s.erase(f);
                }

                dist[dest] = nodeDist + childPair.second;
                s.insert(make_pair(dist[dest],dest));


            }
        }

    }

    for(auto d : dist){

        cout << d.first << " is located at a distance of " << d.second << endl;
    }

}

int main(){

    Graph G;
    G.addEdge("A","B",true,20);
    G.addEdge("B","D",true,40);
    G.addEdge("A","C",true,10);
    G.addEdge("C","D",true,40);
    G.addEdge("A","D",true,50);
    //G.addEdge("A","B",true,20);
    G.shortestPath("A");
    //G.printGraph(); 

    return 0;

}