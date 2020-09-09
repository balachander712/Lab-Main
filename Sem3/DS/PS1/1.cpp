#include <iostream>
using namespace std;

class Node{

private:
    int data;
    Node* leftChild;
    Node* rightChild;
public:

    Node(){
        leftChild = NULL;
        rightChild = NULL;
    }

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

    void deleteMin(){
        if(this->leftChild->getLeftchild() == NULL){
            this->leftChild == NULL;
            
            delete this->getLeftchild();
        }
        else{
            this->leftChild->deleteMin();
        }

    }

    bool getElement(int value){
        if(this->data == value)
            return true;

        if(this->data < value)
            this->leftChild->getElement(value);
        else
            this->rightChild->getElement(value);

        return false;
    }

    int getMax(){
        if(this->rightChild == NULL)
            return this->data;
        
        this->rightChild->getMax();
    }

    int getLeftChild(int value){
        if(this->data == value){
            return this->leftChild->data;
        }

        if(value < this->data){
            this->leftChild->getLeftChild(value);
        }
        else
            this->rightChild->getLeftChild(value);
    }

    int getRightChild(int value){
        if(this->data == value){
            return this->rightChild->data;
        }
        
        if(value < this->data){
            this->leftChild->getRightChild(value);
        }
        else
            this->rightChild->getRightChild(value);

    }

    void traverseInorder(){
        if(this->leftChild != NULL){
            this->leftChild->traverseInorder();
        }

        cout << this->data << " " ;

        if(this->rightChild != NULL){
            this->rightChild->traverseInorder();
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

    void deleteMin(){
        root->deleteMin();
    }

    void getElement(int value){
        if(root->getElement(value))
            cout << "The element " << value << " is found in the tree " << endl;
        else
            cout << "ELEMENT NOT FOUND!!!" << endl;
    }

    int getMax(){
        return root->getMax();
    }
    
    int getLeftChild(int value){
        return root->getLeftChild(value);
    }

    int getRightChild(int value){
        return root->getRightChild(value);
    }

    void traverseInorder(){
        root->traverseInorder();
    }
};

int main(){

    cout << "Hello World " << endl;
    return 0;
}