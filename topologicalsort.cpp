#include<bits/stdc++.h>
using namespace std;
const int  N = 1e5+5;
bool vis[N];
vector<int>v[N];
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
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    

    
    return 0;
}

/*
input:
6 7
1 2
1 3
2 4
3 4
4 5
4 6
5 6
output:
1 3 2 4 5 6 
*/