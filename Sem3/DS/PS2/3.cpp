#include <iostream>
#include <vector>
using namespace std;

class Node{

    int data;
    Node* leftChild;
    Node* rightChild;
public:
    Node(int);
    friend class Tree;
};

Node:: Node(int value){
    data = value;
    leftChild = NULL;
    rightChild = NULL;
};


class Tree{
    
public:
    Node* root;
    Tree() { root = NULL; };
    void insert(Node*&,int);
    void traverseInOrder(Node*&,vector<int>);

};

void Tree:: insert(Node*& node, int value){
    
    if(node == NULL){
        node = new Node(value);
        return;
    }

    else if(value < node->data){
        insert(node->leftChild, value);
    }
    else{
        insert(node->rightChild,value);
    }
}

void Tree:: traverseInOrder(Node*& node,vector<int> v){
    if(node != NULL){
        traverseInOrder(node->leftChild,v);
        cout << node->data << " ";
        v.push_back(node->data);
        traverseInOrder(node->rightChild,v);
    }
}

int main(){

    Tree tree;
    tree.insert(tree.root,10);
    tree.insert(tree.root,20);
    tree.insert(tree.root,-1);
    tree.insert(tree.root,5);
    tree.insert(tree.root,30);
    tree.insert(tree.root,50);
    tree.insert(tree.root,2);
    vector<int> v;
    tree.traverseInOrder(tree.root,v);
    cout << "Hello" << endl;

    for(int i = 0; i < v.size(); i++){
        cout << "Hey" << endl;
        cout << v[i] << " " << endl;
    }

    cout << "You Dumb idiot" << endl;

    return 0;
}