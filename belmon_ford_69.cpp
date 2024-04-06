#include <iostream>
using namespace std;

#define max 100
#define infinity 9999
#define nil -1
#define true 1
#define false 0

int n; //number of vertices in graph
int adj[max][max];
int predecessor[max];
int pathlength[max];
int ispresent_in_queue[max];
int queue[max];
int front,rear;

int create_graph();
int bellmonford(int s);
void initilize_queue();
void insert_queue(int added_item);
int is_empty_queue();
int delete_queue();
int findpath(int s,int v);

int main()
{
    int s,flag,v;
    create_graph();
    cout<<"enter the source vertex"<<endl;
    cin>>s;
    flag=bellmonford(s);
    if(flag==-1)
    {
        cout<<"ERRor : negative cycle in graph"<<endl;
        exit(1);
    }
        while(1)
    {
        cout<<"enter destination vertex : -1 for exit"<<endl;
        cin>>v;
        if(v==-1)
            break;
        if((v<0)||(v>=n))
            cout<<"this vertex does not exist"<<endl;
        else if(v==s)
            cout<<"source and destination vertices are same"<<endl;
        else if(pathlength[v]==infinity)
            cout<<"there is no path from source to destination vertex"<<endl;
        else
            findpath(s,v);
    }

    return 0;
}


int create_graph()
{
    int max_e,i,origin,destination,wt,j;
    cout<<"enter vertices of graph"<<endl;
    cin>>n;
    max_e=n*(n-1);
    for(i=0;i<max_e;i++)
    {
        cout<<"enter the origin and destination of graph"<<endl;
        cin>>origin>>destination;
        cout<<"enter the weight"<<endl;
        cin>>wt;
        adj[origin][destination]=wt;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<adj[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}

int bellmonford(int s)
{
    int k=0,i,current;
    // 1 initialise pathlength by infinity and predecerr is nil and not any vertex is present in queue
    for(i=0;i<n;i++)
    {
        predecessor[i]=nil;
        pathlength[i]=infinity;
        ispresent_in_queue[i]=false;
    }
    initilize_queue();

    // 2 make path length of source vertex equal to 0 and insert it into queue
    pathlength[s]=0;
    insert_queue(s);
    ispresent_in_queue[s]=true;
    while(!is_empty_queue())
    {
        // 3 delete the vertex from queue and make it current
        current=delete_queue();
        ispresent_in_queue[current]=false;
        if(s==current)
            k++;
        if(k>=n)
            return -1; //negative cycle can be reachable form source vertex
        for(i=0;i<n;i++)
        {
            if(adj[current][i]!=0)
            {
                if(pathlength[i]>adj[current][i]+pathlength[current])
                {
                    pathlength[i]=adj[current][i]+pathlength[current];
                    predecessor[i]=current;
                    if(!ispresent_in_queue[i])
                        {
                            insert_queue(i);
                            ispresent_in_queue[i]=true;
                        }
                }

            }

        }


    }
    return 1;
}

void initilize_queue()
{
    int i;
    for(i=0;i<max;i++)
    {
        queue[i]=0;
    }
    rear=-1;
    front=-1;
}

void insert_queue(int added_item)
{
    if(rear==max-1)
    {
        cout<<"queue is overflow"<<endl;
        exit(1);
    }
    else
    {
        if(front==-1)
            front=0;
        rear+=1;

        queue[rear]=added_item;
    }

}

int is_empty_queue()
{
    if((front==-1)||(front>rear))
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int d;
    if(is_empty_queue())
    {
        cout<<"queue is underflow"<<endl;
        exit(1);
    }
    else
    {
        d=queue[front];
        front=front+1;
    }
    return d;
}

int findpath(int s,int v)
{
    int i,u;
    int path[max];
    int shortdist=0;
    int count=0;
    while(v!=s)
    {
        count++;
        path[count]=v;
        u=predecessor[v];
        shortdist+=adj[u][v];
        v=u;
    }
    count++;
    path[count]=s;
    cout<<"shortest path is "<<endl;
    for(i=count;i>=1;i--)
    {
        cout<<path[i];
    }
    cout<<endl;
    cout<<"shortest distance is = "<<shortdist<<endl;
    return 0;
}
