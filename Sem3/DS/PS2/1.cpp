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
    Node* left = node.leftChild;
    Node* leftRight = left->rightChild;

    left->rightChild = &node;
    node.leftChild = leftRight;

    node.height = getNodeHeight(node);
    left->height = getNodeHeight(*left);

    AVLTree temp;
    if(temp.root == &node){
        temp.root = left;
    }
    
}

void Node:: LRRotation(Node node){
    //implement rotations
    Node* left = node.leftChild;
    Node* leftRight = left->rightChild;
    Node* leftRightRight = leftRight->rightChild;
    Node* leftRightLeft = leftRight->leftChild;

    leftRight->rightChild = &node;
    leftRight->leftChild = left;
    left->rightChild = leftRightLeft;
    node.rightChild = leftRightRight;

    node.height = getNodeHeight(node);
    left->height = getNodeHeight(*left);
    leftRight->height = getNodeHeight(*leftRight);

    AVLTree temp;
    if(temp.root == &node){
        temp.root == leftRight;
    }
    
}

void Node:: RLRotation(Node node){
    //implement rotations
    
    Node* right = node.rightChild;
    Node* rightLeft = right->leftChild;
    Node* rightLeftLeft = rightLeft->leftChild;
    Node* rigthLeftRight = rightLeft->rightChild;

    rightLeft->rightChild = right;
    rightLeft->leftChild = &node;
    right->leftChild = rigthLeftRight;
    node.rightChild = rightLeftLeft;

    rightLeft->height = getNodeHeight(*rightLeft);
    node.height = getNodeHeight(node);
    right->height = getNodeHeight(*right);

    AVLTree temp;
    if(temp.root == &node){
        temp.root = rightLeft;
    }
}

void Node:: RRRotation(Node node){
    //implement rotations
    Node* right = node.rightChild;
    Node* rightLeft = right->leftChild;

    right->leftChild = &node;
    node.rightChild = rightLeft;

    node.height = getNodeHeight(node);
    right->height = getNodeHeight(*right);

    AVLTree temp;
    if(temp.root == &node){
        temp.root = right;
    }
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

public:

    static Node* root;
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