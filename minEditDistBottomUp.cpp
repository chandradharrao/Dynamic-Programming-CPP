#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
//bottom up approach
//dp[i][j] = num of min edits required to convert string of length i to string of length j 

int min(int a,int b,int c){
    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    return c;
}

int numMinEdits(string s1,string s2){
    int n = s1.length();
    int m = s2.length();
    //create dp table
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    //if n == 0,then m insert ops required
    for(int j = 0;j<m+1;j++){
        dp[0][m] = j;
    }
    //if m == 0,then n removal ops are req
    for(int i = 0;i<n+1;i++){
        dp[i][0] = i;
    }

    //i,j rep iterating length of s1 and s2
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            //num of ops req to convert s1 to s2 AFTER we:
            //insert
            int insertOps = dp[i][j-1];
            //remove
            int remOps = dp[i-1][j];
            //replace a char
            int repOps = dp[i-1][j-1];
            if( s1[i-1] == s2[j-1] ){
                //if same,then no need to insert,remove or replace THAT char,focus on the remaining strings
                dp[i][j] = 0 + dp[i-1][j-1];
            }else{
                //remove,insert or replace that cahacter and focus for the remaining string
                dp[i][j] = min(1+insertOps,1+remOps,1+repOps);
            }
        }
    }
    return dp[m][n];
}

int main(){
    string s1 = "abc";
    string s2 = "bcd";
    int n = numMinEdits(s1,s2);
    cout << "The min num of ops req  to conv s1 to s2 is " <<n << endl; 
}