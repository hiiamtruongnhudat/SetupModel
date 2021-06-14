#include<bits/stdc++.h>
using namespace std;


class Node
{
public:
    int data;
    Node *pNext;
    Node(int x);
};
Node::Node(int x)
{
    data = x;
    pNext = NULL;
}
class Queue
{
public:
    Node *pHead;
    Node *pTail;
    bool isEmpty();
    void enQueue(int x);
    void deQueue();
    int front();
    void Display();
    Queue();
};

Queue::Queue()
{
    pHead = pTail = NULL;
}

bool Queue::isEmpty()
{
    return (pHead == NULL);
}

// push_back
void Queue::enQueue(int x)
{
    Node *p = new Node(x);
    if (isEmpty())
    {
        pHead = pTail = p;
    }
    else
    {
        pTail -> pNext = p;
        pTail = p;
    }
}

void Queue::deQueue()
{
    if (isEmpty())
        return;
    Node *ptr = pHead;
    pHead = pHead->pNext;
    delete (ptr);
    if (isEmpty())
        pTail = NULL;
}

int Queue::front()
{
    if(isEmpty())
        return -1;
    else
    {
        return pHead->data;
    }
}
void Queue::Display()
{
    if(isEmpty())
        return;
    while(!isEmpty())
    {
        int x = pHead->data;
        cout << x << " ";
        deQueue();
    }
}

int main()
{
    Queue q;
    for (int i = 1; i <= 10; i++)
        q.enQueue(i);
    cout << "\n";
    int  x = q.front();
    cout << x;
    return 0;
}