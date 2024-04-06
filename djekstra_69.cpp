#include <iostream>

using namespace std;

#define max 100
#define infinity 9999
#define nil -1
#define temp 0
#define permanent 1

int adj[max][max];
int predecer[max];
int pathlength[max];
int status[max];

int create_graph();
void djekstra(int src,int n);
int min_path(int n);
int findpath(int s,int v);

int main()
{
    int src,v;
    int n=create_graph();
    cout<<"enter source vertex of graph"<<endl;
    cin>>src;
    djekstra(src,n);

    while(1)
    {
        cout<<"enter destination vertex : -1 for exit"<<endl;
        cin>>v;
        if(v==-1)
            break;
        if((v<0)||(v>=n))
            cout<<"this vertex does not exist"<<endl;
        else if(v==src)
            cout<<"source and destination vertices are same"<<endl;
        else if(pathlength[v]==infinity)
            cout<<"there is no path from source to destination vertex"<<endl;
        else
            findpath(src,v);
    }

    return 0;
}

int create_graph()
{
    int n,max_e,i,origin,destination,wt,j;
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
    return n;
}

void djekstra(int src,int n)
{
    int i,current;
    // 1 make all vertices temporary and initiliase pathlenght with infinity and predecer as nil

    for(i=0;i<n;i++)
    {
        status[i]=temp;
        pathlength[i]=infinity;
        predecer[i]=nil;
    }

    // 2 make source vertex pathlenght is 0
    pathlength[src]=0;

    while(1)
    {
        //3 from all temporary vertices find min pathlengh of vertices make it current and permanent
        current=min_path(n);
        if(current==nil)
            return;
        status[current]=permanent;

        //from all adjacy temporary vertices from current
        for(i=0;i<n;i++)
        {
            if((adj[current][i]!=0)&&(status[i]==temp))
            {
                if(pathlength[current]+adj[current][i]<pathlength[i])
                {
                    predecer[i]=current;
                    pathlength[i]=pathlength[current]+adj[current][i];
                }
            }
        }
    }
}

int min_path(int n)
{
    int i;
    int min=infinity;
    int k=nil;
    for(i=0;i<n;i++)
    {
        if((status[i]==temp)&&(pathlength[i]<min))
        {
            min=pathlength[i];
            k=i;
        }
    }
    return k;
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
        u=predecer[v];
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
