#include <iostream>
using namespace std;

class Node{

    int data;
    Node* leftChild;
    Node* rightChild;
    int height;
public:
    Node();
    Node(int);
    void insert(int);
    int getNodeHeight(Node);
    int getBalanceFactor(Node);
    void LLRotation(Node);
    void LRRotation(Node);
    void RRRotation(Node);
    void RLRotation(Node);
    bool hasLeftChild();
    bool hasRightChild();
    void traverseInorder();
};

Node:: Node(){
    leftChild = NULL;
    rightChild = NULL;
    height = 0;
}

Node:: Node(int value){
    this->data = value;
}

void Node:: insert(int value){
    if(data < value){
        if(this->leftChild == NULL){
            leftChild = new Node(value);
        }
        else
        {
            leftChild->insert(value);
        }
        
    }
    else
    {
        if(this->rightChild == NULL){
            rightChild = new Node(value);
        }
        else
        {
            rightChild->insert(value);
        }
    }

    height = getNodeHeight(*this);

    if(getBalanceFactor(*this) == 2 && value < this->leftChild->data)
        LLRotation(*this);
    if(getBalanceFactor(*this) == 2 && value > this->leftChild->data)
        LRRotation(*this);
    if(getBalanceFactor(*this) == -2 && value > this->rightChild->data)
        RRRotation(*this);
    if(getBalanceFactor(*this) == -2 && value < this->rightChild->data)
        RLRotation(*this);

    
    traverseInorder();
}

void Node:: LLRotation(Node node){
    //implement rotations
}

void Node:: LRRotation(Node node){
    //implement rotations
}

void Node:: RLRotation(Node node){
    //implement rotations
}

void Node:: RRRotation(Node node){
    //implement rotations
}

void Node:: traverseInorder(){
    if(this->leftChild != NULL){
        this->traverseInorder();
    }

    cout << this->data << " " ;

    if(this->rightChild != NULL){
        this->traverseInorder();
    }
}

int Node:: getNodeHeight(Node node){
    
    int left,right;
    left = node.hasLeftChild() ? node.height : 0;
    right = node.hasRightChild() ? node.height : 0;

    return left > right ? left + 1 : right + 1;
}

int Node:: getBalanceFactor(Node node){

    int left,right;

    left = node.hasLeftChild() ? node.leftChild->height : 0;
    right = node.hasRightChild() ? node.rightChild->height : 0;

    return left - right;

}



bool Node:: hasLeftChild(){
    if(this->leftChild != NULL){
        return true;
    }

    return false;
}

bool Node:: hasRightChild(){
    if(this->rightChild !=NULL){
        return true;
    }

    return false;
}

class AVLTree{
    
    Node* root;
public:
    AVLTree();
    void insert(int);
    void traverseInorder();
};

AVLTree:: AVLTree(){
    root = NULL;
}

void AVLTree:: insert(int value){
    if(root == NULL){
        root = new Node(value);
    }
    else
    {
        root->insert(value);
    }
    
}

void AVLTree:: traverseInorder(){
    if(root != NULL){
        root->traverseInorder();
    }
    else
    {
        cout << "EMPTY TREE!!!" << endl;
    }
    
}

int main(){

    return 0;
}