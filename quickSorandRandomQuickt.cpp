#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int p,int r){
    int x = arr[r];
    int i = p-1;
    for(int j=p;j<r;j++){
        if(arr[j]<=x){
            i = i+1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

int randomized(int arr[],int p,int r){
    int i = p + rand()%(r-p+1);
    swap(arr[i],arr[r]);
    return partition(arr,p,r);
}

void randomQuicksort(int arr[],int p,int r){
    if(p<r){
        int q = randomized(arr,p,r);
        randomQuicksort(arr,p,q-1);
        randomQuicksort(arr,q+1,r);
    }
}

void Quicksort(int arr[],int p,int r){
    if(p<r){
        int q = partition(arr,p,r);
        Quicksort(arr,p,q-1);
        Quicksort(arr,q+1,r);
    }
}



int main(){
    int inputSizes[] = {100,1000,10000,100000};
    cout<<"-----Random Data----------"<<endl;
    for(int size:inputSizes){
        int arr1[size],arr2[size];
        for(int i=0;i<size;i++){
            int num = rand()%100;
            arr1[i] = num;
            arr2[i] = num;
        }
        clock_t start,end;
        start = clock();
        Quicksort(arr1,0,size-1);
        end = clock();
        double quickTime = double(end - start)*1.0 / CLOCKS_PER_SEC;

        start = clock();
        randomQuicksort(arr2,0,size-1);
        end = clock();
        double randomTime = double(end - start)*1.0 / CLOCKS_PER_SEC;

        cout<<"For Size "<<size<<" : "<<"Quick sort time -> "<<quickTime<<" ms " <<"Randomized Quick Time -> "<<randomTime<<" ms"<<endl;
    }

    cout<<"-----Increasing Data Data----------"<<endl;
    for(int size:inputSizes){
        int arr1[size],arr2[size];

        for(int i=0;i<size;i++){
            arr1[i] = i;
            arr2[i] = i;
        }
        clock_t start,end;
        double quickTime;
        if(size!=100000){
            start = clock();
            Quicksort(arr1,0,size-1);
            end = clock();
            quickTime = double(end - start)*1.0 / CLOCKS_PER_SEC;
        }else{
            quickTime = -1;
        }
        start = clock();
        randomQuicksort(arr2,0,size-1);
        end = clock();
        double randomTime = double(end - start)*1.0 / CLOCKS_PER_SEC;

        cout<<"For Size "<<size<<" : "<<"Quick sort time -> "<<quickTime<<" ms " <<"Randomized Quick Time -> "<<randomTime<<" ms"<<endl;
    }


    cout<<"-----Decrasing a Data----------"<<endl;
    for(int size:inputSizes){
        int arr1[size],arr2[size];
        int num = size;
        for(int i=0;i<size;i++){
            arr1[i] = num;
            arr2[i] = num;
            num--;
        }
        clock_t start,end;
        double quickTime;
        if(size!=100000){
            start = clock();
            Quicksort(arr1,0,size-1);
            end = clock();
            quickTime = double(end - start)*1.0 / CLOCKS_PER_SEC;
        }
        else{
            quickTime = -1;
        }
        start = clock();
        randomQuicksort(arr2,0,size-1);
        end = clock();
        double randomTime = double(end - start)*1.0 / CLOCKS_PER_SEC;

        cout<<"For Size "<<size<<" : "<<"Quick sort time -> "<<quickTime<<" ms " <<"Randomized Quick Time -> "<<randomTime<<" ms"<<endl;
    }

    cout<<"-----Same Data----------"<<endl;
    for(int size:inputSizes){
        int arr1[size],arr2[size];

        int num = 5;
        for(int i=0;i<size;i++){
            arr1[i] = num;
            arr2[i] = num;
        }
        clock_t start,end;
        double quickTime;
        if(size!=100000){
            start = clock();
            Quicksort(arr1,0,size-1);
            end = clock();
            quickTime = double(end - start)*1.0 / CLOCKS_PER_SEC;
        }
        else{
            quickTime = -1;
        }
        double randomTime ;
        if(size!=100000){
            start = clock();
            randomQuicksort(arr2,0,size-1);
            end = clock();
            randomTime = double(end - start)*1.0 / CLOCKS_PER_SEC;
        }
        else{
            randomTime = -1;
        }


        cout<<"For Size "<<size<<" : "<<"Quick sort time -> "<<quickTime<<" ms " <<"Randomized Quick Time -> "<<randomTime<<" ms"<<endl;
    }

}
