#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>
using namespace std;

class Queue
{
    int front,rear,size;
    int *queue;
public:
    Queue(int c);
    ~Queue();
    void enQueue(int data);
    void deQueue();
    void queueDisplay();
}
Queue::~Queue()
{
    delete queue;
}
void Queue::enQueue(int data)
{
    if(size==rear)
    {
        cout<<"Queue is Full ";
        return;
    }
    else
    {
        queue[rear++]=data;
    }
    return;
}

void Queue::deQueue()
{
    if(front==rear)
    {
        cout<<"Queue is Empty ";
        return;
    }
    else
    {
        for(int i=0;i<rear-1;i++)
            queue[i]=queue[i+1];
        rear--;
    }
    return;
}

void Queue::queueDisplay()
{
    int i;
    if(front==rear)
    {
        cout<<"Queue is Empty ";
        return;
    }
    for(i=front;i<rear;i++)
    {
        cout<<queue[i]<<" ";
    }
    return;
}

#endif // QUEUE_H_INCLUDED
