#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *head;
    void insertBeg(Node);
};

void Node::insertBeg(Node node)
{
    Node *new_node = new Node;
    new_node->next=head;
    head=new_node;
}


int main()
{
    return 0;
}
