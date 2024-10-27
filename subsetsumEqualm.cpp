#include<bits/stdc++.h>
using namespace std;
vector<int>x;
vector<int>w;
int m;
void sumofSubset(int s,int k,int r){
    // left side
    x[k] = 1;
    if(s+w[k]==m){
        for (int i = 1; i <= k; i++)
        {
            if(x[i]==1){
                cout<<w[i]<<" ";
            }
        }
        cout<<endl;
    }else if(s+w[k]+w[k+1]<=m){
        sumofSubset(s+w[k],k+1,r-w[k]);
    }
    // right side
    if((s+r-w[k]>=m) && (s+w[k+1]<=m)){
        x[k] = 0;
        sumofSubset(s,k+1,r-w[k]);
    }
}

int main(){
    int n;cin>>n>>m;
    w.resize(n+1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin>>w[i];
        sum += w[i];
    }
    x.resize(n+1);
    sumofSubset(0,1,sum);
}