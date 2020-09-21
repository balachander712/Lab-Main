#include <iostream>
using namespace std;


class Node{

    int data;
    int height;
    Node* leftChild;
    Node* rightChild;
public:
    Node(int);
    friend class Tree;
};

Node:: Node(int value){
    data = value;
    height = 0;
    leftChild = NULL;
    rightChild = NULL;
}


class Tree{

public:
    Node* root;
    Tree() { root = NULL; };
    void insert(Node*&,int);
    void traverseInOrder(Node*&);
    void LLRotation(Node*&);
    void LRRotation(Node*&);
    void RRRotation(Node*&);
    void RLRotation(Node*&);
    int getNodeHeight(Node*&);
    int getBalanceFactor(Node*&);

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

    node->height = getNodeHeight(node);

    if(getBalanceFactor(node) == 2  && getBalanceFactor(node->leftChild) == 1){
        //perform LL rotation
        LLRotation(node);
        traverseInOrder(root);
    }
    else if(getBalanceFactor(node) == 2 && getBalanceFactor(node->leftChild) == -1){
        //perform LR rotation
        LRRotation(node);
        traverseInOrder(root);
    }
    else if(getBalanceFactor(node) == -2 && getBalanceFactor(node->rightChild) == -1){
        //perform RR rotation
        RRRotation(node);
        traverseInOrder(root);
    }
    else if(getBalanceFactor(node) == -2 && getBalanceFactor(node->rightChild) == 1){
        // perform RL rotation
        RLRotation(node);
        traverseInOrder(root);
    }

        
}

void Tree::LLRotation(Node*& node){

    Node* left = node->leftChild;
    Node* leftRight = left->rightChild;

    left->rightChild = node;
    node->leftChild = leftRight;

    node->height = getNodeHeight(node);
    left->height = getNodeHeight(left);

    if(root == node) root = left;
}

void Tree::LRRotation(Node*& node){

    Node* left = node->leftChild;
    Node* leftRight = left->rightChild;
    Node* leftRightLeft = leftRight->leftChild;
    Node* leftRightRight = leftRightLeft->rightChild;

    leftRight->rightChild = node;
    leftRight->leftChild = left;
    node->rightChild = leftRightRight;
    left->leftChild = leftRightLeft;

    leftRight->height = getNodeHeight(leftRight);
    node->height = getNodeHeight(node);
    left->height = getNodeHeight(left);

    if(root == node) root = leftRight;
}


void Tree::RRRotation(Node*& node){

    Node* right = node->rightChild;
    Node* rightLeft = right->leftChild;

    right->leftChild = node;
    node->rightChild = rightLeft;

    right->height = getNodeHeight(right);
    node->height = getNodeHeight(node);

    if(root == node) root = right;
}

void Tree::RRRotation(Node*& node){

    Node* right = node->rightChild;
    Node* rightLeft = right->leftChild;
    Node* rightLeftLeft = rightLeft->leftChild;
    Node* rightLeftRight = rightLeft->rightChild;

    rightLeft->leftChild = node;
    rightLeft->rightChild = right;
    node->rightChild = rightLeftLeft;
    right->leftChild = rightLeftRight;

    rightLeft->height = getNodeHeight(rightLeft);
    node->height = getNodeHeight(node);
    right->height = getNodeHeight(right);

    if(root == node) root = rightLeft;
}

int Tree:: getNodeHeight(Node*& node){

    int left,right;

    left = node->leftChild == NULL ? 0 : node->leftChild->height;
    right = node->rightChild == NULL ? 0 : node->rightChild->height;

    return left > right ? left + 1 : right + 1;
}

int Tree:: getBalanceFactor(Node*& node){
    int left,right;

    left = node->leftChild == NULL ? 0 : node->leftChild->height;
    right = node->rightChild == NULL ? 0 : node->rightChild->height;

    return left - right;
}

void Tree:: traverseInOrder(Node*& node){
    if(node != NULL){
        traverseInOrder(node->leftChild);
        cout << node->data << " ";
        traverseInOrder(node->rightChild);
    }
}

int main(){

    return 0;
}