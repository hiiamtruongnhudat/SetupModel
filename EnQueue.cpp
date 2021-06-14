#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
int V, E, S;
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
void BFS(int node)
{
    Queue q;
    q.enQueue(node);
    while (!q.isEmpty())
    {
        int u = q.front(); q.deQueue();
        cout << u << " ";
        visited[u] = true;
        for (int i = 0 ; i < adj[u].size(); ++i)
            if(!visited[adj[u][i]])
            {
                visited[adj[u][i]] = true;
                q.enQueue(adj[u][i]);
            }
    }
}
void test_case()
{
    memset(visited,false,sizeof(visited));
    for (int i = 0; i <= 1001; ++i)
        adj[i].clear();
    cin >> V >> E >> S;
    for (int i = 0 ; i < E ;++i)
        {
            int v,w;
            cin >> v >> w;
            adj[v].push_back(w);
            // adj[w].push_back(v);
        }
    BFS(S);
    cout << "\n";
}
int main()
{
    int t; cin >> t;
    while(t--)
    {
        test_case();
    }
    return 0;
}