#include<bits/stdc++.h>
using namespace std;

string findLCS(const string& str1, const string& str2){
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i<=m; ++i){
        for(int j=1; j<=n; j++){
            if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i=m, j=n;
    string lcs;
    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
            lcs+=str1[i-1];
            --i;
            --j;
        }
        else if (dp[i-1][j]>dp[i][j-1]) --i;
        else --j;
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main(){
    string str1, str2;
    cout<<"Enter the first string: ";
    cin>>str1;
    cout<<"Enter the second string: ";
    cin>>str2;
    string lcs = findLCS(str1, str2);
    cout<<"Length of Longest Common Subsequence is:"<<lcs.length()<<endl;
    cout<<"The longest common subsequence is: "<<lcs<<endl;
}
/*input
lullabybabies
skullandbones
*/