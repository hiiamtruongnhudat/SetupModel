#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *pNext;
};
class Stack
{    
public:
    Node *pTop;
    Node *initializeNode(int x);
    bool isEmpty();
    bool push(int x);
    bool pop();
    int top();
    void display();
    Stack();
};

Stack::Stack()
{
    this->pTop = NULL;
}
Node *Stack::initializeNode(int x)
{
    Node *p = new Node();
    p->data = x;
    p->pNext = NULL;
    return p;
}
bool Stack::isEmpty()
{
    return (pTop == NULL);
}
bool Stack::push(int x)
{   
    Node *p = this->initializeNode(x);
    if(this->isEmpty())
    {
        this->pTop = p;
    }
    else
    {
        p->pNext = this->pTop;
        this->pTop = p;
    }
    return true;
}
int Stack::top()
{
    if(this->isEmpty())
    {
        return 0;
    }
    int x = this->pTop->data;
    return x;
}
bool Stack::pop()
{
    if(this->isEmpty())
    {
        return false;
    }
    else
    {
        Node *ptr = pTop;
        pTop = pTop->pNext;
        delete ptr;
    }
    return true;
}
void Stack::display()
{
    if(this->isEmpty())
        return;
    while(!this->isEmpty())
    {
        int x = this->top();
        cout << x << " ";
        this->pop();
    }
}
int main()
{
    Stack st;
    for(int i = 0; i <= 10; i++)
        st.push(i);
    st.display();
    return 0;
}