#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

class List{
    Node *head;
public:
    List(){
        head=NULL;
    }
    void insertBeg();
    void insertMidAfter();
    void insertMidBefore();
    void insertEnd();
    void deleteBeg();
    void deleteMidAfter();
    void deleteMidBefore();
    void deleteEnd();
    void display();
};

void List::insertBeg(){
    int val;
    Node *newnode;
    newnode = new Node;
    cout<<"Enter the value to be inserted ";
    cin>>val;
    if(head==NULL)
    {
        newnode->data=val;
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        newnode->data=val;
        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;

    }
    
}

void List::insertMidAfter(){
    int val1,val2;
    int flag=0;
    Node *newnode;
    newnode= new Node;
    cout<<"Enter an element to insert ";
    cin>>val1;
    cout<<"Enter the element after to which to be inserted ";
    cin>>val2;

    if(head==NULL){
        newnode->data=val1;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
    }
    else{
        Node *t;
        t=new Node();
        t=head;
        while(t!=NULL){
            if(t->data==val2){
                flag=1;
                break;
            }
            t=t->next;
        }
        if(flag==1){
            newnode->data=val1;
            newnode->next=t->next;
            newnode->prev=t;
            (t->next)->prev=newnode;
            t->next=newnode;
        }
        else
        {
            cout<<"\nVALUE NOT FOUND!!! ";
        }
        
    }
}

void List::insertMidBefore(){
    int val1,val2,flag=0;
    Node *newnode;
    newnode=new Node;
    cout<<"\nEnter an element to insert ";
    cin>>val1;
    cout<<"\nEnter the element after which to be inserted ";
    cin>>val2;

    if(head=NULL){
        newnode->data=val1;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        Node *t;
        t=new Node();
        t=head;
        while(t!=NULL){
            if(t->data==val2){
                flag=1;
                break;
            }
            t=t->next;
        }
        if(flag==1){
            t=t->prev;
            newnode->data=val1;
            newnode->next=t->next;
            newnode->prev=t;
            (t->next)->prev=newnode;
            t->next=newnode;
        }
    }
    
}

void List::insertEnd(){
    int val;
    Node *newnode;
    newnode=new Node;
    cout<<"\nEnter the element to insert ";
    cin>>val;
    if(head=NULL){
        newnode->data=val;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        Node *t;
        t=new Node();
        t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        newnode->data=val;
        newnode->next=t->next;
        newnode->prev=t;
        t->next=newnode;
    }
}

void List::deleteBeg(){
    if(head==NULL){
        cout<<"EMPTY!!! ";
    }
    else
    {
        Node *b;
        b=new Node;
        b=head;
        (b->next)->prev=NULL;
        head=head->next;
        delete b;
    }
    
}

int main()
{
    return 0;
}