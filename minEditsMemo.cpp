#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//top down with memoization

int min(int a,int b,int c){
    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    return c;
}

int util(string s1,string s2,int i,int j,unordered_map<string,int>& dp){
    if(i == -1 && j == -1 ) return 0;
    //since len = last index + 1,we need to convert the zero based indexing to length
    if(i < 0) return 1+j;
    if(j < 0) return 1+i;

    //check if cached in memo 
    string key = to_string(i) + "," + to_string(j);
    if(dp.find(key) != dp.end()) return dp[key];

    //if not cached
    if(s1[i] == s2[j]) return 0 + util(s1,s2,i-1,j-1,dp);
    int insertOps = 1 + util(s1,s2,i,j-1,dp);
    int remOps = 1 + util(s1,s2,i-1,j,dp);
    int replaceOps = 1 + util(s1,s2,i-1,j-1,dp);

    return dp[key] = min(insertOps,remOps,replaceOps);
}

int numMinEdits(string s1,string s2){
    //create hashtable to store the num of minimum operations required to  convert s1[0,,i] to s2[0..j]
    unordered_map<string,int> dp;
    return util(s1,s2,s1.length()-1,s2.length()-1,dp);
}

int main(){
    string s1 = "abc";
    string s2 = "bcd";
    int n = numMinEdits(s1,s2);
    cout << "The min num of ops req  to conv s1 to s2 is " <<n << endl; 
}