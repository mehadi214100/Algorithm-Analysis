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

int main(){
    vector<vector<int>>graph = {
        {0,1,0,0,1,1,1},
        {1,0,1,1,0,0,0},
        {0,1,0,1,0,0,1},
        {0,1,1,0,1,0,0},
        {1,0,0,1,0,1,1},
        {1,0,0,0,1,0,1},
        {1,0,1,0,1,1,0}
    };
    for(int i=1;i<=graph.size();i++){
        if(Coloring(graph,i)){
            cout<<"Result : "<<i;
            break;
        }
    }
}


