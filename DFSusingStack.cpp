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
    Node *initNode(int x);
    bool isEmpty();
    void push(int x);
    void pop();
    int top();
    void Display();
    Stack();
};

Stack::Stack()
{
    pTop = NULL;
}
bool Stack::isEmpty()
{
    return (pTop == NULL);
}
Node* Stack::initNode(int x)
{
    Node *p = new Node();
    p -> data = x;
    p -> pNext = NULL;
    return p;
}
void Stack::push(int x)
{
    Node *new_node = initNode(x);
    if (isEmpty())
    {
        pTop = new_node;
    }
    else
    {
        new_node->pNext = pTop;
        pTop = new_node;
    }
}

void Stack::pop()
{
    if(isEmpty())
        return;
    Node *ptr = pTop;
    pTop = pTop->pNext;
    delete (ptr);
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

class Graph
{
private:
    int V, E;
    vector<int> *adj;
    bool *visited;
public:
    Graph(int V, int E);
    void addEdge();
    void DFS(int index);
    void Display();
    ~Graph();
};

Graph::Graph(int V, int E)
{
    this->V = V;
    this->E = E;
    adj = new vector<int>[V+1];
    visited = new bool[V+1];
}

Graph::~Graph()
{
    delete (adj);
}
// add Edge into list
void Graph::addEdge()
{
    for(int i = 0; i < E; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void Graph::DFS(int index)
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
            if (!visited[adj[s][i]])
            {
                cout << adj[s][i] << " ";
                st.push(s);
                st.push(adj[s][i]);
                break;
            }
        }
    }
}

int main()
{
    int V, E, current;
    int t; cin >> t;
    cin >> V >> E >> current;
    Graph g(V,E);
    g.addEdge();
    g.DFS(current);
    return 0;
}