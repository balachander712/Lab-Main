#include <iostream>
using namespace std;
class Node{
    Node *link;
    int data;
    public:
    static Node *start;
    Node(){
        link=NULL;
        data=0;
    }
    Node(int);
    void insert(Node*,int);
    void print(Node*);
};

Node *Node::start=NULL;
Node::Node(int d){
    link=NULL;
    data=d;
}

void Node::insert(Node *t,int data){
    if(t==NULL){
        start=new Node(data);
    }
    else{
        while(t->link!=NULL){
            t=t->link;
        }
        t->link=new Node(data);
    }
}
void Node::print(Node *t){
    while(t!=NULL){
        cout<<"Data : "<<t->data<<"\n";
        t=t->link;
    }
}


int main(){
    Node ob;
    Node::start=new Node(10);
    cout<<"Start : "<<Node::start<<"\n";
    ob.insert(Node::start,20);
    cout<<"Start : "<<Node::start<<"\n";
    ob.print(Node::start);
    ob.insert(Node::start,30);
    ob.print(Node::start);
    ob.insert(Node::start,30);
    ob.print(Node::start);

    return 0;
}
