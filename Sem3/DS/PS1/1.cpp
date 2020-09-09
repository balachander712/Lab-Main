#include <iostream>
using namespace std;

class Node{

private:
    int data;
    Node* leftChild;
    Node* rightChild;
public:
    Node(int value){
        this->data = value;
    }
    
    Node* getLeftchild() { return this->leftChild; }
    
    Node* getRightChild() { return this->rightChild; }
    
    void setLeftChild(Node* node) {
        this->leftChild = node;
    }

    void setRightChild(Node* node){
        this->rightChild = node;
    }

    void insert(int value){
        if(this->data == value)
            return;

        if(this->data < value){
            if(this->leftChild == NULL){
                this->leftChild = new Node(value);
            }
            else
            {
                this->leftChild->insert(value);
            }
            
        }
        else
        {
            if(this->rightChild == NULL){
                this->rightChild = new Node(value);
            }
            else
            {
                this->rightChild->insert(value);
            }
            
        }
        
    }
};

class Tree{

private:
    Node *root = NULL;
public:
    void insert(int value){
        if(root == NULL){
            root = new Node(value);
        }
        else{
            root->insert(value);
        }
    }
};

int main(){


    return 0;
}