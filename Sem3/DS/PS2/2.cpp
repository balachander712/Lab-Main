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
    Tree() { root = NULL; }
    void insert(Node*&,int);
    void deleteNode(Node*&,int);
    Node* LLRotation(Node*&);
    Node* RRRotation(Node*&);
    int getBalanceFactor(Node*& node);
    int getNodeHeight(Node*&);
    void traverseInOrder(Node*&);
    int getMinValue(Node*&);
    int max(int,int);
};

void Tree:: insert(Node*& node, int value){
    
    if(node == NULL){
        node = new Node(value);
        node->height = 1;
        return;
    }

    else if(value < node->data){
        insert(node->leftChild, value);
    }
    else{
        insert(node->rightChild,value);
    }

    node->height = 1 + max(getNodeHeight(node->leftChild), getNodeHeight(node->rightChild));

    int balanceFactor = getBalanceFactor(node);

    if(balanceFactor > 1 && value < node->leftChild->data){
        node = LLRotation(node);
        traverseInOrder(root);
    }
    if(balanceFactor < -1 && value > node->rightChild->data){
        node = RRRotation(node);
        traverseInOrder(root);
    }
    if(balanceFactor > 1 && value > node->leftChild->data){
        node->leftChild = RRRotation(node->leftChild);
        node = LLRotation(node);
        traverseInOrder(node);
    }
    if(balanceFactor < -1 && value < node->rightChild->data){
        node->rightChild = LLRotation(node->rightChild);
        node = RRRotation(node);
        traverseInOrder(node);
    }
    
}

void Tree::deleteNode(Node*& node,int value){
    
    if(node == NULL)
        return;
    else{
        if(value < node->data)
            deleteNode(node->leftChild,value);
        else if(value > node->data)
            deleteNode(node->rightChild,value);
        else{
            if(node->leftChild == NULL && node->rightChild == NULL){
                Node* temp = node;
                node = NULL;
                delete temp;
            }
            else if(node->leftChild == NULL && node->rightChild != NULL ){
                Node* temp = node;
                node = node->rightChild;
                delete temp;
            }
            else if(node->leftChild != NULL && node->rightChild == NULL){
                Node* temp = node;
                node = node->leftChild;
                delete temp;
            }
            else{
                //implement delete
                int min = getMinValue(node->rightChild);
                node->data = min;
                deleteNode(node->rightChild,min);
            }
        }
    }

    // node->height = 1 + max(getNodeHeight(node->leftChild),getNodeHeight(node->rightChild));
    //node->height = 1 + max(getNodeHeight(node->leftChild), getNodeHeight(node->rightChild));
    int balance = getBalanceFactor(node);

    if(balance > 1 && getBalanceFactor(node->leftChild) >= 0){
        node = LLRotation(node);
    }
    if(balance > 1 && getBalanceFactor(node->leftChild) < 0){
        node->leftChild = RRRotation(node->leftChild);
        node = LLRotation(node);
    }
    if(balance < -1 && getBalanceFactor(node->rightChild) <= 0){
        node = RRRotation(node);
    }
    if(balance < -1 && getBalanceFactor(node->rightChild) > 0){
        node->rightChild = LLRotation(node->rightChild);
        node = RRRotation(node);
    }
}

Node* Tree::LLRotation(Node*& node){
    
    Node* left = node->leftChild;
    node->leftChild = left->rightChild;
    left->rightChild = node;

    node->height = getNodeHeight(node);
    left->height = getNodeHeight(left);

    return left;
}

Node* Tree::RRRotation(Node*& node){

    Node* right = node->rightChild;
    node->rightChild = right->leftChild;
    right->leftChild = node;

    node->height = getNodeHeight(node);
    right->height = getNodeHeight(right);

    return right;
}

int Tree::getMinValue(Node*& node){
    if(node->leftChild == NULL){
        return node->data;
    }
    else{
        getMinValue(node->leftChild);
    }

    return INT32_MIN;
}

void Tree:: traverseInOrder(Node*& node){
    if(node != NULL){
        traverseInOrder(node->leftChild);
        cout << node->data << " ";
        traverseInOrder(node->rightChild);
    }
}

int Tree::getNodeHeight(Node*& node){
    if(node == NULL) return 0;

    return node->height;
}

int Tree::getBalanceFactor(Node*& node){
    
    if(node == NULL) return 0;

    return getNodeHeight(node->leftChild) - getNodeHeight(node->rightChild);
}

int Tree::max(int num1, int num2){

    return num1 > num2 ? num1 : num2;
}

int main(){

    Tree tree;
    cout << "Hello";
    tree.insert(tree.root,10);
    tree.insert(tree.root,20);
    tree.insert(tree.root,30);
    tree.insert(tree.root,40);
    tree.insert(tree.root,50);
    tree.insert(tree.root,60);
    tree.insert(tree.root,70);
    cout << "Hey dumbass" << endl;
    tree.traverseInOrder(tree.root);
    tree.deleteNode(tree.root,30);
    tree.traverseInOrder(tree.root);

    return 0;
}