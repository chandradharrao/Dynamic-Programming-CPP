#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//since mcm has many overlapping sub problms,we can cache them
//Eg: multiplication of ABCD has overlapping AB(CD) and B(CD) subproblem
//each of the multiplication is characterized by the indexes of the dim array using l and r.
//hence dp[i][j] -> the min cost in multiplying the elements of the array dith dimensions dim[i....j] ie l=i and r=j

int util(vector<int> dim,int l,int r,vector<vector<int>>& dp){
    if(l<=r) return 0;

    //if min cost already cached
    if(dp[l][r] != -1) return dp[l][r];

    //if not cached,
    int min_cost = INT16_MAX;
    //try for all possible paranthesis pos
    for(int k = l;k<r;k++){
        min_cost = min(min_cost,util(dim,l,k,dp)+util(dim,k+1,r,dp)+dim[l-1]*dim[k]*dim[r]);
    }

    return dp[l][r] = min_cost;
}

int mcm(vector<int> dim){
    int n = dim.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return util(dim,1,n,dp);
}

int main(){
    vector<int> arr = { 1,2,3,4,3 };
    int res = mcm(arr);
    cout << "Min num of mult is " << res << endl;
}