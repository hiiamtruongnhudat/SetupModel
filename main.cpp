#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
int V, E, current;
bool visited[1001];
class Node
{
public:
    int data;
    Node*pNext;
};
class Stack
{
public:
    Node *pTop;
    bool isEmpty();
    bool push(int x);
    bool pop();
    int top();
    void Display();
    Node *initializeNode(int x);
    Stack();
};
Node *Stack::initializeNode(int x)
{
    Node *p = new Node();
    p->data = x;
    p->pNext = NULL;
    return p;
}
Stack::Stack()
{
    pTop = NULL;
}
bool Stack::isEmpty()
{
    return (pTop == NULL);
}
bool Stack::push(int x)
{
    Node *new_node = initializeNode(x);
    if (isEmpty())
    {
        pTop = new_node;
    }
    else
    {
        new_node->pNext = pTop;
        pTop = new_node;
    }
    return true;
}
bool Stack::pop()
{
    if(isEmpty())
        return false;
    Node *ptr = pTop;
    pTop = pTop->pNext;
    delete (ptr);
    return true;
}
int Stack::top()
{
    if(isEmpty())
        return -1;
    return pTop->data;
}
void Stack::Display()
{
    if(isEmpty())
        return;
    while(!isEmpty())
    {
        int x = top();
        cout << x << " ";
        pop();
    }
}
void DFS(int index)
{
    Stack st;
    st.push(index);
    cout << index << " ";
    while(!st.isEmpty())
    {
        int s = st.top(); st.pop();
        visited[s] = true;
        for (int i = 0; i < adj[s].size(); i++)
        {
            if(!visited[adj[s][i]])
            {
                visited[adj[s][i]]= true;
                cout << adj[s][i] << " ";
                st.push(s);
                st.push(adj[s][i]);
                break;
            }
        }
    }
}
void solve()
{
    cin >> V >> E >> current;
    for (int i = 0 ; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(current);
}
int main()
{   
    solve();
    // Stack st;
    // for (int i =1 ;i <= 10; i++)
    //     st.push(i);
    // st.Display();
    return 0;
}