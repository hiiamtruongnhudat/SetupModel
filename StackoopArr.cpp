// stack using array

#include<bits/stdc++.h>
using namespace std;
#define MAX 100
class Stack
{
private:
    int top;
public:
    int a[MAX];
    bool isEmpty();
    int topp();
    bool push(int x);
    int pop();
    Stack();
};
//
Stack::Stack()
{
    top = -1;
}
//
bool Stack::isEmpty()
{
    return (top < 0);
}
//
bool Stack::push(int x)
{
    if( top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << "pushed into stack \n";
        return true;
    }
}
// pop 
int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
// top
int Stack::topp()
{
    if (isEmpty())
    {
        cout << "Stack is empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}
int main()
{
    Stack s;
    for (int i = 1; i <= 10; i++)
        s.push(i);
    cout << s.pop() << " Popped \n";
    cout << "Element present in stack: ";
    while(!s.isEmpty())
    {
        cout << s.topp() << " ";
        s.pop();
    }
    return 0;
}
