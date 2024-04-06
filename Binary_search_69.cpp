#include <iostream>

using namespace std;

int main()
{
    int array[10],i,search;
    cout<<"enter array elements"<<endl;
    for(i=0;i<10;i++)
    {
       cin>>array[i];
    }
    cout<<"enter element you want to search"<<endl;
    int l=0;
    int up=9;
    int mid=(l+up)/2;
    cin>>search;

    while(l<=up)
    {
        if(search>array[mid])
        {
            l=mid+1;
        }
        else if(search==array[mid])
        {
            cout<<"element found"<<endl;
            break;
        }
        else
        {
            up=mid-1;
        }
     mid=(l+up)/2;
    }
    if(l>up)
    {
        cout<<"not found"<<endl;
    }
    return 0;
}
