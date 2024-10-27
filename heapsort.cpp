#include<bits/stdc++.h>
using namespace std;

void Maxheapify(int arr[],int n,int i){
    int left = i*2;
    int right = i*2+1;
    int large = i;

    if(left<=n && arr[left]>arr[large]) large = left;
    if(right<=n && arr[right]>arr[large]) large = right;
    if(i!=large){
        swap(arr[i],arr[large]);
        Maxheapify(arr,n,large);
    }
}

void heapSort(int arr[],int n){
    int t = n;
    while(t>1){
        swap(arr[t],arr[1]);
        t--;
        Maxheapify(arr,t,1);
    }
}

void output(int arr[],int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int arr[10000000];
int main(){
    int sizes[] = {100,1000,10000,100000,1000000};
    cout<<"------Time Complexity for Random Number------"<<endl<<endl;
    for(int sz:sizes){
        arr[0] = -1;
        int n = sz;
        for(int i=1;i<=n;i++){
            int num = rand()%100;
            arr[i] = num;
        }
        clock_t first,last;
        first = clock();
        for(int i=n/2;i>0;i--){
            Maxheapify(arr,n,i);
        }
        heapSort(arr,n);
        last = clock();
        double execution = (double(last-first)/CLOCKS_PER_SEC)*1000;
        cout<<"Execution time for "<<sz<<" elements : "<<execution<<" ms"<<endl;
    }

    cout<<endl;
    cout<<"------ Time Complexity for Increasing Number ------"<<endl<<endl;
    for(int sz:sizes){
        arr[0] = -1;
        int n = sz;
        for(int i=1;i<=n;i++){
            int num = i;
            arr[i] = num;
        }
        clock_t first,last;
        first = clock();
        for(int i=n/2;i>0;i--){
            Maxheapify(arr,n,i);
        }
        heapSort(arr,n);
        last = clock();
        double execution = (double(last-first)/CLOCKS_PER_SEC)*1000;
        cout<<"Execution time for "<<sz<<" elements : "<<execution<<" ms"<<endl;
    }


    cout<<endl;
    cout<<"------ Time Complexity for Decreasing  Order ------"<<endl<<endl;
    for(int sz:sizes){
        arr[0] = -1;
        int n = sz;
        int k = 1;
        for(int i=n;i>=1;i--){
            arr[k] = i;
            k++;
        }
        clock_t first,last;
        first = clock();
        for(int i=n/2;i>0;i--){
            Maxheapify(arr,n,i);
        }
        heapSort(arr,n);
        last = clock();
        double execution = (double(last-first)/CLOCKS_PER_SEC)*1000;
        cout<<"Execution time for "<<sz<<" elements : "<<execution<<" ms"<<endl;
    }

}

