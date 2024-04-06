#include<iostream>
using namespace std;

void quick(int a[], int l, int up);
int partition(int a[], int l, int up);

int main() 
{    
    int n;
    cout<<"enter the size of an array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter array elements"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    
    int low = 0;
    int up = n-1;
    quick(arr, low, up);

    cout << "sorted elements are" << endl;
    for (int i = 0; i <= up; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void quick(int a[], int l, int up) {
    if (l >= up) {
        return;
    }
    int pvtloc = partition(a, l, up);
    quick(a, l, pvtloc - 1); //left sublist
    quick(a, pvtloc + 1, up); //right sublist
}

int partition(int a[], int l, int up) {
    if (l >= up) {
        return l;
    }
    int temp, pvt;
    int i = l + 1;
    int j = up;
    pvt = a[l];
    while (i <= j) {
        while (a[i] < pvt) {
            i++;
        }
        while (a[j] > pvt) {
            j--;
        }
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        } else {
            i++;
        }
    }
    // Swap pivot with element at position j
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

