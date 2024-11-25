#include<bits/stdc++.h>
using namespace std;

vector<int>x;

bool place(int k,int l){
    for (int i = 1; i <= k-1; i++)
    {
       if(x[i]==l || abs(k-i)==abs(l-x[i])){
            return false;
       }
    }
    return true;
}

void nQueen(int n,int k){
    for (int i = 1; i <= n; i++)
    {
        if(place(k,i)){
            x[k] = i;
            if(k==n){
                for (int d = 1; d <= n; d++)
                {
                    cout<<x[d]<<" ";
                }
                cout<<endl;
            }else{
                nQueen(n,k+1);
            }
        }
    }
}

int main(){
    int n;cin>>n;
    x.resize(n+1);
    nQueen(n,1);
}
