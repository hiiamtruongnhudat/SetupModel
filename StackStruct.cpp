#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    node *pNext;
}Node;
typedef struct stack
{
    Node *pTop;
}Stack;
Node *initNode(int x)
{
    Node *p = new Node();
    p->data = x;
    p->pNext = NULL;
    return p;
}
void initStack(Stack &st)
{
    st.pTop = NULL;
}
bool isEmpty(Stack st)
{
    return (st.pTop == NULL);
}
bool push(Stack &st, Node *p)
{
    if (isEmpty(st))
    {
        st.pTop = p;
    }
    else
    {
        p->pNext = st.pTop;
        st.pTop = p;
    }
    return true;
}
bool pop(Stack &st, int &x)
{
    if (isEmpty(st) == true)
    {
        return false;
    }
    else
    {
        Node *p = st.pTop;
        x = p->data;
        st.pTop = st.pTop->pNext;
        delete p;
    }
    return true;
}
bool top(Stack &st, int &x)
{
    if(isEmpty(st))
        return false;
    x = st.pTop->data;
    return true;
}
void output(Stack st)
{
    while(isEmpty(st) == false)
    {   
        int x;
        pop(st,x);
        cout << x << " ";
    }
}
int main()
{
    Stack st;
    initStack(st);
    for (int i = 1; i <=  10; i++)
    {
        Node *p = initNode(i);
        push(st,p);
    }
    int x;
    top(st,x);
    cout << x << "\n";
    output(st);
    return 0;
}

