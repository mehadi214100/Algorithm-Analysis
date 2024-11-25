#include<bits/stdc++.h>
using namespace std;

int pivotFind(int arr[],int l,int r){
    int pivot = arr[l];
    int i = l;
    int j = r;
    while (i<j)
    {
        while (arr[i]<=pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
           j--;
        }
        if(i<j) swap(arr[i],arr[j]);
        
    }
    swap(arr[j],arr[l]);
    return j;
    
}

void quicksort(int arr[],int l,int r){
    if(l<r){
        int pivot = pivotFind(arr,l,r);
        quicksort(arr,l,pivot-1);
        quicksort(arr,pivot+1,r);
    }
}

int main(){
    int n;cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Before Sort : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    quicksort(arr,0,n-1);
    cout<<"\nAfter Sort : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}