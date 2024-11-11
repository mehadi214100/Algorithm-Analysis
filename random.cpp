#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int p,int r){
    int x = arr[r];
    int i = p-1;
    for(int j=p ;j<r;j++){
        if(arr[j]<=x){
            i = i+1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}


int randomized_partition(int arr[],int p,int r){
    int i = p + rand()%(r-p+1);
    swap(arr[i],arr[r]);
    return partition(arr,p,r);
}


void randomized_quicksort(int arr[],int p,int r){
    if(p<r){
        int q = randomized_partition(arr,p,r);
        randomized_quicksort(arr,p,q-1);
        randomized_quicksort(arr,q+1,r);
    }
}

int main(){
    int arr[] = {8,1,4,6,0,3,9,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    randomized_quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
