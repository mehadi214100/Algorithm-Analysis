#include<bits/stdc++.h>
using namespace std;

bool NextValue(int k,vector<vector<int>>&graphs,int m,vector<int>&result){
    int n = graphs.size();
    while(true){
        result[k] = (result[k]+1)%(m+1);
        if(result[k]==0) return false;
        bool valid = true;
        for(int j=0;j<n;j++){
            if(graphs[k][j]==1 && result[k]==result[j]){
                valid = false;
                break;
            }
        }
        if(valid) return true;
    }
}

bool graphColoring(int k,vector<vector<int>>&graphs,int m,vector<int>&result){
    int n = graphs.size();
    while(true){
        NextValue(k,graphs,m,result);
        if(result[k]==0) return false;
        if(k==n-1){
                return true;
        }else{
            return graphColoring(k+1,graphs,m,result);
        }
    }
}

bool Coloring(vector<vector<int>>&graphs,int m){
    int n = graphs.size();
    vector<int>result(n,0);
    return graphColoring(0,graphs,m,result);
}

int nodeCheck(vector<int>arr1,vector<int>arr2){
    bool check = false;
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2.size();j++){
            if(arr1[i]==arr2[j]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    cout<<"Total Number of Course :";
    int n;cin>>n;
    vector<vector<int>>students(n);
    for(int i=0;i<n;i++){
        int number;
        cout<<"Total Number of Students :";
        cin>>number;
        students[i].resize(number);

        for(int j=0;j<number;j++){
            cin>>students[i][j];
        }
    }

    vector<vector<int>>graph(n);
    for(int i=0;i<n;i++){
            graph[i].resize(n);
            for(int j=0;j<n;j++){
                graph[i][j] = 0;
            }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                vector<int>arr1 = students[i];
                vector<int>arr2 = students[j];
                if(nodeCheck(arr1,arr2)){
                    graph[i][j] = 1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
    }

    for(int i=1;i<=graph.size();i++){
        if(Coloring(graph,i)){
            cout<<"Result : "<<i;
            break;
        }
    }
}




