#include<bits/stdc++.h>
using namespace std;
vector<int>w;
vector<int>x;
int n,m;
void sumofsubset(int s,int k,int r){
    // left size
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
        sumofsubset(s+w[k],k+1,r-w[k]);
    }

    // right
    if(s+r-w[k]>=m && s+w[k+1]<=m){
        x[k] = 0;
        sumofsubset(s,k+1,r-w[k]);
    }

}


int main(){
    cin>>n>>m;
    int sum = 0;
    w.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>w[i];
        sum += w[i];
    }
    x.resize(n+1);
    sumofsubset(0,1,sum);
    
    return 0;
}