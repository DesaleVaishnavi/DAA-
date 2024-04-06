
#include<iostream>
using namespace std;

# define MAX 100

# define initial 1
#define waiting 2
#define visited 3

int n;
int adj [MAX] [MAX];
int state[MAX];

void create_graph();
void BF_Traversal ();
void BFS(int v);

int queue [MAX],front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue ();
int isEmpty_queue();

int main()
{
    create_graph();
    BF_Traversal();
}

void create_graph()
{
    int max_e,i,origin,destination,j;
    cout<<"enter vertices of graph"<<endl;
    cin>>n;
    max_e=n*(n-1);
    for(i=0;i<max_e;i++)
    {
        cout<<"enter the origin and destination of graph"<<endl;
        cin>>origin>>destination;
        adj[origin][destination]=1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<adj[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void BF_Traversal()
{
    int v;
    for(v=0;v<n;v++)
        state[v]=initial;
    cout<<"enter starting vertex for breadth search"<<endl;
    cin>>v;
    BFS(v);
}

void BFS (int v)
{
    int i;
    insert_queue(v);
    state[v]=waiting;
    while(!isEmpty_queue())
    {
        v=delete_queue();
        cout<<v;
        state[v]=visited;
        for(i=0;i<n;i++)
        {
            if(adj[v][i]==1&&state[i]==initial)
            {
                insert_queue(i);
                state[i]=waiting;
            }
        }
    }
    cout<<endl;
}

void insert_queue(int vertex)
{
    if(rear==MAX-1)
        cout<<"queue is overflow"<<endl;
    else
    {
        if(front==-1)
            front=0;
        rear+=1;
        queue[rear]=vertex;
    }
}

int isEmpty_queue()
{
    if(front==-1||front>rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int del_item;
    if(front==-1||front>rear)
    {
        cout<<"queue is underflow"<<endl;
        exit(1);
    }
    del_item=queue[front];
    front+=1;
    return del_item;
}
