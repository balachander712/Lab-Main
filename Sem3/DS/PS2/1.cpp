#include <iostream>
using namespace std;

class Node{

    int data;
    Node* leftChild;
    Node* rightChild;
    int height;
public:
    Node();
};

Node:: Node(){
    leftChild = NULL;
    rightChild = NULL;
    height = 0;
}

class AVLTree{

};

int main(){

    return 0;
}