#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define MAX 1000
#include <iostream>

using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;

public:
    Stack(int);
    ~Stack();

    Stack() {top=-1};
    int push(int x);
    int pop();
    int peek();
    bool isEmpty();
}

Stack::Stack(int size)
{
    arr= new int[size];
    top=-1;
}

Stack::~Stack()
{
    delete arr;
}

int Stack::push(int x)
{
    if(top>=size)
    {
        cout<<"Stack Overflow ";
        return 0;
    }
    arr[++top]=x;

    return 0;
}

int Stack::peek()
{
    if(!isEmpty())
        return arr[top];
    else
    {
        cout<<"Stack Underflow ";
        return 0;
    }
}

int Stack::pop()
{
    if(isEmpty())
     {
         cout<<"Stack Underflow ";
         return 0;
     }
     else
        return arr[top--];
}

bool isEmpty()
{
    return (top<0);
}
#endif // STACK_H_INCLUDED
