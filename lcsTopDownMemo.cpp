#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//top down recursive with tabulation -> memoization

int util(string s1,string s2,int i,int j,vector<vector<int*>>& dp){
    //if empty string index -> 0
    if(i <= 0 || j <= 0) return 0;

    //if already cached
    if(dp[i][j] != nullptr){
        return *dp[i][j];
    } 

    if(s1[i-1] == s2[j-1]){
        //move both index by -1
        int res = 1 + util(s1,s2,i-1,j-1,dp);
        dp[i][j] = &res;
    }else{
        //consider the two choices
        int res = 0 + max(util(s1,s2,i-1,j,dp),util(s1,s2,i,j-1,dp));
        dp[i][j] = &res;
    }

    return *dp[i][j];
}

int lcs(string s1,string s2){
    int m = s1.length();
    int n = s2.length();

    vector<vector<int*>> dp(m+1,vector<int*>(n+1,nullptr));

    //lcs('',abc) and lcs(abc,'') is 0
    for(int i = 0;i<=m;i++){
       dp[i][0] = new int;
       *dp[i][0] = 0;
    }

    for(int j = 0;j<=n;j++){
        dp[0][j] = new int;
        *dp[0][j] = 0;
    }

    //top down because starting from index m,n of table
    return util(s1,s2,m,n,dp);
}

int main(){
    string s1 = "acadb";
    string s2 = "cbda";

    cout << "The longest subsequence is " << lcs(s1,s2) << endl;
}