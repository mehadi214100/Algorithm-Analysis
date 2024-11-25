#include<bits/stdc++.h>
using namespace std;

void maxHepify(int arr[],int n,int i){
    int left = i*2;
    int right = i*2+1;
    int large = i;
    if(left<=n && arr[left]>arr[large]) large = left;
    if(right<=n && arr[right]>arr[large]) large = right;
    if(i!=large){
        swap(arr[i],arr[large]);
        maxHepify(arr,n,large);
    }
}

void heapSort(int arr[],int n){
    int t = n;
    while (t>1)
    {
        swap(arr[t],arr[1]);
        t--;
        maxHepify(arr,t,1);
    }
    
}

int main(){
    int n;cin>>n;
    int arr[n+1];
    arr[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    for (int i = n/2; i >0 ; i--)
    {
        maxHepify(arr,n,i);
    }
    heapSort(arr,n);
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
    return 0;
}
