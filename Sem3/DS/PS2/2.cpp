#include <iostream>
using namespace std;

class Node{

    int data;
    Node* leftChild;
    Node* rightChild;
    int height;
    static int count;
public:
    Node();
    Node(int);
    void insert(int);
    int getNodeHeight(Node);
    int getBalanceFactor(Node);
    int getData() { return this->data; }
    void setHeight(int value) { this->height = value; }
    void setData(int value) { this->data = value; }
    Node* getLeftchild() { return leftChild; }
    Node* getRightChild() { return rightChild; }
    void setLeftChild(Node *node) { this->leftChild = node; }
    void setRightChild(Node* node) { this->rightChild = node; }
    void LLRotation(Node);
    void LRRotation(Node);
    void RRRotation(Node);
    void RLRotation(Node);
    Node* deleteNode(Node*,int);
    void deleteMin();
    void deleteLeft(int);
    void deleteRoot();
    bool hasLeftChild();
    bool hasRightChild();
    int getMin(Node*);
    void traverseInorder();
    int* getElements(int);
    int Print(Node*,int,int);
    int countLeaf(Node*);
};

Node:: Node(){
    leftChild = NULL;
    rightChild = NULL;
    height = 0;
    count = 0;
}

Node:: Node(int value){
    this->data = value;
}

int Node:: Print(Node* node,int key1, int key2){
    if(node == NULL){
        return;
    }

    if(key1 < node->data){
        Print(node->leftChild,key1,key2);
    }

    if(key1 <= node->data && key2 >= node->data){
        cout << node->data << " ";
        return node->data;
    }

    if(key2 > node->data){
        Print(node->rightChild,key1,key2);
    }
}

int Node:: countLeaf(Node* node){
    if(node != NULL){
        countLeaf(node->leftChild);
        if(node->leftChild == NULL && node->rightChild == NULL){
            count++;
        }
        countLeaf(node->rightChild);
    }

    return count;
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

void Node:: deleteMin(){
    AVLTree temp;
    int min = getMin(temp.root);
    deleteNode(temp.root,min);
}

void Node:: deleteLeft(int value){
    
    AVLTree temp;
    if(rightChild == NULL){
        deleteNode(temp.root,value);
    }
}

void Node:: deleteRoot(){
    AVLTree temp;
    int value = temp.root->data;
    deleteNode(temp.root,value);
}

Node* Node::deleteNode(Node* subTreeRoot, int value){
    if(subTreeRoot == NULL){
        return subTreeRoot;
    }

    if(value < subTreeRoot->getData()){
        subTreeRoot->setLeftChild(deleteNode(subTreeRoot->getLeftchild(), value));
    }
    else if(value > subTreeRoot->getData()){
        subTreeRoot->setRightChild(deleteNode(subTreeRoot->getRightChild(),value));
    }

    //Else encountered the data
    //delete the data

    else{
        //Case 1 and 2 : Delete node with 0 or 1 children
        if(subTreeRoot->getLeftchild() == NULL){
            Node* temp = subTreeRoot->getRightChild();
            delete subTreeRoot;
            return temp;
        }
        if(subTreeRoot->getRightChild() == NULL){
            Node* temp = subTreeRoot->getLeftchild();
            delete subTreeRoot;
            return temp;
        }
        //case 3: Delete node with 2 children
        else{
            //set the node as the highest node in the RST
            subTreeRoot->setData(subTreeRoot->getMin(subTreeRoot->getRightChild()));
            //delete the node having the smallest value in the RST
            subTreeRoot->setRightChild(deleteNode(subTreeRoot->getRightChild(),subTreeRoot->getData()));

        }
    }

    subTreeRoot->setHeight(subTreeRoot->getNodeHeight(*subTreeRoot));

    //peform AVL rotations

    if(subTreeRoot->getBalanceFactor(*subTreeRoot) > 1 && subTreeRoot->getBalanceFactor(*subTreeRoot->getLeftchild()) == 0){
        subTreeRoot->LLRotation(*subTreeRoot);
    }
    if(subTreeRoot->getBalanceFactor(*subTreeRoot) > 1 && subTreeRoot->getBalanceFactor(*subTreeRoot->getLeftchild()) == 1){
        subTreeRoot->LLRotation(*subTreeRoot);
    }
    if(subTreeRoot->getBalanceFactor(*subTreeRoot) > 1 && subTreeRoot->getBalanceFactor(*subTreeRoot->getLeftchild()) == -1){
        subTreeRoot->LRRotation(*subTreeRoot);
    }
    if(subTreeRoot->getBalanceFactor(*subTreeRoot) < -1 && subTreeRoot->getBalanceFactor(*subTreeRoot->getRightChild()) == 0){
        subTreeRoot->RRRotation(*subTreeRoot);
    }
    if(subTreeRoot->getBalanceFactor(*subTreeRoot) < -1 && subTreeRoot->getBalanceFactor(*subTreeRoot->getRightChild()) == 1){
        subTreeRoot->RLRotation(*subTreeRoot);
    }
    if(subTreeRoot->getBalanceFactor(*subTreeRoot) < -1 && subTreeRoot->getBalanceFactor(*subTreeRoot->getRightChild()) == -1){
        subTreeRoot->RRRotation(*subTreeRoot);
    }


    return subTreeRoot;
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

int Node:: getMin(Node* node){
    if(node->getLeftchild() == NULL){
        return node->data;
    }

    getMin(node->getLeftchild());
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
    int getHeight();
    int returnKey(int,int);
    void deleteMin();
    void deleteLeft(int);
    void deleteRoot();
    void getElements(int,int);
    int countLeaf();
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

int AVLTree:: countLeaf(){
    root->countLeaf(root);
}

void AVLTree:: getElements(int key1, int key2){
    root->Print(root,key1,key2);
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

int AVLTree:: getHeight(){
    root->getNodeHeight(*root);
}

void AVLTree::deleteMin(){
    root->deleteMin();
}

void AVLTree::deleteRoot(){
    root->deleteRoot();
}

void AVLTree:: deleteLeft(int value){
    root->deleteLeft(value);
}

int main(){

    return 0;
}