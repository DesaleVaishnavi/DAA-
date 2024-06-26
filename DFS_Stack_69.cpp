#include <iostream>

using namespace std;

#define max 100
#define initial 1
#define visited 2;

int n;
int adj[max][max];
int state[max];
void create_graph();
void df_traversal();
void dfs(int v);

int stack[max];
int top=-1;
void push(int v);
int pop();
int isEmpty_stack();

int main()
{
    create_graph();
    df_traversal();
    return 0;
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

void df_traversal()
{
    int v;
    for(v=0;v<n;v++)
    {
        state[v]=initial;
    }
    cout<<"enter startind node for dfs"<<endl;
    cin>>v;
    dfs(v);
}

void dfs(int v)
{
    int i;
    push(v);
    while(!isEmpty_stack())
    {
        v=pop();
        if(state[v]==initial)
        {
            cout<<v<<" ";
            state[v]=visited;
        }
        for(i=n-1;i>=0;i--)
        {
            if(adj[v][i]==1&&state[i]==initial)
                push(i);
        }
    }
}
int pop()
{
    int v;
    if(top==-1)
    {
        cout<<"stack underflow"<<endl;
        exit(1);
    }
    else
    {
    v=stack[top];
    top=top-1;
    return v;
    }
}

void push(int v)
{
    if(top==(max-1))
    {
        cout<<"Stack is Overflow"<<endl;
        return;
    }
    top+=1;
    stack[top]=v;
}
int isEmpty_stack()
{
  if(top==-1)
        return 1;
  else
    return 0;
}
