#include<iostream>
using namespace std;

#define max 100

void merge_sort(int arr[],int low,int up);
void merge_s(int arr[],int temp[],int low1,int up1,int low2,int up2);
void copy_s(int arr[],int temp[],int low,int up);

int main()
{
    int i,n,arr[max];
    cout<<"enter the size of array:"<<endl;
    cin>>n;
    cout<<"enter array elements "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    cout<<"sorted list is "<<endl;
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}

void merge_sort(int arr[],int low,int up)
{
    int mid;
    int temp[max];
    if(low<up)
    {
        mid=(low+up)/2;
        merge_sort(arr,low,mid); //left sublist
        merge_sort(arr,mid+1,up); //right sublist
        merge_s(arr,temp,low,mid,mid+1,up);
        copy_s(arr,temp,low,up);
    }
}

void merge_s(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
    int i=low1;
    int j=low2;
    int k=low1;
    while((i<=up1)&&(j<=up2))
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=up1)
        temp[k++]=arr[i++];
    while(j<=up2)
        temp[k++]=arr[j++];
}

void copy_s(int arr[],int temp[],int low,int up)
{
    int i;
    for(i=low;i<=up;i++)
        arr[i]=temp[i];
}
