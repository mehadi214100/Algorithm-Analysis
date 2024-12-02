#include<bits/stdc++.h>
using namespace std;
const int  N = 1e5+5;
bool vis[N];
bool travis[N];
vector<int>v[N];
vector<int>transpose[N];
stack<int>st;
void dfs(int s){
    vis[s] = true;
    //cout<<s<<" ";
    for(int adj:v[s]){
        if(!vis[adj]){
            dfs(adj);
        }
    }
    st.push(s);
}

void revDFS(int s){
    travis[s] = true;
    cout<<s<<" ";
    for(int adj:transpose[s]){
        if(!travis[adj]){
            revDFS(adj);
        }
    }
}


int main(){
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) dfs(i);
    }
    // transpose
    for(int i = 1;i<=n;i++){
        for (int adj:v[i]){
            transpose[adj].push_back(i);
        }
    }
    
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if(!travis[top]){
            revDFS(top);
            cout<<endl;
        }
    }
    

    
    return 0;
}

/*
input:
5 5
1 3
3 2
2 1
1 4
4 5
output:
1 2 3 
4 
5 
*/