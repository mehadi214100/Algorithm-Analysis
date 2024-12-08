#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e3;
int dis[N][N];
const int inf = 1e9+5;
void initialize(){
    for(int i=1;i<=n;i++){
        for (int j = 1; j <=n; j++)
        {
            if(i!=j) dis[i][j] = inf;
        }  
    }
}

void printer(){
    for(int i=1;i<=n;i++){
        for (int j = 1; j <=n; j++)
        {
            if(dis[i][j]==inf)cout<<"x ";
            else cout<<dis[i][j]<<" ";
        }
        cout<<endl;  
    }
}

int main(){
    cin>>n>>m;
    initialize();
    while (m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v] = w;
    }
    cout<<"Before : "<<endl;
    printer();
    for (int k = 1;k <=n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
           for (int j = 1; j <= n; j++)
           {
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
           }
        }
    }

    cout<<"After : "<<endl;
    printer();
}

/*
5 7
1 2 2
1 3 6
2 3 1
3 4 4
4 2 6
2 5 3
5 4 9
*/