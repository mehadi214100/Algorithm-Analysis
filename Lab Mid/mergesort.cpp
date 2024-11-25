#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int r,int m){
    int leftSize = m-l+1;
    int rightSize = r-m;
    int left[leftSize],right[rightSize];

    for (int i = l,k=0; i <= m; i++,k++)
    {
        left[k] = arr[i]; 
    }
    for (int i = m+1,k=0; i <= r; i++,k++)
    {
        right[k] = arr[i]; 
    }
    int i = 0,j=0,k=l;
    while (i<leftSize && j<rightSize)
    {
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i<leftSize)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j<rightSize)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,r,mid);
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
    mergesort(arr,0,n-1);
    cout<<"\nAfter Sort : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}